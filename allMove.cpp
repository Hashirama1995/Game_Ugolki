#include "allMove.h"

template<typename T>
allMove<T>::allMove()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
allMove<T>::~allMove()
{
    clear();
}

template<typename T>
void allMove<T>::pop_front()
{
    Node<T>* temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template<typename T>
void allMove<T>::push_back(T data1)
{
    if (head == nullptr)
    {
        head = new Node<T>(data1);
    }
    else
    {
        Node<T>* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data1);
    }
    Size++;
}

template<typename T>
void allMove<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template<typename T>
T& allMove<T>::operator[](const int index)
{
    Node<T>* current = this->head; // ссылка на голову
    int counter = 0;

    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data1;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename T>
void allMove<T>::push_front(T data1)
{
    head = new Node<T>(data1, head);
    Size++;
}

template<typename T>
void allMove<T>::insert(T value1, int index)
{
    if (index == 0)
    {
        push_front(value1);
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        previous->pNext = new Node<T>(value1, previous->pNext);
        Size++;
    }
}

template<typename T>
void allMove<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Node<T>* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}

template<typename T>
void allMove<T>::pop_back()
{
    removeAt(Size - 1);
}