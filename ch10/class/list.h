#ifndef LIST_H_
#define LIST_H_
template <class T>
void half(T &num)
{
    std::cout << num << " half is: " << (num /= 2.0);
}

template <class T>
class List {
   private:
    struct Node {
        T data;
        Node *next;
    };
    Node *head;
    // int size;
    List(const List &ls) head(nullptr){};
    List &operator=(const List &ls) { return *this; };

   public:
    List()
    {
        head = nullptr;
        // size = 0;
    }
    void Print();
    bool Insert(T num, int pos = 1);
    bool Delete(int pos = 1);
    void Reverse();
    void visit(void (*pf)(T &num));
    ~List();
};
template <class T>
List<T>::~List()
{
    Node *flag;
    while (head != nullptr) {
        flag = head;
        head = head->next;
        delete flag;
    }
}

template <class T>
void List<T>::Print()
{
    Node *flag;
    flag = head;
    std::cout << "Link list: ";
    if (flag == nullptr) {
        std::cout << "Empty link list.\n";
        return;
    }
    while (flag != nullptr) {
        std::cout << flag->data << ' ';
        flag = flag->next;
    }
    std::cout << "Done!" << std::endl;
}

template <class T>
bool List<T>::Insert(T num, int pos)
{
    Node *temp = new Node;
    temp->data = num;
    temp->next = nullptr;
    Node *flag;
    flag = head;
    if (pos == 1) {
        temp->next = head;
        head = temp;
        return true;
    }
    for (int i = 1; i < pos - 1; ++i) {
        flag = flag->next;
        if (flag == nullptr) {
            std::cout << "Request position can't achieve, insert failed.\n";
            return false;
        }
    }
    temp->next = flag->next;
    flag->next = temp;
    return true;
}

template <class T>
bool List<T>::Delete(int pos)
{
    Node *flag, *flag2;
    flag = head;
    if (pos == 1) {
        if (flag == nullptr) {
            std::cout << "Empty link list, delete failed.\n";
            return false;
        }
        head = flag->next;
        delete flag;
        return true;
    }
    for (int i = 1; i < pos - 1; ++i) {
        flag = flag->next;
        if (flag == nullptr) {
            std::cout << "Request position can't achieve, delete failed.\n";
            return false;
        }
    }
    flag2 = flag->next;
    flag->next = flag2->next;
    delete flag2;
    return true;
}

template <class T>
void List<T>::Reverse()
{
    Node *prev, *curr, *next;
    prev = nullptr;
    curr = head;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

template <class T>
void List<T>::visit(void (*pf)(T &num))
{
    Node *flag;
    int i = 1;
    flag = head;
    while (flag != nullptr) {
        std::cout << "Operation #" << i++ << ": ";
        pf(flag->data);
        flag = flag->next;
        std::cout << std::endl;
    }
}

#endif