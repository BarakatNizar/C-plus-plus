#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

//Basic Operations:
//1- Insert end
//2- spec insertion , after a specific `node->code` . 
//3- Display nodes
//4- Display a specifies node by code
//5- Modify `grd` for a specific node.
//6- Delete node if exist by `code`

struct Node {
    Node *next;
    string name;
    float grd;
    int code;
};
struct DATA{
    Node *head;
    Node *tail;
};

void add_list_end(  DATA *, const Node *p);
void add_list( DATA* , const Node *p, int code);
void show_list( DATA* );
Node *find_node( DATA* , int code);
int del_node(  DATA *, int code);
void free_list(  DATA*);

int main()
{
    DATA students;
    int k, sel, code;
    float grd;
    Node *p, n;
    students.head = nullptr;
    while(1)
    {
    cout << "\nMenu selections\n";
    cout << "---------------\n";
    cout << "1. Add student at the end\n";
    cout << "2. Add student\n";
    cout << "3. View all students\n";
    cout << "4. View student\n";
    cout << "5. Modify student\n";
    cout << "6. Delete student\n";
    cout << "7. Exit\n";
    cout << "\nEnter choice: ";
    cin >> sel;
    switch(sel)
    {
    case 1:
    case 2: 
    /* To avoid the repetition of the same code we use the same case to insert data. 
    Then, the if statement checks the user's choice and calls the respective function. */
        cin.get();
        cout << "Name: ";
        getline(cin, n.name);
        cout << "Code: ";
        cin >> n.code;
        cout << "Grade: ";
        cin >> n.grd;
        
        if(sel == 1)
            add_list_end(&students,&n);
        else
        {
            cout << "\nEnter student code after which the new student will be added: ";
            cin >> code;
            add_list(&students,&n, code);
        }
        break;
    
    case 3:
        if(students.head == nullptr)
            cout << "\nThe list is empty\n";
        else
            show_list(&students);
        break;

    case 4:
        if(students.head == nullptr)
            cout << "\nThe list is empty\n";
        else
        {
            cout << "\nEnter student code to search: ";
            cin >> code;
            p = find_node(&students,code);
            if(p != nullptr)
                cout << "\nN:" << p->name << " G:" << p->grd << '\n';
            else
                cout << "\nStudent with code " <<code << " does not exist\n";
        }
        break;

    case 5:
        if(students.head == nullptr)
            cout << "\nThe list is empty\n";
        else
        {
            cout << "\nEnter student code to modify: ";
            cin >> code;
            cout << "Enter new grade: ";
            cin >> grd;
            p = find_node(&students,code);
            if(p != nullptr)
                p->grd = grd;
            else
            cout << "\nStudent with code " <<code << " does not exist\n";
        }
        break;

    case 6:
        if(students.head == nullptr)
            cout << "\nThe list is empty\n";
        else
        {
            cout << "\nEnter student code to delete: ";
            cin >> code;
            k = del_node(&students , code);
            if(k == 0)
                cout << "\nStudent with code " <<code << " is deleted\n";
            else
                cout << "\nStudent with code " <<code << " does not exist\n";
        }
        break;

    case 7:
        if(students.head != nullptr)
            free_list(&students);
            return 0;
    
    default:
        cout << "\nWrong choice\n";
        break;
    }
    }
    return 0;
}

void add_list_end(   DATA *d ,const Node *p)
{
    Node *new_node;
    new_node = new Node;
    *new_node = *p;
    new_node->next = nullptr;
    if(d->head == nullptr)
        d->head = d->tail = new_node;
    else
    {
    	d->tail->next = new_node;
    	d->tail = new_node;
    }
}


void add_list(  DATA *d ,const Node *p, int code)
{
    Node *new_node, *ptr;
    ptr = d->head;
    while(ptr != nullptr)
    {
    if(ptr->code == code)
    {
        new_node = new Node;
        *new_node = *p; // Copy the student's data.
        new_node->next = ptr->next; /* The new node is linked to the node after the current node. */
        ptr->next = new_node; /* The current node is linked to the new node. */
        if(ptr == d->tail) /* Check if the new node is added at the end of the list. If it is, it becomes the new tail. */
            d->tail = new_node;
        return;
    }
    ptr = ptr->next; // Check the next node.
    }
    /* If this point is reached it means that the input code does not correspond to an existing student. */
    cout << "\nStudent with code " << code << " does not exist\n";
}

void show_list(  DATA *d )
{
    Node *p;
    p = d->head;
    cout << "\n***** Student Data *****\n\n";
    while(p != nullptr)
    {
        cout << "C:" << p->code << " N:" << p->name << " G:" << p->grd << '\n';
        p = p->next;
    }
}

Node *find_node(  DATA *d ,int code)
{
    Node *p;
    p =d->head;
    while(p != nullptr)
    {
        if(p->code == code)
            return p;
        p = p->next;
    }
    return nullptr;
}

int del_node(  DATA *d,int code)
{
    Node *p, *prev_node; /* prev_node always points to the previous node from the one that is going to be deleted. */
    p = prev_node = d->head;
    while(p != nullptr)
    {
        if(p->code == code)
        {
            if(p == d->head)
                d->head = p->next; 
                /* If the node is the head of the list, the next node becomes the new head. 
                If there is no other node, the list becomes empty and head becomes nullptr. */
            else
                {
                    /* p points to the node that will be deleted and prev_node points to the previous one. 
                    This statement links the previous node with the node after the one to be deleted. */
                prev_node->next = p->next;
                if(p == d->tail) 
                    d->tail = prev_node;
                    /* Check if the deleted node is the tail of the list. 
                If it is, the previous node becomes the new tail. */
                
                }
            delete p; // Delete the node.
            return 0;
        }
        prev_node = p; /* prev_node points to the node that was just checked and found that it has other code than the input code. */
        p = p->next; /* Now, p points to the next node. Notice that prev_node always points to the previous node from the one to be examined. */
    }
    return -1;
}

void free_list(  DATA *d)
{
    Node *p, *next_node;
    p = d->head;
    while(p != nullptr)
    {
        next_node = p->next;
        delete p;
        p = next_node;
    }
}

/*
Caution : If you want to change the first menu choice and insert the data of the new student at the
beginning of the list and not at its end, replace the add_list_end() with the add_stack() presented in
the stack program. In that case, the tail pointer is not needed.
*/
