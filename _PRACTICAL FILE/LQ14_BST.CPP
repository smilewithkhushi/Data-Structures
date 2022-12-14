#include <iostream>
using namespace std;
template <class Type>
struct node
{
public:
    Type info;
    struct node<Type> *left;
    struct node<Type> *right;
};

template <class Type>
class BST
{
public:
    node<Type> *root;
    BST()
    {
        root = NULL;
    }
    BST(Type data)
    {
        root->info = data;
        root->left = NULL;
        root->right = NULL;
    }
    void insert(Type, node<Type> *);
    void preorder(node<Type> *);
    void postorder(node<Type> *);
    void inorder(node<Type> *);
    void display(node<Type> *, int);
    int maxheight(node<Type> *);
    void printLevelOrder(node<Type> *);
    void printGivenLevel(node<Type> *, int);
    void search(node<Type> *, Type);
    void deleteByMerging(node<Type> *&p);
    void FindDelete(Type);
};
template <class Type>
void BST<Type>::search(node<Type> *p, Type x)
{
    while (p != 0)
        if (x == p->info)
        {
            cout << "The node with value: " << p->info << " is present in the BST!\n";
            return;
        }
        else if (x < p->info)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    cout << "Node with the " << x << " info value is not present in the BST\n";
}
template <class Type>
void BST<Type>::printLevelOrder(node<Type> *root)
{
    int h = maxheight(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        printGivenLevel(root, i);
        cout << "\n";
    }
}
template <class Type>
void BST<Type>::printGivenLevel(node<Type> *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        cout << root->info << " ";
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}
template <class Type>
void BST<Type>::deleteByMerging(node<Type> *&del)
{
    node<Type> *temp = del;
    if (del != NULL)
    {
        if (!del->right)
        {
            del = del->left;
        }
        else if (del->left == NULL)
        {
            del = del->right;
        }
        else
        {
            temp = del->left;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            temp->right = del->right;
            temp = del;
            del = del->left;
        }
        delete temp;
    }
}
template <class Type>
void BST<Type>::FindDelete(Type el)
{
    node<Type> *temp = root, *prev = NULL;
    while (temp != NULL)
    {
        if (temp->info == el)
        {
            break;
        }
        prev = temp;
        if (el < temp->info)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    if (temp != NULL && temp->info == el)
    {
        if (temp == root)
        {
            deleteByMerging(root);
        }
        else if (prev->left == temp)
        {
            deleteByMerging(prev->left);
        }
        else
        {
            deleteByMerging(prev->right);
        }
    }
    else if (root != NULL)
    {
        cout << "Element " << el << " not in the tree" << endl;
    }
    else
    {
        cout << "Tree is empty" << endl;
    }
}
template <class Type>
void BST<Type>::insert(Type data, node<Type> *current)
{
    node<Type> *temp;
    if (root == NULL)
    {
        root = new node<Type>;
        root->info = data;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        if ((data < current->info) && (current->left == NULL))
        {
            temp = new node<Type>;
            temp->info = data;
            temp->left = temp->right = NULL;
            current->left = temp;
        }
        else if ((data >= current->info) && (current->right == NULL))
        {
            temp = new node<Type>;
            temp->info = data;
            temp->left = temp->right = NULL;
            current->right = temp;
        }
        else
        {
            if (data < current->info)
                insert(data, current->left);
            else
                insert(data, current->right);
        }
    }
}
template <class Type>
void BST<Type>::preorder(node<Type> *p)
{
    if (p != NULL)
    {
        cout << p->info << " ";
        preorder(p->left);
        preorder(p->right);
    }
}
template <class Type>
void BST<Type>::postorder(node<Type> *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->info << " ";
    }
}
template <class Type>
void BST<Type>::inorder(node<Type> *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout << p->info << " ";
        inorder(p->right);
    }
}
template <class Type>
int BST<Type>::maxheight(node<Type> *current)
{
    if (current == NULL)
        return 0;
    else
    {
        int leftheight = maxheight(current->left);
        int rightheight = maxheight(current->right);
        if (leftheight > rightheight)
            return (leftheight + 1);
        else
            return (rightheight + 1);
    }
}
template <class Type>
void BST<Type>::display(node<Type> *p, int l)
{
    int i;
    if (p != NULL)
    {
        display(p->right, l + 1);
        cout << endl;
        if (p == root)
            cout << "Root->:";
        else
        {
            for (i = 0; i < l; i++)
                cout << " ";
        }
        cout << p->info;
        display(p->left, l + 1);
    }
}
int main()
{
    BST<int> l1;
    int choice, s;
    int n;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        cout << "MAIN MODULE....\n";
        cout << "1.Insert\n";
        cout << "2.PreOrder\n";
        cout << "3.PostOrder\n";
        cout << "4.InOrder\n";
        cout << "5.MaxHeight\n";
        cout << "6.Display\n";
        cout << "7.Deletion by Merging\n";
        cout << "8.Level By Level Traversal\n";
        cout << "9.Search an element in BST\n";
        cout << "Enter your choice\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the elements you want to push\n";
            cin >> s;
            for (int i = 0; i < s; i++)
            {
                cout << "Enter the element to push\n";
                cin >> n;
                l1.insert(n, l1.root);
            }
            break;
        case 2:
            l1.preorder(l1.root);
            break;
        case 3:
            l1.postorder(l1.root);
            break;
        case 4:
            l1.inorder(l1.root);
            break;
        case 5:
            n = l1.maxheight(l1.root);
            cout << "Height= " << n << endl;
            break;
        case 6:
            l1.display(l1.root, 1);
            break;
        case 7:
            cout << "Enter the node you want to delete : ";
            cin >> s;
            l1.FindDelete(s);
            cout << "Tree after deletion : " << endl;
            l1.display(l1.root, 1);
            break;
        case 8:
            cout << "\nLevel by Level Traversal : \n";
            l1.printLevelOrder(l1.root);
            cout << endl;
            break;
        case 9:
            cout << "\nEnter the info part of the node which you want to search in the BST\n";
            cin >> s;
            l1.search(l1.root, s);
            break;
        default:
            cout << "Error in input\n";
            break;
        }
        cout << "\nDo you want to continue\n";
        cin >> ch;
    }
    return 0;
}