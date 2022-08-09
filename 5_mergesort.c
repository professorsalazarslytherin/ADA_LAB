/*C program to find the Merge sort and analyse the input for the same*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int count;
int a[100],i,j,f,l;
void merge(int a[],int f,int mid,int l)
{
    int n1=mid-f+1;
    int n2=l-mid;
    int i,j,k=f,t1[n2],t2[n2],c[10000];
    for(i=0;i<n1;i++)
        t1[i]=a[i+f];
    for(i=0;i<n2;i++)
        t2[i]=a[mid+i+1];
    i=0,j=0;
    while (i<n1&&j<n2)
    {
        if(t1[i]<=t2[j])
            c[k++]=t1[i++];
        else
            c[k++]=t2[j++];
    }
    while (i<n1)
    {
        c[k++]=t1[i++];
    }
    while (j<n2)
    {
        c[k++]=t2[j++];
    }
    for(i=0;i<=l;i++)
    {
        a[i]=c[i];
    }
}
void mergesort(int a[],int f,int l)
{
    count++;
    if(f<l)
    {
        int mid=(f+l)/2;
        mergesort(a,f,mid);
        mergesort(a,mid+1,l);
        merge(a,f,mid,l);
    }
}
void main()
{
    FILE *fp;
    fp=fopen("merge1.txt","w");
    for(i=1;i<100;i++)
    {
        count=0;
        for(j=0;j<i;j++)
        {
            a[j]=rand()%100;
        }
        f=0;
        l=j;
        mergesort(a,f,l);
        fprintf(fp,"%d\t%d\n",j,count);
    }
}