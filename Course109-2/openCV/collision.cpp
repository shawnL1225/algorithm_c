#include <cstdio>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

int ballNum;
double width, height;

struct Ball
{
    double r;
    double m;
    double vx, vy;
    double px, py;
} ball[100];

void draw(){
    Mat back(height, width, CV_8UC3, Scalar(255,255,255));
    for(int i=0; i<ballNum; i++){
        circle(back, Point(ball[i].px, ball[i].py), ball[i].r, Scalar(0,255,0), -1);
    }
    
    imshow("img", back);
    
}
void move(){
    int vWei = 5;
    for(int i=0; i<ballNum; i++){
        ball[i].px += ball[i].vx*vWei;
        ball[i].py += ball[i].vy*vWei;
    }
}
void newVelocity(int i, int j){
    Ball a = ball[i], b = ball[j];

}
void collid(){
    for(int i=0;i<ballNum;i++){
        for(int j=i+1;j<ballNum;j++){
            Ball a = ball[i], b = ball[j];
            double dis = (a.px-b.px)*(a.px-b.px) + (a.py-b.py)*(a.py-b.py);
            double r = (a.r + b.r)*(a.r + b.r);
            
            if(dis < r){
                cout << "collid" << endl;
                cout << "dis: " << dis << "r: "<< r <<endl;
                newVelocity(i, j);
            }
        }
    }
}


int main(){
    int resizeW = 100;
    
    cin >> ballNum >> width >> height;

    for(int i=0; i<ballNum; i++){
        cin >> ball[i].r >> ball[i].m >> ball[i].vx >> ball[i].vy >> ball[i].px >> ball[i].py;
        ball[i].r*=resizeW;  ball[i].px*=resizeW; ball[i].py*=resizeW;
        
        if(ball[i].py==0) ball[i].py = 40; //easy case
    }
    width*=resizeW; height*=resizeW; 
    if(height == 0) height = 80; //easy case

    while(1){
        draw();
        waitKey(100);
        move();
        collid();

        
    }

   
    return 0;
}
