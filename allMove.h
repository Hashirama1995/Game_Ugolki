#pragma once
template<typename T>
class allMove
{
public:
    allMove();
    ~allMove();
    void pop_front();//Убрать из начала
    void push_back(T data1);//Вставить в конец списка новый элемент
    void clear();//Очистить список
    int GetSize() { return Size; }//Показать длинну массива
    T& operator[] (const int index);
    void push_front(T data1);//Добавить в начало
    void insert(T value1, int index);//Вставить на позицию
    void removeAt(int index);//Удалить на позиции
    void pop_back();//Удалить из конца
private:
    template<typename T>
    class Node
    {
    public:
        Node* pNext;
        T data1;
        Node(T data1 = T(), Node* pNext = nullptr)
        {
            this->data1 = data1;
            this->pNext = pNext;
        }
    };
    Node<T>* head; // Указатель на 1 элемент
    int Size; // Размер списка
};

