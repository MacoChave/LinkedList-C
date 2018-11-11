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

void printData (Data * data)
{
    printf(" Number: %d ", data->info);
}

#endif // DATA_H_INCLUDED