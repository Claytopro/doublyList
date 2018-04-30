/*
By:clayton provan
date:april 28th
linked list but points back to the previous link as well
*/
#include "ddlist.h"

int main(){
    struct listNode **list = calloc(sizeof(Node),6); 
    addToEnd(list,newNode("dick"));
    addToEnd(list,newNode("forest"));
    push(list,newNode("eat"));
    push(list,newNode("cock"));
    addToEnd(list,newNode("hop"));
    push(list,newNode("apple"));
    push(list,newNode("butter"));
    


    printLinkedList(*list);

    reverseOrder(list);
    printf("\nreversed\n");
    printLinkedList(*list);

    deleteList(list);

    return 0;
}


Node *newNode(char *string){
       
    struct listNode *new = malloc(sizeof(Node));
    new->data = string;
    new->prev = NULL;
    new->next = NULL;

    return new;
}

Node *pop(Node **list){
    struct listNode *temp = *list; 
    *list = (*list)->next;
    (*list)->prev = NULL;
    
    return temp;
}

void push(Node **list, Node *toAdd){
    toAdd->next = *list;
   /*ignores first input because it would have no memory
   to point from*/
    if(*list !=NULL){
    (*list)->prev = toAdd;
    }
    (*list) = toAdd;
}

void addToEnd(Node **list,Node *toAdd){
    Node *temp = *list;

    if((*list) == NULL){
        toAdd->next = *list;
        *list = toAdd;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = toAdd;
    toAdd->prev = temp;
}

void printLinkedList(Node *list){
   
        while(list != NULL){
        printf("%s \n",list->data);
        list = list->next;
    }

}
/*reverse how prev pointer nad next pointer*/
void reverseOrder(Node **list){
    Node *temp = NULL;
    Node *lastLink = NULL;

    while(*list){
        if((*list)->next == NULL){
            lastLink = (*list);
        }
        temp = (*list)->next;
        (*list)->next = (*list)->prev;
        (*list)->prev = temp;
  
        *list = (*list)->prev;      
    }
    *list = lastLink;
    
}

void deleteNode(Node **toDelete){

}

void deleteList(Node **list){
  Node *temp = NULL; 
    while( (*list) != NULL){
        temp = *list;
        *list = (*list)->next;
        free(temp);
       
    }
    free(list);
}
