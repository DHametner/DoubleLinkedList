#include <stdio.h>

#include "list.h"
#include "compare.h"

void test_with_num(struct DoubleLinkedList** list_ref)
{
    printf("TESTING(with numbers):\n");
    printf("Is empty: %s\n", list_empty(list_ref) ? "true" : "false");

    list_insert(list_ref, (int*) 1);
    list_insert(list_ref, (int*) 2);
    list_insert(list_ref, (int*) 3);
    list_insert(list_ref, (int*) 4);

    printf("List size: %d \n", list_size(list_ref));
    printf("Is empty: %s\n", list_empty(list_ref) ? "true" : "false");

    printf("Contains 2: %s \n", list_contains(list_ref, (void *) 2, &num_compare) ? "true" : "false");
    printf("Contains 5: %s \n", list_contains(list_ref, (void *) 5, &num_compare) ? "true" : "false");

    printf("Remove 3: %s \n", list_remove(list_ref, (void *) 3, &num_compare) ? "true" : "false");
    printf("Remove 5: %s \n", list_remove(list_ref, (void *) 5, &num_compare) ? "true" : "false");
    printf("Contains 3: %s \n", list_contains(list_ref, (void *) 3, &num_compare) ? "true" : "false");

    for (size_t i = 0; i < list_size(list_ref); i++)
    {
        printf("%d ", (int) (*list_at(list_ref, i))->value);
    }
    printf("\n");
    printf("END TESTING(with numbers) ...\n");
}

void test_with_str(struct DoubleLinkedList** list_ref)
{
    printf("TESTING(with strings):\n");
    printf("Is empty: %s\n", list_empty(list_ref) ? "true" : "false");

    list_insert(list_ref, "Apple");
    list_insert(list_ref, "Microsoft");
    list_insert(list_ref, "IBM");
    list_insert(list_ref, "Nokia");

    printf("List size: %d \n", list_size(list_ref));
    printf("Is empty: %s\n", list_empty(list_ref) ? "true" : "false");

    printf("Contains Apple: %s \n", list_contains(list_ref, "Apple", &str_compare) ? "true" : "false");
    printf("Contains Samsung: %s \n", list_contains(list_ref, "Samsung", &str_compare) ? "true" : "false");

    printf("Remove IBM: %s \n", list_remove(list_ref, "IBM", &str_compare) ? "true" : "false");
    printf("Remove Samsung: %s \n", list_remove(list_ref, "Samsung", &str_compare) ? "true" : "false");
    printf("Contains IBM: %s \n", list_contains(list_ref, "IBM", &str_compare) ? "true" : "false");

    for (size_t i = 0; i < list_size(list_ref); i++)
    {
        printf("%s ", (char*) (*list_at(list_ref, i))->value);
    }
    printf("\n");
    printf("END TESTING(with strings): ...\n");
}

int main()
{
    struct DoubleLinkedList *list = NULL;

    list = list_create();
    test_with_num(&list);
    list_clear(&list);

    list = list_create();
    test_with_str(&list);
    list_clear(&list);

    return 0;
}