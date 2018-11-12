#include "list.h"
#include "data.h"

int main()
{
    List * list = newList();

    insert(&list, newData(5), compareData);
    printList(list, printData);

    insert(&list, newData(10), compareData);
    printList(list, printData);

    insert(&list, newData(1), compareData);
    printList(list, printData);

    insert(&list, newData(3), compareData);
    printList(list, printData);

    insert(&list, newData(20), compareData);
    printList(list, printData);

    insert(&list, newData(25), compareData);
    printList(list, printData);

    return 0;
}