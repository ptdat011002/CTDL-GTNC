#include <iostream>
#include <fstream>

#define max 100

using namespace std;

typedef struct EdgeTag
{
    int u, v;
} edge;

typedef struct GraphTag
{
    edge e[max];
    int m;
} graph;

void nhap(graph &g)
{
    ifstream fi("D:\\Code\\Cau truc du lieu va giai thuat nang cao\\dsCanh.txt");
    if (fi.is_open() == true)
    {
        fi >> g.m;
        for (int i = 0; i < g.m; i++)
        {
            fi >> g.e[i].u >> g.e[i].v;
        }
    }
}

void xuat(graph g)
{
    cout << "Danh sach canh : " << g.m << endl;
    for (int i = 0; i < g.m; i++)
    {
        cout << g.e[i].u << " " << g.e[i].v << endl;
    }
}

int main(int argc, char const *argv[])
{
    graph g;
    nhap(g);
    xuat(g);
    return 0;
}


