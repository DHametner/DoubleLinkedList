//
// Created by Daniel on 06/02/2022.
//

#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node
{
    void*        value;
    struct Node* next;
    struct Node* prev;
};

struct DoubleLinkedList
{
    struct Node* head;
    size_t       size;
};

struct DoubleLinkedList* list_create();

bool list_empty(struct DoubleLinkedList**);

bool list_insert(struct DoubleLinkedList**, void*);

bool list_remove(struct DoubleLinkedList**, void*, bool (*)(const void*, const void*));

void* list_at(struct DoubleLinkedList**, size_t index);

bool list_contains(struct DoubleLinkedList**, void*, bool (*)(const void*, const void*));

void list_clear(struct DoubleLinkedList**);

size_t list_size(struct DoubleLinkedList**);