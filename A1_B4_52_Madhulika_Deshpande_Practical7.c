#include <stdio.h>
#include <float.h>
#define MAX 100
void obst(float p[], float q[], int n) 
{
    float w[MAX + 2][MAX + 1] = {0}, e[MAX + 2][MAX + 1] = {0};
    int r[MAX + 2][MAX + 1] = {0};
    for (int i = 1; i <= n + 1; i++) 
    {
        w[i][i - 1] = q[i - 1];
        e[i][i - 1] = q[i - 1];
    }
    for (int l = 1; l <= n; l++)
    { 
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j];
            e[i][j] = FLT_MAX;
            for (int k = i; k <= j; k++) 
            {
                float t = e[i][k - 1] + e[k + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    r[i][j] = k; 
                }
            }
        }
    }
    printf("\nMinimum expected search cost of the optimal binary search tree is: %.4f\n", e[1][n]);
    printf("\nWeight matrix w[i][j]:\n");
    for (int i = 1; i <= n + 1; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            if (j >= i - 1)
                printf("%8.4f ", w[i][j]);
            else
                printf("         ");
        }
        printf("\n");
    }
    printf("\nExpected cost matrix e[i][j]:\n");
    for (int i = 1; i <= n + 1; i++) 
    {
        for (int j = 0; j <= n; j++)
        {
            if (j >= i - 1)
                printf("%8.4f ", e[i][j]);
            else
                printf("         ");
        }
        printf("\n");
    }
    printf("\nRoot matrix r[i][j]:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
        {
            if (j >= i)
                printf("%3d ", r[i][j]);
            else
                printf("    ");
        }
        printf("\n");
    }
}
int main() 
{
    int n;
    printf("Enter the number of book IDs: ");
    scanf("%d", &n);
    int keys[MAX];
    float p[MAX], q[MAX + 1];
    printf("Enter the sorted book IDs separated by spaces:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &keys[i]);
    }
    printf("Enter the probabilities of successful searches for each book ID:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Probability of successful search for book %d (ID %d): ", i + 1, keys[i]);
        scanf("%f", &p[i]);
    }
    printf("Enter the probabilities of unsuccessful searches (between keys):\n");
    for (int i = 0; i <= n; i++) 
    {
        printf("Probability of unsuccessful search q[%d]: ", i);
        scanf("%f", &q[i]);
    }
    obst(p, q, n);
    return 0;
}