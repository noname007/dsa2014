#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define STUDENT_NUM 500005
#define BUF_SIZE 1<<20
typedef struct {
    int loveD;
    int num;
}Student;

struct fastio{
    char input[BUF_SIZE];
    fastio()
    {
//        setvbuf(stdin,input,_IOFBF,BUF_SIZE);
    }
};

Student Teacher[3][STUDENT_NUM];
int selectedStudent[STUDENT_NUM];
int cmp(const void *a,const void *b)
{
    Student *a1 = (Student *)a;
    Student *b1 = (Student *)b;
    return a1->loveD - b1->loveD;
}


int main()
{
//    FILE *fp = freopen("N1_N20_S5.in.txt","r",stdin);
    int student_num;
    char TeacherName[]={'A','B','C'};
    scanf("%d",&student_num);
    for(int i = 0;i < 3;++i)
    {
        for(int j = 0;j<student_num;++j)
        {
            scanf("%d",&(Teacher[i][j].num));
//            Teacher[i][j].num = j+1;
        }
    }
    int who;
    scanf("%d",&who);
//    qsort(Teacher[0],student_num,sizeof(Teacher[0][0]),cmp);
//    qsort(Teacher[1],student_num,sizeof(Teacher[0][0]),cmp);
//    qsort(Teacher[2],student_num,sizeof(Teacher[0][0]),cmp);
//    memset(selectedStudent,0,sizeof(int)*STUDENT_NUM);
    int loveOrder[]={0,0,0};
    for(int i = 0;i < student_num;++i)
    {
        for(int j = 0;j<3;++j)
        {
            while(selectedStudent[ Teacher[j][ loveOrder[j] ].num ] == 1)
            {
                ++loveOrder[j];
            }
            if(Teacher[j][ loveOrder[j] ].num == who)
            {
                printf("%c\n",TeacherName[j]);
                return 0;
            }
            else{
                selectedStudent[Teacher[j][ loveOrder[j] ].num] = 1;
//                for(int k = 0;k<student_num+1;++k)
//                {
//                    printf("%d ",selectedStudent[k]);
//                }
//                printf("T:%d--S:%d\n",j,Teacher[j][ loveOrder[j] ].num);
                ++loveOrder[j];
            }
        }
    }
    return 0;

}
