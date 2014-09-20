#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
    int len1 = 10,len2 = 10;
    int **p = (int **) malloc(sizeof(int *) * (len1+3));
    for(int i = 0;i<len1;++i)
    {
        p[i] = (int *) malloc(sizeof(int ) * (len2+3));
        memset(p[i],0,sizeof(int)*(len2+3));
    }
    cout <<p[1][1];
}
