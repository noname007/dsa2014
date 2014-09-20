#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

/*
*递归方式解决。大量重复，时间复杂度在指数时间左右
*/
int lcs_length_recurive(char *str1, char *str2, int len1, int len2)
{
//    int len1 = strlen(str1);
//    int len2 = strlen(str2);

    if(len1==0|| len2==0)
    {
        return 0;
    }

    if(str1[len1 -1] == str2[len2 - 1])
    {
//        str1[len1 - 1] = '\0';
//        str2[len2 - 1] = '\0';
        return lcs_length_recurive(str1, str2, len1-1, len2-1) + 1;
    }
    else
    {
        int lcs1 = lcs_length_recurive(str1, str2, len1-1, len2);
        int lcs2 = lcs_length_recurive(str1, str2, len1, len2 - 1);
        return  lcs1 > lcs2 ? lcs1 : lcs2;
    }
}

/*
*递推式子O(mn)
*/
int lcs_length_recursion(char *str1,char *str2)
{
    /*
    *malloc申请二维数组
    *http://bbs.csdn.net/topics/230081799
    */
    int len1 = strlen(str1);
    int len2 = strlen(str2);
//    int **p = (int **) malloc(sizeof(int *) * (len1+3));
//    for(int i = 0;i<len1;++i)
//    {
//        p[i] = (int *) malloc(sizeof(int) * (len2+3));
//        memset(p[i],0,sizeof(int)*(len2+3));
//    }
    int p[100][100];


    for(int i = 1; i <= len1; ++i)
    {
        for(int j = 1; j <= len2; ++j)
        {
            if(str1[i-1]==str2[j-1])
                p[i][j] = p[i-1][j-1]+1;
            else
                p[i][j] = p[i-1][j] > p[i][j-1]?p[i-1][j] : p[i][j-1];
        }
    }

    cout<<endl<<"|  ";
    for(int i=0;i<len2;++i)
    {
        cout<<" | "<<str2[i];
    }
    cout<<" | "<<endl;
    for(int i = 1;i<=len1;++i)
    {
        cout<<"| "<<str1[i-1]<<" | ";
        for(int j = 1;j<=len2;++j)
        {
            cout<<p[i][j]<<" | ";
        }
        cout<<endl;
    }

//    for(int i = 0; i < len1;++i)
//        free(p[i]);
//    free(p);
    return p[len1][len2];

}

int main()
{
    char str11[100],str22[100];
    char *str1 = "program";
    char *str2 = "algorithm";
    cout<<"Calculat LCS('program','algorithm') = ? y/n"<<endl;

    char temp;
    cin >>temp;

    if(temp=='n')
    {
        str1 = str11;
        str2 = str22;
        cin >>str1>>str2;
    }
    //cout<<lcs_length_recurive(str1, str2, strlen(str1), strlen(str2)) <<endl;
    cout<<endl<<"LCS = "<<lcs_length_recursion(str1,str2)<<endl;
    return 0;
}
