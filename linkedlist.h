#include <stdlib.h>
#include <stdio.h>

typedef struct node_s
{
    int data;
    struct node_s *next;
}Node;

typedef struct list_s
{
    Node *head;
}List;


List * listCtor();
Node * nodeCtor(int value);
int insertNode(List *list, Node *node, int index);
int removeNode(List *list, Node *node);
int removeNodeByIndex(List *list, int index);
int listLength(List *list);
Node * getNode(List *list, int index);
void printList(List *list);
int deleteList(List * list);
