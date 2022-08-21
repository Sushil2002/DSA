//===========================================================================
// Name        : DSAL_Assigmnment_06.cpp
// Author      : Sushilkumar Dhamane
// Roll No     : 21123
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


/*Represent a given graph using adjacency list to perform DFS and BFS. Use the map of the area around the college as the graph. Identify the prominent landmarks as nodes and perform DFS and BFS on that.
 */

#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define MAX 10
using namespace std;
class Node
{
    int data;
    Node *next;

public:
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int i)
    {
        next = NULL;
        data = i;
    }
    friend class Graph;
    friend class Queue;
};
class Queue
{
    Node *q[50];
    int front = -1;
    int rear = -1;

public:
    void Enqueue(Node *ptr)
    {
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }
        q[rear] = ptr;
    }
    Node *Dequeue()
    {
        Node *t1 = new Node;
        t1 = q[front];
        front++;
        return t1;
    }
    int Empty()
    {
        if (front == (rear + 1) || front == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
class Graph
{
    int v, e;
    Node **head;
    int *visted;
    // A pointer is used to store the address of variables. So, when we define a pointer to pointer, the first
    // pointer is used to store the address of the second pointer. Thus it is known as double pointers.
public:
    Graph()
    {
        v = e = 0;
        head = NULL;
        visted = 0;
    }
    Graph(int nv, int ne)
    {
        v = nv;
        e = ne;
        visted = new int[v];
        head = new Node *[v];
        for (int i = 0; i < v; i++)
        {
            head[i] = new Node(i);
        }
        for (int i = 0; i < v; i++)
        {
            visted[i] = 0;
        }
    }
    void Create_Graph()
    {
        for (int i = 0; i < e; i++)
        {
            int src, dest;
            cout << "\nEnter the Source data:-";
            cin >> src;
            cout << "\nEnter the destination data:-";
            cin >> dest;

            Node *newnode1 = new Node(dest);
            Node *newnode2 = new Node(src);
            Node *temp = head[src];
            if (temp == NULL)
            {
                head[src] = newnode2;
                head[src]->next = newnode1;
            }
            else
            {
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newnode1;
            }
        }
    }
    void Display_Representation()
    {
        for (int i = 0; i < v; i++)
        {
            Node *temp = head[i];
            cout << "[ " << i << " ] :";
            while (temp->next != NULL)
            {
                cout << temp->data << "-->";
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
    }
    void DFS(int v)
    {
        Node *temp;
        visted[v] = 1;
        if (head[v] != NULL)
        {
            cout << head[v]->data;
        }
        temp = head[v]->next;
        while (temp != NULL)
        {
            int t = temp->data; 
            if (visted[t] == 0)
            {
                cout << "  "; 
                DFS(t);
            }
            temp = temp->next;
        }
    }
    void BFS(int v1)
    {
        Queue q;
        bool visited[v] = {false};
        q.Enqueue(head[v1]);
        visited[head[v1]->data] = true;
        while (!q.Empty())
        {
            Node *ptr = q.Dequeue();
            cout << ptr->data << "  ";
            Node *temp = head[ptr->data];
            while (temp != NULL)
            {
                if (visited[temp->data] == false)
                {
                    q.Enqueue(head[temp->data]);
                    visited[temp->data] = true;
                }
                else
                {
                    temp = temp->next;
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    int v, e, ver;
    cout << "\n\nEnter TOtal Number of Vertices - ";
    cin >> v;
    cout << "\nEnter TOtal Number of Edges - ";
    cin >> e;
    Graph g1(v, e);
    int ch;
    do
    {
        cout << "\n1.Create Graph - " << endl;
        cout << "2.Display Adjacency List Represenation - " << endl;
        cout << "3.Display DFS for graph - " << endl;
        cout << "4.Display BFS for graph - " << endl;
        cout << "\nEnter the Choice - ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            g1.Create_Graph();
            break;
        case 2:
            g1.Display_Representation();
            break;
        case 3:
            cout << "DFS(Depth first Search) for Above Graph is " << endl;
            g1.DFS(0);
            cout << endl;
            break;
        case 4:
            int x;
            cout << "Enter the start Vertex  -";
            cin >> x;
            cout << "BFS(Breath first Search) for Above Graph is " << endl;
            g1.BFS(x);
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

Enter TOtal Number of Vertices - 4

Enter TOtal Number of Edges - 6

1.Create Graph - 
2.Display Adjacency List Represenation - 
3.Display DFS for graph - 
4.Display BFS for graph - 

Enter the Choice - 1

Enter the Source data:-0

Enter the destination data:-1

Enter the Source data:-1

Enter the destination data:-3

Enter the Source data:-3

Enter the destination data:-2

Enter the Source data:-2

Enter the destination data:-0

Enter the Source data:-0

Enter the destination data:-3

Enter the Source data:-2

Enter the destination data:-1

1.Create Graph -
2.Display Adjacency List Represenation -
3.Display DFS for graph -
4.Display BFS for graph -

Enter the Choice - 2
[ 0 ] :0-->1-->3
[ 1 ] :1-->3
[ 2 ] :2-->0-->1
[ 3 ] :3-->2

1.Create Graph -
2.Display Adjacency List Represenation -
3.Display DFS for graph -
4.Display BFS for graph -

Enter the Choice - 3
DFS(Depth first Search) for Above Graph is 
0  1  3  2

1.Create Graph -
2.Display Adjacency List Represenation -
3.Display DFS for graph -
4.Display BFS for graph -

Enter the Choice - 4
Enter the start Vertex  -0
BFS(Breath first Search) for Above Graph is 
0  1  3  2

1.Create Graph -
2.Display Adjacency List Represenation -
3.Display DFS for graph -
4.Display BFS for graph -

Enter the Choice - 0
PS D:\SEM-4\DSA\DSA_Assighmnet> 
*/