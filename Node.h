#ifndef NODE_H
#define NODE_H
#include <list>

using namespace std;


template <class T>
class Node {
    protected:
    T data;
    Node<T> *leftNode;
    Node<T> *rightNode;
    public:
    Node();
    ~Node();
    Node(T& value);
    T& get_value();
    void set_value(T& value);
    Node<T>* getRightNode();
    Node<T>* getLeftNode();
    bool isLeftEmpty();
    bool isRightEmpty();
    void setLeftNode(Node<T>* node);
    void setRightNode(Node<T>* node);
    void erase_list();
    void add_child(T& nval);
    bool remove_child(T& nval);
    bool is_leaf();
    list<Node<T>*>& get_children();
};

using namespace std;

template<class T>
Node<T>::Node(): leftNode(nullptr), rightNode(nullptr) {}

template<class T>
Node<T>::~Node() {
    delete leftNode;
    delete rightNode;
}

template<class T>
Node<T>::Node(T& value){
    this->data = value;
    this->leftNode = NULL;
    this->rightNode = NULL;
}

template<class T>
T& Node<T>::get_value() {
    return this->data;
}

template<class T>
void Node<T>::set_value(T& value) {
    this->data = value;
}

template<class T>
Node<T>*Node<T>::getLeftNode(){
    return this->leftNode;
}

template<class T>
Node<T>* Node<T>::getRightNode(){
    return this->rightNode;
}

template<class T>
void Node<T>::setLeftNode(Node<T>* node){
    this->leftNode = node;
}

template <class T>
void Node<T>::setRightNode(Node<T>* node) {
    this->rightNode = node;
}

template <class T>
bool Node<T>::isLeftEmpty() {
    return this->leftNode == NULL;
}

template <class T>
bool Node<T>::isRightEmpty() {
    return this->rightNode == NULL;
}






#endif //NODE_H
