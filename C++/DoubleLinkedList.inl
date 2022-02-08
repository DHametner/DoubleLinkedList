//
// Created by Daniel on 06/02/2022.
//

template<class T>
DoubleLinkedList<T>::DoubleLinkedList()
        : m_head(NULL),
          m_size(0)
{
}

template<class T>
bool DoubleLinkedList<T>::isEmpty()
{
    return m_head == NULL;
}

template<class T>
void DoubleLinkedList<T>::insert(T value)
{
    Node<T> *newNode = new Node<T>;
    newNode->value = value;

    if (m_head == NULL)
    {
        m_head = newNode;
        m_size++;
    } else
    {
        Node<T> *current;
        for (current = m_head; current != NULL; current = current->next)
        {
            if (current->next == NULL)
            {
                current->next = newNode;
                current->next->prev = current;
                current->next->value = value;

                m_size++;
                break;
            }
        }
    }
}

template<class T>
bool DoubleLinkedList<T>::remove(T value)
{
    if (isEmpty())
        return false;

    Node<T> *current;
    for (current = m_head; current != NULL; current = current->next)
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
T DoubleLinkedList<T>::at(size_t index)
{
    T value = T();

    if (isEmpty())
        return value;

    size_t count = 0;

    Node<T> *current;
    for (current = m_head; current != NULL; current = current->next)
    {
        if (count == index)
        {
            value = current->value;
            break;
        }
        count++;
    }
    return value;
}

template<class T>
bool DoubleLinkedList<T>::contains(T value)
{
    if (isEmpty())
        return false;

    Node<T> *current;
    for (current = m_head; current != NULL; current = current->next)
    {
        if (current->value == value)
            return true;
    }
    return false;
}

template<class T>
void DoubleLinkedList<T>::clear()
{
    if (isEmpty())
        return;

    Node<T> *current;
    for (current = m_head; current != NULL; current = current->next)
    {
        delete current->prev;
    }
    m_head = NULL;
    m_size = 0;
}

template<class T>
size_t DoubleLinkedList<T>::size()
{
    return m_size;
}
