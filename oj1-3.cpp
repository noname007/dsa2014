#include<stdio.h>
#include<stdlib.h>
//#include<iostream>
using namespace std;
typedef struct
{
    int x,y;
}Point;
Point P[5000005];
int temp[5000005];
int cmp(const void * a,const void * b)
{
    Point *aa = (Point *)a;
    Point *bb = (Point *)b;
    return  bb->x - aa->x;
}

long long int merge_sort(Point *arr,int start,int mid,int last)
{

    for(int i = start;i<mid;++i)
    {
        temp[i] = arr[i].y;
    }
    int k = start;
    long long int reverse_order = 0;

    for(int i = start, j = mid ; i < mid ; )
    {

        if(j < last &&  arr[j].y <= temp[i])
        {
            arr[k++].y = arr[j++].y;
            reverse_order += (mid-i);
        }

        if(last <= j || temp[i]<arr[j].y)
        {
            arr[k++].y= temp[i++];
        }
    }
    return reverse_order;
}

long long int _merge(Point * arr, int start, int last)
{
    if(start +1 == last)
    {
        return 0;
    }
    long long int reverse_order=0;
    int mid = (start + last)>>1;
    reverse_order += _merge(arr,start,mid);
    reverse_order += _merge(arr,mid,last);
    return reverse_order +  merge_sort(arr,start,mid,last);
}


int main()
{
    int lamb_tower;

    scanf("%d",&lamb_tower);

    for(int i =0;i<lamb_tower;++i)
    {
        scanf("%d%d",&(P[i].x),&(P[i].y));
    }
    qsort(P,lamb_tower, sizeof(P[0]),cmp);
    long long int reverse_order = _merge(P,0,lamb_tower);

    printf("%lld\n",reverse_order);

    return 0;

}
