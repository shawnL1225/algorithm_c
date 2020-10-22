/*  probID: 7-1-MinPos  */

int MinPos( int A[], int left, int right ){
    int minP = left,minv = A[left];
    for(int i=left+1;i<=right;i++){
        if(A[i]<minv){
            minP = i;
            minv = A[i];
        }
    }

    return minP;
};