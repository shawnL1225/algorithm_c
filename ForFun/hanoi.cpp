//只能往右移的hanoi
#include <bits/stdc++.h>
using namespace std;
int big=0, mid=0, small=0;
int disc[4] = {0};
void moveSmall(int dest){
    while(small != dest){
        int next = (small+1)%3;
        printf("small : %d -> %d\n", small, next);
        small = next;
    }   
}
void moveMid(int dest){
    while(mid!=dest){
        int next = (mid+1)%3;
        moveSmall((next+1)%3);
        printf("mid : %d -> %d\n", mid, next);
        mid = next;
    }
}
void moveBig(int dest){
    while(big != dest){
        int next = (big+1)%3;
        moveMid((next+1)%3);
        moveSmall((next+1)%3);
        printf("big : %d -> %d\n", big, next);
        big = next;
    }
}

// general
void move(int n, int dest){
    if(n>0){
        while(disc[n] - dest){
            int next = (disc[n]+1)%3;
            move(n-1,(next+1)%3);
            // move(n-2,(next+1)%3); //只有三個時 把上兩個移到buffer
            printf("%d : %d -> %d\n",n,disc[n],next);
            disc[n] = next;
            move(n-1,next); //上層再搬回來
        }
    }
}

int main(){
    // moveBig(2);
    // moveMid(2);
    // moveSmall(2);
    move(3,2);
    printf("%d %d %d\n",disc[1],disc[2],disc[3]);
    // printf("%d %d %d\n",small,mid,big);
}

