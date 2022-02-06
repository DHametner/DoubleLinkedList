//
// Created by Daniel on 06/02/2022.
//

#include "list.h"

bool list_insert(struct Node** head_ref, void* value)
{
    if (value == NULL)
        return false;

    struct Node *new_node = malloc(sizeof(struct Node));

    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head_ref == NULL)
    {
        (*head_ref) = new_node;
        return true;
    }

    struct Node *current = *head_ref;
    while (current != NULL)
    {
        if (current->next == NULL)
        {
            current->next = new_node;
            new_node->prev = current;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool list_remove(struct Node** head_ref, void* value)
{
    if(value == NULL)
        return false;

    struct Node *current = *head_ref;
    while (current != NULL)
    {
        if(strcmp(current->value, value) == 0)
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);

            return true;
        }
        current = current->next;
    }
    return false;
}

struct Node** list_at(struct Node** head_ref, size_t index)
{
    if (*head_ref == NULL)
        return NULL;

    size_t count = 0;

    struct Node *current = *head_ref;
    while (current != NULL)
    {
        if (index == count)
            return &current;
        current = current->next;
        count++;
    }
 return NULL;
}

bool list_contains(struct Node** head_ref, void* value)
{
    if (*head_ref == NULL || value == NULL)
        return false;

    struct Node *current = *head_ref;
    while (current != NULL)
    {

        if(strcmp(current->value,value) == 0)
            return true;
        current = current->next;
    }
    return false;
}

void list_clear(struct Node** head_ref)
{
    if (*head_ref == NULL)
        return;

    struct Node *current = *head_ref;
    while (current != NULL)
    {
        free(current->prev);
        current = current->next;
    }
}

size_t list_size(struct Node** head_ref)
{
    size_t size = 0;

    if (*head_ref == NULL)
        return size;

    struct Node *current = *head_ref;
    while (current != NULL)
    {
        size++;
        current = current->next;
    }
    return size;
}
