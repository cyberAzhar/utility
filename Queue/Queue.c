#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

int max_queue_size;

void set_max_queue_size(int integer){
    max_queue_size = integer;
}

Node* make_node(double val){
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

int queue_size(Node *head, int counter){
    if(head->next!=NULL){
        counter = queue_size(head->next,++counter);
        return counter;
    }
    else{
        counter++;
        return counter;
    }
}

error_status print_queue(Node *head){
    if(head!=NULL){
        if(head->next!=NULL){
            printf("%.2lf ",head->val);
            print_queue(head->next);
        }
        else{
            printf("%.2lf\n", head->val);
        }
        return NO_ERROR;
    }
    else{
        return ERROR_QUEUE_EMPTY;
    }
}

//function to return the tail of queue given the head
Node* return_tail(Node *head){
    Node *tail;
    if(head->next!=NULL){
        tail = return_tail(head->next);
        return tail;
    }
    else{
        tail = head;
        return tail;
    }
}

//function to return head given the tail of the queue
Node* return_head(Node *tail){
    Node *head;
    if(tail->prev!=NULL){
        head = return_head(tail->prev);
        return head;
    }
    else{
        head = tail;
        return head;
    }
}

//dequeue function
error_status dequeue(Node **head, Node **tail){
    error_status E;
    if(*head!=NULL){
        Node *clone = (*head)->next;
        free(*head);
        *head = clone;
        if(*head==NULL)(*tail)=NULL;
        return NO_ERROR;
    }
    else{
        return ERROR_QUEUE_EMPTY;
    }
}

//enque function
error_status enqueue(Node** node, Node **head, Node **tail){
    int c=0;
    if(queue_size((*head),c)<max_queue_size){
        (*tail)->next = *node;
        (*node)->prev = *tail;
        *tail = *node;
        return NO_ERROR;
    }
    else{
        return ERROR_QUEUE_FULL;
    }
}

error_status destroy_queue(Node **head, Node **tail){
    if((*head)==NULL){
        return ERROR_QUEUE_EMPTY;        
    }
    else{
        int c=0;
        int size = queue_size(*head,c);
        for(int i=0;i<size;i++){
            dequeue(head, tail);
        }
        return NO_ERROR;
    }
}