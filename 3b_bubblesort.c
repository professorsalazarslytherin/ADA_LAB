/*C program to show best case,average case and worst case in Bubble sort*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int sort(int *a,int n)
{
    int temp,i,j,count=0,loopcount=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                loopcount++;
            }
            count++;
        }
        if(loopcount==0)
        {
            return count;
        }
    }
    return count;
}
void main()
{
    int a[100],b[100],c[100],i,j,count;
    FILE *fp1,*fp2,*fp3;
    fp1=fopen("bubblebest.txt","w");
    fp2=fopen("bubavg.txt","w");
    fp3=fopen("bubworst.txt","w");
    for(i=1;i<=100;i++)
    {
        for(j=0;j<i;j++)
        {
            a[j]=(j*2)+25;
            b[j]=rand()%100;
            c[j]=100-(2*j);
        }
        count=sort(a,j);
        fprintf(fp1,"%d\t%d\n",j,count);
        count=sort(b,j);
        fprintf(fp2,"%d\t%d\n",j,count);
        count=sort(c,j);
        fprintf(fp3,"%d\t%d\n",j,count);
    }
}