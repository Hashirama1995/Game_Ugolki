#pragma once
template<typename T>
class allMove
{
public:
    allMove();
    ~allMove();
    void pop_front();//������ �� ������
    void push_back(T data1);//�������� � ����� ������ ����� �������
    void clear();//�������� ������
    int GetSize() { return Size; }//�������� ������ �������
    T& operator[] (const int index);
    void push_front(T data1);//�������� � ������
    void insert(T value1, int index);//�������� �� �������
    void removeAt(int index);//������� �� �������
    void pop_back();//������� �� �����
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
    Node<T>* head; // ��������� �� 1 �������
    int Size; // ������ ������
};

