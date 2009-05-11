/* This is NOT my code - it comes from a tutorial online and I'm trying to make the code somewhat sane */
#include <allegro.h>
#include <cstdlib>
#include <time.h>

void drawPaddle(int x, int y, int col);
void drawBall(int x, int y, bool visible);

int ball_x = 320;
int ball_y = 240;

int ball_tempX = 320;
int ball_tempY = 240;

int p1_x = 20;
int p1_y = 210;

int p1_tempX = 20;
int p1_tempY = 210;

int p2_x = 620;
int p2_y = 210;

int p2_tempX = 620;
int p2_tempY = 210;

int dir;     //This will keep track of the circles direction
            //1= up and left, 2 = down and left, 3 = up and right, 4 = down and right

BITMAP *buffer; //This will be our temporary bitmap for double buffering

void moveBall()
{

    ball_tempX = ball_x;
    ball_tempY = ball_y;

	if (dir == 1 && ball_x > 5 && ball_y > 5)
	{
		if( ball_x == p1_x + 15 && ball_y >= p1_y && ball_y <= p1_y + 60)
		{
            	dir = arc4random()% 2 + 3;
         	}
		else
		{
			--ball_x;
			--ball_y;
         }
	}
	else if (dir == 2 && ball_x > 5 && ball_y < 475)
	{

         if( ball_x == p1_x + 15 && ball_y >= p1_y && ball_y <= p1_y + 60){
                  dir = arc4random()% 2 + 3;
         }else{    
                 --ball_x;
                 ++ball_y;
         }

    } else if (dir == 3 && ball_x < 635 && ball_y > 5){

         if( ball_x + 5 == p2_x && ball_y >= p2_y && ball_y <= p2_y + 60){
                  dir = arc4random()% 2 + 1;
         }else{    
                 ++ball_x;
                 --ball_y;
         }

    } else if (dir == 4 && ball_x < 635 && ball_y < 475){

      	if( ball_x + 5 == p2_x && ball_y >= p2_y && ball_y <= p2_y + 60){
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
    
    rest(15);

}    

void move(int player)
{
	int temp_y;
	int temp_x;
	if (player == 1)
	{
		temp_y = p1_y;
		temp_x = p1_x;
		if ( key[KEY_W] && p1_y > 0)
		{
			--p1_y;
		}
		else if( key[KEY_S] && p1_y < 420)
		{
			++p1_y;
		}
		acquire_screen();
    		drawPaddle(temp_x, temp_y, 0);
    		drawPaddle(p1_x, p1_y, 255);
    		release_screen();
	}
	else
	{
		p2_tempY = p2_y;
		if( key[KEY_UP] && p2_y > 0)
		{
	        	--p2_y;
      	}
		else if ( key[KEY_DOWN] && p2_y < 420)
		{
     			 ++p2_y;
    		}
		acquire_screen();
		drawPaddle(p2_tempX, p2_tempY, 0);
      	drawPaddle(p2_x, p2_y, 255);
    		release_screen();
	}
}


void startNew()
{

    clear_keybuf();
    readkey();
    clear_to_color( buffer, makecol( 0, 0, 0));
    ball_x = 320;
    ball_y = 240;

    p1_x = 20;
    p1_y = 210;

    p2_x = 620;
    p2_y = 210;

}    

void checkWin(){

	if ( ball_x < p1_x)
	{
		textout_ex( screen, font, "Player 2 Wins!", 320, 240, makecol( 255, 0, 0), makecol( 0, 0, 0));
		startNew();
	}
	else if ( ball_x > p2_x)
	{
		textout_ex( screen, font, "Player 1 Wins!", 320, 240, makecol( 255, 0, 0), makecol( 0, 0, 0)); 
		startNew();
    }
}

void setupGame()
{
	acquire_screen();
	drawPaddle(p1_x, p1_y, 255);
	drawPaddle(p2_x, p2_y, 255);
	drawBall(ball_x, ball_y, true);
	draw_sprite( screen, buffer, 0, 0);
	release_screen();
	dir = arc4random() % 4 + 1;

}

int main()
{

    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode( GFX_AUTODETECT, 640, 480, 0, 0);
    buffer = create_bitmap( 640, 480); 

    setupGame();

	while( !key[KEY_ESC])
	{

        move(1);
        move(2);
        moveBall();
        checkWin();
	}

	return 0;
}
END_OF_MAIN();

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
