#include<cstdio>
#include<iostream>
using namespace std;
int deleteEleMap[500000];
class heap_min
{
    int heap_tree[1000];
    int nodeNum ;
    int tem1  ,tem2 ;

public:
    heap_min()
    {
        nodeNum = 0；
        tem1 = 0；
        tem2 = 0;
//        int a = 1;
//        int b = 2;
//        exchange(a,b);
//        cout << a<<b<<endl;
    }
    void insertEle(int a)
    {
        heap_tree[++nodeNum] = a;
        tem1 = nodeNum>>1;
        tem2 = nodeNum;
        while(tem1 && heap_tree[tem1] < heap_tree[tem2])
        {
            exchange(heap_tree[tem1],heap_tree[tem2]);
            tem2 = tem1;
            tem1 >>=1;
        }
    }
    void deleteEle()
    {
        heap_tree[0] = heap_tree[1];
        heap_tree[1] = heap_tree[nodeNum--];
        tem1 = 1;
        tem2 = tem1<<1;
        while(tem2 <= nodeNum )
        {
            //单个子节点，直接取其下标。双个子节点取较小者下标
            tem2 += ( tem2 < nodeNum ) ? 0 : AmaxB(heap_tree[tem2], heap_tree[temp2 + 1]);
            //up-2-down
            if(heap_tree[tem1] < heap_tree[tem2])
            {
                exchange(heap_tree[tem1], heap_tree[tem2]);
            }
            else
            {
                break;
            }
            tem1 = tem2;
            tem2 <<=1;
        }
    }
private:
    void exchange(int &a,int &b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    int AmaxB(int a,int b)
    {
        return a>b;
    }
};


int main()
{
    heap_min a,b,c;
    return 0;
}
