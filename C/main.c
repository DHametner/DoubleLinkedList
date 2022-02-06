#include <stdio.h>
#include "list.h"

int main()
{
    struct Node* list = NULL;

    list_insert(&list, "One");
    list_insert(&list, "Two");
    list_insert(&list, "Three");
    list_insert(&list, "Four");

    printf("list size: %d \n",list_size(&list));

    printf("Find Three: %s \n",list_contains(&list, "Three") ? "true" : "false");
    printf("Find Five: %s \n",list_contains(&list, "Five") ? "true" : "false");

    printf("Remove Three: %s \n",list_remove(&list, "Three") ? "true" : "false");
    printf("Remove Five: %s \n",list_remove(&list, "Five") ? "true" : "false");
    printf("Find Three: %s \n",list_contains(&list, "Three") ? "true" : "false");

    for(size_t i = 0; i < list_size(&list); i++)
    {
        printf("%s ", (char*)(*list_at(&list,i))->value);
    }
    printf("\n");

    list_clear(&list);
    return 0;
}