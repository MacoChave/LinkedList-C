#include "list.h"
#include "data.h"

int main()
{
    List * list = newList();

    insert(&list, newData(5));
    printList(list);

    insert(&list, newData(10));
    printList(list);

    insert(&list, newData(1));
    printList(list);

    insert(&list, newData(3));
    printList(list);

    insert(&list, newData(20));
    printList(list);

    insert(&list, newData(25));
    printList(list);

    return 0;
}