#include <iostream>
using namespace std;
class Graph
{
    int v;
    int e;
    int **head;
    bool *visited;

public:
    Graph(int vert = 0, int edg = 0)
    {
        v = vert;
        e = edg;
        head = new int *[v];
        visited = new bool[v];
        for (int i = 0; i < v; i++)
        {
            visited[i] = 0;
            head[i] = new int[v];
        }
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                head[i][j] = 99999;
            }
        }
    }
    void ResetVisit()
    {
        for (int i = 0; i < v; i++)
        {
            visited[i] = 0;
        }
    }
    void Create()
    {
        for (int i = 0; i < e; i++)
        {
            int src, dest, wt;
            cout << "Enter Source: ";
            cin >> src;
            cout << "Enter Destination: ";
            cin >> dest;
            cout << "Enter Weight: ";
            cin >> wt;
            head[src][dest] = head[dest][src] = wt;
        }
    }
    void Display()
    {
        cout << "---------------------------------" << endl;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << head[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "---------------------------------" << endl;
    }

    bool isvalid(int u, int v)
    {
        if (u == v)
            return 0;
        if (visited[u] == 0 && visited[v] == 0)
            return 0;
        else if (visited[u] == 1 && visited[v] == 1)
            return 0;
        return 1;
    }

    void prims()
    {
        cout << "--------------PRIM'S ALGORITHM--------------" << endl;
        ResetVisit();
        visited[0] = 1;
        int edge_count = 0;
        int mincost = 0;
        int a, b;
        while (edge_count < v - 1)
        {
            int min = 99999,
                a = b = -1;
            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < v; j++)
                {
                    if (head[i][j] < min)
                    {
                        if (isvalid(i, j)) // checks and finds the minimum weight edge among the adjacent vertices of current MST
                        {
                            min = head[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }
            if (a != (-1) && b != (-1))
            {
                cout << "Edge " << edge_count++ << ": (" << a << "," << b << ")\tCost: " << min << endl;
                mincost = mincost + min;
                visited[b] = visited[a] = 1;  
            }
        }
        cout << "Minimum cost:" << mincost << endl;
        cout << "--------------------------------------------" << endl;
    }
};

int main()
{
    int verti, desti;
    cout << "Enter number of vertices: ";
    cin >> verti;
    cout << "Enter number of edges: ";
    cin >> desti;
    Graph g(verti, desti);
    g.Create();
    g.Display();
    g.prims();

    return 0;
}