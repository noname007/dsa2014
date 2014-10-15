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

class List
{

    SListNode * head = new SListNode,*tail=new SListNode,*cycleHead = new SListNode,*cycleTail = new SListNode;
    int _nodeNum=0,_cycleNodeNum = 0;

 public:
    List()
    {
        cycleHead->parent=NULL;
        cycleHead->success=NULL;
        _insertAfter(cycleHead,cycleTail);
        head->parent = NULL;
        head->success = NULL;
        _insertAfter(head,tail);
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
//        Node->data = c;
        insertBefore(temp,Node);
        check_rule(temp->parent);
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

    void deleteNode(SListNode *n)
    {
        n->parent->success = n->success;
        n->success->parent = n->parent;
        --_nodeNum;
        _insertAfter(cycleHead,n);
        ++_cycleNodeNum;
    }

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
        b->parent =  a->parent;
        a->parent =  b;
        b->success = a;
    }

    void _insertAfter(SListNode *a, SListNode *b)
    {
        b->success = a->success;
        a->success = b;
        b->parent = a;
    }

    void check_rule(SListNode *Node)
    {
        int same_node_num = 0;
        SListNode * tail = Node->success,*head = Node->parent;

        while(tail != NULL && Node->data == tail->data)
        {
            tail = tail->success;
            ++same_node_num;
        }

        while(head !=NULL && Node->data == head->data)
        {
            ++same_node_num;
            head = head->parent;
        }

        if( 2 < same_node_num)
        {
            cycleTail->parent->success = head->success;
            tail->parent->success = cycleTail;
            _cycleNodeNum += same_node_num;
        }
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
    while((c = getchar())!='\n')
    {

        a->insertBefore(a->getTail(),c);
    }
    getchar();
    scanf("%d",&n) ;

    int positon;
    while(n--)
    {
        getchar();
        scanf("%d %c\n",&positon,&c);
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
