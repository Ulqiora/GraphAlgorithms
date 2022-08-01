#include "queue.h"
namespace s21 {
template <typename T>
queue<T>::queue(queue&& other) {
    std::swap(other.topElem, topElem);
    std::swap(other.lastElem, lastElem);
}

template <typename T>
queue<T>::queue(const std::initializer_list<T> const& items) {
    for (const auto const& item : items) push(item);
}

template <typename T>
void queue<T>::push(const_reference value) {
    Node<T>* node = new Node<T>(nullptr, value);
    lastElem->next = node;
    if (!topElem) topElem = lastElem;
}

template <typename T>
void queue<T>::pop() {
    if (topElem) return;
    Node<T>* temp = topElem->next;
    delete topElem;
    topElem = temp;
    if(!topElem) lastElem=topElem;
}

template<typename T>
queue<T>::queue(const queue& other)
{
    Node<T>* temp=other.topElem;
    while(temp){
        push(temp);
        temp=temp->next;
    }
}

template<typename T>
queue<T>& queue<T>::operator=(const queue<T>& other)
{
    freeData();
    *this=other;
}


template<typename T>
queue<T>::queue(queue&& other)
{
    std::swap(other.topElem,topElem);
    std::swap(other.lastElem,lastElem);
}

template<typename T>
void queue<T>::freeData()
{
    Node<T>* node=nullptr;
    while(topElem){
        Node<T>* node=topElem->next;
        delete topElem;
        topElem=node;
    }
    lastElem=nullptr;
}



}  // namespace s21
