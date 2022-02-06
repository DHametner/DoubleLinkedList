//
// Created by Daniel on 06/02/2022.
//

template<class T>
DoubleLinkedList<T>::DoubleLinkedList()
        : m_elem(NULL),
          m_size(0)
{
}

template<class T>
bool DoubleLinkedList<T>::isEmpty()
{
    return m_size == 0;
}

template<class T>
bool DoubleLinkedList<T>::insert(T data)
{
    if (m_elem == NULL)
    {
        m_elem = new Node<T>();
        m_elem->value = data;

        m_size++;
        return true;
    }

    Node<T> *current;
    for (current = m_elem; current != NULL; current = current->next)
    {
        if (current->next == NULL)
        {
            current->next = new Node<T>();
            current->next->prev = current;
            current->next->value = data;

            m_size++;
            return true;
        }
    }
    return false;
}

template<class T>
bool DoubleLinkedList<T>::remove(T value)
{
    Node<T> *current;
    for (current = m_elem; current != NULL; current = current->next)
    {
        if (current->value == value)
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;

            delete current;
            m_size--;
            return true;
        }
    }
    return false;
}

template<class T>
void DoubleLinkedList<T>::clear()
{
    Node<T> *current;
    for (current = m_elem; current != NULL; current = current->next)
    {
        delete current->prev;
    }
    m_elem = NULL;
    m_size = 0;
}

template<class T>
Node<T> &DoubleLinkedList<T>::at(size_t index)
{
    size_t count = 0;

    Node<T> *current;
    for (current = m_elem; current != NULL; current = current->next)
    {
        if (count == index)
            return *current;
        count++;
    }
}

template<class T>
bool DoubleLinkedList<T>::contains(T value)
{
    Node<T> *current;
    for (current = m_elem; current != NULL; current = current->next)
    {
        if (current->value == value)
            return true;
    }
    return false;
}

template<class T>
size_t DoubleLinkedList<T>::size()
{
    return m_size;
}
