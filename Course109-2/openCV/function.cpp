#include <cstdio>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


#define pi 3.14159
using namespace cv;
 
// int main(){
    
//     int a = 30, b = 30, c = 1;

    

//     while(1){
//         Mat img(500, 500, CV_8UC3, Scalar(255,255,255));
//         for(double t=0; t<=2*pi; t+=0.001){
//             int y = 250 + a*sin(t) ;
//             int x = 250 + b*cos(c*t);
//             circle(img, Point(y,x), 3, Scalar(0,255,0), -1);
//         }

//         Mat dst;
//         resize(img, img, Size(900,900));
        
//         imshow("window", img);
//         int k = waitKey(0);

//         if(k == 61){
//             a+=20;b+=20;
//         }else if(k == 45 && a >= 20){
//             a-=20;b-=20;
//         }
//         printf("%d\n",k);
        
//     }
    
//     return 0;
// }



int main(){
    
    int a = 30, b = 30, c = 3;

    Mat img(500, 500, CV_8UC3, Scalar(255,255,255));
    for(double t=0; t<=2*pi; t+=0.001){
        int y = 250 + a*sin(t) ;
        int x = 250 + b*cos(c*t);
        circle(img, Point(y,x), 3, Scalar(0,255,0), -1);
    }
    imshow("img", img);

    while(1){
        int k = waitKey(0);

        if( k == 61){
            resize(img, img, Size(550,550));
            int offset_x = 275-250;
            int offset_y = 275-250;

            Rect roi;
            roi.x = offset_x;
            roi.y = offset_y;
            roi.width = 500;
            roi.height = 500;
            Mat crop = img(roi);
            imshow("img", crop);
            img = crop;
        }
        else if( k == 45){
            resize(img, img, Size(450,450));
            Mat expan(500, 500, CV_8UC3, Scalar(255,255,255));

            Mat insetImage(expan, Rect(25, 25, 450, 450));
            img.copyTo(insetImage);

            imshow("img", expan);
            img = expan;
        }

        

    }
    
    return 0;
}




