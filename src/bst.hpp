#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include "node.hpp"

template<class T>
class BST{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);

    Node<T> *remove_helper(Node<T> *node, T);

    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);

    std::vector<T> *inorder_helper(Node<T> *node, std::vector<T> *vect);

    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);

    std::vector<T> *postorder_helper(Node<T> *node, std::vector<T> *vect);

    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);

    std::vector<T> *preorder_helper(Node<T> *node, std::vector<T> *vect);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);

    int get_size_helper(Node<T> *node);
private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;
};

template<class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template<class T>
BST<T>::~BST()
{
    root = NULL;
    while(root != NULL)
    {
        remove(root->get_data());
    }
}

template<class T>
 std::vector<T> * BST<T>::inorder()
{
    std::vector<T> *vec = new std::vector<T>;

    Node<T> *cur = root;
        
    vec = inorder_helper(cur, vec);
 
    return vec;
}

// Recursive inorder helper
template<class T>
 std::vector<T> * BST<T>::inorder_helper(Node<T> *node, std::vector<T> *vect)
 {
    if(node != NULL)
    {
        inorder_helper(node->get_left(), vect);

        vect->push_back(node->get_data());

        inorder_helper(node->get_right(), vect);
    }  
    return vect;

 }

template<class T>
 std::vector<T> * BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;

    Node<T> *cur = root;
        
    vec = preorder_helper(cur, vec);

    return vec;
}

// Recursive preorder helper
template<class T>
 std::vector<T> * BST<T>::preorder_helper(Node<T> *node, std::vector<T> *vect)
 {
    if(node != NULL)
    {
        vect->push_back(node->get_data());

        preorder_helper(node->get_left(), vect);

        preorder_helper(node->get_right(), vect);
    }
    return vect;
 }


template<class T>
 std::vector<T> * BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;
   
    Node<T> *cur = root;
        
    vec = postorder_helper(cur, vec);

    return vec;
}

// Recursive postorder helper
template<class T>
 std::vector<T> * BST<T>::postorder_helper(Node<T> *node, std::vector<T> *vect)
 {
    if(node != NULL)
    {
        postorder_helper(node->get_left(), vect);

        postorder_helper(node->get_right(), vect);

        vect->push_back(node->get_data());
    }
    return vect;

 }

template<class T>
void BST<T>::insert(T new_data)
{
    Node<T> *newNode = new Node<T>(new_data);


    if(root == NULL)
    {
        root = newNode;
    }
    else  
    {
        Node<T> *cur = root;
        while (cur != NULL)
        {
            if(new_data < cur->get_data())
            {
                if(cur->get_left() == NULL)
                {
                    cur->set_left(newNode);
                    cur = NULL;
                }
                else
                {
                    cur = cur->get_left();
                }
            }
            else
            {
                if(cur->get_right() == NULL)
                {
                    cur->set_right(newNode);
                    cur = NULL; 
                }
                else
                    cur = cur->get_right();              
            }
        }
    }
    return;    
}


template<class T>
Node<T> *BST<T>::search(T val)
{
    Node<T> *cur = root;

    while (cur != NULL)
    {
        if(val == cur->get_data())
        {
            return cur;
        }
        else if (val < cur->get_data())
        {
            cur = cur->get_left();
        }
        else
        {
            cur = cur->get_right();
        }
    }
    return NULL;
}



template<class T>
void BST<T>::remove(T val)
{
    Node<T> *par = new Node<T>();

    int sucData;
    Node<T> *cur = root;

    root = remove_helper(cur, val);

    return;
}

// Recursive remove helper
template<class T>
Node<T> *BST<T>::remove_helper(Node<T> *node, T val)
{
    if(node == NULL)
    {
        return root;
    }
    if(val < node->get_data())
    {
        node->set_left(remove_helper(node->get_left(), val));
    }
    else if(val > node->get_data())
    {
        node->set_right(remove_helper(node->get_right(), val));
    }
    else
    {
        if(node->get_left() == NULL)
        {
            Node<T> *temp = node->get_right();
            return temp;
        }
        else if(node->get_right() == NULL)
        {
            Node<T> *temp = node->get_left();
            return temp;
        }

        Node<T> *suc = node->get_right();
        while(suc && suc->get_left() != NULL)
        {
            suc = suc->get_left();
        }
        int data = suc->get_data();

        node->set_data(data);

        node->set_right(remove_helper(node->get_right(), data));

    }

    return node;
}


template<class T>
int BST<T>::get_size()
{
    int count = 0;
    if (root != NULL)
    {
        count = get_size_helper(root);
    }
    return count;
}

// Recursive get size helper
template<class T>
int BST<T>::get_size_helper(Node<T> *node)
{
    int count = 1;
    if(node->get_left() != NULL)
    {
        count += get_size_helper(node->get_left());
    }
    if(node->get_right() != NULL)
    {
        count += get_size_helper(node->get_left());
    }
    return count;
}