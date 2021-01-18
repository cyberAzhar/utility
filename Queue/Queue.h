/**
@brief   An attempt at an API for queue
@author  Azhar Tanweer
@version 1.0
**/

/**
@mainpage Welcome to Documentation !!!

This library is written in C !!!

Enjoy !!!
**/

#ifndef _AZHAR_QUEUE_
#define _AZHAR_QUEUE_

/**
 * A Gloabal integer variable containing the queue size
 **/
extern int max_queue_size;


/**
 * @brief An enum representing error status to be returned to the user having error types as enumerations.
 * 
 * The three error types are
 *  -ERROR_QUEUE_FULL: returned when the queue is full. Usually happens when user tries to enqueue.
 *  -ERROR_QUEUE_EMPTY: returned when the queue is empty. Usually happens when the user tries to dequeue/destroy, or print.
 *  -NO_ERROR: returned when the function is executed successfully.
 * 
**/
typedef enum {ERROR_QUEUE_FULL, ERROR_QUEUE_EMPTY, NO_ERROR} error_status;


/**
 * @brief This is the basic building block for the queue.
 * 
 * The structure "Node" contains:
 *  -**Val**: A *double* variable; contains the data for this node.
 *  -**next**: A *pointer* to the next node. If no next node, this is NULL.
 *  -**prev**: A *pinter* to the previous node. Of no previous node, this is NULL.
**/
typedef struct Node{
    double val;
    struct Node *next;
    struct Node *prev;
} Node;


/**
 * @brief Sets the Global integer variable **max_queue_size** equal to the entered queue size.
 * 
 * @param integer The desired queue size
**/
void set_max_queue_size (int integer);


/**
 * @brief Generates a node containing the entered data.
 * 
 * A "node" is a C structure which is the basic building block for the queue.
 * The structure "Node" contains:
 *  -**Val**: A *double* variable; contains the data for this node.
 *  -**next**: A *pointer* to the next node. If no next node, this is NULL.
 *  -**prev**: A *pinter* to the previous node. Of no previous node, this is NULL.
 * 
 * @param val The data to be stored in the generated node
 * 
 * @return A pointer to the generated node
**/
Node* make_node(double val);


/**
 * A recursive function which returns the current queue size.
 * 
 * @param head The head of the queue (The *pointer* to the first node of the queue)
 * @param counter An integer which will be used as a counter integer (will be incremented to the queue size) and will be returned. Needless to say this must be zero is usual cases.
 * 
 * @return An integer equal to queue size.
 * 
 * @warning The argument **counter** must be zero for the function to work in intentioned way. 
**/
int queue_size(Node *head, int counter);


/**
 * A recursive function which prints the entire queue on the screen.
 * 
 * @param head The head of the queue (The *pointer* to the first node of the queue)
 *  
 * @return the **error_status**
**/
error_status print_queue(Node *head);


/**
 * @brief returns the tail of the queue
 * 
 * @param head the head of the queue (The *pointer* to the first node of the queue)
 * 
 * @return the tail of the queue (A *pointer* to the last node of the queue)
**/
Node* return_tail(Node *head);


/**
 * @brief returns the head of the queue
 * 
 * @param tail the head of the queue (The *pointer* to the last node of the queue)
 * 
 * @return the head of the queue (The *pointer* to the first node of the queue)
**/
Node* return_head(Node *tail);


/**
 * @brief dequeues a node from the queue.
 * 
 * A "node" is a C structure which is the basic building block for the queue.
 * The structure "Node" contains:
 *  -**Val**: A *double* variable; contains the data for this node.
 *  -**next**: A *pointer* to the next node. If no next node, this is NULL.
 *  -**prev**: A *pinter* to the previous node. Of no previous node, this is NULL.
 * 
 * this function deletes an entry at the start (head) of the queue. The head and tail of the queue will be automatically handled; the user need not change head/tail of the queue.
 * Function will rerurn an error if the called on an empty queue.
 * 
 * @param head The pointer to head of the queue (The *pointer* to the *pointer* to the first node of the queue)
 * @param tail The pointer to tail of the queue (The *pointer* to the *pointer* to the last node of the queue) 
 * 
 * @return the **error_status**: ERROR_QUEUE_EMPTY if the queue is empty; else NO_ERROR
**/
error_status dequeue(Node **head, Node **tail);


/**
 * @brief enqueues a node into the queue.
 * 
 * A "node" is a C structure which is the basic building block for the queue.
 * The structure "Node" contains:
 *  -**Val**: A *double* variable; contains the data for this node.
 *  -**next**: A *pointer* to the next node. If no next node, this is NULL.
 *  -**prev**: A *pinter* to the previous node. Of no previous node, this is NULL.
 * 
 * this function appends an entry at the end (tail) of the queue. The head and tail of the queue will be automatically handled; the user need not change head/tail of the queue.
 * Function will rerurn an error if the called on a full queue. 
 * 
 * @param node The pointer to the pointer to the node to be inserted into the queue
 * @param head The pointer to head of the queue (The *pointer* to the *pointer* to the first node of the queue)
 * @param tail The pointer to tail of the queue (The *pointer* to the *pointer* to the last node of the queue) 
 * 
 * @return the **error_status**: ERROR_QUEUE_FULL if the queue is full; else NO_ERROR
**/
error_status enqueue(Node** node, Node **head, Node **tail);


/**
 * @brief destroys the queue
 * 
 * deletes the entire queue from existence. The head (The *pointer* to the first node of the queue) and tail (The *pointer* to the last node of the queue) would be equal to NULL after the operation.
 * 
 * @param head The pointer to head of the queue (The *pointer* to the *pointer* to the first node of the queue)
 * @param tail The pointer to tail of the queue (The *pointer* to the *pointer* to the last node of the queue) 
 * 
 * @return the **error_status**: ERROR_QUEUE_EMPTY if the queue is empty; else NO_ERROR
**/
error_status destroy_queue(Node **head, Node **tail);

#endif