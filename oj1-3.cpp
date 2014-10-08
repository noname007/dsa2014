#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef struct
{
    int x[10^6],y[10^6];
}Point;

//int (*pf)(int *x,int y,int index1,int  index2);

int cmp(int *x,int *y,int index1,int  index2)
{


}

int merge_sort(Point*,int,int,int,int (*pf)(int *x,int *y,int index1,int index2));

int _merge(Point * arr, int start, int last,int (*pf)(int *x,int *y,int index1,int index2))
{
    if(start +1 == last)
    {
        return 0;
    }
    int reverse_order=0;
    int mid = (start + last)>>1;
    _merge(arr,start,mid,pf);
    _merge(arr,mid,last,pf);
    return reverse_order + merge_sort(arr,start,mid,last,pf);

}

int merge_sort(Point *arr,int start,int mid,int last,int (*pf)(int *x,int *y,int index1,int index2))
{
    int *temp = new int[mid - start];
    for(int i = start;i<mid;++i)
    {
        temp[i] = arr->x[i];
    }
    int k = start;
    int reverse_order = 0;

    for(int i = start,j= mid;i<mid||j<last;++i,++j)
    {
//        if(temp[i] >= arr[j])
//        {
//            arr[k++] = arr[j];
//            reverse_order += j-i;
//        }
//        else
//        {
//            arr[k++] = temp[i];
//        }
    }
    delete []temp;
    return reverse_order;
}

int main()
{
    int lamb_tower;
    Point P;
    scanf("%d",&lamb_tower);

//    while(lamb_tower --)
    for(int i =0;i,lamb_tower;++i)
    {
        scanf("%d%d",&P.x[i],&P.y[i]);
    }
    _merge(&P,0,lamb_tower,cmp);
}
