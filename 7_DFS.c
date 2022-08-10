/*C program to check connectivity and acyclicity of a graph*/
#include<stdio.h>
#include<stdlib.h>
int g[100][100],visited[100],acyclic=1;
int i,count=0,j,k,n;
int v;
void dfs(int v)
{
    visited[v]=1;
    for(i=0;i<n;i++)
    {
        if(g[v][i]&&!visited[i])
        {
            printf("%d->",i);
            dfs(i);
        }
        if(g[v][i]&&visited[i])
            acyclic=0;
    }

}
void main()
{ 
    printf("\nEnter the number of vertices: ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix: ");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&g[i][j]);
    dfs(0);
    for(i=0;i<n;i++)
        if(visited[i])
            count++;
    if(count==n)
        printf("\nThe graph is connected");
    else
        printf("\nThe graph is not connected");
    if(acyclic)
        printf("\nThe graph is ayclic");
    else
        printf("\nThe graph is not connected");
    if(count!=n)
    {
        for(i=0;i<n;i++)
            visited[i]=0;
        for(i=0;i<n;i++)
        {
            dfs(i);
            printf("\n");
        }
    }
}