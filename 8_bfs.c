/*C program to check for connectivity and acyclicity of the graph using BFS aglgorithm*/
#include<stdio.h>
#include<stdlib.h>
int graph[100][100],visited[100],ac=1,f=0,r=-1,q[40],i,j,n;
void bfs(int v)
{
    visited[v]=1;
    for(int i=0;i<n;i++)
    {
        if(graph[v][i]&&!visited[i])
        {
            printf("%d->",v);
            q[++r]=i;
        }
        if(graph[v][i]&&visited[i])
            ac=0;
        if(f<r)
        {
            visited[q[f]]=1;
            bfs(q[f++]);
        }
    }
}
void main()
{
    int v,count=0;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    bfs(0);
    for(i=0;i<n;i++)
        if(visited[i])  
            count++;
    if(count==n)
        printf("\nThe graph is connected");
    else
        printf("\nThe Graph is not connected");
    if(ac)
        printf("\nThe graph is Acyclic");
    else
        printf("\nThe graph is cyclic");
    if(count!=n)
    {
        for(i=0;i<n;i++)
            visited[i]=0;
        for(i=0;i<n;i++)
        {
            bfs(i);
            printf("\n");
        }
    }  
}