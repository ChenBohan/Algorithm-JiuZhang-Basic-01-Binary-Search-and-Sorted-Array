class Solution
{
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n)
    {
        int pos = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while (pos >= 0)
        {
            if (i < 0)
            {
                A[pos--] = B[j--];
            }
            if (j < 0)
            {
                A[pos--] = A[i--];
            }
            if (A[i] >= B[j])
            {
                A[pos--] = A[i--];
            }
            else
            {
                A[pos--] = B[j--];
            }
        }
    }
};
