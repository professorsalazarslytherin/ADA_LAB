#include <stdio.h>
#include<stdlib.h>
int graph[100][100], n, visited[100]={0}, a[100],k=-1;
void dfs(int v){
	visited[v]=1;
	for(int i=0;i<n;i++){
		if (graph[v][i] && !visited[i]){
			dfs(i);
		}
	}	
	a[++k]=v;
}
void main(){
	int i,count=0,j;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix: ");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
	for(i=0;i<n;i++){
		if (!visited[i])
			dfs(i);
	}
	printf("\nTopological sorted order is: ");
	for(i=n-1;i>=0;i--){
		printf("%d-->",a[i]);
	}
	printf("\n");
}