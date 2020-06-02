//
//  Queue.h
//  Lab 4
//
//  Created by Wilson Wu on 6/2/20.
//  Copyright © 2020 None. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
#include "LinkedList.h"
#include "LinkNode.h"

template<typename T> class Queue : protected SinglyLinkedList<T>
{
public:
    Queue();
    
    virtual ~Queue();
    void enqueue(T obj);
    void dequeue();
    T peekFront();
    T peekRear();
    void clear();
    bool isEmpty();
protected:
private:
};

template<typename T>
Queue<T>::Queue()
{
    SinglyLinkedList<T>::count = 0;
    SinglyLinkedList<T>::start = nullptr;
    SinglyLinkedList<T>::end = nullptr;
}

template<typename T>
void Queue<T>::enqueue(T obj)
{
    SinglyLinkedList<T>::appendNode(obj);
}

template<typename T>
void Queue<T>::dequeue()
{
    SinglyLinkedList<T>::deleteNode(SinglyLinkedList<T>::start -> data);
}

template<typename T>
T Queue<T>::peekFront()
{
    return SinglyLinkedList<T>::start -> data;
}

template<typename T>
T Queue<T>::peekRear()
{
    return SinglyLinkedList<T>::end -> data;
}

template<typename T>
void Queue<T>::clear()
{
    SinglyLinkedList<T>::clear();
}

template<typename T>
bool Queue<T>::isEmptys()
{
    return SinglyLinkedList<T>::isEmpty();
}

template<typename T>
Queue<T>::~Queue()
{
    LinkNode<T>* nodePtr;
    LinkNode<T>* next;
    nodePtr = SinglyLinkedList<T>::start;
    while (nodePtr != nullptr)
    {
        next = nodePtr->next;
        delete nodePtr;
        nodePtr = next;
    }
}

#endif /* Queue_h */
