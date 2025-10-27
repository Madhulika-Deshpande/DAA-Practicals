#include <stdio.h>
#include <stdbool.h>
#define MAX 20
int n;
int m;
int adj[MAX][MAX];
int color[MAX];
bool isSafe(int v, int c)
{
    for(int i=0; i<n; i++)
    {
        if(adj[v][i] && color[i]==c)
        {
            return false;
        }
    }
    return true;
}
bool graphColoring(int v)
{
    if(v==n)
    {
        return true;
    }
    for(int c=1; c<=m; c++)
    {
        if(isSafe(v, c))
        {
            color[v]=c;

            if(graphColoring(v+1))
            {
                return true;
            }

            color[v]=0;
        }
    }
    return false;
}
void printColors()
{
    printf("Vertex colors:\n");
    for(int i=0; i<n; i++)
    {
        printf("Vertex %d -> Color %d\n", i+1, color[i]);
    }
}
void solveGraph(int vertices, int colors, const int matrix[][MAX], int graphNum)
{
    n=vertices;
    m=colors;

    for(int i=0; i<n; i++)
    {
        color[i]=0;
        for(int j=0; j<n; j++)
        {
            adj[i][j]=matrix[i][j];
        }
    }
    printf("\nGraph %d:(V=%d,Colors=%d)\n", graphNum, n, m);
    if(graphColoring(0))
    {
        printColors();
    }
    else
    {
        printf("Coloring NOT Possible with M=%d.\n", m);
    }
}
int main()
{
    const int graph1_adj[MAX][MAX]={
        {0, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 1},
        {0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 1},
        {0, 0, 0, 1, 0, 1},
        {1, 1, 0, 1, 1, 0}
    };
    int vertices1=6;
    int colors1=3;

    const int graph2_adj[MAX][MAX]={
        {0,1,1,1,1},
        {1,0,1,1,1},
        {1,1,0,1,1},
        {1,1,1,0,1},
        {1,1,1,1,0}
    };
    int vertices2=5;
    int colors2=5;

    solveGraph(vertices1, colors1, graph1_adj, 1);
    solveGraph(vertices2, colors2, graph2_adj, 2);

    return 0;
}