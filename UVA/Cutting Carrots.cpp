#define MAX_N 2
struct Matrix
{
    int mat[MAX_N][MAX_N];
};


Matrix matMul(Matrix a, Matrix b)   // O(n^3)
{
    Matrix ans;
    int i, j, k;
    for (i = 0; i < MAX_N; i++)
        for (j = 0; j < MAX_N; j++)
            for (ans.mat[i][j] = k = 0; k < MAX_N; k++) // if necessary, use
                ans.mat[i][j] += a.mat[i][k] * b.mat[k][j]; // modulo arithmetic
    return ans;
}


Matrix matPow(Matrix base, int p)   // O(n^3 log p)
{
    Matrix ans;
    int i, j;
    for (i = 0; i < MAX_N; i++) for (j = 0; j < MAX_N; j++)
            ans.mat[i][j] = (i == j); // prepare identity matrix
    while (p)   // iterative version of Divide & Conquer exponentiation
    {
        if (p & 1) ans = matMul(ans, base); // if p is odd (last bit is on)
        base = matMul(base, base); // square the base
        p >>= 1; // divide p by 2
    }
    return ans;
}
