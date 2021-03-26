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
    LinkedList() : m_size(0), m_head(nullptr), m_tail(nullptr) {}
    LinkedList(T data) : m_size(1), m_head(new Node(data)), m_tail(m_head) {}
    ~LinkedList();

    void clear();
    void pop_back();
    void pop_front();
    void push_back(T data);
    void push_front(T data);
    bool is_empty() const { return m_size == 0; }
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
        Node* prev;
        Node(T data_ = T(), Node* next_ = nullptr, Node* prev_ = nullptr) : data(data_), next(next_), prev(prev_) {}
    };

    std::size_t m_size;
    Node* m_head;
    Node* m_tail;
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
void LinkedList<T>::pop_back()
{
    if (m_size == 0)
    {
        return;
    }
    else if (m_size == 1)
    {
        m_tail->next = nullptr;
        m_tail->prev = nullptr;
        delete m_tail;
    }
    else
    {
        auto former_tail = m_tail;
        m_tail = m_tail->prev;
        m_tail->next = nullptr;
        delete former_tail;        
    }
    --m_size;
}

template<typename T>
void LinkedList<T>::pop_front()
{
    if (m_size == 0)
    {
        return;
    }
    else if (m_size == 1)
    {
        m_head->next = nullptr;
        m_head->prev = nullptr;
        delete m_head;
    }
    else
    {
        auto former_head = m_head;
        m_head = m_head->next;
        m_head->prev = nullptr;
        delete former_head;      
    }
    --m_size;
}

template<typename T>
void LinkedList<T>::push_back(T data)
{
    if (is_empty())
    {
        m_head = new Node(data);
        m_tail = m_head;
    }
    else
    {
        m_tail->next = new Node(data, nullptr, m_tail);
        m_tail = m_tail->next;
    }

    m_size += 1;
}

template<typename T>
void LinkedList<T>::push_front(T data)
{
    if (is_empty())
    {
        m_head = new Node(data);
        m_tail = m_head;
    }
    else
    {
        m_head->prev = new Node(data, m_head, nullptr);
        m_head = m_head->prev;
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
    Node* current;
    if (bool from_head_to_tail = index <= m_size/2; from_head_to_tail)
    {
        current = m_head;
        for (std::size_t counter = 0; current != nullptr; ++counter)
        {
            if (counter == index)
            {
                break;
            }
            current = current->next;

        }
    }
    else
    {
        current = m_tail;
        for (std::size_t counter = m_size - 1; current != nullptr; --counter)
        {
            if (counter == index)
            {
                break;
            }
            current = current->prev;

        }
    }

    return current->data;
}

template<typename T>
const T& LinkedList<T>::operator[](const std::size_t index) const
{
    Node* current;
    if (bool from_head_to_tail = index <= m_size/2; from_head_to_tail)
    {
        current = m_head;
        for (std::size_t counter = 0; current != nullptr; ++counter)
        {
            if (counter == index)
            {
                break;
            }
            current = current->next;

        }
    }
    else
    {
        current = m_tail;
        for (std::size_t counter = m_size - 1; current != nullptr; --counter)
        {
            if (counter == index)
            {
                break;
            }
            current = current->prev;

        }
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
