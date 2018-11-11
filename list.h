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

Node * newNode (Data * data)
{
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->preview = NULL;

    return node;
}

void push_front (List ** list, Data * data)
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

void push_back (List ** list, Data * data)
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

void insert (List ** list, Data * data)
{
    if ((*list)->size > 0)
    {
        if ((*list)->first->data->info > data->info)
            push_front(list, data);
        else if ((*list)->first->data->info < data->info)
            push_back(list, data);
        else
        {
            Node * current = (*list)->first->next;
            while (current != NULL)
            {
                if (current->data->info > data->info)
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

void printList (List * list)
{
    Node * current = list->first;
    while (current != NULL)
    {
        printData(current->data);
        current = current->next;
    }
    printf("\n");
}

#endif // LIST_H_INCLUDED