#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <cstddef>
#include <string>

template<typename T>
class BinaryTree
{
public:
    BinaryTree() = default;
    BinaryTree(T data) : m_size(1), m_root(new Leaf(data)) {}
    ~BinaryTree()
    {
        clear(m_root);
        delete m_root;
    }

    bool is_empty() const { return m_size == 0; }
    std::size_t size() const { return m_size; }

    void insert(T data);
    void print(const std::string& delim = " ") const;
    void clear();
    // void erase(T data);

private:
    enum class Direction { LEFT, RIGHT };

    struct Leaf
    {
        T data = T();
        Leaf* parent { nullptr };
        Leaf* left { nullptr };
        Leaf* right { nullptr };
    };

    std::size_t m_size { 0 };
    Leaf* m_root { nullptr };
    bool not_cleaned_yet { true };

    void insert(Leaf* leaf, T data);
    void print(Leaf* leaf, const std::string& delim) const;

    void clear(Leaf* leaf);
};

template<typename T>
void BinaryTree<T>::insert(Leaf* leaf, T data)
{
    if (leaf)
    {
        Direction direction = Direction::LEFT;
        Leaf* parent = leaf;
        while (leaf)
        {
            parent = leaf;
            if (data < leaf->data)
            {
                leaf = leaf->left;
                direction = Direction::LEFT;
            }
            else
            {
                leaf = leaf->right;
                direction = Direction::RIGHT;
            } 
        }

        leaf = new Leaf(data, parent);

        if (direction == Direction::LEFT)
        {
            parent->left = leaf;
        }
        else
        {
            parent->right = leaf;
        }
    }
    else
    {
        m_root = new Leaf(data);
    }
    m_size +=1;
}

template<typename T>
void BinaryTree<T>::insert(T data)
{
    insert(m_root, data);
    not_cleaned_yet = true; 
}

template<typename T>
void BinaryTree<T>::print(Leaf* leaf, const std::string& delim) const
{
    if (leaf)
    {
        print(leaf->left, delim);
        std::cout << leaf->data << delim;
        print(leaf->right, delim);
    }
}

template<typename T>
void BinaryTree<T>::print(const std::string& delim) const
{ 
    if (m_root)
    {
        print(m_root, delim);
    }
    else
    {
        std::cout << "There is no elements to display. The tree is empty.";
    }
    std::cout << std::endl << std::endl;
}

template<typename T>
void BinaryTree<T>::clear(Leaf* leaf)
{
    if (leaf)
    {
        clear(leaf->left);
        clear(leaf->right);
        if (leaf != m_root)
        {
            delete leaf;            
        }
        else
        {
            m_size = 0;
            m_root->data = T();
            m_root->left = nullptr;
            m_root->right = nullptr;
            m_root = nullptr;
        }
    }
}

template<typename T>
void BinaryTree<T>::clear()
{
    if (not_cleaned_yet)
    {
        clear(m_root);
        not_cleaned_yet = false;        
    }
}

// template<typename T>
// void BinaryTree<T>::erase(T data)
// {
//     //TODO
// }

#endif
