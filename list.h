#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

typedef struct Node Node;
typedef struct List List;

struct Node
{
    Data * data;
    Node * next;
    Node * preview;
};

struct List
{
    int size;
    Node * first;
    Node * last;
};

List * newList ()
{
    List * list = (List *)malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    return list;
}

Node * newNode (void * data)
{
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->preview = NULL;

    return node;
}

void push_front (List ** list, void * data)
{
    if ((*list)->size > 0)
    {
        Node * node = newNode(data);
        node->next = (*list)->first;
        (*list)->first->preview = node;
        (*list)->first = node;
    }
    else
        (*list)->first = (*list)->last = newNode(data);
    (*list)->size++;
}

void push_back (List ** list, void * data)
{
    if ((*list)->size > 0)
    {
        Node * node = newNode(data);
        node->preview = (*list)->last;
        (*list)->last->next = node;
        (*list)->last = node;
    }
    else
        (*list)->first->next = (*list)->last = newNode(data);
    (*list)->size++;   
}

/**
 * Definir función int (*compare[TIPO])(void *, void*)
*/
void insert (List ** list, void * data, int (*compare)(void *, void *))
{
    if ((*list)->size > 0)
    {
        if (compare((*list)->first->data, data) > 0)
            push_front(list, data);
        else if (compare((*list)->first->data, data) < 0)
            push_back(list, data);
        else
        {
            Node * current = (*list)->first->next;
            while (current != NULL)
            {
                if (compare(current->data, data) > 0)
                {
                    Node * node = newNode(data);
                    current->preview->next = node;
                    node->preview = current->preview;
                    node->next = current;
                    current->preview = node;

                    (*list)->size++;
                    return;
                }
                else{
                    current = current->next;
                }
            }
        }
    }
    else
        push_front(list, data);
}

void printList (List * list, void (*fptr)(void *))
{
    Node * current = list->first;
    while (current != NULL)
    {
        (*fptr)(current->data);
        current = current->next;
    }
    printf("\n");
}

#endif // LIST_H_INCLUDED