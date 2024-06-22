/*
Template Stack<T> class and the Node class with private members.

The purpose of this code is to create a stack in which data of generic type can be stored.

*/
#include <iostream>
#include <string>
using std::cout;
using std::string;

class Node{
    private:
        string name;
        float grd;
        int code ;
    public:
        Node* next;
        bool friend Compare(const Node&,const Node&);
        Node(string name , int code ,float grd)
        {
            this->name=name;
            this->code=code;
            this->grd=grd;
            next=nullptr;
        }
        Node(Node&s)
        {
            name=s.name;
            code=s.code;
            grd=s.grd;
            next=s.next;
        }
        void show()const {
            cout<<"Name: "<<name<<" Code: "<<code <<" Grd: "<<grd<<std::endl;;
        }
};


template <typename T> class Stack
{
    private:
        Node *head;
        int length;
    public:
        Stack(){length=0 ; head=nullptr;}
        ~Stack();
        void add_stack(T t);
        void show_stack()const;
        void pop(); //Should Display the popped Data.
        bool operator==(const Stack<T>&);
        void free_stack(){
            length=0;
            Node *p , *next_node;
            p=head;
            while(p!=nullptr)
            {
                next_node=p->next;
                delete p;
                p=next_node;
            }
            delete p;
            delete next_node;
            delete head;
            p=nullptr;
            next_node=nullptr;
            head=nullptr;
        }
};
template <typename T> Stack<T>::~Stack(){
            length=0;
            Node *p , *next_node;
            p=head;
            while(p!=nullptr)
            {
                next_node=p->next;
                delete p;
                p=next_node;
            }
            p=nullptr;
            next_node=nullptr;
            head=nullptr;
}


template <typename T>void Stack<T>::add_stack(T t)
{
    if (head==nullptr)
        {head=new Node(t);}
    else {
        Node *p=new Node(t);
        p->next=head;
        head=p;
    }

    length++;
}
template <typename T>void Stack<T>::show_stack()const {
    Node* temp=head;
    while(temp!=nullptr)
    {
        temp->show();
        temp=temp->next;
    }

}
template <typename T>void Stack<T>::pop(){
    if (length==0)
        {
            cout<<"Stack is Empty.\n";
            return ;
        }
    Node *temp=head;
    head=head->next;
    temp->show();
    temp->next=nullptr;
    delete temp;
    length--;
}
template< typename T> bool Stack<T>::operator==(const Stack<T> &St)
{
    if (this== &St)
        return true;
    if (this->length != St.length)
        return false;
    Node *t1=this->head , *t2=St.head;
    for (int i=0 ; i<this->length ; i++)
        {
            if (!Compare(*t1,*t2))
                return false;
            t1=t1->next;
            t2=t2->next;
        }
        t1=nullptr;
        t2=nullptr;
        return true;


}


bool Compare(const Node &St1,const Node &St2 );

int main()
{
    Node n1("First", 1, 2), n2("Sec", 3, 4), n3("Third", 5, 6);
    Stack<Node> st1;
        /* The code of the functions of the Stack is similar to the code of the respective functions in C.14.8. */

    st1.add_stack(n1); /* The add_stack() should add a student in the stack. */
    st1.add_stack(n2);
    st1.add_stack(n3);
    st1.show_stack(); /* The show_stack() should display the data of the students. */
    
    st1.pop(); /* The pop() should display the data of the student that was extracted from the stack. */

    st1.show_stack(); /* In this example, the program should display the data of n1, n2. */

    Stack<Node> st2;
    st2.add_stack(n1);
    st2.add_stack(n2);

    cout<<"\n\n";
    st2.show_stack();
    cout << ((st1 == st2) ? "Same\n" : "Different\n"); /* If the two stacks contain the same number of elements and their names are the same,
    as in this example, the program should display Same. */
    return 0;
}


bool Compare(const Node &St1,const Node &St2 )
{
    return (St1.code==St2.code && St1.name==St2.name && St1.grd==St2.grd) ;
}

