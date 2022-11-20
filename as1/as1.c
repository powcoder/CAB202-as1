#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <cab202_graphics.h>
#include <cab202_timers.h>

int studentnumber = 10092030;
int gamescore = 0;
int live = 5;
char player = 'J';
int minute = 0;
int seconds = 0;
int cheese = 0;
int traps = 0;
int weapons = 0;
int level = 1;

sprite_id jerry;





void draw_all ( FILE * stream){
    char pen = '*';

    while(!feof(stream)){
        char command;

        double x1;
        double y1;
        double x2; 
        double y2; 

        int num = fscanf(stream, "%c %lf %lf %lf %lf" , &command, &x1, &y1, &x2, &y2);
        x1 = x1 * screen_width() - 0.5;
        y1 = y1 * screen_height() - 0.5 + 5;
        x2 = x2 * screen_width() - 0.5;
        y2 = y2 * screen_height() - 0.5 + 5;


        if(num == 3){
            if(command == 'J')
            pen = 'J';
            draw_char(x1, y1, pen);
        }
        if(num == 3){
            if(command == 'T')
            pen = 'T';
            draw_char(x1, y1, pen);
        }
        if(num == 5){
            if(command == 'W')
            pen = '*';
            draw_line(x1, y1, x2, y2, pen);
        } 
    }
}

// Insert other functions here, or include header files
void setup () {
    int x1 = 0.2 * screen_width();
    int x2 = 0.4 * screen_width();
    int x3 = 0.6 * screen_width();
    int x4 = 0.8 * screen_width();
    //row 1
    draw_formatted(0, 0, "StudentNo: n%d", studentnumber);
    draw_formatted(x1, 0, "Score: %d", gamescore);
    draw_formatted(x2, 0, "Lives: %d", live);
	draw_formatted(x3, 0, "Player: %c", player);
    draw_formatted(x4, 0, "Time: %02i:%02i", minute, seconds);
    //row 2
    draw_formatted(0, 2, "Cheese: %d", cheese);
    draw_formatted(x1, 2, "Traps: %d", traps);
    draw_formatted(x2, 2, "Fireworks: %d", weapons);
    draw_formatted(x3, 2, "Level: %d", level);
    //border
    draw_line(0, 3, screen_width(), 3, '-');

    time = create_timer(1000);

    jerry = sprite_create
}

void time_update() {
	if (timer_expired(time)) {
        timer_reset(time);
		seconds = seconds + 1;
    }
    if (seconds == 60) {
        minute = minute + 1;
        seconds = 0;	
    }
}

void jerrymove
void loop() {
    // Insert loop logic here.
}

#define MAX_ITEMS (100)

int main(int argc, char *argv[]) {
    setup_screen();
    setup ();
    for (int i = 1; i < argc; i++) 
    {
        FILE * stream = fopen(argv[i], "r");
        if (stream != NULL)
        {   
            draw_all(stream);
            fclose(stream);
        }

        show_screen();
        wait_char();
    }
    return 0;
}