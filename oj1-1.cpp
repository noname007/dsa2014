#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int dot;
int bq(int *arr,int start,int last, int &num)
{
    if(start>last)
        return last;
    int mid = (start + last)/2;

    if(arr[mid]>=num)
    {
        last = mid - 1;
        if(arr[last] < num)
        {
            return last;
        }
    }
    else
    {
        start = mid +1;
        if(arr[start] >= num)
        {
            return mid;
        }
    }
    return bq(arr,start,last,num);
}
int cmp(const void *c1,const void * c2)
{
    int  c11 = * ((int *)c1);
    int c22 = * ((int *)c2);
    return  c11 -c22;
 }

int main()
{
    int query;
    scanf("%d%d",&dot,&query);
    int quence[500010],*tem;
    tem = quence;
    for(int i = 0;i < dot; ++i)
    {
        scanf("%d",tem++);
    }
    qsort(quence,dot,sizeof(int),cmp);
//    for(int i = 0;i < dot; ++i)
//    {
//        cout <<quence[i]<<" ";
//    }
//    cout <<endl;

    int start, last,first,second;

    while(query--)
    {
        scanf("%d%d",&start,&last);
        first = bq(quence,0,dot-1,start);
        second = bq(quence,0,dot-1,last);
        if(quence[second+1] == last)
            second += 1;
        cout << second - first<<endl;
    }
    return 0;
}
