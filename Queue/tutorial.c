#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main(){
    int N;
    printf("\n\n=====================================================\n\n");
    printf("This is queue made using linked-list");
    printf("\n\n=====================================================\n\n");

    printf("Enter the Queue size: ");
    scanf("%d",&N);
    set_max_queue_size(N);

    int response;
    Node *head=NULL;
    Node *tail=NULL;
    error_status error;
    while(response!=4){
        printf("\n-------------------------\n");
        printf("[0] Enqueue\n");
        printf("[1] Reveal queue data\n");
        printf("[2] Dequeue\n");
        printf("[3] Print the whole queue\n");
        printf("[4] exit\n");
        printf("-------------------------\n");
        printf("\nyour response: ");
        scanf("%d",&response);
        if(response==0){
            if(head==NULL){
                double data;
                printf("Enter the data (float): ");
                scanf("%lf",&data);
                head = make_node(data);
                tail=head;
                printf("Enqueued!\n");
            }
            else{
                double data;
                printf("Enter the data (float): ");
                scanf("%lf",&data);
                Node *node = make_node(data);
                error = enqueue(&node, &head, &tail);
                if(error==NO_ERROR)
                    printf("Enqueued!\n");
                else printf("ERROR: The Queue is full!\n");       
            }
        }
        else if(response==1){
            if(head!=NULL)
                printf("Front of the queue: %.2lf\n",head->val);
            else printf("ERROR: The Queue is empty!\n");
            if(tail!=NULL)
                printf("End of the queue: %.2lf\n\n",tail->val);
        }
        else if(response==2){
            error = dequeue(&head, &tail);
            if(error==NO_ERROR)
                printf("Dequeued!\n");
            else printf("ERROR: The Queue is empty!\n");
        }
        else if(response==3){
            error = print_queue(head);
            if(error==ERROR_QUEUE_EMPTY)
                printf("ERROR: The Queue is empty!\n");
        }
        else if(response==4) printf("\n");
        else if(response==5){
            error = destroy_queue(&head,&tail);
            if(error==NO_ERROR)
                printf("Destroyed!\n");
            else printf("ERROR: The Queue is empty!\n");
        }
        else printf("read the instructions dumbass\n");
    }
    return 0;
}