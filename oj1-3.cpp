#include<cstdio>
#include<cstdlib>
#include<iostream>
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
    //x,y¾ù»¥Òì
//    if(aa->x == bb->x)
//    {
//        return bb->y - aa->y;
//    }
//    else
//    {
        return  bb->x - aa->x;
//    }
}

int merge_sort(Point *arr,int start,int mid,int last)
{
//    int *temp = new int[mid - start];
//    temp -= start;
    for(int i = start;i<mid;++i)
    {
        temp[i] = arr[i].y;
    }
    int k = start;
    long long int reverse_order = 0;
//    printf("start:%d mid:%d last:%d\n",start,mid,last);
    for(int i = start, j = mid ; i < mid ; )
    {

        if(j < last &&  arr[j].y <= temp[i])
        {
            arr[k++].y = arr[j++].y;
            reverse_order += (mid-i);
//            ++j;
        }

        if(last <= j || temp[i]<arr[j].y)
        {
            arr[k++].y= temp[i++];
        }
    }
//    printf("%d\n",reverse_order);
//    delete []temp;
    return reverse_order;
}

int _merge(Point * arr, int start, int last)
{
    if(start +1 == last)
    {
        return 0;
    }
    long long int reverse_order=0;
    int mid = (start + last)>>1;
//    printf("%d\n",mid);
    reverse_order += _merge(arr,start,mid);
    reverse_order += _merge(arr,mid,last);
    return reverse_order +  merge_sort(arr,start,mid,last);
}


int main()
{
    int lamb_tower;

    scanf("%d",&lamb_tower);

//    while(lamb_tower --)
    for(int i =0;i<lamb_tower;++i)
    {
        scanf("%d%d",&(P[i].x),&(P[i].y));
    }
    qsort(P,lamb_tower, sizeof(P[0]),cmp);
    long long int reverse_order = _merge(P,0,lamb_tower);
    printf("%lld\n",reverse_order);
//    for(int i =0;i<lamb_tower;++i)
//    {
//
//        printf("%d %d\n",P[i].x,P[i].y);
//    }
}
