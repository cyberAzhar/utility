 #include <stdio.h>
 #include <stdlib.h>

 typedef struct Point{
     int x;
     int y;
 }Point;

 typedef struct Rect{
     Point leftdown;
     Point rightup;
 }Rect;

double calculate_rect_area(struct Rect *rect){
    double area = (rect->leftdown.x-rect->rightup.x)*(rect->leftdown.y-rect->rightup.y);
    return area;
}

typedef struct Node{
    double val;
    struct Node *next;
}Node;

Node* make_node(double val){
    Node *nd = (Node*)malloc(sizeof(Node));
    nd->val = val;
    nd->next = NULL;
    return nd;
}

Node* push(Node *newnode, Node *head){
    newnode->next = head;
    head = newnode;

    return head;
}

Node* pop(Node *head){
    Node *clone = head->next;
    free(head);
    head = clone;

    return head;
}

void print_list(Node *head){
    Node *cur = head;
    while(1){
        printf("%lf ",cur->val);
        if(cur->next==NULL)break;
        cur = cur->next;
    }
    printf("\n");
}



int main(){
    Rect rectangle = {{0,0},{2,2}};
    Rect *rect = &rectangle;
    double area = calculate_rect_area(rect);
    printf("calculated area for a rectangle having coordinates (0,0) and (2,2) = %lf\n",area);
    printf("\n\n=====================================================\n\n");
    printf("This is stack made using linked-list (robust version)");
    printf("\n\n=====================================================\n\n");


    int response;
    int c=0;
    Node *head=NULL;
    while(response!=4){
        printf("\n-------------------------\n");
        printf("[0] push data\n");
        printf("[1] see the top data\n");
        printf("[2] pop data\n");
        printf("[3] see the full stack\n");
        printf("[4] exit\n");
        printf("-------------------------\n");
        printf("\nyour response: ");
        scanf("%d",&response);
        if(response==0){
            c++;
            if(c==1){
                double data;
                printf("Enter the data (float): ");
                scanf("%lf",&data);
                head = make_node(data);
                printf("stacked");
            }
            else{
                double data;
                printf("Enter the data (float): ");
                scanf("%lf",&data);
                Node *node = make_node(data);
                head = push(node, head);
                printf("stacked");                
            }
        }
        else if(response==1){
            if(head!=NULL)printf("top of the stack: %lf",head->val);
            else printf("The stack is empty!");
        }
        else if(response==2){
            if(head!=NULL){
                head = pop(head);
                printf("Popped!");
            }
            else printf("Nothing to pop!");
        }
        else if(response==3){
            if(head!=NULL) print_list(head);
            else printf("The stack is empty");
        }
        else if(response==4) printf("\n");
        else printf("read the instructions dumbass\n");
    }
    return 0;
}
