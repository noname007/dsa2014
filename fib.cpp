//+#include <iostream>
#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

void echo(int *num,int n)
{
    for(int i = 0;i < n;++i)
    {
        cout<<num[i]<<"\n"<<endl;
    }
}

void calc_fib(int n)
{
    //int fib[1000];
    //if(n==0)
    n +=1;
    int *p = (int*)malloc(sizeof(int)*(n+5));

    p[0] = 0;
    p[1] = 1;

    for(int i = 2;i<n;++i)
    {

        p[i] = p[i-1] + p[i-2];
    }

    for(int i = 0;i<n;++i)
    {
        cout<<"fib["<<i<<"] = "<<p[i]<<";"<<endl;
    }
    free(p);
    //int *p ;
}

int main()
{
    //cout << "Hello world!" << endl;
    calc_fib(9);
    return 0;
}
