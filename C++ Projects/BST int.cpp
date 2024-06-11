/*
C.14.14 Write a recursive function that counts the nodes of the tree.
*/

#include <iostream> 
#include <cstring>
using std::cout;
using std::cin;
using std::string;

const int MAX_NODES=200;

struct Node
{
int key;
Node *left;
Node *right;
};

Node* add_node(Node *p, int key);
void delete_tree(Node *p);
int get_count(Node*p);


void show_inorder(Node *p);
void show_postorder(Node *p);
void show_preorder(Node *p);
void show_levelorder(Node *p); 

Node* find_node(Node *p, int key);
Node* SmallestKey(Node*p);
void find_min(Node*p);




void add_queue(Node *arr[], Node *p, int *cnt);
Node* pop(Node *arr[], int *cnt) ;

int main()
{
    int sel, key;
    Node *root;
    root = nullptr;
    while(1)
    {
        cout << "\nMenu selections\n";
         cout << "---------------\n";
        cout << "1. Add Node\n";
        cout << "2. Show Tree\n";
        cout << "3. Exit\n";
        cout << "4. Smallest key\n";
        cout << "5. Number of keys\n";
        cout << "\nEnter choice: ";
        cin >> sel;
    switch(sel)
    {
        case 1:
            cout << "Key: ";
            cin >> key;
            root = add_node(root, key);
            break;
        case 2:
            cout << "Added Keys: ";
            show_inorder(root);
            break;
        case 3:
            cout << "\nDeleted Keys: ";
            delete_tree(root);
            return 0;
        case 4:
            cout<<"Smallest Key: "<<SmallestKey(root)->key;
            break ;
        case 5:
            cout<<"Number of keys is :"<<get_count(root)<<" .\n";
            break;
        default:
            system("clear");
            cout << "\nWrong choice\n";
            break;
    }
    }
    return 0;
}
Node* add_node(Node *p, int key)
{
    if(p == nullptr)
    {
        p = new Node;
        p->left = p->right = nullptr;
        p->key = key;
    }
    else
    {
        if(key < p->key)
            p->left = add_node(p->left, key);
        else if(key > p->key)
            p->right = add_node(p->right, key);
        else
            cout << "Error: Key(" << key << ") exists\n";
    }
    return p;
}
void show_inorder(Node *p)
{
    if(p == nullptr)
        return;    
    show_inorder(p->left);
    cout << p->key << ' ';
    show_inorder(p->right);
}
void delete_tree(Node *p)
{
    if(p == nullptr)
        return;
    delete_tree(p->left);
    delete_tree(p->right);
    cout << p->key << ' ';
    delete p;
}

void show_postorder(Node *p)
{
    if(p == nullptr)
        return;
    show_postorder(p->left);
    show_postorder(p->right);
    cout << p->key << ' ';
}

void show_preorder(Node *p)
{
    if(p == nullptr)
        return;
    cout << p->key << ' ';
    show_postorder(p->left);
    show_postorder(p->right);
}

Node* find_node(Node *p, int key)
{
    if(p == nullptr) /* Check if the tree is empty. We could use the while condition, I just prefer to make it clear. */
        return nullptr;
    while(p != nullptr)
    {
        if(key < p->key)
            p = p->left;
        else if(key > p->key)
            p = p->right;
        else
            return p;
    }
    return nullptr;
}



    void show_levelorder(Node *p)
    {
        Node *arr[MAX_NODES]= {0};
        int start  , end;

        if (p==nullptr)
            return;

        start=end=0;
        add_queue(arr, p , &end); //Store the root.

        while ((p=pop(arr,&start)) != nullptr)
        {
            cout<<p->key<<" ";
            if (p->left)
                add_queue(arr,p->left , &end);
            if (p->right)
                add_queue(arr,p->right , &end);
            
        }
    }
    void add_queue(Node *arr[], Node *p, int *cnt)
    {
        arr[*cnt] = p;
        (*cnt)++;
    }
    Node* pop(Node *arr[], int *cnt)
    {
        Node *tmp;
        tmp = arr[*cnt];
        (*cnt)++;
        return tmp;
        /* Alternatively, without using tmp:
            (*cnt)++;
            return arr[*cnt-1];
        */
    }


Node* SmallestKey(Node*p){
    if (p==nullptr)
        return nullptr;
    
    if (p->left==nullptr)
        return p;
    else 
         return SmallestKey(p->left);
}

void find_min(Node*p)
{
    if (p==nullptr)
        return ;
    if (p->left==nullptr)
        {
            cout<<"Minimum Key :"<<p->key<<"\n";
            return; 
        }
    find_min(p->left);
}
int get_count(Node*p){
    if (p==nullptr)
        return 0;
    else if (p->left==nullptr && p->right==nullptr)
        return 1;
    else if (p->left)
        return (1 + get_count(p->left));
    else if (p->right)
        return (1+ get_count(p->right));

}