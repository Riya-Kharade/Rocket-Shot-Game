#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>  // for sound()

int ch, s = 4, i, k = 0;
char arr[20], shot[20], starts, arr1[20], arr2[20];
int x1 = 200, y1 = 350, x2 = 200, y2 = 350;
int x3 = 180, y3 = 390, x4 = 220, y4 = 390;
int bc1 = 100, bc2 = 150, bh = 100, bh2 = 50;
int min = 100, max = 330, min1 = 101, max1 = 331;
int incre = 2, level = 50, lev = 1, move = 11;

void start() {
    setbkcolor(BLACK);
    setcolor(BROWN);
    settextstyle(0, 0, 5);
    outtextxy(100, 140, "ROCKET SHOT");

    settextstyle(3, 0, 2);
    outtextxy(220, 200, "Press s to start");
    outtextxy(220, 250, "Press h to help");
    outtextxy(220, 300, "Press e to exit");
}

void ghelp() {
    cleardevice();
    setcolor(MAGENTA);
    settextstyle(3, 0, 2);
    outtextxy(0, 100, "1. Use <- and -> arrow keys to move rocket.");
    outtextxy(0, 140, "2. Press F to fire bullets.");
    outtextxy(0, 180, "3. SHOTS: Number of shots remaining.");
    outtextxy(0, 220, "4. SCORE: Hit target middle for points.");
    outtextxy(0, 260, "5. TARGET: Aim to reach target score to win.");
    outtextxy(0, 300, "6. Hitting the target middle adds 1 shot!");
    outtextxy(0, 340, "7. Missing decreases shots by 1.");
    outtextxy(0, 380, "TIP: Target falls faster in higher levels.");
    getch();
}

void loading() {
    cleardevice();
    outtextxy(250, 200, "LOADING");
    for (i = 150; i < 350; i++) {
        putpixel(i, 250, WHITE);
        delay(15);
    }
}

void rocket() {
    setcolor(6);
    setfillstyle(SOLID_FILL, 6);
    line(x1, y1, x3, y3);
    line(x2, y2, x4, y4);
    line(x3, y3, x4, y4);
    floodfill(x1 + 1, y3 - 1, 6);

    setcolor(62);
    setfillstyle(SOLID_FILL, 62);
    rectangle(x3, y3, x4, y4 + 40);
    floodfill(x3 + 1, y3 + 1, 62);

    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    line(x3 + 5, y4 + 40, x4 - 5, y4 + 40);
    line(x3 + 5, y4 + 40, x3 + 5, y4 + 50);
    line(x4 - 5, y4 + 40, x4 - 5, y4 + 50);
    line(x3 + 5, y4 + 50, x3 + 10, y4 + 60);
    line(x4 - 5, y4 + 50, x4 - 10, y4 + 60);
    line(x3 + 10, y4 + 60, x3 + 10, y4 + 65);
    line(x4 - 10, y4 + 60, x4 - 10, y4 + 65);
    line(x3 + 10, y4 + 65, x3 + 20, y4 + 75);
    line(x4 - 10, y4 + 65, x4 - 20, y4 + 75);
    floodfill(x3 + 6, y4 + 41, RED);
}

void target2(int bc2, int bh2) {
    setcolor(10);
    setfillstyle(HATCH_FILL, 10);
    circle(bc2, bh2, 20);
    floodfill(bc2 + 1, bh2 + 1, 10);

    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(bc2 + 25, bh2, 5);
    floodfill(bc2 + 26, bh2 + 1, YELLOW);

    circle(bc2 - 25, bh2, 5);
    floodfill(bc2 - 24, bh2 + 1, YELLOW);

    circle(bc2, bh2 + 25, 5);
    floodfill(bc2 + 1, bh2 + 26, YELLOW);

    circle(bc2, bh2 - 25, 5);
    floodfill(bc2 + 1, bh2 - 24, YELLOW);
}

void crst(int xx1, int xx2, int yy1, int yy2) {
    setcolor(WHITE);
    line(xx1, yy1 + 5, xx2, yy1 + 5);
    line(xx1 + 5, yy1, xx1 + 5, yy2);
    line(xx1, yy1, xx2, yy2);
    line(xx2, yy1, xx1, yy2);
}

