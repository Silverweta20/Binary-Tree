//
// Created by LENOVO on 20/03/2026.
//

#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <iostream>
using namespace std;


template <class T>
class Tree {
    protected:
    Node<T>* root;
    public:
    Tree();
    Tree(T& val);
    ~Tree();
    bool empty();
    Node<T>* getRoot();
    void setRoot(Node<T>* root);
    bool insertNode(T& val);
    bool deleteNode(T& val);
    bool search(T& n);
    unsigned int depth();
    unsigned int wide();
    void preOrder();
    void inOrder();
    void postOrder();
    void levelOrder();

    private:
    bool insertNode(T& val, Node<T>* node);
    bool search(T& n, Node<T>* node);
    unsigned int depth(Node<T>* node);
    bool deleteNode(T& val, Node<T>* node, Node<T>* parent);
    unsigned int wide(Node<T>* node);
    void preOrder(Node<T>* node);
    void postOrder(Node<T>* node);
    void inOrder(Node<T>* node);
    void levelOrder(Node<T>* node);

};

using namespace std;


template <class T>
Tree<T>::Tree(){
    this->root = NULL;
}

template <class T>
Tree<T>::~Tree() {
    delete root;
}

template<class T>
Tree<T>::Tree(T &val) {
    root = new Node<T>(val);
}


template <class T>
bool Tree<T>::empty() {
    if(nullptr == root->getLeftNode() && nullptr == root->getRigtNode()) {
        return true;
    }
    return false;
}

template <class T>
Node<T>* Tree<T>::getRoot() {
    return root;
}

template <class T>
void Tree<T>::setRoot(Node<T>* nroot) {
    this->root = nroot;
}

/*
 Inserta el valor 'val' como hijo del nodo que contiene el valor 'father'. Retorna true si se pudo insertar, false en caso contrario.
 */
template <class T>
bool Tree<T>::insertNode(T& val) {
    if (root == nullptr) {
        root = new Node<T>(val);
        return true;
    }
    return insertNode(val, root);
}

template <class T>
bool Tree<T>::insertNode(T& val, Node<T>* node) {
    if(nullptr == node) return false;
    if (node->get_value() < val) {
        if (!node->isRightEmpty()) {
            return insertNode(val, node->getRightNode());
        }else {
            auto* newNode = new Node<T>(val);
            node->setRightNode(newNode);
            return true;
        }
    }
    else if (node->get_value() > val) {
        if (!node->isLeftEmpty()) {
            return insertNode(val, node->getLeftNode());
        }else {
            Node<T>* newNode = new Node<T>(val);
            node->setLeftNode(newNode);
            return true;
        }
    }
    return false;
}

template <class T>
bool Tree<T>::deleteNode(T& val) {
    if (root == nullptr) return false;
    return deleteNode(val, root, nullptr);
}

template <class T>
bool Tree<T>::deleteNode(T& val, Node<T>* node, Node<T>* parent){
    if (node == nullptr) return false;
    if (val < node->get_value()) {
        return deleteNode(val, node->getLeftNode(), node);
    } else if (val > node->get_value()) {
        return deleteNode(val, node->getRigtNode(), node);
    }else {
        if (node->isLeftEmpty() && node->isRightEmpty()) {
            if (parent == nullptr) {
                root = nullptr;
            } else if (parent->getLeftNode()->get_value() == node->get_value()) {
                parent->setLeftNode(nullptr);
            } else {
                parent->setRightNode(nullptr);
            }
            delete node;
        } else if (node->isLeftEmpty()) {
            Node<T>* temp = node->getRigtNode();
            if (parent == nullptr) {
                root = temp;
            } else if (parent->getLeftNode()->get_value() == node->get_value()) {
                parent->setLeftNode(temp);
            } else {
                parent->setRightNode(temp);
            }
            delete node;
        } else if (node->isRightEmpty()) {
            Node<T>* temp = node->getLeftNode();
            if (parent == nullptr) {
                root = temp;
            } else if (parent->getLeftNode() == node) {
                parent->setLeftNode(temp);
            } else {
                parent->setRightNode(temp);
            }
            delete node;
        } else {
            Node<T>* successorParent = node;
            Node<T>* successor = node->getRigtNode();
            while (!successor->isLeftEmpty()) {
                successorParent = successor;
                successor = successor->getLeftNode();
            }
            node->set_value(successor->get_value());
            return deleteNode(successor->get_value(), successor, successorParent);
        }
    }

    return false;
}

template <class T>
bool Tree<T>::search(T& n) {
    if (root == nullptr) return false;
    return search(n, root);
}

template <class T>
bool Tree<T>::search(T& n,Node<T>* node) {
   if(node == nullptr) return false;
    if(node->get_value() == n) return true;
    if (n < node->get_value()) {
        return search(n, node->getLeftNode());
    } else {
        return search(n, node->getRigtNode());
    }
}

template <class T>
unsigned int Tree<T>::depth() {
    if (root == nullptr) return -1; // Check if the tree is empty
    if (this->empty()) return 0;
    return depth(root);
}

template <class T>
unsigned int Tree<T>::depth(Node<T>* node) {
    if (node->isLeftEmpty()&&node->isRightEmpty()) return 0;
    unsigned int max = 0;
    unsigned int d = 0,i = 0;
    if (!node -> isLeftEmpty()) {
        i = depth(node -> getLeftNode());
    }
    if (!node -> isRightEmpty()) {
        d = depth(node -> getRightNode());
    }
    if (i > max) max = i;
    if (d > max) max = d;
    return max + 1;
}

/*
 Retorna el ancho del arbol.
 */
template <class T>
unsigned int Tree<T>::wide() {
    if (root == nullptr) return 0;
    return wide(root);
}

template <class T>
unsigned int Tree<T>::wide(Node<T>* node) {
    unsigned int maxWide = 0;

    return maxWide;
}
template <class T>
void Tree<T>:: preOrder() {
    if (root == nullptr) return;
    preOrder(root);
    }
template <class T>
void Tree<T>:: preOrder(Node<T>* node) {
    if (node == nullptr) return;
    cout << node->get_value() << endl;
    preOrder(node->getLeftNode());
    preOrder(node->getRightNode());
}
template <class T>
void Tree<T>::inOrder() {
    if (root == nullptr) return;
    inOrder(root);
}

template <class T>
void Tree<T>::inOrder(Node<T>* node) {
    if (node == nullptr) return;
    inOrder(node->getLeftNode());
    cout << node->get_value() << endl;
    inOrder(node->getRightNode());
}
template <class T>
void Tree<T>::postOrder() {
    if (root == nullptr) return;
    postOrder(root);
}

template <class T>
void Tree<T>::postOrder(Node<T>* node) {
    if (node == nullptr) return;
    postOrder(node->getLeftNode());
    postOrder(node->getRightNode());
    cout << node->get_value() << " ";

}
template <class T>
void Tree<T>::levelOrder() {
    if (root == nullptr) return;
    list<Node<T>*> queue;
    queue.push_back(root);

    while (!queue.empty()) {
        Node<T>* node = queue.front();
        queue.pop_front();
        cout << node->get_value() << " ";

        if (!node->isLeftEmpty())
            queue.push_back(node->getLeftNode());
        if (!node->isRightEmpty())
            queue.push_back(node->getRightNode());
    }
}





#endif //TREE_H
