//
// Created by Daniel on 06/02/2022.
//

#pragma once

#include <cstddef>
#include <cstdlib>
#include <string>

template<class T>
struct Node
{
    T        value;
    Node<T>* next = NULL;
    Node<T>* prev = NULL;
};

template<class T>
class IList
{
public:
    virtual bool isEmpty()   = 0;

    virtual void insert(T)   = 0;

    virtual bool remove(T)   = 0;

    virtual T at(size_t)     = 0;

    virtual bool contains(T) = 0;

    virtual void clear()     = 0;

    virtual size_t size()    = 0;
};
