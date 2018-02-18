//Genghis Khan

#include <iostream>
using namespace std;

//******************************************************************************
class node
{
public:
    int element;
    node* ptr;
    friend class list;
};

//******************************************************************************
class list
{
public:
    //Including head and tail attributes and making them public so that they are easily accessible to anyone using the linked list construction
    node head;
    node tail;

    list()
    {
        head.element = -1;
        head.ptr = NULL;
        tail.element = -1;
        tail.ptr = &head;
    }

    bool empty()
    {
        return(head.element == -1 && head.ptr == NULL);
    }

    bool one()
    {
        return(head.element != -1 && head.ptr == NULL);
    }

    void append(int a)
    {
        if(empty())
        {
            head.element = a;
            tail.element = a;
        }

        else if(one())
        {
            node *v = new node;
            v -> element = a;
            v -> ptr = NULL;
            head.ptr = v;
            tail.element = a;
            tail.ptr = v;
        }

        else
        {
            node *w = new node;
            w -> element = a;
            w -> ptr = NULL;
            (*tail.ptr).ptr = w;
            tail.ptr = w;
            tail.element = a;
        }

    }

    void print()
    {
        node iter;
        iter.element = head.element;
        iter.ptr = head.ptr;
        while(iter.ptr != NULL)
        {
            cout << iter.element << endl;
            iter.element = (*iter.ptr).element;
            iter.ptr = (*iter.ptr).ptr;
        }

        cout << tail.element;

    }


};

//******************************************************************************
int main()
{
    int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list lst;
    for(int i = 0; i < 10; i++)
    {
        lst.append(values[i]);
    }

    lst.print();

};