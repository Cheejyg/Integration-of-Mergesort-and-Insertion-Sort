// CX1007 Data Structures

#ifndef LT10_LinkedList_h
#define LT10_LinkedList_h

////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode{
    int item;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
    int size;
    ListNode *head;
    ListNode *tail;
} LinkedList;

////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

#endif
