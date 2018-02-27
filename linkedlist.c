#include "linkedlist.h"

List * listCtor()
{
    List *list = (List *)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

Node * nodeCtor(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->data = value;
    return node;
}

int insertNode(List *list, Node *node, int index)
{
    if(index == 0)
    {
        node->next = list->head;
        list->head = node;
    }
    else
    {
        if(index > (listLength(list)))
            return -1;
        Node *prev = getNode(list, index - 1);
        node->next = prev->next;
        prev->next = node;

    }
    return 0;
}

int removeNode(List *list, Node *node)
{
    int indx = 0;
    Node *temp = NULL;
    for(temp = list->head; NULL != temp; temp = temp->next)
    {
        if(temp == node)
        {
            Node *prev = getNode(list, indx - 1);
            prev->next = node->next;
            free(node);
            break;
        }
        ++indx;
    }
    return 0;
}

int removeNodeByIndex(List *list, int index)
{
    if(index > listLength(list))
        return -1;

    if(getNode(list, index) == NULL)
        return -1;
        
    if(index == 0)
    {
        list->head = list->head->next;
        free(list->head);

        return 0;
    }

    Node *prev = getNode(list, index - 1);
    Node *to_remove = prev->next;

    prev->next = to_remove->next;
    free(to_remove);

    return 0;
}

int listLength(List *list)
{
    int len = 0;
    Node *temp = NULL;
    for(temp = list->head; NULL != temp; temp = temp->next)
    {
        ++len;
    }
    return len;
}

Node * getNode(List *list, int index)
{
    if(index > listLength(list))
        return NULL;

    Node *temp = list->head;
    for(int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }

    return temp;
}

void printList(List *list)
{
    Node *temp = NULL;
    for(temp = list->head; NULL != temp; temp = temp->next)
    {
        printf("[%d]->", temp->data);
    }
    printf("[NULL]\n");
}

int deleteList(List * list)
{

    Node * freeme = list->head;
    Node * next = freeme;
    while(NULL != freeme)
    {
        next = freeme->next;
        free(freeme);
        freeme = next;
    }
    free(list);

    return 0;
}
