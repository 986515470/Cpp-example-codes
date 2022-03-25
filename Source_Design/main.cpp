/**
 * ������������n����ׯ����Ҫ����n����ׯ��ѡ��һ����ׯ�½�һ��ҽԺ��ʹ����Ĵ�ׯ������ҽԺ�ľ���������˵�϶̣���ƽϺ���
     ʵ��Ҫ�󣺿��Խ��������Ϊ��n���ӵ㣬����n���ӵ�֮�佨��һ������ͼ�����ϵ�Ȩֵw(i,j)��ʾ��ׯi��j֮���·�ĳ��ȣ�
     ������ͼ��n������֮�䣬����������n(n-1)/2����·���������Щ��·��ѡ��n-1����·��
     ��ʹ�ܵ���·��̣�����n���������ͨ�����Խ�����಻ͬ������ͼ��
     ÿһ������ͼ�����Ա�ʾһ����·��������Ҫѡ��һ������ͼ��ʹͼ�ϸ���֮С��
 */
#include <iostream>
#include "Tree.cpp"
using namespace std;
#define MAXV 50
#define INF 32767
typedef int InfoType;
//�ڽӾ���洢����
typedef struct {
    int no;
    InfoType info;
} VertexType;
typedef struct {
    int edges[MAXV][MAXV];
    int n, e;
    VertexType vexs[MAXV];
} MGraph;

//�ҿ�˹�����㷨
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
            continue;//��ȥ�Լ�
        else {
            if (dist[i] >= 10)
                cout << "��" << v << "��" << i << "�����·��Ϊ��" << dist[i] << " ";
            else
                cout << "��" << v << "��" << i << "�����·��Ϊ��" << dist[i] << "  "; //С��10�������һ���ո�ʹ����������
            cout << v;
            Ppath(path, i, v);
            cout << "->" << i << endl;
            num += dist[i];//·��֮��


        }

    }
    cout << "��Ϊ��" << " " << num << endl;
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
    cout << "����������ͼ�Ķ��������";
    cin >> n;
    int *A = new int[n];
    cout << "����������ͼ���ڽӾ���" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> g.edges[i][j];
        }
    g.n = n;
    cout << "���õҿ�˹�����㷨�õ������·��Ϊ��" << endl;
    for (int i = 0; i < n; i++)
        Dijkstra(g, i, A);
    int min = A[0];
    for (int i = 1; i < n; i++)
        if (min > A[i]) {
            min = A[i];
        }
    cout << "�����ȽϿɵã��� ";
    for (int i = 0; i < n; i++) {
        if (A[i] == min)
            cout << i << " ";//�����ж������Ҫ��

    }
    cout << "����ׯ����Ҫ��,���·��Ϊ��" << min << endl;
    cout << endl;
}

//������
int main() {

    while (true) {
        cout << "==============��ѡ��ѡ���Ӧ�ı��=============\n";
        cout << "\t1.��n����ׯ��ѡ��һҽԺ��ѡַ����\t\n";
        cout << "\t2.�����������㷨��ʵ��\t\n";
        cout << "\t3.�˳�\t\n";
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
                    cout << "����������������룺";
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
