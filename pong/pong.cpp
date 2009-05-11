/* This is NOT my code - it comes from a tutorial online and I'm trying to make the code somewhat sane */
#include <allegro.h>
#include <cstdlib>

void drawPaddle(int x, int y, int col);
void drawBall(int x, int y, bool visible);
void move(int player, int old_x, int old_y);

int ball_x = 320;
int ball_y = 240;

int player_x[3];
int player_y[3];

const int BALL_RADIUS = 5;
const int BALL_Y_MIN = 25;


int dir;     //This will keep track of the circles direction
            //1= up and left, 2 = down and left, 3 = up and right, 4 = down and right

BITMAP *buffer; //This will be our temporary bitmap for double buffering

void moveBall()
{
	int ball_tempX;
	int ball_tempY;
	ball_tempX = ball_x;
	ball_tempY = ball_y;

	if (dir == 1 && ball_x > BALL_RADIUS && ball_y > BALL_Y_MIN + BALL_RADIUS)
	{
		if( ball_x == player_x[1] + 15 && ball_y >= player_y[1] && ball_y <= player_y[1] + 60)
		{
            	dir = arc4random()% 2 + 3;
         	}
		else
		{
			--ball_x;
			--ball_y;
		}
	}
	else if (dir == 2 && ball_x > BALL_RADIUS && ball_y < SCREEN_H - BALL_RADIUS)
	{
		if( ball_x == player_x[1] + 15 && ball_y >= player_y[1] && ball_y <= player_y[1] + 60)
		{
            	dir = arc4random()% 2 + 3;
         	}
		else
		{
            	--ball_x;
			++ball_y;
         	}
	}
	else if (dir == 3 && ball_x < SCREEN_W - BALL_RADIUS && ball_y > BALL_Y_MIN + BALL_RADIUS)
	{
		if( ball_x + BALL_RADIUS == player_x[2] && ball_y >= player_y[2] && ball_y <= player_y[2] + 60)
		{
                  dir = arc4random()% 2 + 1;
         	}
		else
		{
                 ++ball_x;
                 --ball_y;
         	}
	}
	else if (dir == 4 && ball_x < SCREEN_W - BALL_RADIUS && ball_y < SCREEN_H - BALL_RADIUS)
	{
      	if( ball_x + BALL_RADIUS == player_x[2] && ball_y >= player_y[2] && ball_y <= player_y[2] + 60)
		{
            	dir = arc4random()% 2 + 1;
		}
		else
		{
			++ball_x;
			++ball_y;
		}
	}
	else
	{
		if (dir == 1 || dir == 3)
		{
			++dir;
		}
		else
		{
			--dir;
		}
    }

	acquire_screen();
	drawBall(ball_tempX,ball_tempY, false);
	drawBall(ball_x,ball_y, true);
	draw_sprite( screen, buffer, 0, 0);
	release_screen();


}

void move(int player, int old_x, int old_y)
{
	int temp_y;
	int temp_x;
	int playerDirUp = false;
	int playerDirDown = false;
	int keyUp = (player == 1) ? KEY_W : KEY_UP;
	int keyDown = (player == 1) ? KEY_S : KEY_DOWN;

	if (key[keyUp])
	{
		playerDirUp = true; //up
	}
	else if (key[keyDown]) //down
	{
		playerDirDown = true;
	}

	int new_x, new_y;
	temp_y = old_y;
	temp_x = old_x;

	if ( playerDirUp && old_y > BALL_Y_MIN)
	{
		--player_y[player];
	}
	else if( playerDirDown && old_y < 420)
	{
		++player_y[player];
	}
	new_x = player_x[player];
	new_y = player_y[player];

	acquire_screen();
	drawPaddle(temp_x, temp_y, 0);
      drawPaddle(new_x, new_y, 255);
    	release_screen();
}


void startNew()
{
	clear_keybuf();
	readkey();
	clear_to_color( buffer, makecol( 0, 0, 0));
	ball_x = 320;
	ball_y = 240;

	player_x[1] = 20;
	player_y[1] = 210;

	player_x[2] = 620;
	player_y[2] = 210;
}

void checkWin()
{
	if ( ball_x < player_x[1])
	{
		textout_ex( screen, font, "Player 2 Wins!", 320, 240, makecol( 255, 0, 0), makecol( 0, 0, 0));
		startNew();
	}
	else if ( ball_x > player_x[2])
	{
		textout_ex( screen, font, "Player 1 Wins!", 320, 240, makecol( 255, 0, 0), makecol( 0, 0, 0)); 
		startNew();
	}

}

void setupGame()
{
	acquire_screen();
	drawPaddle(player_x[1], player_y[1], 255);
	drawPaddle(player_x[2], player_y[2], 255);
	drawBall(ball_x, ball_y, true);
	draw_sprite( screen, buffer, 0, 0);
	release_screen();
	dir = arc4random() % 4 + 1;

}

void drawPaddle(int x, int y, int col)
{
	rectfill( buffer, x, y, x + 10, y + 60, makecol ( 0, 0, col));
}

void drawBall(int x, int y, bool visible)
{
	if (visible)
	{
		circlefill ( buffer, x, y, 5, makecol( 128, 255, 0));
	}
	else
	{
		circlefill ( buffer, x, y, 5, makecol( 0, 0, 0));
	}
}

int main()
{
	int rest_speed = 15;
	int ball_effect = 0;

	if (allegro_init() != 0)
	{
		return 1;
	}

	install_keyboard();
	set_color_depth(16);
	set_gfx_mode( GFX_AUTODETECT, 640, 480, 0, 0);
	buffer = create_bitmap( 640, 480);
	startNew();

	setupGame();

	while( !key[KEY_ESC])
	{
		move(1, player_x[1], player_y[1]);
		move(2, player_x[2], player_y[2]);
		moveBall();
		checkWin();
		textprintf_centre_ex(buffer, font, SCREEN_W/2, 1,
			makecol(0,0,255),makecol(255,0,0),
			 "X=%d, Y=%d, rest speed = %d, ball effect = %d",
			ball_x, ball_y, rest_speed, ball_effect
			);
		fastline(buffer, 0, BALL_Y_MIN, SCREEN_W, BALL_Y_MIN, makecol(0,255,0));
		if (key[KEY_PGUP])
		{
			++rest_speed;
		}
		if (key[KEY_PGDN])
		{
			--rest_speed;
		}
		rest(rest_speed);
	}
	return 0;
}
END_OF_MAIN();
