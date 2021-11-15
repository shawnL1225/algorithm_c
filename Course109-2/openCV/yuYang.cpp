#include<bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
Mat img;
int g[10][10];
int lim;
int level,end_total;
struct POS{
    int x,y;
}player;
int k,step; // k: waitkey , step : record the sum of using step
void setmap(int level){
    if(level==1){
        int tmp[8][8]={
        {0,0,1,1,1,0,0,0},
        {0,0,1,2,1,0,0,0},
        {0,0,1,0,1,1,1,1},
        {1,1,1,3,0,3,2,1},
        {1,2,0,3,4,1,1,1},
        {1,1,1,1,3,1,0,0},
        {0,0,0,1,2,1,0,0},
        {0,0,0,1,1,1,0,0}
        };
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++)
                g[i][j]=tmp[i][j];
        }
        player.x=4;player.y=4;
        end_total=4;
        lim=11;
    }
    if(level==2){
        int tmp[8][8]={
        {1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,2,1},
        {1,0,0,1,1,1,0,1},
        {1,0,3,1,1,0,0,1},
        {1,0,4,3,0,0,0,1},
        {1,1,0,1,0,0,3,1},
        {1,0,0,2,0,0,0,1},
        {1,1,1,1,1,1,1,1}
        };
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++)
                g[i][j]=tmp[i][j];
        }
        player.x=4;player.y=2;
        end_total=2;
        lim=20;
    }
    if(level==4){
        int tmp[8][8]={
        {1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,1},
        {1,0,2,0,1,1,1,1},
        {1,5,0,3,0,3,2,1},
        {1,0,0,3,0,0,4,1},
        {1,1,0,1,0,0,3,1},
        {1,0,0,1,2,0,0,1},
        {1,1,1,1,1,1,1,1}
        };
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++)
                g[i][j]=tmp[i][j];
        }
        player.x=4;player.y=6;
        end_total=3;
        lim=31;
    }
    // 0: air , 1:wall , 2:end, 3:box , 4:player
    if(level==3){
        int tmp[8][8]={
        {1,1,1,1,1,1,1,1},
        {1,0,0,0,5,4,1,1},
        {1,2,0,0,0,3,0,1},
        {1,0,5,0,0,1,0,1},
        {1,0,0,2,5,0,0,1},
        {1,0,0,1,0,3,0,1},
        {1,0,3,0,0,0,2,1},
        {1,0,5,0,1,1,1,1}
        };
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++)
                g[i][j]=tmp[i][j];
        }
        player.x=1;player.y=5;
        end_total=3;
        lim=37;
    }
}
int main(){
    int y=1;
    ag:;
    cout<<"==========================="<<endl;
    cout<<"=                         ="<<endl;
    cout<<"=     push push game      ="<<endl;
    cout<<"=                         ="<<endl;
    cout<<"=     made by YeiYuYang   ="<<endl;
    cout<<"=                         ="<<endl;
    cout<<"==========================="<<endl;

    cout<<"======================"<<endl;
    cout<<"=                    ="<<endl;
    cout<<"=  level 1.  easy    ="<<endl;
    cout<<"=  level 2.  normal  ="<<endl;
    cout<<"=  level 3.  hard    ="<<endl;
    cout<<"=  level 4.  extra   ="<<endl;
    cout<<"=                    ="<<endl;
    cout<<"======================"<<endl;

    cout<<"choose level : ";
    cin>>level;
    om:;
    step=0;
    setmap(level);

    system("cls");
    //cout<<"======Game Start======"<<endl;
    // 0: air , 1:wall , 2:end, 3:box , 4:player
    int h=end_total;
    while(1){
        cout<<"======================"<<endl;
        cout<<"=                    ="<<endl;
        cout<<"=     push push      ="<<endl;
        cout<<"=                    ="<<endl;
        cout<<"=     made by ...    ="<<endl;
        cout<<"=                    ="<<endl;
        cout<<"=     level "<<level<<"        ="<<endl;
        cout<<"=                    ="<<endl;
        cout<<"======================"<<endl;
        cout<<"======================"<<endl;
        cout<<"                                      "<<endl;
        cout<<"  Remaining steps:"<<lim-step<<endl;
        cout<<"  Finish:"<<h-end_total<<"/"<<h<<endl;
        cout<<"  Using steps:"<<step<<endl;
        cout<<"                                      "<<endl;
        cout<<"======================"<<endl;
        img=Mat(800,800, CV_8UC3, Scalar(255,255,255));
        for(int i=0;i<=700;i+=100){
            for(int j=0;j<=700;j+=100){
                rectangle(img, Point(i,j), Point(i+100,j+100), Scalar(0,0,0), 1);
            }
        }

        for(int i=0;i<=700;i+=100){
            for(int j=0;j<=700;j+=100){
                //wall
                if(g[j/100][i/100]==1)
                    rectangle(img, Point(i,j), Point(i+100,j+100), Scalar(0,0,0), -1);
                //end
                else if(g[j/100][i/100]==2){
                    circle(img,Point(i+50,j+50),40,Scalar(218,112,214),3);
                }
                //box
                else if(g[j/100][i/100]==3){
                    circle(img,Point(i+50,j+50),40,Scalar(218,112,214),-1);
                }
                //player
                else if(g[j/100][i/100]==4){
                    circle(img,Point(i+50,j+50),30,Scalar(255,215,0),-1);
                }
                else if(g[j/100][i/100]==5){
                    rectangle(img, Point(i,j), Point(i+100,j+100), Scalar(0,215,255), -1);
                }
            }
        }
        imshow("Window",img);
        if(!end_total) break;
        int k=waitKey(0);
        // 0: air , 1:wall , 2:end, 3:box , 4:player
        switch(k){
        case 'a':
            switch(g[player.x][player.y-1]){
            case 1 : break;
            case 0 : g[player.x][player.y]=0,g[player.x][player.y-1]=4,player.y--,step++;break;
            case 2 : break;
            case 3 :
                switch(g[player.x][player.y-2]){
                case 0 : g[player.x][player.y-2]=3, g[player.x][player.y-1]=4,g[player.x][player.y]=0,player.y--,step++;break;
                case 2 : g[player.x][player.y-2]=3, g[player.x][player.y-1]=4,g[player.x][player.y]=0,player.y--,end_total--,step++;break;
                default:
                    break;
                }
            break;
            case 5:
                switch(g[player.x][player.y-2]){
                case 0 : g[player.x][player.y-2]=1, g[player.x][player.y-1]=4,g[player.x][player.y]=0,player.y--,step++;break;
                //case 2 : g[player.x][player.y-2]=1, g[player.x][player.y-1]=4,g[player.x][player.y]=0,player.y--,end_total--,step++;break;
                default:
                    break;
                }
            break;
            default:
                break;
            }
        break;

        case 'w':
            switch(g[player.x-1][player.y]){
            case 1 : break;
            case 0 : g[player.x][player.y]=0,g[player.x-1][player.y]=4,player.x--,step++;break;
            case 2 : break;
            case 3 :
                switch(g[player.x-2][player.y]){
                case 0 : g[player.x-2][player.y]=3, g[player.x-1][player.y]=4,g[player.x][player.y]=0,player.x--,step++;break;
                case 2 : g[player.x-2][player.y]=3, g[player.x-1][player.y]=4,g[player.x][player.y]=0,player.x--,end_total--,step++;break;
                default:
                    break;
                }
            break;
            case 5 :
                switch(g[player.x-2][player.y]){
                case 0 : g[player.x-2][player.y]=1, g[player.x-1][player.y]=4,g[player.x][player.y]=0,player.x--,step++;break;
                //case 2 : g[player.x-2][player.y]=1, g[player.x-1][player.y]=4,g[player.x][player.y]=0,player.x--,end_total--,step++;break;
                default:
                    break;
                }
            break;
            default:
                break;
            }
        break;

        case 's':
            switch(g[player.x+1][player.y]){
            case 1 : break;
            case 0 : g[player.x][player.y]=0,g[player.x+1][player.y]=4,player.x++,step++;break;
            case 2 : break;
            case 3 :
                switch(g[player.x+2][player.y]){
                case 0 : g[player.x+2][player.y]=3, g[player.x+1][player.y]=4,g[player.x][player.y]=0,player.x++,step++;break;
                case 2 : g[player.x+2][player.y]=3, g[player.x+1][player.y]=4,g[player.x][player.y]=0,player.x++,end_total--,step++;break;
                default:
                    break;
                }
            break;
            case 5 :
                switch(g[player.x+2][player.y]){
                case 0 : g[player.x+2][player.y]=1, g[player.x+1][player.y]=4,g[player.x][player.y]=0,player.x++,step++;break;
                //case 2 : g[player.x+2][player.y]=1, g[player.x+1][player.y]=4,g[player.x][player.y]=0,player.x++,end_total--,step++;break;
                default:
                    break;
                }
            break;
            default:
                break;
            }
        break;

        case 'd':
            switch(g[player.x][player.y+1]){
            case 1 : break;
            case 0 : g[player.x][player.y]=0,g[player.x][player.y+1]=4,player.y++,step++;break;
            case 2 : break;
            case 3 :
                switch(g[player.x][player.y+2]){
                case 0 : g[player.x][player.y+2]=3, g[player.x][player.y+1]=4,g[player.x][player.y]=0,player.y++,step++; break;
                case 2 : g[player.x][player.y+2]=3, g[player.x][player.y+1]=4,g[player.x][player.y]=0,player.y++,end_total--,step++; break;
                default:
                    break;
                }
            break;
            case 5:
                switch(g[player.x][player.y+2]){
                case 0 : g[player.x][player.y+2]=1, g[player.x][player.y+1]=4,g[player.x][player.y]=0,player.y++,step++; break;
                //case 2 : g[player.x][player.y+2]=1, g[player.x][player.y+1]=4,g[player.x][player.y]=0,player.y++,end_total--,step++; break;
                default:
                    break;
                }
            break;
            default:
                break;
            }
        break;

        case 'p':goto om;
        default:
            break;
        }// end of switch
        if(step>lim) break;
        system("cls");

    }// end of while(1)


    if(step>lim){
        rectangle(img, Point(100,300), Point(700,600), Scalar(255,255,255), -1);
        putText(img, string("Game over"), Point(250,450), 0, 2, Scalar(0,0,0),5);
        imshow("Window",img);
        waitKey(0);
        cout<<"=============ggwp ============="<<endl;
        cout<<"= Using too many steps loser  ="<<endl;
        cout<<"=     Play again : press 1    ="<<endl;
        cout<<"=       Leave    : press 0    ="<<endl;
        cout<<"==============================="<<endl;
    }
    else{
        rectangle(img, Point(100,300), Point(700,600), Scalar(255,255,255), -1);
        putText(img, string("You win!"), Point(250,450), 0, 2, Scalar(0,0,0),5);
        imshow("Window",img);
        waitKey(0);
        cout<<"=======RESULT OF THE GAME======"<<endl;
        cout<<"=    Using step  :  "<<step<<"        ="<<endl;
        cout<<"=     Play again : press 1    ="<<endl;
        cout<<"=     Leave      : press 0    ="<<endl;
        cout<<"==============================="<<endl;
    }

    int p;
    cin>>p;
    if(p){
        destroyAllWindows();
        system("cls");
        y++;
        goto ag;
    }
    return 0;
}

