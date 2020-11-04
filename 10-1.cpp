/*  probID: 10-1-Partition  */


int L[200000],R[200000],S[200000];
int Partition_by_key(int A[], int l, int r,int k){
    
    
    int ln=0,rn=0,sn=0;
    
    for(int i=l;i<=r;i++){
        if(A[i] < A[k])
            {L[ln] = A[i]; ln++;}
        else if(A[i] > A[k])
            {R[rn] = A[i]; rn++;}
        else 
            {S[sn] = A[i]; sn++;}
    }

    int i = l;
    for(int j=0;j<ln;j++,i++)
        A[i] = L[j];
    int new_k = i;
    for(int j=0;j<sn;j++,i++)
        A[i] = S[j];
    for(int j=0;j<rn;j++,i++)
        A[i] = R[j];
    return new_k;
    
}