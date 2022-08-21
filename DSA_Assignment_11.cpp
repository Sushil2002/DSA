//============================================================================
// Name        : DSAL_Assigmnment_11.cpp
// Author      : Sushilkumar Dhamane
// Roll No     : 21123
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*Implement  the  Heap  sort  algorithm  implemented  in  CPP/Java  demonstrating  heap 
data structure with modularity of programming language.
*/

#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;
class DataBase
{
    int *Heap;
    int size;

public:
    DataBase()
    {
        size = 0;
        Heap = new int[size];
    }
    void Insert(int key)
    {
        size++;
        Heap[size - 1] = key;
        int ptr = size - 1;
        while (ptr > 0)
        {
            int parent = (ptr - 1) / 2;
            if (Heap[ptr] < Heap[parent])
            {
                int temp = Heap[ptr];
                Heap[ptr] = Heap[parent];
                Heap[parent] = temp;
                ptr = parent;
            }
            else
            {
                break;
            }
        }
    }
    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << Heap[i] << "  ";
        }
        cout << endl;
    }
    void Delete()
    {
        if (size == 0)
        {
            cout << "\nHeap is Empty!" << endl;
        }
        else
        {
            int ptr = 0, lchild = 1, rchild = 2;
            cout << Heap[0] << "  ";
            int last = Heap[size - 1];
            size = size - 1;
            while (rchild <= size - 1)
            {
                if (last <= Heap[lchild] && last <= Heap[rchild])
                {
                    Heap[ptr] = last;
                    break;
                }
                if (Heap[lchild] < Heap[rchild])
                {
                    Heap[ptr] = Heap[lchild];
                    ptr = lchild;
                }
                else
                {
                    Heap[ptr] = Heap[rchild];
                    ptr = rchild;
                }
                lchild = 2 * ptr + 1;
                rchild = lchild + 1;
            }
            if (lchild == size - 1 && last > Heap[lchild])
            {
                Heap[ptr] = Heap[lchild];
                ptr = lchild;
            }
            Heap[ptr] = last;
        }
    }
    void Sorting()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            Delete();
        }
    }
};
int main()
{
    DataBase d;
    int ch;
    do
    {
        cout << "\n1.Insert Data(In Heap) - " << endl;
        cout << "2.Display Representaion of Tree- " << endl;
        cout << "3.Display Heap Sort - " << endl;
        cout << "\nEnter the Choice - ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int x;
            cout << "\nEnter the Element - ";
            cin >> x;
            d.Insert(x);
            break;
        case 2:
            d.Display();
            break;
        case 3:
            cout << endl;
            d.Sorting();
            cout << endl;
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
1.Insert Data(In Heap) -
2.Display Representaion -
3.Display Heap Sort -

Enter the Choice - 1

Enter the Element - 10

1.Insert Data(In Heap) -
2.Display Representaion -
3.Display Heap Sort -

Enter the Choice - 1

Enter the Element - 3

1.Insert Data(In Heap) -
2.Display Representaion -
3.Display Heap Sort -

Enter the Choice - 1

Enter the Element - 7

1.Insert Data(In Heap) -
2.Display Representaion -
3.Display Heap Sort -

Enter the Choice - 1

Enter the Element - 5

1.Insert Data(In Heap) -
2.Display Representaion -
3.Display Heap Sort -

Enter the Choice - 1

Enter the Element - 50

1.Insert Data(In Heap) -
2.Display Representaion -
3.Display Heap Sort -

Enter the Choice - 1

Enter the Element - 70

1.Insert Data(In Heap) -
2.Display Representaion -
3.Display Heap Sort -

Enter the Choice - 1

Enter the Element - 15

1.Insert Data(In Heap) -
2.Display Representaion -
3.Display Heap Sort -

Enter the Choice - 1

Enter the Element - 30

1.Insert Data(In Heap) -
2.Display Representaion -
3.Display Heap Sort -

Enter the Choice - 1

Enter the Element - 1

1.Insert Data(In Heap) -
2.Display Representaion -
3.Display Heap Sort -

Enter the Choice - 1

Enter the Element - 9

1.Insert Data(In Heap) -
2.Display Representaion -
3.Display Heap Sort -

Enter the Choice - 1

Enter the Element - 11

1.Insert Data(In Heap) -
2.Display Representaion -
3.Display Heap Sort -

Enter the Choice - 2
1  3  7  5  9  70  15  30  10  50  11

1.Insert Data(In Heap) -
2.Display Representaion -
3.Display Heap Sort -

Enter the Choice - 3

1  3  5  7  9  10  11  15  30  50  70

1.Insert Data(In Heap) -
2.Display Representaion -
3.Display Heap Sort -

Enter the Choice - 0
PS D:\SEM-4\DSA\DSA_Assighmnet>
*/