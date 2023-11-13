#include <bits/stdc++.h>
using namespace std;

// using array
class Arr_Stack
{
    // properties
private:
    int *arr;
    int top;
    int size;

    // behaviour
public:
    Arr_Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    ~Arr_Stack()
    {
        delete[] arr;
    }

    void Push(int element)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = element;
        }

        else
        {
            cout << "Stack Overflow " << endl;
        }
    }

    void Pop()
    {
        if (!Empty())
        {
            top--;
        }

        else
        {
            cout << "Stack Underflow " << endl;
        }
    }

    int Top()
    {
        if (top != -1)
        {
            return arr[top];
        }

        cout << "Stack is Empty " << endl;
        return -1;
    }

    bool Empty()
    {
        if (top == -1)
        {
            return true;
        }

        return false;
    }
};

// using linklist
class LinkList
{
public:
    int val;
    LinkList *next;

    LinkList(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class Link_Stack
{
private:
    LinkList *top;
    LinkList *head;
    int size;
    int count;

public:
    Link_Stack(int size)
    {
        this->size = size;
        count = 0;
        top = NULL;
        head = NULL;
    }

    void Create_node(int val)
    {
        LinkList *new_node = new LinkList(val);

        if (top != NULL)
        {
            top->next = new_node;
            top = new_node;
            return;
        }

        top = new_node;
    }

    void destroy(LinkList *head)
    {
        if (head == NULL)
        {
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            return;
        }

        delete (head->next);
    }

    LinkList *getprevTop(LinkList *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }

        while (head->next->next != NULL)
        {
            head = head->next;
        }

        return head;
    }

    void Push(int element)
    {
        if (count < size)
        {
            Create_node(element);
            count++;
            return;
        }

        cout << "Stack Overflow " << endl;
    }

    void Pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow " << endl;
            return;
        }

        LinkList *to_delete = top;
        LinkList *top = getprevTop(head);

        if (top != NULL)
        {
            top->next = NULL;
        }

        delete to_delete;
    }

    int Top()
    {
        if (top == NULL)
        {
            return -1;
        }

        return (top->val);
    }

    bool Empty()
    {
        return (top == NULL);
    }

    ~Link_Stack()
    {
        destroy(head);
    }
};

int main()
{
    Arr_Stack st(5);

    st.Push(22);
    st.Push(32);
    st.Push(45);

    cout << st.Top() << endl;

    st.Pop();
    cout << st.Top() << endl;

    st.Pop();
    cout << st.Top() << endl;

    st.Pop();
    cout << st.Top() << endl;

    st.~Arr_Stack();

    Link_Stack stt(5);

    stt.Push(22);
    stt.Push(32);
    stt.Push(45);

    cout << stt.Top() << endl;

    stt.Pop();
    cout << stt.Top() << endl;

    stt.Pop();
    cout << stt.Top() << endl;

    stt.Pop();
    cout << stt.Top() << endl;

    stt.~Link_Stack();

    return 0;
}

// using STl
int main()
{
    // creation of stack
    stack<int> st;

    st.push(3);
    st.push(2);

    st.pop();

    cout << st.top() << endl;

    if (!st.empty())
    {
        cout << "NOT empty" << endl;
    }

    else
    {
        cout << "empty" << endl;
    }

    return 0;
}