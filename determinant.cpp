#include <bits/stdc++.h>
using namespace std;
int n;
double A[9][9], determinant(int, double[9][9]);

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%lf",&A[i][j]);
    printf("%f\n",determinant(n,A));

    return 0;
}

double determinant(int n,double A[9][9])
{
    if(n==1) return A[0][0];

    
    double sum=0;
    for(int j=0;j<n;j++)
    {
        double B[9][9];
        int plusone = 0;
        for(int i=0;i<n;i++)
        {   
            if(i==j) plusone = 1;
            for(int k=1;k<n;k++)
            {
                B[i][k-1] = A[i+plusone][k];
            }
        }
        // for(int i=0;i<n-1;i++){
        //     for(int k=0;k<n-1;k++)
        //         cout << B[i][k]<< ' ';
        //     cout <<endl;
        // }
            
        sum+= pow(-1,j+1) *A[j][0] *determinant(n-1,B);
    }
    return sum;
}