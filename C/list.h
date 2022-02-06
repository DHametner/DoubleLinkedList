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

bool list_insert(struct Node**, void*);

bool list_remove(struct Node**, void*);

struct Node** list_at(struct Node**, size_t index);

bool list_contains(struct Node**, void*);

void list_clear(struct Node**);

size_t list_size(struct Node**);