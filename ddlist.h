#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*****
* Self-defined Data Structures
*****/

/* The listNode data type for storing entries in a linked list */

typedef struct listNode Node;
struct listNode {
    char *data;
    Node *next;
    Node *prev;
};


/*****
* Function Prototypes for linkedList.c
*****/


/***** Mandatory Functions *****/


/* Mandatory: Frees all allocated memory associated with the list pointers iteratively */
void deleteList(Node **list);

/* Mandatory: Frees all allocated memory associated with a single node */
void deleteNode(Node **toDelete);

/* Mandatory: Allocates memory for a new string and returns a pointer to the memory */
Node *newNode(char *string);

/* Mandatory: Removes a node from the front of a list and returns a pointer to said node */
Node *pop(Node **list);

/* Mandatory: Adds a node to the front of a list */
void push(Node **list, Node *toAdd);

/*add to tail*/
void addToEnd(Node **list,Node *toAdd);

/* Mandatory: Return a list of pointers in order */
void reverseOrder(Node **list);

/* Optional: Prints an entire linked list. Nodes are printed from first to last. */
void printLinkedList(Node *list);
