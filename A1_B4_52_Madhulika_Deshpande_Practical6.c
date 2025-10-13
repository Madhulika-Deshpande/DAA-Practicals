#include<stdio.h>
#include<limits.h>
#define N 4
int graph[N][N]={
    {0,10,15,20},
    {5,0,9,10},
    {6,13,0,12},
    {8,8,9,0}
};
int min_cost=INT_MAX;
int best_path[N+1];
int current_path[N+1];
void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int calculate_cost(int path[])
{
    int cost=0;
    for(int i=0;i<N-1;i++)
    {
        cost+=graph[path[i]][path[i+1]];
    }
    cost+=graph[path[N-1]][path[0]];
    return cost;
}
void permute(int cities[],int left,int right)
{
    if(left==right)
    {
        current_path[0]=0;
        for(int i=0;i<N-1;i++)
        {
            current_path[i+1]=cities[i];
        }
        int cost=calculate_cost(current_path);
        if(cost<min_cost)
        {
            min_cost=cost;
            for(int i=0;i<N;i++)
            {
                best_path[i]=current_path[i];
            }
            best_path[N]=0;
        }
    }
    else
    {
        for(int i=left;i<=right;i++)
        {
            swap(cities,left,i);
            permute(cities,left+1,right);
            swap(cities,left,i);
        }
    }
}
int main()
{
    int cities[N-1]={1,2,3};
    permute(cities,0,N-2);
    printf("Best path:");
    for(int i=0;i<=N;i++)
    {
        printf("%d",best_path[i]+1);
        if(i!=N)
        {
            printf("->");
        }
    }
    printf("\nCost of travelling is:%d\n",min_cost);
    return 0;
}