void stars() {
    int sx1 = 50, sx2 = 60, sy1 = 0, sy2 = 10;
    crst(sx1 + 10, sx2 + 10, sy1 + 10, sy2 + 10);
    crst(sx1 + 20, sx2 + 20, sy1 + 30, sy2 + 30);
    crst(sx1 + 30, sx2 + 30, sy1 + 40, sy2 + 40);
    crst(sx1 + 60, sx2 + 60, sy1 + 30, sy2 + 30);
    crst(sx1 + 250, sx2 + 250, sy1 + 30, sy2 + 30);
    crst(sx1 + 200, sx2 + 200, sy1 + 60, sy2 + 60);
    crst(sx1 + 230, sx2 + 230, sy1 + 200, sy2 + 200);
    crst(sx1 + 100, sx2 + 100, sy1 + 80, sy2 + 80);
    crst(sx1 + 20, sx2 + 20, sy1 + 330, sy2 + 330);
    crst(sx1 + 50, sx2 + 50, sy1 + 300, sy2 + 300);
    crst(sx1 + 20, sx2 + 20, sy1 + 200, sy2 + 200);
    crst(sx1 + 200, sx2 + 200, sy1 + 230, sy2 + 230);
    crst(sx1 + 150, sx2 + 150, sy1 + 180, sy2 + 180);
    crst(sx1 + 20, sx2 + 20, sy1 + 30, sy2 + 30);
    crst(sx1 + 100, sx2 + 100, sy1 + 120, sy2 + 120);
    crst(sx1 + 50, sx2 + 50, sy1 + 300, sy2 + 300);
    crst(sx1 + 70, sx2 + 70, sy1 + 340, sy2 + 340);
    crst(sx1 + 280, sx2 + 280, sy1 + 320, sy2 + 320);
    crst(sx1 + 250, sx2 + 250, sy1 + 380, sy2 + 380);
    crst(sx1 + 180, sx2 + 180, sy1 + 270, sy2 + 270);
}

void main() {
    int gd = DETECT, gm;
    int y, temp_i;  // all local variables declared here
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    detectgraph(&gd, &gm);
    srand(time(NULL));

    bc1 = (rand() % (max - min + 1)) + min;
    bc2 = (rand() % (max1 - min1 + 1)) + min1;

    do {
        cleardevice();
        start();
        starts = getch();

        if (starts == 'e' || starts == 'E') exit(0);
        else if (starts == 's' || starts == 'S') {
            loading();
            settextstyle(1, 0, 3);

            while (1) {
                cleardevice();
                stars();
                setcolor(GREEN);
                line(50, 0, 50, 400);
                line(350, 0, 350, 400);

                setcolor(52);
                setfillstyle(SOLID_FILL, BLACK);
                rectangle(50, 0, 350, 470);
                rectangle(350, 0, 650, 470);
                floodfill(51, 351, 52);

                sprintf(arr2, "LEVEL = %d", lev);
                outtextxy(450, 60, arr2);
                sprintf(arr, "SCORE = %d", k);
                outtextxy(450, 140, arr);
                sprintf(shot, "SHOTS = %d", s);
                outtextxy(450, 180, shot);
                sprintf(arr1, "TARGET = %d", level);
                outtextxy(450, 100, arr1);

                rocket();
                target2(bc2, bh2);

                if (kbhit()) {
                    ch = getch();
                    if (ch == 'e' || ch == 'E') break;

                    else if (ch == 'f' || ch == 'F') {
                        s--;
                        if (s >= 0) {
                            y = y1;
                            sound(500);  // firing sound
                            for (temp_i = 0; temp_i < 100; temp_i += 10) {
                                cleardevice();
                                stars();
                                rocket();
                                target2(bc2, bh2);
                                line(x1, y, x2, y - 20);
                                y -= 20;
                                delay(50);
                            }
                            nosound();

                            if (x1 >= bc2 - 10 && x1 <= bc2 + 10) {
                                k += 10;
                                s++;
                                bc2 = (rand() % (max1 - min1 + 1)) + min1;
                                bh2 = 0;
                                sound(1000); delay(200); nosound(); // hit sound
                            }
                        }
                    }

                    else if (ch == 77) { if (x4 < 340) { x1 += move; x2 += move; x3 += move; x4 += move; } }
                    else if (ch == 75) { if (x3 > 50) { x1 -= move; x2 -= move; x3 -= move; x4 -= move; } }
                }

                bh2 += incre;

                if (s <= 0 || (bh2 >= y3 && bh2 <= y4 + 75)) {
                    cleardevice();
                    setcolor(RED);
                    settextstyle(3, 0, 5);
                    outtextxy(200, 200, "GAME OVER!");
                    delay(2000);
                    break;
                }

                if (lev == 1) level = 50;
                else if (lev == 2) level = 80;
                else if (lev == 3) level = 150;

                if (k >= level) {
                    lev++; k = 0;
                    if (lev == 2) s = 5; else if (lev == 3) s = 7; else s = 4;
                    incre += 1;
                    cleardevice();
                    outtextxy(200, 200, "LEVEL UP!");
                    sound(800); delay(500); nosound();
                    delay(1000);
                    bh2 = 50;
                    bc2 = (rand() % (max1 - min1 + 1)) + min1;
                }

                delay(100);
            }
        }
        else if (starts == 'h' || starts == 'H') ghelp();

    } while (starts != 'e' && starts != 'E');

    getch();
    closegraph();
}
