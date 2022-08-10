/*C program to implement Brute Force string matching to search for a pattern of length 'M'*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void match(int ch)
{
    FILE *f;
    int i,j,k,count;
    char *pat,a[5]="aaaa",b[5]="aaba",c[5]="efgh";
    switch(ch)
    {
        case 1:f=fopen("strbest.txt","w");
                break;
        case 2:f=fopen("stravg.txt","w");
                break;
        case 3:f=fopen("strworst.txt","w");
                break;
    }
    for(i=100;i<=1000;i+=100)
    {
        char *arr=malloc(i*sizeof(char));
        for(j=0;j<i;j++)
            arr[j]='a';
        switch (ch)
        {
            case 1:pat=a;
                    break;
            case 2:pat=b;
                    break;
            case 3:pat=c;   
                    break;
        }
        count=0;
        for(j=0;j<i-4;j++)
            for(k=0;k<4;k++)
            {
                count++;
                if(pat[k]!=arr[j+k])
                    break;
            }
        fprintf(f,"%d\t%d\n",i,count);
    }
    fclose(f);
}
void main()
{
    for(int i=1;i<=3;i++)
        match(i);
}