//
// Created by Daniel on 06/02/2022.
//

#pragma once

#include "IList.hpp"

template<class T>
class DoubleLinkedList : public IList<T>
{
public:
    DoubleLinkedList();

    DoubleLinkedList(const DoubleLinkedList &) = default;

    virtual ~DoubleLinkedList() = default;

public:
    bool isEmpty() override;

    void insert(T value) override;

    bool remove(T value) override;

    T at(size_t) override;

    bool contains(T) override;

    void clear() override;

    size_t size() override;

private:
    Node<T>* m_head;
    size_t   m_size;
};

#include "DoubleLinkedList.inl"
