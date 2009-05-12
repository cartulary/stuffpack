/* This is NOT my code - it comes from a tutorial online and I'm trying to make the code somewhat sane */
#include <allegro.h>
#include <algorithm>
//#include <cstdlib>

void drawPaddle(int x, int y, int col);
void drawBall(int x, int y, bool visible, int ball_effect);
void move(int player, int old_x, int old_y);

int ball_x = 320;
int ball_y = 240;

int player_x[3];
int player_y[3];

const int BALL_RADIUS = 5;
const int BALL_Y_MIN = 25;

int paddle_size_h;

bool invert_keys;

int dir;     //This will keep track of the circles direction
            //1= up and left, 2 = down and left, 3 = up and right, 4 = down and right

BITMAP *buffer; //This will be our temporary bitmap for double buffering

void moveBall(int ball_effect)
{
	int ball_tempX;
	int ball_tempY;
	ball_tempX = ball_x;
	ball_tempY = ball_y;

	if (dir == 1 && ball_x > BALL_RADIUS && ball_y > BALL_Y_MIN + BALL_RADIUS)
	{
		if( ball_x == player_x[1] + 15 && ball_y >= player_y[1] && ball_y <= player_y[1] + paddle_size_h)
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
		if( ball_x == player_x[1] + 15 && ball_y >= player_y[1] && ball_y <= player_y[1] + paddle_size_h)
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
		if( ball_x + BALL_RADIUS == player_x[2] && ball_y >= player_y[2] && ball_y <= player_y[2] + paddle_size_h)
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
      	if( ball_x + BALL_RADIUS == player_x[2] && ball_y >= player_y[2] && ball_y <= player_y[2] + paddle_size_h)
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
	drawBall(ball_tempX,ball_tempY, false, 0);
	drawBall(ball_x,ball_y, true, ball_effect);
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
	if (invert_keys)
	{
		std::swap (keyUp, keyDown);
	}

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

	paddle_size_h = 60;
	invert_keys = false;
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
	drawBall(ball_x, ball_y, true, 1);
	draw_sprite( screen, buffer, 0, 0);
	release_screen();
	dir = arc4random() % 4 + 1;

}

void drawPaddle(int x, int y, int col)
{
	rectfill( buffer, x, y, x + 10, y + paddle_size_h, makecol ( 0, 0, col));
}

void drawBall(int x, int y, bool visible, int ball_effect)
{
	if (visible)
	{
		circlefill ( buffer, x, y, 5, makecol( ball_effect * 20 , 255 - (ball_effect * 10), ball_effect));
	}
	else
	{
		circlefill ( buffer, x, y, 5, makecol( 0, 0, 0));
	}
}

int main()
{
	int rest_speed = 15;
	int ball_effect = 1;

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

	int no_win_counter = 0;
	while( !key[KEY_ESC])
	{
		move(1, player_x[1], player_y[1]);
		move(2, player_x[2], player_y[2]);
		moveBall(ball_effect);
		if (no_win_counter == 0)
		{
			checkWin();
		}
		else
		{
			--no_win_counter;
		}
		textprintf_centre_ex(buffer, font, SCREEN_W/2, 1,
			makecol(0,0,255),makecol(255,0,0),
			 "X=%d, Y=%d, rest speed = %d, ball effect = %d, no_win_counter = %d",
			ball_x, ball_y, rest_speed, ball_effect, no_win_counter
			);
		if (invert_keys)
		{
			textout_centre_ex(buffer, font, "keys inverted", SCREEN_W/2 - 100, 10, makecol(0,0,255), makecol(0,0,0));
		}
		else
		{
			textout_centre_ex(buffer, font, "             ", SCREEN_W/2 - 100, 10, makecol(0,0,0), makecol(0,0,0));
		}
		if (ball_effect == 2)
		{
			textout_centre_ex(buffer, font, "dir random", SCREEN_W/2 + 100, 10, makecol(0,0,255), makecol(0,0,0));
		}
		else
		{
			textout_centre_ex(buffer, font, "          ", SCREEN_W/2 + 100, 10, makecol(0,0,0), makecol(0,0,0));
		}
		fastline(buffer, 0, BALL_Y_MIN, SCREEN_W, BALL_Y_MIN, makecol(0,255,0));
		if (key[KEY_PGUP])
		{
			++rest_speed;
		}
		if (key[KEY_PGDN])
		{
			--rest_speed;
		}
		if (key[KEY_SPACE])
		{
			drawBall(ball_x, ball_y, false, ball_effect);
			ball_x = (arc4random() % (SCREEN_W - 40)) + 20;
			ball_y = (arc4random() % (SCREEN_H - 40)) + 20;
			drawBall(ball_x, ball_y, true, ball_effect);
		}
		if (arc4random() % 500 == 1)
		{
			ball_effect = arc4random() % 10;
		}
		switch (ball_effect)
		{
			case 2:
				if (arc4random() % 100 < 5)
				{
					dir = arc4random() % 4 + 1;
				}
				break;
			case 3:
				if (arc4random() % 100 < 5)
				{
					drawBall(ball_x, ball_y, false, ball_effect);
					ball_x = (arc4random() % (SCREEN_W - 40)) + 20;
					ball_y = (arc4random() % (SCREEN_H - 40)) + 20;
					drawBall(ball_x, ball_y, true, ball_effect);
					// once we move randomly - don't move again
					ball_effect = 1;
				}
				break;
			case 4:
				paddle_size_h += 10;
				ball_effect = 1;
				break;
			case 5:
				paddle_size_h -= 10;
				ball_effect = 1;
				break;
			case 6:
				rest_speed = rest_speed / 2;
				// only do this once
				ball_effect = 1;
				break;
			case 7:
				no_win_counter = 1000;
				ball_effect = 1;
				break;
			case 8:
				invert_keys = !invert_keys;
				ball_effect = 1;
				break;
			default:
				ball_effect = 1;
				break;
		}
		rest(rest_speed);
	}
	return 0;
}
END_OF_MAIN();

/*
Ball effects
1 - normal ball
2 - random chance of changing direction
3 - random chance of moving to random position
4 - bigger paddles
5 - smaller paddles
6 - ultra fast movement (low rest speed)
7 - freeze win check for 1000 counts (other ball effects help);
8 - invert keys
*9
*10 - go through to other side
*not yet complete
*/

