/*  probID: 12-1-MergeSort  */

void MergeSortedArrays( int A[],int a, int B[], int b, int temp[] ){
    int a_start=0,b_start=0;
    int i=0;

    for(;i<a+b;i++){
        if(a_start == a || b_start == b) break;

        if(A[a_start] < B[b_start]){
             temp[i] = A[a_start];
             a_start++;
        }  
        else{
            temp[i] = B[b_start];
            b_start++;
        }    
    }
    if(a_start == a){
        for(;i<a+b;i++,b_start++){
            temp[i] = B[b_start];
        }
    }
    else{
        for(;i<a+b;i++,a_start++){
            temp[i] = A[a_start];
        }
    }
};

int recursive_merge_sort( int A[], int left, int right, int temp[] )
{
    
    if(left >= right) return 0;
    int mid = (left+right)/2;
    recursive_merge_sort( A, left, mid, temp );
    recursive_merge_sort( A, mid+1, right, temp );
    MergeSortedArrays( A+left, mid-left+1, 
                        A+mid+1, right-mid, temp );


    for(int i = left,j=0;i<=right;i++,j++){
        A[i] = temp[j];
    }
    return 0;
}

void merge_sort(int A[], int n )
{
    int temp[n];
    recursive_merge_sort( A, 0, n-1, temp );
}

