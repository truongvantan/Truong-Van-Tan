template <class T>
class List;

template <class T>
class Node
{
    private:
        T data;
        Node *pNext;
        friend class List<T>;
    public:
        Node();
        Node(T);
        T GetData();
        Node* GetpNext();
        void SetData(T);
};

template <class T>
Node<T>::Node()
{
    this->pNext = nullptr;
}

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->pNext = nullptr;
}


template <class T>
T Node<T>::GetData()
{
    return this->data;
}

template <class T>
Node<T>* Node<T>::GetpNext()
{
    return this->pNext;
}

template <class T>
void Node<T>::SetData(T data)
{
    this->data = data;
}