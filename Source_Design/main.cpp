/**
 * 问题描述：有n个村庄，现要从这n个村庄中选择一个村庄新建一所医院，使其余的村庄到这所医院的距离总体来说较短，设计较合理。
     实现要求：可以将问题抽象为有n个接点，在这n个接点之间建立一个无向图，边上的权值w(i,j)表示村庄i到j之间道路的长度，
     在无向图中n个顶点之间，最多可能设置n(n-1)/2条线路，如何在这些线路中选择n-1条线路，
     以使总的线路最短？对于n个顶点的连通网可以建立许多不同的无向图，
     每一个无向图都可以表示一个道路网，其中要选择一个最优图，使图上各边之小。
 */
#include <iostream>
#include "Tree.cpp"
using namespace std;
#define MAXV 50
#define INF 32767
typedef int InfoType;
//邻接矩阵存储方法
typedef struct {
    int no;
    InfoType info;
} VertexType;
typedef struct {
    int edges[MAXV][MAXV];
    int n, e;
    VertexType vexs[MAXV];
} MGraph;

//狄克斯特拉算法
void Ppath(int path[], int i, int v) {
    int k;
    k = path[i];
    if (k == v)
        return;
    Ppath(path, k, v);
    cout << "->" << k;
}

int num = 0;

int DisPath(int dist[], int path[], int n, int v) {
    for (int i = 0; i < n; i++) {
        if (i == v)
            continue;//除去自己
        else {
            if (dist[i] >= 10)
                cout << "从" << v << "到" << i << "的最短路径为：" << dist[i] << " ";
            else
                cout << "从" << v << "到" << i << "的最短路径为：" << dist[i] << "  "; //小于10的数多加一个空格，使其排列整齐
            cout << v;
            Ppath(path, i, v);
            cout << "->" << i << endl;
            num += dist[i];//路径之和


        }

    }
    cout << "和为：" << " " << num << endl;
    int num1 = num;
    num = 0;
    return num1;
}

void Dijkstra(MGraph g, int v, int A[]) {
    int dist[MAXV], path[MAXV];
    int s[MAXV];
    int mindis, i, j, u;
    for (i = 0; i < g.n; i++) {
        dist[i] = g.edges[v][i];
        s[i] = 0;
        if (g.edges[v][i] < INF)
            path[i] = v;
        else
            path[i] = -1;
    }
    s[v] = 1;
    path[v] = 0;
    for (i = 0; i < g.n - 1; i++) {
        mindis = INF;
        for (j = 0; j < g.n; j++) {
            if (s[j] == 0 && dist[j] < mindis) {
                u = j;
                mindis = dist[j];
            }
        }
        s[u] = 1;
        for (j = 0; j < g.n; j++) {
            if (s[j] == 0) {
                if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j]) {
                    dist[j] = dist[u] + g.edges[u][j];
                    path[j] = u;
                }
            }
        }
    }
    A[v] = DisPath(dist, path, g.n, v);
}

void Creat_Village() {
    int n;
    MGraph g;
    cout << "请输入无向图的顶点个数：";
    cin >> n;
    int *A = new int[n];
    cout << "请输入无向图的邻接矩阵：" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> g.edges[i][j];
        }
    g.n = n;
    cout << "采用狄克斯特拉算法得到的最短路径为：" << endl;
    for (int i = 0; i < n; i++)
        Dijkstra(g, i, A);
    int min = A[0];
    for (int i = 1; i < n; i++)
        if (min > A[i]) {
            min = A[i];
        }
    cout << "经过比较可得：第 ";
    for (int i = 0; i < n; i++) {
        if (A[i] == min)
            cout << i << " ";//可能有多个符合要求

    }
    cout << "个村庄符合要求,最短路径为：" << min << endl;
    cout << endl;
}

//主函数
int main() {

    while (true) {
        cout << "==============请选择选项对应的编号=============\n";
        cout << "\t1.从n个村庄中选择建一医院的选址问题\t\n";
        cout << "\t2.二叉树排序算法的实现\t\n";
        cout << "\t3.退出\t\n";
        cout << "===========================================\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                Creat_Village();
                continue;
            case 2:
                Tree();
                continue;
            case 3:
                break;
            default:
                while (choice != 1 && choice != 2) {
                    cout << "输入错误！请重新输入：";
                    cin >> choice;
                }
                continue;
        }
        return 0;
    }


}

/**

 //n=4

 0 99999 3 6
 99999 0 2 5
 3  2 0 7
 6  5 7 0

 //n=5
 0 3 4 5 6
 3 0 4 5 6
 4 4 0 1 7
 5 5 1 0 1
 6 6 7 1 0

 0 9999 1 3 9999
 9999 0 9999 4 5
 1 9999 0 9999 9
 3 4 9999 0 1
 9999 5 9 1 0


 //n=6

 0 2 2 9999 9999 3
 2 0 3 9999 9999 9999
 2 3 0 6 9999 4
 9999 9999 6 0 7 5
 9999 9999 9999 7 0 2
 3 9999 4 5 2 0



 */
