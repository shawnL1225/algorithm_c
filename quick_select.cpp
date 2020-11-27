/* probID: MT2A-5-Quick-Select */
// #include <bits/stdc++.h>
// using namespace std;
int L[10000000], R[10000000], S[10000000];
int Partition_by_key(int A[], int left, int right, int key)
{
    int l = 0, r = 0, s = 0;
    for (int i = left; i <= right; i++)
    {
        if (A[i] < A[key])
        {
            L[l] = A[i];
            l++;
        }
        else if (A[i] > A[key])
        {
            R[r] = A[i];
            r++;
        }
        else
        {
            S[s] = A[i];
            s++;
        }
    }
    int i = left;
    for (int ml = 0; ml < l; i++, ml++)
    {
        A[i] = L[ml];
    }
    int new_k = i;
    for (int ms = 0; ms < s; i++, ms++)
    {
        A[i] = S[ms];
    }
    for (int mr = 0; mr < r; i++, mr++)
    {
        A[i] = R[mr];
    }

    return new_k;
}

int quick_select(int A[], int left, int right, int k)
{
    if (left == right)
        return A[left];

    int index = (left + right) / 2;

    int key = Partition_by_key(A, left, right, index);

    if (right - key + 1 > k)
        return quick_select(A, key + 1, right, k);
    else if (right - key + 1 < k)
        return quick_select(A, left, key - 1, k - (right - key + 1));
    else
        return A[key];
}
// #include <stdio.h>
// int A[10000000];
// int quick_select(int[], int, int, int);
// int main()
// {
//     int n, k, value;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &A[i]);
//     scanf("%d", &k);
//     value = quick_select(A, 0, n - 1, k);
//     printf("%d", value);
//     return 0;
// }
