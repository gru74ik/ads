#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstddef>
#include <algorithm>
#include <string>

template<typename T>
class LinkedList
{
public:
    LinkedList() : m_size(0), m_head(nullptr) {}
    LinkedList(T data) : m_size(1), m_head(new Node(data)) {}
    ~LinkedList();

    void clear();
    void pop_front();
    void push_back(T data);
    bool is_empty() const { return m_head == nullptr; }
    std::size_t size() const { return m_size; }
    void print(const std::string& delim = ", ") const;

    T& operator[](const std::size_t index);
    const T& operator[](const std::size_t index) const;
    LinkedList<T>& operator=(LinkedList<T> rhs);

private:
    struct Node
    {
        T data;
        Node* next;
        Node(T data_ = T(), Node* next_ = nullptr) : data(data_), next(next_) {}
    };

    std::size_t m_size;
    Node* m_head;
};

template<typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template<typename T>
void LinkedList<T>::clear()
{
    while (!is_empty())
    {
        pop_front();
    }
}

template<typename T>
void LinkedList<T>::pop_front()
{
    auto previous_head = m_head;
    m_head = m_head->next;
    delete previous_head;
    --m_size;
}

template<typename T>
void LinkedList<T>::push_back(T data)
{
    if (is_empty())
    {
        m_head = new Node(data);
    }
    else
    {
        Node* current = m_head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new Node(data);
    }

    m_size += 1;
}

template<typename T>
void LinkedList<T>::print(const std::string& delim) const
{
    if (!is_empty())
    {
        for (Node* current = m_head; current != nullptr; current = current->next)
        {
            std::cout << current->data;
            if (current->next != nullptr)
            {
                std::cout << delim;
            }
        }
    }
    else
    {
        std::cout << "The list is empty.";
    }
    std::cout << "\n\n";
}

template<typename T>
T& LinkedList<T>::operator[](const std::size_t index)
{
    Node* current = m_head;
    for (std::size_t counter = 0; current != nullptr; ++counter)
    {
        if (counter == index)
        {
            break;
        }
        current = current->next;

    }
    return current->data;
}

template<typename T>
const T& LinkedList<T>::operator[](const std::size_t index) const
{
    Node* current = m_head;
    for (std::size_t counter = 0; current != nullptr; ++counter)
    {
        if (counter == index)
        {
            break;
        }
        current = current->next;

    }
    return current->data;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> rhs)
{
    std::swap(rhs.m_head, this->m_head);
    return *this;
}

#endif //LINKEDLIST_H
