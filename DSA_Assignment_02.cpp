//============================================================================
// Name        : DSAL_Assigmnment_02.cpp
// Author      : Sushilkumar Dhamane
// Roll No     : 21123
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


/*A Dictionary store keywords and its meanings. Provide facility for adding new keywords, deleting keywords,
   updating values of any entry. Provide facility to display whole data sorted
   in ascending/ Descending order. Also Search_recursion how many maximum comparisons may
   require for finding any keyword. Use Binary Search_Iterative Tree for implementation.
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
    string data1, data2;
    Node *right;
    Node *left;

public:
    Node()
    {
        right = NULL;
        left = NULL;
    }
    friend class BST;
};
class BST
{
    Node *root;

public:
    BST() { root = NULL; }
    void Create()
    {
        string s1, s2;
        Node *temp = new Node;
        cout << "\nEnter the KeyWord - ";
        cin >> s1;
        cout << "\nEnter the Meaning - ";
        cin >> s2;
        temp->data1 = s1;
        temp->data2 = s2;
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            Node *ptr = root;
            while (ptr != NULL)
            {
                if (s1 < ptr->data1)
                {
                    if (ptr->left == NULL)
                    {
                        ptr->left = temp;
                        break;
                    }
                    else
                    {
                        ptr = ptr->left;
                    }
                }
                else if (s1 > ptr->data1)
                {
                    if (ptr->right == NULL)
                    {
                        ptr->right = temp;
                        break;
                    }
                    else
                    {
                        ptr = ptr->right;
                    }
                }
                else
                {
                    cout << "\nDublicate Element Are Not Allowed!" << endl;
                    break;
                }
            }
        }
    }
    void InOrder(Node *temp1)
    {
        if (temp1 != NULL)
        {
            InOrder(temp1->left);
            cout << temp1->data1 << "   :   ";
            cout << temp1->data2 << endl;
            InOrder(temp1->right);
        }
    }
    void PreOrder(Node *temp1)
    {
        if (temp1 != NULL)
        {
            cout << temp1->data1 << "   :   ";
            cout << temp1->data2 << endl;
            PreOrder(temp1->left);
            InOrder(temp1->right);
        }
    }
    void PostOrder(Node *temp1)
    {
        if (temp1 != NULL)
        {
            PreOrder(temp1->left);
            InOrder(temp1->right);
            cout << temp1->data1 << "   :   ";
            cout << temp1->data2 << endl;
        }
    }
    void Display_Inorder()
    {
        cout << "\nInOrder Traversing is - " << endl;
        InOrder(root);
        cout << "\n\nPre Order Traversing is - " << endl;
        PreOrder(root);
        cout << "\n\nPost Order Traversing is - " << endl;
        PostOrder(root);
    }
    void Revrese_inorder(Node *temp1)
    {
        if (temp1 != NULL)
        {
            Revrese_inorder(temp1->right);
            cout << temp1->data1 << " : " << temp1->data2 << endl;
            Revrese_inorder(temp1->left);
        }
    }
    void Display_Acending()
    {
        InOrder(root);
    }
    void Display_Decending()
    {
        Revrese_inorder(root);
    }
    // 1.In Binary Tree the Searching Complexity is O(n)->Each Element Need to Be eiterate
    // 2.In Binary Search_Iterative Tree the Searching Complexity is O(logn)->In this the key key is eihter On left Or Right Side of the Root(According to Propety of BST)
    // 3.In Worst case complexicity the Elemnt is leaf Node then we can say that complexity is equal to height of Binary tree.
    Node *search_it(Node *root, string key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else
        {
            while (root != NULL)
            {
                if (root->data1 == key)
                {
                    cout << "\nData Found" << endl;
                    cout << key << "  -  " << root->data2 << endl;
                    return root;
                }
                if (root->data1 < key)
                {
                    root = root->right;
                }
                else
                {
                    root = root->left;
                }
            }
            cout << "Oops Data Not Found!" << endl;
            return NULL;
        }
    }
    void Serch_it_display()
    {
        string key;
        cout << "ENter the Key - ";
        cin >> key;
        search_it(root, key);
    }
    // Search_Iterative Using withnout Recursion
    void Search_Iterative()
    {
        string key;
        cout << "Enter the KeyWord Which Need To Be Searched - ";
        cin >> key;
        Node *loc, *par;
        if (root == NULL)
        {
            cout << "\nNO Binary Tree Exits!" << endl;
            loc = NULL;
            par = NULL;
        }
        loc = par = NULL;
        int count = 0;
        Node *ptr = root;
        while (ptr != NULL)
        {
            if (key == ptr->data1)
            {
                loc = ptr;
                if (key == root->data1)
                {
                    count++;
                    cout << "Data Found!" << endl;
                    cout << "You Searched For Root Node - " << endl;
                    cout << loc->data1 << " : " << loc->data2 << endl;
                    cout << "Number Of Comparision Required Are - " << count << endl;
                    break;
                }
                else
                {
                    cout << "\nKeyWord Found!" << endl;
                    cout << loc->data1 << " : " << loc->data2 << " And Its Parent is " << par->data1 << endl;
                    cout << "Number Of Comparision Required Are - " << count + 1 << endl;
                    break;
                }
            }
            else if (key < ptr->data1)
            {
                count++;
                par = ptr;
                ptr = ptr->left;
            }
            else
            {
                count++;
                par = ptr;
                ptr = ptr->right;
            }
        }
        if (loc == NULL)
        {
            cout << "Number Of Comparision Required Are - " << count << endl;
            cout << "\nNo Data Found!" << endl;
        }
    }

    // Search_Iterative Using Recursion
    void Search_recursion(Node *root, string x)
    {
        if (root->data1 == x)
        {
            cout << "Data Found!" << endl;
            cout << x << "<--->" << root->data2 << endl;
            // return root;
        }
        else
        {
            if (x > root->data1)
            {
                Search_recursion(root->right, x);
            }
            else
            {
                Search_recursion(root->left, x);
            }
            // return root;
        }
    }
    void Search_Call()
    {
        string x;
        cout << "Enter the Word to Be Search_wrecursion - ";
        cin >> x;
        Search_recursion(root, x);
    }
    Node *InoerderPreedeccorr(Node *root)
    {
        Node *temp = root->left;
        while (temp != NULL)
        {
            temp = temp->right;
        }
        return temp;
    }
    void Update()
    {
        string key, newvaule;
        cout << "\nEnter the Keyword Whose Vaule Need to be Update - ";
        cin >> key;
        Node *loc, *par;
        if (root == NULL)
        {
            cout << "\nNO Binary Tree Exits!" << endl;
            loc = NULL;
            par = NULL;
        }
        loc = par = NULL;
        Node *ptr = root;
        while (ptr != NULL)
        {
            if (key == ptr->data1)
            {
                loc = ptr;
                cout << "\nEnter the New Meaning for " << key << " - ";
                cin >> newvaule;
                if (key == root->data1)
                {
                    root->data2 = newvaule;
                    break;
                }
                loc->data2 = newvaule;
                break;
            }
            else if (key < ptr->data1)
            {
                par = ptr;
                ptr = ptr->left;
            }
            else
            {
                par = ptr;
                ptr = ptr->right;
            }
        }
    }
    Node *DeleteInBST(Node *root, string key)
    {
        Node *temp = root;
        if (root == NULL)
        {
            return root;
        }
        else if (key < root->data1)
        {
            root->left = DeleteInBST(root->left, key);
            return root;
        }
        else if (key > root->data1)
        {
            root->right = DeleteInBST(root->right, key);
            return root;
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                temp = root;
                delete temp;
                return NULL;
            }
            if (root->left == NULL)
            {
                temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            if (root->right == NULL)
            {
                temp = root;
                root = root->left;
                delete temp;
                return root;
            }
            temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data1 = temp->data1;
            root->data2 = temp->data2;
            root->right = DeleteInBST(root->right, temp->data1);
            return root;
        }
    }
    void Display_Delete()
    {
        string key;
        cout << "\nEnter the Word Need To Be Deleted - ";
        cin >> key;
        DeleteInBST(root, key);
    }
};
int main()
{
    BST t;
    int ch;
    do
    {
        cout << "\n1.Add Node To  BST - " << endl;
        cout << "2.Display Traversing(InOrder,PreOrder,PostOrder) - " << endl;
        cout << "3.Display Data In Ascending Order - " << endl;
        cout << "4.Display Data In Decending Order - " << endl;
        cout << "5.Search_Iterative For KeyWord(without Recursion) - " << endl;
        cout << "6.Update the Meaning - " << endl;
        cout << "7.Delete Node In Binary Search_Iterative Tree - " << endl;
        cout << "8.Search_Iterative Iterative TehKnowlege - " << endl;
        cout << "9. Search_Iterative keyword Using Recursion -  " << endl;
        cout << "\nEnter choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            t.Create();
            break;
        case 2:
            t.Display_Inorder();
            break;
        case 3:
            cout << "\nAscending Order Is - " << endl;
            t.Display_Acending();
            cout << endl;
            break;
        case 4:
            cout << "\nDecending Order Is - " << endl;
            t.Display_Decending();
            cout << endl;
            break;
        case 5:
            t.Search_Iterative();
            break;
        case 6:
            t.Update();
            cout << "\nData Updated SuccessFully!" << endl;
            break;
        case 7:
            t.Display_Delete();
            cout << "\nNode Deleted SuccessFully!" << endl;
            break;
        case 8:
            t.Serch_it_display();
            break;
        case 9:
            t.Search_Call();
            break;
        default:
            break;
        }
    } while (ch != 0);

    return 0;
}

/*
                             PICT : PUNE
                        /                   \
                HOUSE:FAMILY            RIGHT:CORRECT
                /       \                    /    \
        APPLE:FRIUT        NULL            NULL       ZEBRA:ANIMAL
*/

