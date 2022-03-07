#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int mode, n, m;
long long myPow(int a, int b){
    long long sum = 1;
    for(int powT=0; powT<b; powT++){
        sum *= a;
    }
    return sum;
}
void mode0(){
    char data[1000];
    int chuncks[1000];

    scanf("%d%d%s", &n, &m, &data);
    //set chunck length
    int chunckLength = strlen(data)/n;

    //split data into chuncks
    for(int numChunks=0; numChunks<n; numChunks++){
        char chunck[chunckLength];
        strncpy(chunck, &data[numChunks*chunckLength], chunckLength);
        chuncks[numChunks] = atoi(chunck);
    }
    //print the first n equations
    for(int numEquations=0; numEquations<n; numEquations++){
        for(int j=0;j<n;j++){
            if(numEquations == j) printf("1 ");
            else printf("0 ");
        }
        printf("%d\n", chuncks[numEquations]);
    }
    //print the remaining m equations
    for(int numEquations=1; numEquations<=m; numEquations++){
        int equationSum = 0;
        for(int ctPower=0; ctPower<n; ctPower++){
            equationSum += chuncks[ctPower] * myPow(numEquations, ctPower);
            printf("%d ", (int)myPow(numEquations, ctPower));
        }
        printf("%d\n", equationSum);

    }

}
void swap(double** a, double** b){
    double *temp = *a;
    *a = *b;
    *b = temp;
}


void mode1(){
    
    scanf("%d", &n);

    //input n of equations
    double** equation = (double **) malloc(sizeof (double *)*n);
    for(int i=0; i<n ;i++){
        equation[i]=(double *) malloc(sizeof(double)*(n+1));
        for(int j=0;j<n+1;j++){
            scanf("%lf", &equation[i][j]);
        }
    }
    //guassian elimination
    for(int leadCol=0; leadCol<n; leadCol++){
        //skip if the row of leaing is 0
        int choose = leadCol;
        while(choose < n && !equation[choose][leadCol]) choose++;

        //interchange 
        if(choose != leadCol) swap(equation+choose, equation+leadCol);

        //divid row to make leading to one
        for(int wholeRow=n; wholeRow>0; wholeRow--){
            equation[leadCol][wholeRow] /= equation[leadCol][leadCol];
        }
  
        //subtract the other row
        for(int subtractRow=0; subtractRow<n; subtractRow++){
            if(subtractRow != leadCol){
                double times = equation[subtractRow][leadCol]/equation[leadCol][leadCol];
                for(int wholeRow=0; wholeRow<n+1; wholeRow++)
                    equation[subtractRow][wholeRow] -= equation[leadCol][wholeRow]*times;
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n+1;j++){
        //         printf("%f ", equation[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");

        

    }
    for(int chunck=0;chunck<n;chunck++){
        printf("%.0f", equation[chunck][n]);
    }
}

int main(){
    
    // input mode
    scanf("%d", &mode);
    if(!mode) mode0();
    else mode1();

    return 0;
}