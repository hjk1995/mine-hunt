#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#define CD cleardevice
#define I initgraph
#define mx getmaxx
#define my getmaxy
#define R rectangle
#define C circle
#define S setcolor
#define F floodfill
int scan, ascii;
int x = 80, y = 377, h = 0, f = 1;
int b[200], a[200], c[200];
int mark = 0;
int check();
void home();
void mine();
void win();
void getkey();
void startG();
void closeG();
void mineset();
void object(int, int);
void board();
main()
{
    int i = 0, j = 0, key = 0;
    int k = 0, m = 1, cp = 0;
    srand(time(NULL));
    clrscr();
    startG();
    mine();
    home();
    board();
    while (ascii != 32)
    {
        k = m;
        getkey();
        if (scan == 72 || ascii == 119)
        {
            j = 35;
            cp++;
            object(0, j);
            m = m + 5;
            b[k + 5] = mark;
        }
        else if (scan == 77 || ascii == 100)

        {
            i = 30;
            cp++;
            object(i, 0);
            m++;
            b[k + 1] = mark;
        }
        else if (scan == 75 || ascii == 97)

        {
            i =
                -30;
            cp++;
            object(i, 0);
            m--;
            b[k - 1] = mark;
        }
        else

        {
            settextstyle(7, 0, 2);
            outtextxy(mx(), my() - 200, "Invalid");
        }
        h = check();
        j = checkmine(k);
        settextstyle(7, 0, 2);
        if (h == 1)

        {
            outtextxy(570, 250, "Player Wins!!");
            win();
            break;
        }
        else if (j == 0)

        {
            outtextxy(570, 250, "AI Wins");
            break;
        }
    }
    closeG();
    getch();
}
int checkmine(int k)
{
    int i;
    for (i = 1; i <= 100; i++)
    {
        if (k == a[i])
        {
            return 0;
        }
    }
}
int check()
{
    if (b[100] == mark)
    {
        return 1;
    }
}
void startG()
{
    int gd = DETECT, gm;
 initgraph(&gd,&gm,"C:
\\TC
\\BGI");
}
void closeG()
{
    getch();
    closegraph();
}
void mineset()
{
    int i, j;
    char a[20];
    setbkcolor(WHITE);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    S(RED);
    for (i = 5; i >= 0; i--)

    {
        settextstyle(7, 0, (i / 2));
        outtextxy(294, 127, "Let Mines To Be Set!!");
        setfillstyle(INTERLEAVE_FILL, YELLOW);
        circle(315, 248, 35 + 2 * i);
        F(315, 248, 4);
        setfillstyle(INTERLEAVE_FILL, BLUE);
        circle(315, 248, 25 - i);
        F(315, 248, 4);
        sprintf(a, "%d", i);
        outtextxy((getmaxx() / 2), (getmaxy() / 2), a);
        delay(1000);
        if (i == 0)
        {
            break;
        }
        CD();
    }
    CD();
}
void object(int i, int j)
{
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    x = x + i;
    y = y - j;
    if ((x < 400 && y < 400) && (x > 90 && y > 40))

    {
        fillellipse(x, y, 7, 7);
    }
}
void board()
{
    int i;
    char a[5];
    setbkcolor(WHITE);
    S(8);
    R(0, 0, mx(), my());
    line((mx() - 145), 0, (mx() - 145), my());
    line((mx() - 145), (my() - 300), mx(), (my() - 300));
    R(90, 40, 400, 400);
    R(70, 20, 420, 420);
    S(RED);
    R(70, 365, 90, 385);
    S(BLUE);
    outtextxy(570, 210, "Status:");
    outtextxy(570, 70, "Score:");
    for (i = 0; i < 350; i++)

    {
        i = i + 34;
        R(100, 400 - i, 120, 420 - i);
        R(130, 400 - i, 150, 420 - i);
        R(160, 400 - i, 180, 420 - i);
        R(190, 400 - i, 210, 420 - i);
        R(220, 400 - i, 240, 420 - i);
        R(250, 400 - i, 270, 420 - i);
        R(280, 400 - i, 300, 420 - i);
        R(310, 400 - i, 330, 420 - i);
        R(340, 400 - i, 360, 420 - i);
        R(370, 400 - i, 390, 420 - i);
    }
}
void getkey()
{
    union REGS ii, oo;
    ii.h.ah = 0;
    int86(22, &ii, &oo);
    scan = oo.h.ah;
    ascii = oo.h.al;
}
void win()
{
    int area, temp1, temp2, left = 25, top = 75;
    void *p;
    setcolor(YELLOW);
    circle(50, 100, 25);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(50, 100, YELLOW);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(44, 85, 2, 6);
    fillellipse(56, 85, 2, 6);
    ellipse(50, 100, 205, 335, 20, 9);
    ellipse(50, 100, 205, 335, 20, 10);
    ellipse(50, 100, 205, 335, 20, 11);
    area = imagesize(left, top, left + 50, top + 50);
    p = malloc(area);
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(155, 451, "WIN WIN WIN");
    outtextxy(155, 251, "Congo Homie!!");
    setcolor(BLACK);
    rectangle(0, 0, 639, 449);
    while (!kbhit())

    {
        temp1 = 1 + rand(588);
        temp2 = 1 + rand(380);
        getimage(left, top, left + 50, top + 50, p);
        putimage(left, top, p, XOR_PUT);
        putimage(temp1, temp2, p, XOR_PUT);
        delay(150);
        left = temp1;
        top = temp2;
    }
}
void home()
{
    settextstyle(7, 0, 5);
outtextxy(200,200,"Mine
-Trap");
}
void mine()
{
    int i, j;
    for (i = 1; i <= 100; i++)

    {
        b[i] = i;
    }
    srand(time(NULL));
    for (i = 1; i <= 40; i++)
    {
        a[i] = (rand() % 100) + 1;
    }
}
