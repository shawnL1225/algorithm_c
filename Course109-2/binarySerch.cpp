/*  probID: W5-2-BinarySearch  */
// #include <stdio.h>

// int BinarySearch(int[],int,int);

// int A[100000], n;

// int main()
// {
//     int k, i, m;

//     scanf("%d", &n);
//     for(i=0; i<n; i++)
//         scanf("%d", &A[i]);
        
//     scanf("%d", &m);
//     while(m--)
//     {
//         scanf("%d", &k);
        
//         i = BinarySearch(A, n, k);
//         printf("%d ", i);
//         if( i >= 0 && i<n && A[i]==k )
//             printf("Found!\n");
//         else
//             printf("not found\n");
//     }
    
//     return 0;
// }

int BinarySearch(int A[],int n,int k){
    int left = -1, right = n;
    while(left < right - 1){
        int mid = (left + right)/2;
        if(A[mid] >= k)
            right = mid;
        else
            left = mid;
    }
    return right;
}