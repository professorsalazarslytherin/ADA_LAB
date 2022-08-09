/*C program to find the shortest distance between two vertices
Note that the order of growth in the following case belongs to Order of n^3*/
#include<stdio.h>
#include<stdlib.h>
int Min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
void main()
{
    int v;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&v);
    int c[v][v],d[v][v],i,j,k;
    printf("\nEnter the cost matrix:\n ");
    for(i=0;i<v;i++)
        for(j=0;j<v;j++){
            scanf("%d",&c[i][j]);
            d[i][j]=c[i][j];
        }
    for(k=0;k<v;k++)
        for(i=0;i<v;i++)
            for(j=0;j<v;j++)
            {
                d[i][j]=Min(d[i][j],d[i][k]+d[k][j]);
            }
    printf("\nThe minimum cost matrix is \n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
            printf("%d ",d[i][j]);
        printf("\n");
    }
}