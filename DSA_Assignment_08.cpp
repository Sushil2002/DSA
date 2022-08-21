//============================================================================
// Name        : DSAL_Assigmnment_08.cpp
// Author      : Sushilkumar Dhamane
// Roll No     : 21123
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


// Topological Sort=>Acylic and directed Graph Is Required!
/*PROBLEM STTATEMENT=>Write a C++/Java program to implement topological sorting on graph using object
oriented programming features Design necessary class. .( Use of graph)
*/
#include <bits/stdc++.h>
#include <iostream>
#define MAX 50
typedef long long ll;
using namespace std;
class Queue
{
    int Q[MAX];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    int top() // Return the top Element of the queue
    {
        return Q[front];
    }

    void Enqueue(int v)
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
        Q[rear] = v;
    }
    int Dequeue()
    {
        int x;
        x = Q[front];
        front++;
        return x;
    }
    int Empty()
    {
        if (front == rear + 1 || front == -1)
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
    ll G[100][100];
    ll TS[100];
    ll B[100];
    ll size;
    ll Q[MAX];
public:
    Graph(int m)
    {
        size = m;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                G[i][j] = 0;
            }
        }
    }
    void Insert(int x, int y)
    {
        if (G[y][x] == 0)
        {
            G[x][y] = 1;
        }
        else
        {
            cout << "\nGraph must be Directed!" << endl;
        }
    }
    int Indegree(int x)  //x is perticular vertex(vaule)!
    {
        int indeg_count = 0;
        for (int i = 0; i < size; i++)
        {
            if (G[i][x] == 1)
            {
                indeg_count++;
            }
        }
        return indeg_count;
    }
    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << G[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void Topological()
    {
        Queue q;
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            TS[i] = Indegree(i);
            if (TS[i] == 0)
            {
                q.Enqueue(i);
            }
        }
        while (!q.Empty())
        {
            int k = q.top();
            q.Dequeue();
            B[j++] = k;
            for (int i = 0; i < size; i++)
            {
                if (G[k][i] == 1)
                {
                    G[k][i] = 0;
                    TS[i] = TS[i] - 1;
                    if (TS[i] == 0)
                    {
                        q.Enqueue(i);
                    }
                }
            }
        }

        for (int i = 0; i < size; i++)
        {
            cout << B[i] << "  ";
        }
        cout << endl;
    }
    friend class Queue;
};

int main()
{
    int ch, v;
    cout << "\nEnter theTotal Number Of Vertex - ";
    cin >> v;
    Graph g(v);
    do
    {
        cout << "\n1.Create Graph - " << endl;
        cout << "2.To Display - " << endl;
        cout << "3.Display Topological Sort" << endl;
        cout << "\nEnter the Choice  - ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int e;
            cout << "\nEnter the Total Number of Edges - ";
            cin >> e;
            for (int i = 0; i < e; i++)
            {
                int x, y;
                cout << "\nEnter the source and Destination - ";
                cin >> x >> y;
                g.Insert(x, y);
            }
            break;
        case 2:
            g.Display();
            break;
        case 3:
            g.Topological();
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

Enter theTotal Number Of Vertex - 6 

1.Create Graph - 
2.To Display - 
3.Display Topological Sort

Enter the Choice  - 1

Enter the Total Number of Edges - 6

Enter the source and Destination - 5 0

Enter the source and Destination - 5 2

Enter the source and Destination - 4 0

Enter the source and Destination - 4 1

Enter the source and Destination - 2 3

Enter the source and Destination - 3 1

1.Create Graph -
2.To Display -
3.Display Topological Sort

Enter the Choice  - 2
0  0  0  0  0  0  
0  0  0  0  0  0
0  0  0  1  0  0
0  1  0  0  0  0  
1  1  0  0  0  0
1  0  1  0  0  0

1.Create Graph -
2.To Display -
3.Display Topological Sort

Enter the Choice  - 3
4  5  0  2  3  1  

1.Create Graph -
2.To Display -
3.Display Topological Sort

Enter the Choice  - 0
PS D:\SEM-4\DSA\DSA_Assighmnet> 
*/