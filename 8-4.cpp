/*  probID: 8-4-Two-Pointer-Method  */
void merge(int a, int b, int A[], int B[], int merged[])
{
    int a_start = 0, b_start = 0;
    int i = 0;

    for (; i < a + b; i++)
    {
        if (a_start == a || b_start == b)
            break;

        if (A[a_start] < B[b_start])
        {
            merged[i] = A[a_start];
            a_start++;
        }
        else
        {
            merged[i] = B[b_start];
            b_start++;
        }
    }
    if (a_start == a)
    {
        for (; i < a + b; i++, b_start++)
        {
            merged[i] = B[b_start];
        }
    }
    else
    {
        for (; i < a + b; i++, a_start++)
        {
            merged[i] = A[a_start];
        }
    }
};