/*
=================================>
*****    OUTPUT   *****
================================>
1.Add Node To  BST -
2.Display Traversing(InOrder,PreOrder,PostOrder) -
3.Display Data In Ascending Order -
4.Display Data In Decending Order -
5.Search_Iterative For KeyWord(without Recursion) -
6.Update the Meaning -
7.Delete Node In Binary Search_Iterative Tree -
8.Search_Iterative Iterative TehKnowlege -
9. Search_Iterative keyword Using Recursion -

Enter choice:1

Enter the KeyWord - pict

Enter the Meaning - pune

1.Add Node To  BST - 
2.Display Traversing(InOrder,PreOrder,PostOrder) - 
3.Display Data In Ascending Order - 
4.Display Data In Decending Order - 
5.Search_Iterative For KeyWord(without Recursion) -
6.Update the Meaning -
7.Delete Node In Binary Search_Iterative Tree -
8.Search_Iterative Iterative TehKnowlege -
9. Search_Iterative keyword Using Recursion -

Enter choice:1

Enter the KeyWord - house

Enter the Meaning - family

1.Add Node To  BST -
2.Display Traversing(InOrder,PreOrder,PostOrder) -
3.Display Data In Ascending Order -
4.Display Data In Decending Order -
5.Search_Iterative For KeyWord(without Recursion) -
6.Update the Meaning -
7.Delete Node In Binary Search_Iterative Tree -
8.Search_Iterative Iterative TehKnowlege -
9. Search_Iterative keyword Using Recursion -

Enter choice:1    

Enter the KeyWord - right

Enter the Meaning - correct

1.Add Node To  BST -
2.Display Traversing(InOrder,PreOrder,PostOrder) -
3.Display Data In Ascending Order -
4.Display Data In Decending Order -
5.Search_Iterative For KeyWord(without Recursion) -
6.Update the Meaning -
7.Delete Node In Binary Search_Iterative Tree -
8.Search_Iterative Iterative TehKnowlege -
9. Search_Iterative keyword Using Recursion -

Enter choice:1

Enter the KeyWord - apple

Enter the Meaning - fruit

1.Add Node To  BST -
2.Display Traversing(InOrder,PreOrder,PostOrder) -
3.Display Data In Ascending Order -
4.Display Data In Decending Order -
5.Search_Iterative For KeyWord(without Recursion) -
6.Update the Meaning -
7.Delete Node In Binary Search_Iterative Tree -
8.Search_Iterative Iterative TehKnowlege -
9. Search_Iterative keyword Using Recursion -

Enter choice:1

Enter the KeyWord - zebra

Enter the Meaning - animal

1.Add Node To  BST -
2.Display Traversing(InOrder,PreOrder,PostOrder) -
3.Display Data In Ascending Order -
4.Display Data In Decending Order -
5.Search_Iterative For KeyWord(without Recursion) -
6.Update the Meaning -
7.Delete Node In Binary Search_Iterative Tree -
8.Search_Iterative Iterative TehKnowlege -
9. Search_Iterative keyword Using Recursion -

Enter choice:2

InOrder Traversing is -
apple   :   fruit
house   :   family
pict   :   pune
right   :   correct
zebra   :   animal


Pre Order Traversing is -
pict   :   pune
house   :   family
apple   :   fruit
right   :   correct
zebra   :   animal


Post Order Traversing is -
house   :   family
apple   :   fruit
right   :   correct
zebra   :   animal
pict   :   pune

1.Add Node To  BST -
2.Display Traversing(InOrder,PreOrder,PostOrder) -
3.Display Data In Ascending Order -
4.Display Data In Decending Order -
5.Search_Iterative For KeyWord(without Recursion) -
6.Update the Meaning -
7.Delete Node In Binary Search_Iterative Tree -
8.Search_Iterative Iterative TehKnowlege -
9. Search_Iterative keyword Using Recursion -

Enter choice:3

Ascending Order Is -
apple   :   fruit
house   :   family
pict   :   pune
right   :   correct
zebra   :   animal


1.Add Node To  BST -
2.Display Traversing(InOrder,PreOrder,PostOrder) -
3.Display Data In Ascending Order -
4.Display Data In Decending Order -
5.Search_Iterative For KeyWord(without Recursion) -
6.Update the Meaning -
7.Delete Node In Binary Search_Iterative Tree -
8.Search_Iterative Iterative TehKnowlege -
9. Search_Iterative keyword Using Recursion -

Enter choice:4

Decending Order Is -
zebra : animal
right : correct
pict : pune
house : family
apple : fruit


1.Add Node To  BST -
2.Display Traversing(InOrder,PreOrder,PostOrder) -
3.Display Data In Ascending Order -
4.Display Data In Decending Order -
5.Search_Iterative For KeyWord(without Recursion) -
6.Update the Meaning -
7.Delete Node In Binary Search_Iterative Tree -
8.Search_Iterative Iterative TehKnowlege -
9. Search_Iterative keyword Using Recursion -

Enter choice:5
Enter the KeyWord Which Need To Be Searched - pict
Data Found!
You Searched For Root Node -
pict : pune
Number Of Comparision Required Are - 1

1.Add Node To  BST -
2.Display Traversing(InOrder,PreOrder,PostOrder) -
3.Display Data In Ascending Order -
4.Display Data In Decending Order -
5.Search_Iterative For KeyWord(without Recursion) -
6.Update the Meaning -
7.Delete Node In Binary Search_Iterative Tree -
8.Search_Iterative Iterative TehKnowlege -
9. Search_Iterative keyword Using Recursion -

Enter choice:6

Enter the Keyword Whose Vaule Need to be Update - pict 

Enter the New Meaning for pict - college

Data Updated SuccessFully!

1.Add Node To  BST -
2.Display Traversing(InOrder,PreOrder,PostOrder) -
3.Display Data In Ascending Order -
4.Display Data In Decending Order -
5.Search_Iterative For KeyWord(without Recursion) -
6.Update the Meaning -
7.Delete Node In Binary Search_Iterative Tree -
8.Search_Iterative Iterative TehKnowlege -
9. Search_Iterative keyword Using Recursion -

Enter choice:3

Ascending Order Is -
apple   :   fruit
house   :   family
pict   :   college
right   :   correct
zebra   :   animal


1.Add Node To  BST -
2.Display Traversing(InOrder,PreOrder,PostOrder) -
3.Display Data In Ascending Order -
4.Display Data In Decending Order -
5.Search_Iterative For KeyWord(without Recursion) -
6.Update the Meaning -
7.Delete Node In Binary Search_Iterative Tree -
8.Search_Iterative Iterative TehKnowlege - 
9. Search_Iterative keyword Using Recursion -

Enter choice:7

Enter the Word Need To Be Deleted - pict

Node Deleted SuccessFully!

1.Add Node To  BST -
2.Display Traversing(InOrder,PreOrder,PostOrder) -
3.Display Data In Ascending Order -
4.Display Data In Decending Order -
5.Search_Iterative For KeyWord(without Recursion) -
6.Update the Meaning -
7.Delete Node In Binary Search_Iterative Tree -
8.Search_Iterative Iterative TehKnowlege -
9. Search_Iterative keyword Using Recursion -

Enter choice:3

Ascending Order Is -
apple   :   fruit
house   :   family
right   :   correct
zebra   :   animal


1.Add Node To  BST -
2.Display Traversing(InOrder,PreOrder,PostOrder) -
3.Display Data In Ascending Order -
4.Display Data In Decending Order -
5.Search_Iterative For KeyWord(without Recursion) -
6.Update the Meaning -
7.Delete Node In Binary Search_Iterative Tree -
8.Search_Iterative Iterative TehKnowlege -
9. Search_Iterative keyword Using Recursion -

Enter choice:8
ENter the Key - zebra

Data Found
zebra  -  animal

1.Add Node To  BST -
2.Display Traversing(InOrder,PreOrder,PostOrder) -
3.Display Data In Ascending Order -
4.Display Data In Decending Order -
5.Search_Iterative For KeyWord(without Recursion) -
6.Update the Meaning -
7.Delete Node In Binary Search_Iterative Tree -
8.Search_Iterative Iterative TehKnowlege -
9. Search_Iterative keyword Using Recursion -

Enter choice:0
PS D:\SEM-4\DSA\DSA_Assighmnet> 
*/