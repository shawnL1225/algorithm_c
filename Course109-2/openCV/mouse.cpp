#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

#define WINDOW "test"
Point previousPoint;
bool P = false;
Mat img(400, 400, CV_8UC3, Scalar(255,255,255));
Mat nextimg ;
void On_mouse(int event, int x, int y, int flags, void*);
int max255 = 255;
int a,b,c;
int main()
{
    img.copyTo(nextimg);
 namedWindow(WINDOW);
 imshow(WINDOW, nextimg);
 setMouseCallback(WINDOW, On_mouse, 0);

 waitKey(0);
 return 0;
}
void On_mouse(int event, int x, int y, int flags, void*)
{
    if (event == EVENT_RBUTTONDOWN) //right click to change color
    {
        a = rand() % (max255 + 1) ;
        b = rand() % (max255 + 1) ;
        c = rand() % (max255 + 1) ;
        cout << "change color" << endl;
    }
    if (event == EVENT_LBUTTONDBLCLK) //left double click to reset img
    {
        img.copyTo(nextimg);
        imshow(WINDOW, nextimg);
        cout << "reset img" << endl;
    }
    if (event == EVENT_RBUTTONDBLCLK) //right double click to save img
    {
        nextimg.copyTo(nextimg);
    }
    if (event == EVENT_LBUTTONDOWN)  //left click to save point(x,y)
 {
  previousPoint = Point(x, y);
        cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
 }
    //mouse move and flags is left button then write line
 else if (event == EVENT_MOUSEMOVE && (flags&EVENT_FLAG_LBUTTON))
 {
  Point pt(x, y);
  line(nextimg, previousPoint, pt, Scalar(a,b,c), 2, 5, 0);
        cout << "Right button of the mouse is moved - position (" << x << ", " << y << ")" << endl;
  previousPoint = pt;
  imshow(WINDOW, nextimg);
 }
}