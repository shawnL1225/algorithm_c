#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

#define color1 Scalar(143, 157, 42)
#define color2 Scalar(61, 91, 247)

int board[3][3];
Mat bg(800, 600, CV_8UC3, Scalar(214, 221, 226));
int turn = 1; //1->O 2->X
bool win = 0;

bool same(int a, int b, int c){
    return a==b && b==c;
}

void draw(int c, int r){
    // put status
    if(turn == 1){
        circle(bg, Point(c*200+100, r*200+100), 90, color1, 5);
    }else{
        line(bg, Point(c*200+180,r*200+20), Point(c*200+20,r*200+180), color2, 2);
        line(bg, Point(c*200+20,r*200+20), Point(c*200+180,r*200+180), color2, 2);
    }

    // if win
    if(turn == 1){
        if(same(board[0][c] , board[1][c] , board[2][c]) ){
            line(bg, Point(c*200+100,20), Point(c*200+100,580), color1, 5);win=1;
        }
        if(same(board[r][0] , board[r][1] , board[r][2])){
            line(bg, Point(20,r*200+100), Point(580,r*200+100), color1, 5);win=1;
        }
        if(same(board[0][0] , board[1][1] , board[2][2]) && board[1][1]!=0){
            line(bg, Point(20,20), Point(580,580), color1, 5);win=1;
        }
        if(same(board[0][2] , board[1][1] , board[2][0]) && board[1][1]!=0){
            line(bg, Point(580,20), Point(20,580), color1, 5);win=1;
        }
        if(win) putText(bg, string("Circle Win! Press to Restart"), Point(80,700), 0, 1, color1,3);
    }
    else if(turn == 2){
        if(same(board[0][c] , board[1][c] , board[2][c])){
            line(bg, Point(c*200+100,20), Point(c*200+100,580), color2, 5);win=1;
        }
        if(same(board[r][0] , board[r][1] , board[r][2])){
            line(bg, Point(20,r*200+100), Point(580,r*200+100), color2, 5);win=1;
        }
        if(same(board[0][0] , board[1][1] , board[2][2]) && board[1][1]!=0){
            line(bg, Point(20,20), Point(580,580), color2, 5);win=1;
        }
        if(same(board[0][2] , board[1][1] , board[2][0]) && board[1][1]!=0){
            line(bg, Point(580,20), Point(20,580), color2, 5);win=1;
        }
        if(win) putText(bg, string("Cross Win! Press to Restart"), Point(100,700), 0, 1, color2,3);
    }
    int sum = 0;
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << board[i][j];
            sum += board[i][j];
        }
        cout << endl;
    }
    cout << endl;

    if(sum == 13 && !win) putText(bg, string("Tie! Press to Restart"), Point(130,700), 0, 1, Scalar(212, 162, 125),3);
    imshow("ooxx", bg);

   
    
}

void On_mouse(int event, int x, int y, int flags, void*)
{
	
	if (event == EVENT_LBUTTONDOWN)
	{
        if(win) return;

		int col = x/200, row = y/200;
        if(board[row][col] == 0){
            board[row][col] = turn;
            draw(col, row);
            turn = turn%2 +1;
        }
        
	}
}
int main(){
    while(1){
        bg = Mat(800, 600, CV_8UC3, Scalar(214, 221, 226));
        memset(board, 0, sizeof(board));
        turn = 1; //1->O 2->X
        win  = 0;

        line(bg, Point(0,200), Point(600,200),Scalar(212, 162, 125), 2);
        line(bg, Point(0,400), Point(600,400),Scalar(212, 162, 125), 2);
        line(bg, Point(200,0), Point(200,600),Scalar(212, 162, 125), 2);
        line(bg, Point(400,0), Point(400,600),Scalar(212, 162, 125), 2);
        imshow("ooxx", bg);
        setMouseCallback("ooxx", On_mouse, 0);

        waitKey(0);