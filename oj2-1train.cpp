#include<cstdio>
#include<iostream>
using namespace std;
int op[1600005];
int op_top = 0;

int train[1600005];
int top=0;

char op_record[4000000];
int op_record_top= 0;

int num,limit;

void check_train()
{
    while(top && op_top < num && train[top - 1] == op[op_top])
    {
        ++op_top;
        --top;
        op_record[op_record_top ++] = 0;
    }
    return ;
}

int main()
{
    scanf("%d%d",&num,&limit);
    for(int i = 0;i<num;++i)
    {
        scanf("%d",&op[i]);
    }
    if(limit > 0){
        for(int i = 1;i <= num && op_top < num; ++i)
        {
            if(i == op[op_top])
            {
                ++op_top;
                op_record[op_record_top++] = 1;
                op_record[op_record_top++] = 0;
                check_train();
            }
            else {
                train[top++] = i;
                op_record[op_record_top ++] = 1;
                if(top>=limit)
                    break;
            }
        }
    }
    else{
        top = 1;
    }

    if(top==0)
    {
       for(int i = 0;i < op_record_top; ++i)
       {
           if(op_record[i])
           {
                printf("push\n");
           }
           else{
                printf("pop\n");
           }
       }
    }
    else{
        printf("No\n");
    }
    return 0;
}
