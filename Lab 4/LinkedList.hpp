#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class SinglyLinkedList
{
protected:
    struct LinkNode
    {
    public:
        T data;
        struct LinkNode* next;
    };
protected:
    int count;
    LinkNode* start;
    LinkNode* end;
    
public:
    //Ctor
    SinglyLinkedList() : count(0), start(nullptr), end(nullptr) { }
    
    //Dtor
    virtual ~SinglyLinkedList();
    
    //Getters
    int getCount() { return count; }
    
    //Setters
    void incrementCount() { count++; }
    void decrementCount() { count--; }
    
    //Generic List type implementation functions
    bool find(T obj);
    void printList() const;
    bool isEmpty();
    
    //Linked List Specific Functions
    void appendNode(T inputData);
    void insertNode(T inputData);
    void deleteNode(T inputData);
};

template <typename T>
bool SinglyLinkedList<T>::find(T obj)
{
    if (start == nullptr)
        return false;
    else
    {
        LinkNode* nodePtr = nullptr;
        nodePtr = start;
        
        while (nodePtr != nullptr)
        {
            if (nodePtr->data == obj)
                return true;
            
            nodePtr = nodePtr->next;
        }
        return false;
    }
}


template <typename T>
bool SinglyLinkedList<T>::isEmpty()
{
    return (start == nullptr);
}

template <typename T>
void SinglyLinkedList<T>::appendNode(T inputData)
{
    LinkNode* newNode = nullptr; // Points to new node
    LinkNode* nodePtr = nullptr; // Move through the list
    
    //Make new node, populate with data and set next to nullptr
    newNode = new LinkNode;
    newNode->data = inputData;
    newNode->next = nullptr;
    
    if (isEmpty())
    {
        start = newNode;
        end = newNode;
    }
    else
    {
        nodePtr = start;      //start traversing from start node
        
        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;   //set nodePtr to the next node
        }
        
        //insert newNode and end as next
        nodePtr->next = newNode;
        end = nodePtr->next;
    }
    
    incrementCount();
}

template <typename T>
void SinglyLinkedList<T>::deleteNode(T inputData)
{
    LinkNode* nodePtr = nullptr;
    LinkNode* previous = nullptr;
    
    if (isEmpty())
        return;
    
    //If we are deleting first node
    if (start->data == inputData)
    {
        nodePtr = start->next;
        delete start;
        start = nodePtr;
        
        decrementCount();
    } else
    {
        nodePtr = start;
        //Traverse through list
        while (nodePtr != nullptr && nodePtr->data != inputData)
        {
            previous = nodePtr;
            nodePtr = nodePtr->next;
            
            end = nodePtr;
        }
        
        //If not the last node
        if (nodePtr)
        {
            previous->next = nodePtr->next;
            delete nodePtr;
        }
        decrementCount();
    }
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    LinkNode* nodePtr;
    LinkNode* next;
    
    nodePtr = start;
    while (nodePtr != nullptr)
    {
        next = nodePtr->next;
        delete nodePtr;
        nodePtr = next;
    }}

template<typename T>
void SinglyLinkedList<T>::printList() const
{
    LinkNode* nodePtr;
    nodePtr = start;
    
    while (nodePtr != nullptr)
    {
        cout << nodePtr->data << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

#endif /* LinkedList_hpp */
