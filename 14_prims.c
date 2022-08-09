/*C program to find Minimum Spanning Tree of a graph and perform its analysis for different inputs*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int v;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&v);
    int G[v][v],selected[v];
    int min,num=0,i,j,x,y,s=0;
    for(i=0;i<v;i++)
        selected[i]=0;
    selected[0]=1;
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            scanf("%d",&G[i][j]);
    while (num<v-1)
    {
        min=10000;
        x=0,y=0;
        for(i=0;i<v;i++)
            if(selected[i]==1)
            {
                for(j=0;j<v;j++)
                {
                    if(selected[j]==0&&G[i][j]!=0)
                    {
                        if(min>G[i][j])
                        {
                            min=G[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
            printf("\n%d - %d: %d\n",x,y,G[x][y]);
            s=s+G[x][y];
            selected[y]=1;
            num++;  
    }
    printf("\nThe minimum cost spanning tree is %d",s);
}