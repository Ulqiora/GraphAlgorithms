#include "stack.h"

namespace s21{


template<typename T>
stack<T>::stack(stack&& other)
{
    std::swap(topElem,other.topElem);
}


template<typename T>
stack<T>::stack(const stack& other)
{
    
}

template<typename T>
stack<T>::stack(const std::initializer_list<T> const& items)
{
    for(const auto  const& elem:items) push(elem);
}

template<typename T>
void stack<T>::push(const_reference value)
{
    Node* node=new Node<T>();
    node->next=topElem;
    node->data=value;
    topElem=node;
}


template<typename T>
void stack<T>::pop()
{
    if (topElem == nullptr) return;
    Node* last = topNode;
    topElem = topElem->next;
    delete last;
}

template <class T>
stack<T>& stack<T>::operator=(stack<T>&& other) {
    if (this == &other) return *this;
    if (topNode) emptyStack();
    std::swap(topNode, other.topNode);
    return *this;
}

template <class T>
stack<T>& stack<T>::operator=(const stack<T>& other) {
    if (topNode) emptyStack();
    Node* copyTopNode = other.topNode;
    stack<T> reverse;
    while (copyTopNode != nullptr) {
        reverse.push(copyTopNode->data);
        copyTopNode = copyTopNode->next;
    }
    while (reverse.topNode != nullptr) {
        T data = reverse.pop_back();
        push(data);
    }
    return *this;
}


}