#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int height = 500, width= 490;
struct P
{
    bool exit;
    double x, y;
    double vx, vy;
};
P ball[10];
int ballNum = 5 , ballRest, pad_x=width/2, padw=width;
int r = 5;
int BlockRest[7];
Mat back;

void newBall(int i){
    
    int min = -80;int max = 80;
    
    ball[i].vx = (double)(rand() % (max - min + 1) + min)/100.0;
    ball[i].vy =-0.8;
    ball[i].x = 225;
    ball[i].y = 400;
    ball[i].exit = true;

}
int blockW = 70, blockH = 40;
void draw(){
    Mat back(height, width, CV_8UC3, Scalar(214, 221, 226));
    rectangle(back, Point(pad_x,450), Point(pad_x+padw,460),  Scalar(212, 162, 125), -1);
    for(int i=0;i<ballNum;i++){
        if(!ball[i].exit) continue;
        circle(back, Point(ball[i].x, ball[i].y), r, Scalar(212, 162, 125), -1);
    }


    int xbegin = 0,ybegin = 0, ct=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<7;j++){
            if(i < BlockRest[j]){
                ct++;
                rectangle(back, Point(xbegin,ybegin), Point(xbegin+blockW,ybegin+blockH),  Scalar(3, 61, 252), -1);
                rectangle(back, Point(xbegin,ybegin), Point(xbegin+blockW,ybegin+blockH),  Scalar(20, 0, 0), 1);
            }
            xbegin+=blockW;
        }
        xbegin = 0; ybegin+=blockH;
    }
    if(ct == 0){
        putText(back, string("Congrat !"), Point(200,400), 0, 1, Scalar(212, 162, 125),3);
    }
    if(ballRest <= 0){
        putText(back, string("lose press space to continue !"), Point(140,400), 0, 0.5, Scalar(212, 162, 125),1);
    }
    imshow("img", back);
    
}
void init(){
    for(int i=0; i<ballNum; i++)
        newBall(i);
    for(int i=0;i<7;i++) BlockRest[i] = 4;
    pad_x = 225;
    ballRest = ballNum;
}
void move(){
    for(int i=0;i<ballNum;i++){
        if(!ball[i].exit) continue;

        ball[i].x += ball[i].vx;
        ball[i].y += ball[i].vy;
        if(ball[i].x - r <= 0  || ball[i].x + r >= width){
            ball[i].vx = -ball[i].vx;
        }
        if(ball[i].y - r <= 0 ){
            ball[i].vy = -ball[i].vy;
        }

        if(ball[i].y - r >= height){
            // newBall(i);
            ballRest--;
            ball[i].exit = false;
            
        }
    }
    
    
    int k = waitKey(1);
    if(k == 97) {
        pad_x -=20;
        if(pad_x <=0) pad_x = 0;
    } 
    else if(k == 100){
        pad_x +=20;
        if(pad_x+padw >= width) pad_x = width-padw;
    }
    if(k == ' '){
        init();
        
    }
}

void collide(){
    
    for(int i=0;i<ballNum;i++){
        //pad  
        if(ball[i].y <= 460 && ball[i].y >= 450){
            if(ball[i].x >= pad_x && ball[i].x <= pad_x+padw)
                ball[i].vy = -ball[i].vy;
        } 
        
        if(ball[i].y <= BlockRest[(int)ball[i].x / blockW] * blockH){
            cout << "collide: " <<(int)ball[i].x / blockW << ' ' << BlockRest[(int)ball[i].x / blockW] << endl;
            BlockRest[(int)ball[i].x / blockW]--;

            if(BlockRest[(int)ball[i].x / blockW] * blockH - ball[i].y <10)
                ball[i].vy = -ball[i].vy;
            else
                ball[i].vx = -ball[i].vx;
           
        }
    }
}
int main(){
    
    srand( time(NULL) );
    init();
    while(1){
        draw();
        move();
        collide();
    }
    
}