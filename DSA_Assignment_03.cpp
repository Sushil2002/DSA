//============================================================================
// Name        : DSAL_Assigmnment_03.cpp
// Author      : Sushilkumar Dhamane
// Roll No     : 21123
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


/*Create an inordered threaded binary tree and perform inorder and preorder traversals. Analyze time and space complexity of the algorithm.
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
    Node *right, *left;
    int data;
    int lbit, rbit;

public:
    Node()
    {
        right = NULL;
        left = NULL;
        data = 0;
        lbit = 0;
        rbit = 0;
    }
    friend class TBT;
};
class TBT
{
    Node *root, *head;

public:
    TBT()
    {
        root = NULL;
        head = NULL;
    }
    void Create()
    {

        Node *temp = new Node;
        int x;
        cout << "Enter the Data - ";
        cin >> x;
        temp->data = x;
        if (root == NULL)
        {
            Node *head = new Node;
            head->data = -999;
            root = temp;
            head->left = root;
            head->lbit = 1;
            root->left = head;
            root->right=head;
            root->rbit=0;
        }
        else
        {
            Node *ptr = root;
            while (true)
            {
                if (x < ptr->data)
                {
                    if (ptr->lbit != 0)
                    {
                        ptr = ptr->left;
                    }
                    else
                    {
                        temp->lbit = 0;
                        temp->rbit = 0;
                        temp->left = ptr->left;
                        temp->right = ptr;
                        ptr->left = temp;
                        ptr->lbit = 1;
                        return;
                    }
                }
                else if (x > ptr->data)
                {
                    if (ptr->rbit != 0)
                    {
                        ptr = ptr->right;
                    }
                    else
                    {
                        temp->lbit = 0;
                        temp->rbit = 0;
                        temp->right = ptr->right;
                        ptr->right = temp;
                        temp->left = ptr;
                        ptr->rbit = 1;
                        return;
                    }
                }
                else
                {
                    cout << "Dublicate Vaule Inserted!" << endl;
                }
            }
        }
    }
    void Inorder(Node *temp, Node *dummy)
    {
        while (temp->right != dummy)
        {
            while (temp->lbit == 1)
            {
                temp = temp->left;
            }
            cout << temp->data << " ";
            while (temp->rbit == 0)
            {
                temp = temp->right;
                if (temp->right == dummy)
                {
                    return;
                }
                cout << temp->data << " ";
            }
            temp = temp->right;
        } 
    }
    void Preorder(Node *temp, Node *dummy)
    {
        while (temp != dummy)
        {
            cout << temp->data << " ";
            while (temp->lbit ==1)
            {
                temp = temp->left;
                cout << temp->data << " ";
            }
            while (temp->rbit == 0)
            {
                temp = temp->right;
                if (temp == head)
                {
                    return;
                }
            }
            temp = temp->right;
        }
    }
    void Display_Inorder()
    {

        Inorder(root, head);
    }
    void Display_Preorder()
    {
        Preorder(root, head);
    }
};
int main()
{
    TBT t;
    int ch;
    do
    {
        cout << "\n1.Add Node - \n2.Display Inorder- " << endl;
        cout << "3.Display Preorder - " << endl;
        cout << "Enter Choice - ";
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
            t.Display_Preorder();
            break;
        default:
            break;
        }
    } while (ch != 0);

    return 0;
}
/*
=================================>
*****    OUTPUT   *****
================================>
1.Add Node -
2.Display Inorder-
3.Display Preorder -
Enter Choice - 1
Enter the Data - 10

1.Add Node - 
2.Display Inorder- 
3.Display Preorder - 
Enter Choice - 1
Enter the Data - 5

1.Add Node - 
2.Display Inorder- 
3.Display Preorder - 
Enter Choice - 1
Enter the Data - 2

1.Add Node - 
2.Display Inorder- 
3.Display Preorder - 
Enter Choice - 1
Enter the Data - 3

1.Add Node -
2.Display Inorder-
3.Display Preorder -
Enter Choice - 1
Enter the Data - 41

1.Add Node -
2.Display Inorder-
3.Display Preorder -
Enter Choice - 1 
Enter the Data - 21

1.Add Node -
2.Display Inorder-
3.Display Preorder -
Enter Choice - 2

2 3 5 10 21 41 

1.Add Node -
2.Display Inorder-
3.Display Preorder -
Enter Choice - 3
10 5 2 3 41 21 

1.Add Node -
2.Display Inorder-
3.Display Preorder -
Enter Choice - 0
PS D:\SEM-4\DSA\DSA_Assighmnet> 
*/