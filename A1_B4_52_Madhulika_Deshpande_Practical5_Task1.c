#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct
{
    int v;    
    char d;    
} Cell;
char X[MAX],Y[MAX];
Cell cost[MAX][MAX];
int m,n;
void LCS()
{
    for(int i=0;i<=m;i++)
    {
        cost[i][0].v=0;
        cost[i][0].d='H';
    }
    for(int j=0;j<=n;j++)
    {
        cost[0][j].v=0;
        cost[0][j].d='H';
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                cost[i][j].v=cost[i-1][j-1].v+1;
                cost[i][j].d='D';
            }
            else
            {
                if(cost[i-1][j].v>=cost[i][j-1].v)
                {
                    cost[i][j].v=cost[i-1][j].v;
                    cost[i][j].d='U';
                }
                else
                {
                    cost[i][j].v=cost[i][j-1].v;
                    cost[i][j].d='S';
                }
            }
        }
    }
}
void Print_LCS(int i,int j)
{
    if (i == 0 || j== 0)
        return;
    if (cost[i][j].d=='D')
    {
        Print_LCS(i-1,j-1);
        printf("%c",X[i-1]);
    }
    else if(cost[i][j].d=='U')
    {
        Print_LCS(i-1,j);
    }
    else
    {
        Print_LCS(i,j-1);
    }
}
void printCostMatrix()
{
    printf("Cost Matrix (values):\n");
    for (int i=0;i<n;i++)
    {
        if(i==0)
        {
            printf("       ");
        }
        printf(" %c ",Y[i]);
    }
    printf("\n");
    for (int i=0;i<=m;i++)
    {
        if (i==0)
            printf(" -  ");
        else
            printf(" %c  ",X[i-1]);
        for (int j=0;j<=n;j++)
        {
            printf("%2d ",cost[i][j].v);
        }
        printf("\n");
    }
}
int main()
{
    strcpy(X,"AGCCCTAAGGGCTACCTAGCTT");
    strcpy(Y,"GACAGCCTACAAGCGTTAGCTTG");
    m=strlen(X);
    n=strlen(Y);
    LCS();
    printCostMatrix();
    printf("\nLength of LCS:%d\n",cost[m][n].v);
    printf("LCS is:");
    Print_LCS(m,n);
    printf("\n");
    return 0;
}