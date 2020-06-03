#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>
#include "LinkedList.hpp"
#include "LinkNode.hpp"

template<typename T>
class Stack : public SinglyLinkedList<T>
{
public:
    //Ctor
    Stack() : SinglyLinkedList<T>() { };
    
    //Dtor
    virtual ~Stack() { };
    
    //Stack Specific Functions
    void push(T inputData);
    void pop(T &obj);
    void peek(T &obj);
};

template<typename T>
void Stack<T>::push(T inputData)
{
    LinkNode<T>* newNode = nullptr;
    
    //allocate memory
    newNode = (LinkNode<T>*)malloc(sizeof(LinkNode<T>));
    //newNode = new LinkNode<T>;
    
    //if memory allocation success
    if (newNode != nullptr)
    {
        newNode->data = inputData;
        
        if(this->isEmpty())
        {
            this->start = newNode;
            this->end = newNode;
            newNode->next = nullptr;
        }else
        {
            newNode->next = this->start;
            this->start = newNode;
        }
        
        this->incrementCount();
    }
}

template<typename T>
void Stack<T>::pop(T &obj)
{
    LinkNode<T>* ptr = nullptr;
    
    if (this->isEmpty())
        std::cerr << "Stack is empty." << std::endl;
    else
    {
        obj = this->start->data;
        ptr = this->start->next;
        delete this->start;
        this->start = ptr;
        
        this->decrementCount();
    }
}

template<typename T>
void Stack<T>::peek(T &obj)
{
    if (this->isEmpty())
        std::cerr << "Stack is empty." << std::endl;
    else
        obj = this->start->data;
}

#endif /* Stack_hpp */
