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
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);
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
    Node<T> *cur = new Node<T>();
    Node<T> *pre = new Node<T>();
    int i = 0;
    if(root == NULL)
        return
    
    cur = root;

    while(cur != NULL)
    {
        if (cur->get_left() == NULL)
        {
            vec[i] = cur->get_data();
            cur = cur->get_right();
        }
        else
        {
            pre = cur->get_left();
            while(pre->get_right() != NULL && pre->get_right() != cur)
            {
                pre = pre->get_right();
            }

            if(pre->right ==NULL)
            {
                pre->set_right(cur);
                cur = cur->get_left();
            }
            else
            {
                pre->set_right(NULL);
                vec[i] = cur->get_data();
                cur = cur->get_right();
            }

        }
        i++;
    }
    return vec;
}


template<class T>
 std::vector<T> * BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;
    return vec;
}


template<class T>
 std::vector<T> * BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;

    return vec;
}

template<class T>
void BST<T>::insert(T new_data)
{
    Node<T> *newNode = new Node<T>(new_data);

    Node<T> *temp2 = new Node<T>();

    Node<T> *temp1 = root;

    if(root == NULL)
    {
        root = newNode;
    }
    else  
    {
        while (temp1 != 0)
        {
            temp2 = temp1;
            if(new_data < temp1->get_data())
            {
                temp1 = temp1->get_left();
            }
            else
            {
                temp1 = temp1->get_right();                
            }
        }

        if(new_data < temp2->get_data())
        {
            temp2->set_left(newNode);
        }
        else
        {
            temp2->set_right(newNode);
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
    Node<T> *suc = new Node<T>();
    int sucData = 0;
    Node<T> *cur = root;

    while(cur != NULL)
    {   
        if(cur->get_data() == val)
        {
            if(!cur->get_left() && !cur->get_right())
            {
                if(!par)
                {
                    root = NULL;
                }
                else if (par->get_left() == cur)
                {
                    par->set_left(NULL);
                }
                else
                {
                    par->set_right(NULL);
                }
            }
            
            else if(cur->get_left() && !cur->get_right())
            {
                if(!par)
                {
                    root = cur->get_left();
                }
                else if (par->get_left() == cur)
                {
                    par->set_left(cur->get_left());
                }
                else
                {
                    par->set_right(cur->get_left());
                }
            }
            
            else if(!cur->get_left() && cur->get_right())
            {
                if(!par)
                {
                    root = cur->get_right();
                }
                else if (par->get_left() == cur)
                {
                    par->set_left(cur->get_right());
                }
                else
                {
                    par->set_right(cur->get_right());
                }
            }            
            else
            {
                suc = cur->get_right();
                while(suc->get_left() != NULL)
                {
                    suc = suc->get_left();
                }
                //sucData = suc->get_data();
                remove(sucData);
                cur->set_data(sucData);
            }
            return;
        }
        else if(cur->get_data() < val)
        {
            par = cur;
            cur = cur->get_right();
        }
        else
        {
            par = cur;
            cur = cur->get_left();
        }
    }
    return;
}



template<class T>
int BST<T>::get_size()
{

}