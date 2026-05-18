#include <iostream>
#include <cstdlib>
#include <graphics.h>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    int i, x, y, flag = 0;

    // Initialize graphics
    initgraph(&gd, &gm, NULL);

    // Get mid positions in x and y-axis
    x = getmaxx() / 2;
    y = 30;

    while (1)
    {
        // Check if the ball hits the top or bottom of the window
        if (y >= getmaxy() - 30 || y <= 30)
            flag = !flag;

        // Draw the ball
        setcolor(RED);
        circle(x, y, 30);
        floodfill(x, y, RED);

        // Delay for 50 milliseconds
        delay(50);

        // Clear the screen
        cleardevice();

        // Update the position of the ball based on the flag
        if (flag)
            y = y + 5; // Move the ball down
        else
            y = y - 5; // Move the ball up
    }

    // Delay for 5 seconds before closing the graphics window
    delay(5000);
    closegraph();

    return 0;
}
