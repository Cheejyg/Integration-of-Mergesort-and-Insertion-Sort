// CX1007 Data Structures

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll){
    
    ListNode *temp = ll->head;
    
    if (temp == NULL)
        return;
    
    while (temp != NULL){
        printf("%d ", temp->item);
        temp = temp->next;
    }
}

ListNode * findNode(LinkedList *ll, int index){
    
    ListNode *temp;
    
    if (ll == NULL || index < 0 || index >= ll->size)
        return NULL;
    
    temp = ll->head;
    
    if (temp == NULL || index < 0)
        return NULL;
    
    while (index > 0){
        temp = temp->next;
        if (temp == NULL)
            return NULL;
        index--;
    }
    
    return temp;
}

int insertNode(LinkedList *ll, int index, int value){
    
    ListNode *pre, *cur;
    
    if (ll == NULL || index < 0 || index > ll->size + 1)
        return -1;
    
    // If empty list or inserting first node, need to update head pointer
    if (ll->head == NULL || index == 0){
        cur = ll->head;
        ll->head = malloc(sizeof(ListNode));

        if (ll->size == 0)
            ll->tail = ll->head;
        
        ll->head->item = value;
        ll->head->next = cur;
        ll->size++;
        return 0;
    }
    
    // Inserting as new last node
    if (index == ll->size){
        pre = ll->tail;
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        ll->tail = pre->next;
        pre->next->item = value;
        pre->next->next = cur;
        ll->size++;
        return 0;
    }
    
    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    if ((pre = findNode(ll, index-1)) != NULL){
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        pre->next->item = value;
        pre->next->next = cur;
        ll->size++;
        return 0;
    }
    
    return -1;
}

int removeNode(LinkedList *ll, int index){
    
    ListNode *pre, *cur;
    
    // Highest index we can remove is size-1
    if (ll == NULL || index < 0 || index >= ll->size)
        return -1;
    
    // If removing first node, need to update head pointer
    if (index == 0){
        cur = ll->head->next;
        free(ll->head);
        ll->head = cur;
        ll->size--;
        
        if (ll->size == 0)
            ll->tail = 0;
        
        return 0;
    }
    
    // Find the nodes before and after the target position
    // Free the target node and reconnect the links
    if ((pre = findNode(ll, index-1)) != NULL){
        
        // Removing the last node, update the tail pointer
        if (index == ll->size - 1){
            ll->tail = pre;
            free(pre->next);
            pre->next = NULL;
        }
        else{
            cur = pre->next->next;
            free(pre->next);
            pre->next = cur;
        }
        ll->size--;
        return 0;
    }
    
    return -1;
}
