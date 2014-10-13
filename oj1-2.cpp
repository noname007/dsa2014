#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

typedef struct ListNode{
    char data;
    ListNode *success;
    ListNode *parent;
}SListNode;

class List{
    SListNode * head = new SListNode,*tail=new SListNode,*cycleHead = new SListNode,*cycleTail = new SListNode;
    int _nodeNum=0,_cycleNode = 0;
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

    int getNodeNum()
    {
        return _nodeNum;
    }

    void deleteNode(SListNode *n)
    {
        n->parent->success = n->success;
        n->success->parent = n->parent;
        _insertAfter(cycleHead,n);
        ++_cycleNode;
    }

    void
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
}
