#include <bits/stdc++.h>
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
    Mat back(height, width, CV_8UC3, Scalar(214, 221, 226));
    for(int i=0; i<ballNum; i++){
        circle(back, Point(ball[i].px, ball[i].py), ball[i].r, Scalar(212, 162, 125), -1);
        char s[2]; itoa(i, s, 10);
        putText(back, s, Point(ball[i].px-10, ball[i].py+10), 0, 1, Scalar(100, 204, 245),3);
    }
    
    imshow("img", back);
    
}
void move(){
    int vWei = 1;
    for(int i=0; i<ballNum; i++){
        ball[i].px += ball[i].vx*vWei;
        ball[i].py += ball[i].vy*vWei;

        if(ball[i].px - ball[i].r <= 0  || ball[i].px + ball[i].r >= width){
            ball[i].vx = -ball[i].vx;
            ball[i].px = (ball[i].px - ball[i].r <= 0)? ball[i].r : width - ball[i].r;
        }
        if(ball[i].py - ball[i].r <= 0  || ball[i].py + ball[i].r >= height){
            ball[i].vy = -ball[i].vy;
            ball[i].py = (ball[i].py - ball[i].r <= 0)? ball[i].r : height - ball[i].r;
        }
    }
    
}
void newVelocity(int i, int j){
    Ball a = ball[i], b = ball[j];
    ball[i].vx = ((a.m-b.m)*a.vx + 2*b.m*b.vx )/(a.m+b.m);
    ball[j].vx = ((b.m-a.m)*b.vx + 2*a.m*a.vx )/(a.m+b.m);
    ball[i].vy = ((a.m-b.m)*a.vy + 2*b.m*b.vy )/(a.m+b.m);
    ball[j].vy = ((b.m-a.m)*b.vy + 2*a.m*a.vy )/(a.m+b.m);

    // ball[i].px += 50*ball[i].vx; ball[i].py += 50*ball[i].vy;
    // ball[j].px += 50*ball[i].vx; ball[j].py += 50*ball[i].vy;
}
void collid(){
    for(int i=0;i<ballNum;i++){
        for(int j=i+1;j<ballNum;j++){
            Ball a = ball[i], b = ball[j];
            double dis = (a.px-b.px)*(a.px-b.px) + (a.py-b.py)*(a.py-b.py);
            double r = (a.r + b.r)*(a.r + b.r);
            
            if(dis < r){
                cout << "collid: " << i << ", " << j << endl;
                cout << "dis: " << dis << "r: "<< r <<endl;
                newVelocity(i, j);
            }
        }
    }
}


int main(){
    int resizeW = 200;
    
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
        waitKey(1);
        move();
        collid();
    }

   
    return 0;
}
