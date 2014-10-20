#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

typedef struct ListNode
{
    char data;
    ListNode *success;
    ListNode *parent;
} SListNode;
//3ks Programcaicai
const int SZ = 1<<20;
struct fastio{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;
//3ks farui,but couldn't use;i don't the resone
//#define IO_BUF_SIZE 1<<20
//char _io_buf[IO_BUF_SIZE];
//static char _out_buf[IO_BUF_SIZE];
//setvbuf(stdin,_io_buf,_IOFBF,IO_BUF_SIZE);
class List
{

    SListNode * head,*tail,*cycleHead ,*cycleTail ;
    int _nodeNum,_cycleNodeNum;


 public:
    List()
    {
        _nodeNum=0;
        _cycleNodeNum = 0;
        head = new SListNode;
        tail=new SListNode;
        cycleHead = new SListNode;
        cycleTail = new SListNode;
        cycleTail->parent=cycleHead;
        cycleHead->success=cycleTail;
//        _insertAfter(cycleHead,cycleTail);
        tail->parent = head;
        head->success = tail;
//        _insertAfter(head,tail);
    }
    ~List()
    {

    }

    void insertBefore(SListNode *a, char c)
    {
        SListNode* b = new SListNode;
        b->data = c;
        _insertBefore(a,b);
        ++_nodeNum;
    }

    void  insertAfter(SListNode *a,char c)
    {
        SListNode * b = new SListNode;
        b->data = c;
        _insertAfter(a,b);
        ++_nodeNum;
    }

    void insertNodeInX(int x,char Node)
    {
        SListNode *temp = head;

        while(x--)
        {
            temp = temp->success;
        }

        insertAfter(temp,Node);
//        travelAll();
        check_rule(temp->success);
    }


    int getNodeNum()
    {
        return _nodeNum;
    }

    void travelAll()
    {
        SListNode * temp =  head;
        while((temp = temp->success) != tail){
            printf("%c",temp->data);
        }
        printf("\n");
    }

//    void deleteNode(SListNode *n)
//    {
//        n->parent->success = n->success;
//        n->success->parent = n->parent;
//        --_nodeNum;
//        _insertAfter(cycleHead,n);
//        ++_cycleNodeNum;
//    }

    SListNode * getTail()
    {
        return tail;
    }
    SListNode * getHead()
    {
        return head;
    }
private:
    void _removeNode(SListNode *a)
    {
        a->parent->success = a->success;
        a->success->parent = a->parent;
    }

    void _insertBefore(SListNode * a,SListNode *b)
    {
        a->parent->success = b;
        b->parent =  a->parent;
        a->parent =  b;
        b->success = a;
    }

    void _insertAfter(SListNode *a, SListNode *b)
    {
        a->success->parent = b;
        b->success = a->success;
        a->success = b;
        b->parent = a;
    }

    void * check_rule(SListNode *Node)
    {
        int same_node_num = 1;
        SListNode * tail = Node->success,*head = Node->parent;
//        travelAll();
        while(tail != this->tail && Node->data == tail->data)
        {
            tail = tail->success;
            ++same_node_num;
        }
//  printf("%d\n",same_node_num);
        while(head !=this->head && Node->data == head->data)
        {
            ++same_node_num;
            head = head->parent;
        }

        if( 2 < same_node_num)
        {
            cycleTail->parent->success = head->success;
            head->success->parent = cycleTail->parent;

            tail->parent->success = cycleTail;
            cycleTail->parent = tail->parent;

            tail->parent = head;
            head->success = tail;

            _cycleNodeNum += same_node_num;
            _nodeNum -= same_node_num;
            if(head != this->head )
            {
                check_rule(head);
            }
        }
//        return head;
//        printf("%d\n",same_node_num);
//        travelAll();
//        return same_node_num
    }

    void _deleteDataList(SListNode *head)
    {

    }

    void _deleteCycleList(SListNode * cycleHead)
    {

    }
};

int main()
{
    List *a = new List;
    int n;
    char c;
    while((c =getchar())&&(c<='Z'&&c>='A'))
    {
        a->insertBefore(a->getTail(),c);
    }



//    a->travelAll();

     scanf("%d",&n) ;

    int positon;
    while(n--)
    {
//        getchar();
        scanf("%d\n",&positon);
        while((c=getchar())&&(c<'A'||c>'Z'));
        a->insertNodeInX(positon,c);

        if(a->getNodeNum())
        {
            a->travelAll();
        }
        else{

            printf("-\n");
        }
    }
}
