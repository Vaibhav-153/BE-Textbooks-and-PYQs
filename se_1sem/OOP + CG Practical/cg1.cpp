#include <graphics.h>
#include <iostream>
using namespace std;

void floodFill(int x, int y, int oldColor, int newColor) {
    int current = getpixel(x, y);
    if (current == oldColor) {
        delay(1);
        putpixel(x, y, newColor);
        floodFill(x + 1, y, oldColor, newColor);
        floodFill(x - 1, y, oldColor, newColor);
        floodFill(x, y + 1, oldColor, newColor);
        floodFill(x, y - 1, oldColor, newColor);
    }
}

int main() {
    int x1, y1, x2, y2, x3, y3, xAvg, yAvg;
    int gdriver = DETECT, gmode;

    initgraph(&gdriver, &gmode, NULL);

    cout << "\nEnter the points of the triangle: ";
    setcolor(1);
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    xAvg = (x1 + x2 + x3) / 3;
    yAvg = (y1 + y2 + y3) / 3;

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    floodFill(xAvg, yAvg, 0, 3);

    getch();
    closegraph();
    return 0;
}
