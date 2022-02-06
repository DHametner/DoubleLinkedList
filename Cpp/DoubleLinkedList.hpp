//
// Created by Daniel on 06/02/2022.
//

#pragma once

#include "IList.hpp"

template<class T>
class DoubleLinkedList : public IList<T>
{
private:
    Node<T>* m_elem;
    size_t   m_size;

public:
    DoubleLinkedList();

    DoubleLinkedList(const DoubleLinkedList &) = default;

    virtual ~DoubleLinkedList() = default;

public:
    bool isEmpty() override;

    bool insert(T data) override;

    bool remove(T value) override;

    void clear() override;

    Node<T>& at(size_t) override;

    bool contains(T) override;

    size_t size() override;
};

#include "DoubleLinkedList.inl"
