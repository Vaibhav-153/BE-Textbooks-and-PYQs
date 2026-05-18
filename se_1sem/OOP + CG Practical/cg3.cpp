#include<graphics.h>
#include<iostream>
using namespace std;
class pt
{
  protected:
        int xco, yco, color;

  public:
        pt() //base class default constructor
        {
               xco = 0;
               yco = 0;
               color = 15;
        }
        void setco(int x, int y)
        {
               xco = x;
               yco = y;
        }
        void setcolor(int c)
        {
               color = c;
        }
        void draw()
        {
                 putpixel(xco, yco, color);
        }
};
class dcircle : public pt
{
  private:
        int r;

  public:
        dcircle() : pt() //child class default constructor
        {
                r = 10;
        }
        void setCircle(int x, int y, int rad, int color)
        {
                 pt::setco(x, y);
                 pt::setcolor(color);
                 r = rad;
        }
        void drawCir(int rad)
        {
                 int q;
                 int x1, y1;
                 x1 = 0; //initialising the x,y cordinates.
                 y1 = rad;
                 q = 3 - (rad * 2);
                 while (x1 <= y1)
                 {
                         if (q <= 0)
                                 q = q + (4 * x1) + 6;
                         else
                         {
                                 q += 4 * (x1 - y1) + 10;
                                 y1--;
                          }
                          x1++;
                          display(x1, y1, xco, yco);
                  }
         }
         void display(int x1, int y1, int x, int y)
         {
                 //plotting the pixels.
                 putpixel(x1 + x, y1 + y, color);
                 putpixel(x1 + x, y - y1, color);
                 putpixel(x - x1, y1 + y, color);
                 putpixel(x - x1, y - y1, color);
                 putpixel(x + y1, y + x1, color);
                 putpixel(x + y1, y - x1, color);
                 putpixel(x - y1, y + x1, color);
                 putpixel(x - y1, y - x1, color);
         }
 
};
int main()
{
          int gd = DETECT, gm, left = 100, top = 100,right = 200,bottom = 200, x = 300, y = 150, radius = 50, color;
          int ch, x1, y1;
          char a;
          cout << "1.Bresenhams circle";
          cout << "\n 2.Exit.";
          cout << "Enter your choice:";
          cin >> ch;
          cout << "\n Enter x1:";
                          cin >> x1;
                          cout << "\n Enter y1:";
                          cin >> y1;
                          cout << "\n Enter radius:";
                          cin >> radius;
                          cout << "\n Enter color:";
                          cin >> color;
           initgraph(&gd, &gm, NULL);
           dcircle cir;
      
           do
           { 
                  switch (ch)
                  {
                   case 1:
                      
                             cir.setCircle(x1, y1, radius, color);
                             cir.drawCir(radius);
                             break;
 
case 2:
                             break;
                   }
                   cout << "\n DO YOU WANT TO CONTINUE y OR n:";
                   cin >> a;
                   cout << a;
           } while (a == 'y');
           delay(3000);
           getch();
           closegraph();
           return 0;
}
                                                                                                                   
                 


