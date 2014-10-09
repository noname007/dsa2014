#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef struct
{
    int x,y;
}Point;

//int (*pf)(int *x,int y,int index1,int  index2);

int cmp(const void * a,const void * b)
{
    Point *aa = (Point *)a;
    Point *bb = (Point *)b;
    if(aa->x == bb->x)
    {
        return bb->y - aa->y;
    }
    else
    {
        return  bb->x - aa->x;
    }

}

int merge_sort(Point *arr,int start,int mid,int last)
{
    int *temp = new int[mid - start];
    for(int i = start;i<mid;++i)
    {
        temp[i] = arr[i].y;
    }
    int k = start;
    int reverse_order = 0;

    for(int i = start, j = mid ; i < mid ; )
    {
        if(j < last &&  arr[j].y <= temp[i])
        {
            arr[k++].y = arr[j].y;
            reverse_order += j-i;
            ++j;
            printf("i:%d k:%d j:%d\n",i,reverse_order,j);
        }

        if(last <= j || temp[i]<arr[j].y)
        {
            arr[k++].y= temp[i++];
        }
    }
    delete []temp;
    return reverse_order;
}

int _merge(Point * arr, int start, int last)
{
    if(start +1 == last)
    {
        return 0;
    }
    int reverse_order=0;
    int mid = (start + last)>>1;
    _merge(arr,start,mid);
    _merge(arr,mid,last);
    return reverse_order + merge_sort(arr,start,mid,last);

}


int main()
{
    int lamb_tower;
    Point P[100005];
    scanf("%d",&lamb_tower);

//    while(lamb_tower --)
    for(int i =0;i<lamb_tower;++i)
    {
        scanf("%d%d",&(P[i].x),&(P[i].y));
    }
    qsort(P,lamb_tower, sizeof(P[0]),cmp);
    int reverse_order = _merge(P,0,lamb_tower);
    printf("%d\n",reverse_order);
}
