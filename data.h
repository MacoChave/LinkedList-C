#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Data Data;

struct Data
{
    int info;
};

Data * newData (int info)
{
    Data * data = (Data *)malloc(sizeof(Data));
    data->info = info;

    return data;
}

void printData (void * data)
{
    printf(" Number: %d ", ((Data *)data)->info);
}

int compareData (void * d1, void * d2)
{
    if (((Data *)d1)->info > ((Data *)d2)->info)
        return 1;
    if (((Data *)d1)->info < ((Data *)d2)->info)
        return -1;
    return 0;
}

#endif // DATA_H_INCLUDED