//
// Created by Daniel on 06/02/2022.
//

#include "list.h"

struct DoubleLinkedList* list_create()
{
    struct DoubleLinkedList* list = malloc(sizeof(struct DoubleLinkedList));

    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->size = 0;
    return list;
}

bool list_empty(struct DoubleLinkedList** list_ref)
{
    return *list_ref == NULL || (*list_ref)->head == NULL;
}

bool list_insert(struct DoubleLinkedList** list_ref, void *value)
{
    if (list_ref == NULL)
        return false;

    struct Node *new_node = malloc(sizeof(struct Node));

    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if ((*list_ref)->head == NULL)
    {
        (*list_ref)->head = new_node;
        (*list_ref)->size++;
        return true;
    }

    struct Node* current = (*list_ref)->head;
    while (current != NULL)
    {
        if (current->next == NULL)
        {
            current->next = new_node;
            new_node->prev = current;
            (*list_ref)->size++;

            return true;
        }
        current = current->next;
    }
    return false;
}

bool list_remove(struct DoubleLinkedList** list_ref, void *value, bool (*compare)(const void*, const void*))
{
    if (list_empty(list_ref) || value == NULL || compare == NULL)
        return false;

    struct Node* current = (*list_ref)->head;
    while (current != NULL)
    {
        if (compare(current->value, value) == true)
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            (*list_ref)->size--;
            free(current);

            return true;
        }
        current = current->next;
    }
    return false;
}

struct Node** list_at(struct DoubleLinkedList** list_ref, size_t index)
{
    if (list_empty(list_ref))
        return NULL;

    size_t count = 0;

    struct Node* current = (*list_ref)->head;
    while (current != NULL)
    {
        if (index == count)
            return &current;
        current = current->next;
        count++;
    }
    return NULL;
}

bool list_contains(struct DoubleLinkedList** list_ref, void *value, bool (*compare)(const void*, const void*))
{
    if (list_empty(list_ref) || value == NULL || compare == NULL)
        return false;

    struct Node* current = (*list_ref)->head;
    while (current != NULL)
    {
        if (compare(current->value, value) == true)
            return true;
        current = current->next;
    }
    return false;
}

void list_clear(struct DoubleLinkedList** list_ref)
{
    if (*list_ref == NULL)
        return;

    struct Node* current = (*list_ref)->head;
    while (current != NULL)
    {
        free(current->prev);
        current = current->next;
    }
    free((*list_ref));
    *list_ref = NULL;
}

size_t list_size(struct DoubleLinkedList** list_ref)
{
    if (list_empty(list_ref))
        return 0;
    return (*list_ref)->size;
}
