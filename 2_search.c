/*C program tos how sequential search and recursive binary search*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int countb;
int linear(int *a, int ele, int n)
{
    int count = 0, i;
    for (i = 0; i < n; i++)
    {
        count++;
        if (a[i] == ele)
            return count;
    }
    return count;
}
void binary(int *a, int beg, int end, int ele, int n)
{
    int mid = 0;
    countb++;
    printf("%d", countb);
    if (beg <= end)
    {
        mid = (beg + end) / 2;
        if (a[mid] == ele)
            return;
        else if (ele > a[mid])
            binary(a, mid + 1, end, ele, n);
        else
            binary(a, beg, mid - 1, end, n);
    }
    return;
}
void main()
{
    int a[100], ele, count = 0, n = 10, i, j, beg, end, mid;
    FILE *fp1, *fp2, *fp3;
    fp1 = fopen("lbest.txt", "w");
    fp2 = fopen("lavg.txt", "w");
    fp3 = fopen("lworst.txt", "w");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j < i; j++)
            a[j] = rand() % 100;
        ele = a[0];
        count = linear(a, ele, j);
        fprintf(fp1, "%d\t%d\n", j, count);
        ele = a[j / 2];
        count = linear(a, ele, j);
        fprintf(fp2, "%d\t%d\n", j, count);
        ele = 1000;
        count = linear(a, ele, j);
        fprintf(fp3, "%d\t%d\n", j, count);
    }
    fp1 = fopen("bbest.txt", "w");
    fp2 = fopen("bavg.txt", "w");
    fp3 = fopen("bworst.txt", "w");
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < i; j++)
            a[j] = j * 2;
        beg = 0, end = j - 1;
        countb = 0;
        ele = a[j / 2];
        binary(a, beg, end, ele, j);
        fprintf(fp1, "%d\t%d\n", j, countb);
        countb = 0;
        ele = a[j / 4];
        binary(a, beg, end, ele, j);
        fprintf(fp2, "%d\t%d\n", j, countb);
        countb = 0;
        ele = 1000;
        binary(a, beg, end, ele, j);
        fprintf(fp3, "%d\t%d\n", j, countb);
    }
}