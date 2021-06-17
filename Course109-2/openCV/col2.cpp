#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

typedef long long lint;

int k;
double Dx,Dy;
struct ball {
    double r;
    double M;
    double Vx;
    double Vy;
    double Px;
    double Py;
};
ball temp;
vector <ball> balls;

void draw_img() {
    Mat img(Dy , Dx , CV_8UC3 , Scalar(255,255,255));
    for(int i = 0 ; i < k ; i++) {
        circle(img , Point(balls[i].Px , balls[i].Py) , balls[i].r , Scalar(255,0,0)  , -1);
        //cout << "index: " << i << " (" << balls[i].Px << "," << balls[i].Py << ")";
    }
    imshow("window",img);
}

void move() {
    for(int i = 0 ; i < k ; i++) {
        balls[i].Px += balls[i].Vx;
        balls[i].Py += balls[i].Vy;
        if(balls[i].Px - balls[i].r <= 0 || balls[i].Px + balls[i].r >= Dx) {
            balls[i].Vx *= -1;
            if(balls[i].Px - balls[i].r <= 0) balls[i].Px = balls[i].r;
            else if(balls[i].Px + balls[i].r >= Dx) balls[i].Px = Dx - balls[i].r;
        }
        if(balls[i].Py - balls[i].r <= 0 || balls[i].Py + balls[i].r >= Dy) {
            balls[i].Vy *= -1;
            if(balls[i].Py - balls[i].r <= 0) balls[i].Py = balls[i].r;
            else if(balls[i].Py + balls[i].r >= Dy) balls[i].Py = Dy - balls[i].r;
        }
    }
}

void formula(int i,int j) {
    ball a = balls[i] , b = balls[j];
    balls[i].Vx = ((a.M - b.M) * a.Vx + 2 * b.M * b.Vx) / (a.M + b.M);
    balls[j].Vx = ((b.M - a.M) * b.Vx + 2 * a.M * a.Vx) / (a.M + b.M);
    balls[i].Vy = ((a.M - b.M) * a.Vy + 2 * b.M * b.Vy) / (a.M + b.M);
    balls[j].Vy = ((b.M - a.M) * b.Vy + 2 * a.M * a.Vy) / (a.M + b.M);
}

void touch () {
    for(int i = 0 ; i < k ; i++) {
        for(int j = i + 1 ; j < k ; j++) {
            double d = (balls[i].Px - balls[j].Px) * (balls[i].Px - balls[j].Px) + (balls[i].Py - balls[j].Py) * (balls[i].Py - balls[j].Py);
            if(d - (balls[i].r + balls[j].r) * (balls[i].r + balls[j].r) < 20) {
                formula(i,j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    cin >> Dx >> Dy;
    if(Dy == 0) Dy = 1.6;
    Dx *= 200;
    Dy *= 200;
    for(int i = 0 ; i < k ; i++) {
        cin >> temp.r >> temp.M >> temp.Vx >> temp.Vy >> temp.Px >> temp.Py;
        temp.r *= 200;
        temp.Px *= 200;
        (temp.Py += 0.8) *=200;
        temp.Vx *= 2;
        temp.Vy *= 2;
        balls.push_back(temp);
    }
    while(1) {
        draw_img();
        waitKey(1);
        move();
        touch();
    }
    return 0;
}