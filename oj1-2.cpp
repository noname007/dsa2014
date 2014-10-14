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

    void insertBefore(SListNode *a,SListNode *b)
    {
        _insertBefore(a,b);
        ++_nodeNum;
    }

    void  insertAfter(SListNode *a,SListNode *b)
    {
        _insertAfter(a,b);
        ++_nodeNum;
    }

    void insertNodeInX(int x,SListNode * Node)
    {
        SListNode *temp = head;
        while(x--)
        {
            temp = temp->success;
        }
        insertBefore(temp,Node);
        check_rule(Node);
    }


    int getNodeNum()
    {
        return _nodeNum;
    }

    void deleteNode(SListNode *n)
    {
        n->parent->success = n->success;
        n->success->parent = n->parent;
        --_nodeNum;
        _insertAfter(cycleHead,n);
        ++_cycleNodeNum;
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

        while(Node->data == tail->data)
        {
            tail = tail->success;
            ++same_node_num;
        }

        while(Node->data == head->data)
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
    List a;
    int n;

    scanf("%d",&n);
    // scan
}
