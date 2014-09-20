#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

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


int main()
{
    char str11[100],str22[100];
    char *str1 = "program";
    char *str2 = "algorithm";
    cout<<"LCS('program','algorithm') = ? y/n"<<endl;

    char temp;
    cin >>temp;

    if(temp=='n')
    {
        str1 = str11;
        str2 = str22;
        cin >>str1>>str2;
    }
    cout<<lcs_length_recurive(str1, str2, strlen(str1), strlen(str2)) <<endl;
    return 0;
}
