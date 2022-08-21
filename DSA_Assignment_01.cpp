// Assignment_01    Data Structure & Algorithm Lab

/*Beginning with an empty binary BT, Construct binary BT by inserting the values in the order given. After constructing a binary BT perform following operations on it-

1.Perform inorder /preorder and post order traversal <-
2.Change a BT so that the roles of the left and right pointers are swapped at every node
3.Find the height of BT <-
4.Copy this BT to another [operator=]
5.Count number of leaves, number of internal nodes. <-
6.Erase all nodes in a binary BT. <-
->(implement both recursive and non-recursive methods)
*/
#include <iostream>
using namespace std;
class Node
{
    // Data Members
    int data;
    Node *right;
    Node *left;

public:
    Node()
    { // Default constructor->they Are automayically Invoke When Object iS Created!
        data = 0;
        right = NULL;
        left = NULL;
    }
    friend class BT;
    friend class stack;
};
class stack
{
    Node *s[50];
    int top = -1;

public:
    void push(Node *t1)
    {
        top++;
        s[top] = t1;
    }
    Node *pop()
    {
        Node *t1 = new Node;
        t1 = s[top];
        top--;
        return t1;
    }
    int empty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
            return 0;
    }
    void Inorder_Nonrecusrsive(Node *root)
    {
        // LEFT   ROOT  RIGHT
        stack s1;
        Node *t1 = root;
        while (!s1.empty() || t1 != NULL)
        {
            if (t1 != NULL)
            {
                s1.push(t1);
                t1 = t1->left;
            }
            else
            {
                t1 = s1.pop();
                cout << t1->data << " ";
                t1 = t1->right;
            }
        }
    }
    void PreOrder_NonRecursion(Node *root)
    {
        // ROOT  LEFT  RIGHT
        stack s1;
        Node *t1 = root;
        Node *prev = NULL;
        while (!s1.empty() || t1 != NULL)
        {
            if (t1 != NULL)
            {
                cout << t1->data << " ";
                s1.push(t1);
                t1 = t1->left;
            }
            else
            {
                prev = s1.pop();
                t1 = prev->right;
            }
        }
    }
    void PostOrder_Nonrecursive(Node *root)
    {
        // LEFT  RIGHT  ROOT
        stack s1, s2;
        Node *t1 = root;
        s1.push(t1);
        while (!s1.empty())
        {
            t1 = s1.pop();
            s2.push(t1);
            if (t1->left != NULL)
            {
                s1.push(t1->left);
            }
            if (t1->right != NULL)
            {
                s1.push(t1->right);
            }
        }
        while (!s2.empty())
        {
            root = s2.pop();
            cout << root->data << " ";
        }
    }
};
class BT
{

public:
    Node *root;
    BT() { root = NULL; }
    // Using Recursion!
    // Creating Function BT!
    Node *Create()
    {
        Node *newnode = new Node(); // Allocating Memory For New Node
        int x;
        cout << "\nEnter the Data:"; // Taking Data For New Node
        cin >> x;
        cout << endl;
        newnode->data = x; // Data Is Given to the Node
        // for NO  Futher Node!
        if (x == -1)
        {
            return NULL;
        }
        else
        {
            newnode->data = x;
            cout << "For Left Child For " << x << endl;
            newnode->left = Create(); // Again Function Is Get Called!(Recursion)
            cout << "For Right Child For " << x << endl;
            newnode->right = Create(); // Again Function Is Get Called!(Recursion)
            return newnode;
        }
    }
    // Recursion->he process in which a function calls itself directly or indirectly is called recursion and the corresponding function is called as recursive function.
    void In_order(Node *temp1)
    { // Left Root Right
        if (temp1 != NULL)
        {
            In_order(temp1->left);
            cout << temp1->data << " ";
            In_order(temp1->right);
        }
    }
    void Pre_order(Node *temp1)
    { // root left right
        if (temp1 != NULL)
        {
            cout << temp1->data << " ";
            Pre_order(temp1->left);
            Pre_order(temp1->right);
        }
    }
    void Post_order(Node *temp1)
    { // left right root
        if (temp1 != NULL)
        {
            Post_order(temp1->left);
            Post_order(temp1->right);
            cout << temp1->data << " ";
        }
    }
    int Calculate_Height(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left_height = Calculate_Height(root->left);
        int right_height = Calculate_Height(root->right);
        if (left_height > right_height)
        {
            return (left_height + 1);
        }
        else
        {
            return (right_height + 1);
        }
    }
    int count = 0; // We Cannot  Inatilize Our count Inside the Function Because we Need to call the Function again and agin
    // if we do so the count will always be start from 0.
    int count_leaves(Node *root)
    {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL  && root->right==NULL){
            return 1;
        }
        count=count_leaves(root->left)+count_leaves(root->right);
        return count;
        //}
       
    }
    // 1.Total Number of External Node = Internal Nodes + 1
    int count_internal(Node *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return 0;
        }
        else
        {
            return 1 + count_internal(root->left) + count_internal(root->right);
        }
    }
    // Erase all nodes in a binary BT
    void Delete_Node(Node *root)
    { // left right root
        if (root == NULL)
        {
            return;
        }
        else
        {
            Delete_Node(root->left);
            Delete_Node(root->right);
            delete root;
        }
    }
    void Switch(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            Node *temp; // temporary Variable,3 varibale method
            temp = root->left;
            root->left = root->right;
            root->right = temp;
            Switch(root->left); // Calling recursively!
            Switch(root->right);
        }
    }
    Node *copy_tree(Node *t)
    {
        Node *p;
        p = NULL;
        if (t != NULL)
        {
            p = new Node();
            p->data = t->data;
            p->left = copy_tree(t->left);
            p->right = copy_tree(t->right);
        }
        return p;
    }
    void Display_copy()
    {
        Node *t = copy_tree(root);
        cout << "\nTree Copied Successfully!" << endl;
    }
};
int main()
{
    BT t1, copy;
    stack s;
    Node *root, *tree2;
    int ch;
    do
    {
        cout << "\n0.Exit" << endl;
        cout << "1.Create BT - " << endl;
        cout << "2.Display Traversing (InOrder,PreOrder,PostOrder) - " << endl;
        cout << "3.Height For the Binary Tree - " << endl;
        cout << "4.Count number of leaves, number of internal nodes - " << endl;
        cout << "5.Change a BT so that the roles of the left and right pointers are swapped at every node - " << endl;
        cout << "6.Display Traversing Non-Recursive - " << endl;
        cout << "7.Copy this Binary Tree to Another - " << endl;
        cout << "8.Delete All Node In Binary Tree - " << endl;
        cout << "\nEnter the Choice - ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            root = t1.Create();
            break;
        case 2:
            if (root != NULL)
            {
                cout << "\nInOrder Traversing is - ";
                t1.In_order(root);
                cout << "\n\nPre Order Traversing is - ";
                t1.Pre_order(root);
                cout << "\n\nPost Order Traversing is - ";
                t1.Post_order(root);
                cout << endl;
            }
            else
            {
                cout << "\nNo Tree Exits!" << endl;
            }
            break;
        case 3:
            int h;
            h = t1.Calculate_Height(root);
            cout << "\nHeight For the Binary BT Is " << h << endl
                 << endl;
            break;
        case 4:
            int p; 
            p=t1.count_leaves(root);
            cout << "\nNumber Of Leaves In Binary tree Are - " << p << endl;
            int d;
            d = t1.count_internal(root);
            cout << "\nNumber Of Internal Node In Binary Node Are - " << d << endl;
            break;
        case 5:
            t1.Switch(root);
            cout << "\nSwaping is Done!" << endl;
            break;
        case 6:
            cout << "\nInOrder Traversing is - ";
            s.Inorder_Nonrecusrsive(root);
            cout << "\n\nPre Order Traversing is - ";
            s.PreOrder_NonRecursion(root);
            cout << "\n\nPost Order Traversing is - ";
            s.PostOrder_Nonrecursive(root);
            break;
        case 7:
            t1.Display_copy();
            cout << "Pre-Order Traversing For Binary Tree Is - ";
            copy.Pre_order(root);
            cout << endl;
            break;
        case 8:
            t1.Delete_Node(root);
            root = NULL;
            cout << "All Node In Binary Tree Deleted Successfully!" << endl;
            break;
        default:
            break;
        }
    } while (ch != 0);

    return 0;
}
/*             BINARY TREE -

                             50
                           /    \
                         22     18
                        / \     /  \
                      14  16   17  NULL

*/
/*
=================================>
*****    OUTPUT   *****
================================>



0.Exit
1.Create BT - 
2.Display Traversing (InOrder,PreOrder,PostOrder) - 
3.Height For the Binary Tree - 
4.Count number of leaves, number of internal nodes - 
5.Change a BT so that the roles of the left and right pointers are swapped at every node - 
6.Display Traversing Non-Recursive - 
7.Copy this Binary Tree to Another - 
8.Delete All Node In Binary Tree - 

Enter the Choice - 1

Enter the Data:50

For Left Child For 50

Enter the Data:22

For Left Child For 22

Enter the Data:14

For Left Child For 14

Enter the Data:-1

For Right Child For 14

Enter the Data:-1

For Right Child For 22

Enter the Data:16

For Left Child For 16

Enter the Data:-1

For Right Child For 16

Enter the Data:-1

For Right Child For 50

Enter the Data:18

For Left Child For 18

Enter the Data:17

For Left Child For 17

Enter the Data:-1

For Right Child For 17

Enter the Data:-1

For Right Child For 18

Enter the Data:-1


0.Exit
1.Create BT -
2.Display Traversing (InOrder,PreOrder,PostOrder) -
3.Height For the Binary Tree -
4.Count number of leaves, number of internal nodes -
5.Change a BT so that the roles of the left and right pointers are swapped at every node -
6.Display Traversing Non-Recursive -
7.Copy this Binary Tree to Another -
8.Delete All Node In Binary Tree -

Enter the Choice - 2

InOrder Traversing is - 14 22 16 50 17 18

Pre Order Traversing is - 50 22 14 16 18 17

Post Order Traversing is - 14 16 22 17 18 50

0.Exit
1.Create BT -
2.Display Traversing (InOrder,PreOrder,PostOrder) -
3.Height For the Binary Tree -
4.Count number of leaves, number of internal nodes -
5.Change a BT so that the roles of the left and right pointers are swapped at every node -
6.Display Traversing Non-Recursive -
7.Copy this Binary Tree to Another -
8.Delete All Node In Binary Tree -

Enter the Choice - 3

Height For the Binary BT Is 3


0.Exit
1.Create BT -
2.Display Traversing (InOrder,PreOrder,PostOrder) -
3.Height For the Binary Tree -
4.Count number of leaves, number of internal nodes -
5.Change a BT so that the roles of the left and right pointers are swapped at every node -
6.Display Traversing Non-Recursive -
7.Copy this Binary Tree to Another -
8.Delete All Node In Binary Tree -

Enter the Choice - 4

Number Of Leaves In Binary tree Are - 3

Number Of Internal Node In Binary Node Are - 3

0.Exit
1.Create BT -
2.Display Traversing (InOrder,PreOrder,PostOrder) -
3.Height For the Binary Tree -
4.Count number of leaves, number of internal nodes -
5.Change a BT so that the roles of the left and right pointers are swapped at every node -
6.Display Traversing Non-Recursive -
7.Copy this Binary Tree to Another -
8.Delete All Node In Binary Tree -

Enter the Choice - 5

Swaping is Done!

0.Exit
1.Create BT -
2.Display Traversing (InOrder,PreOrder,PostOrder) -
3.Height For the Binary Tree -
4.Count number of leaves, number of internal nodes -
5.Change a BT so that the roles of the left and right pointers are swapped at every node -
6.Display Traversing Non-Recursive -
7.Copy this Binary Tree to Another -
8.Delete All Node In Binary Tree -

Enter the Choice - 2

InOrder Traversing is - 18 17 50 16 22 14

Pre Order Traversing is - 50 18 17 22 16 14

Post Order Traversing is - 17 18 16 14 22 50

0.Exit
1.Create BT -
2.Display Traversing (InOrder,PreOrder,PostOrder) -
3.Height For the Binary Tree -
4.Count number of leaves, number of internal nodes -
5.Change a BT so that the roles of the left and right pointers are swapped at every node -
6.Display Traversing Non-Recursive -
7.Copy this Binary Tree to Another -
8.Delete All Node In Binary Tree -

Enter the Choice - 6

InOrder Traversing is - 18 17 50 16 22 14

Pre Order Traversing is - 50 18 17 22 16 14

Post Order Traversing is - 17 18 16 14 22 50
0.Exit
1.Create BT -
2.Display Traversing (InOrder,PreOrder,PostOrder) -
3.Height For the Binary Tree -
4.Count number of leaves, number of internal nodes -
5.Change a BT so that the roles of the left and right pointers are swapped at every node -
6.Display Traversing Non-Recursive -
7.Copy this Binary Tree to Another -
8.Delete All Node In Binary Tree -

Enter the Choice - 7

Tree Copied Successfully!
Pre-Order Traversing For Binary Tree Is - 50 18 17 22 16 14

0.Exit
1.Create BT -
2.Display Traversing (InOrder,PreOrder,PostOrder) -
3.Height For the Binary Tree -
4.Count number of leaves, number of internal nodes -
5.Change a BT so that the roles of the left and right pointers are swapped at every node -
6.Display Traversing Non-Recursive -
7.Copy this Binary Tree to Another -
8.Delete All Node In Binary Tree -

Enter the Choice - 2

InOrder Traversing is - 18 17 50 16 22 14

Pre Order Traversing is - 50 18 17 22 16 14

Post Order Traversing is - 17 18 16 14 22 50

0.Exit
1.Create BT -
2.Display Traversing (InOrder,PreOrder,PostOrder) -
3.Height For the Binary Tree -
4.Count number of leaves, number of internal nodes -
5.Change a BT so that the roles of the left and right pointers are swapped at every node -
6.Display Traversing Non-Recursive -
7.Copy this Binary Tree to Another -
8.Delete All Node In Binary Tree -

Enter the Choice - 8
All Node In Binary Tree Deleted Successfully!

0.Exit
1.Create BT -
2.Display Traversing (InOrder,PreOrder,PostOrder) -
3.Height For the Binary Tree -
4.Count number of leaves, number of internal nodes -
5.Change a BT so that the roles of the left and right pointers are swapped at every node -
6.Display Traversing Non-Recursive -
7.Copy this Binary Tree to Another -
8.Delete All Node In Binary Tree -

Enter the Choice - 2

No Tree Exits!

0.Exit
1.Create BT -
2.Display Traversing (InOrder,PreOrder,PostOrder) -
3.Height For the Binary Tree -
4.Count number of leaves, number of internal nodes -
5.Change a BT so that the roles of the left and right pointers are swapped at every node -
6.Display Traversing Non-Recursive -
7.Copy this Binary Tree to Another -
8.Delete All Node In Binary Tree -

Enter the Choice - 0
PS D:\SEM-4\DSA\DSA_Assighmnet> 
*/