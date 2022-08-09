/*C program to determine the transitive closure of a grpah using Warshall's technique
The order of growth in the following case for Warshall algorithm is n^3*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int v;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&v);
    int c[v][v],i,j,k;
    printf("\nEnter the value of initial matrix");
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            scanf("%d",&c[i][j]);
    for(k=0;k<v;k++)
        for(i=0;i<v;i++)
            for(j=0;j<v;j++)
            {
                if(c[i][j]||c[i][k]&&c[k][j])
                {
                    c[i][j]=1;
                }
            }
    printf("\nTransitive closure Matrix is \n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}