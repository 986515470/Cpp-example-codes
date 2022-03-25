
//��ɶ����������㷨��ʵ��
#include<iostream>
using namespace std;
typedef struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
} NODE, *BSTree;


/*
��ָ��pTree��ָ�Ķ����������еݹ���ҹؼ���Ϊkey��Ԫ�أ�
�����ҳɹ����򷵻�ָ���Ԫ�ؽڵ��ָ�룬���򷵻�NULL
*/
BSTree search(BSTree pTree, int key) {
    if (!pTree || pTree->data == key)
        return pTree;
    else if (key < pTree->data)
        return search(pTree->lchild, key);
    else
        return search(pTree->rchild, key);
}


/*
������·���Ϸ��ʵ����һ���ڵ�ָ�뱣����p�С�
����·���Ϸ��ʵĵ�ǰ�ڵ�ĸ��ڵ�
�ú�������������Ĳ��뺯�����á�
*/
bool Search(BSTree pTree, int key, BSTree parent, BSTree &p) {
    if (!pTree) {
        p = parent;
        return false;
    } else {
        if (key == pTree->data) {
            p = pTree;
            return true;
        } else if (key < pTree->data)
            return Search(pTree->lchild, key, pTree, p);
        else
            return Search(pTree->rchild, key, pTree, p);
    }
}

/*
����pTree��ָ��Ķ����������в��Ҳ����ؼ���Ϊkey������Ԫ��ʱ��
�������ö�����������������ture�����򷵻�false��
����ʱ�����ı���ڵ��ֵ�����Ҫ�������á�
*/
bool insert(BSTree &pTree, int key) {
    BSTree p;
    if (!Search(pTree, key, NULL, p))
    {
        //Ϊ�½ڵ����ռ䣬���Ը���ֵ
        BSTree pNew = (BSTree) malloc(sizeof(NODE));
        pNew->data = key;
        pNew->lchild = pNew->rchild = NULL;

        if (!p)
            pTree = pNew;
        else if (key < p->data)
            p->lchild = pNew;
        else
            p->rchild = pNew;
        return true;
    } else
        return false;
}

/*
���õ�һ���㷨�Ӷ�����������ɾ��ָ��p��ָ��Ľڵ�,
���ڱ��ֶ������������������£��������������ؽӵ��ö�����������.
*/
void Delete1(BSTree &p) {
    BSTree q, s;
    if (!p->lchild) {
        q = p;
        p = p->rchild;
        free(q);
    } else if (!p->rchild) {
        q = p;
        p = p->lchild;
        free(q);
    } else {

        s = p->lchild;
        while (s->rchild)
            s = s->rchild;
        s->rchild = p->rchild;
        q = p;
        p = p->lchild;
        free(q);
    }
}

/*
��pTree��ָ��Ķ����������в��ҵ��ؼ���Ϊkey������Ԫ�أ���ɾ����Ԫ�ض�Ӧ�Ľڵ�
 ���Ҫɾ����ǡ���Ǹ��ڵ㣬���ı���ڵ��ֵ�����Ҫ��������
*/
bool DeleteTree(BSTree &pTree, int key) {
    //�����ڹؼ���Ϊkey�Ľڵ�
    if (!pTree)
        return false;
    else {
        if (key == pTree->data)
        {
            Delete1(pTree);
            return true;
        } else if (key < pTree->data)
            return DeleteTree(pTree->lchild, key);
        else
            return DeleteTree(pTree->rchild, key);
    }
}

/*
���������ĳ�Ϊlen��arr���飬��������Ԫ�ص�˳�򹹽�һ�ö���������
*/
BSTree CreatTree(int *arr, int len) {
    BSTree pTree = NULL;
    int i;
    //��˳������ڵ���뵽������������
    for (i = 0; i < len; i++)
        insert(pTree, arr[i]);
    return pTree;
}

/*
�ݹ���������������������õ�Ԫ�ش�С�����������е�����
*/
void Play(BSTree pTree) {
    if (pTree) {
        if (pTree->lchild)
            Play(pTree->lchild);
        printf("%d ", pTree->data);
        if (pTree->rchild)
            Play(pTree->rchild);
    }
}

/*
�ݹ����ٶ���������
*/
void DestroyTree(BSTree pTree) {
    if (pTree) {
        if (pTree->lchild)
            DestroyTree(pTree->lchild);
        if (pTree->rchild)
            DestroyTree(pTree->rchild);
        free(pTree);
        pTree = NULL;
    }
}


 void Tree() {
    int num;
    printf("������Ҫ����Ľڵ������");
    cin >> num;
    int *arr = (int *) malloc(num * sizeof(int));
    printf("������������%d��������������ȣ���", num);
    for (int i = 0; i < num; i++)
        scanf("%d", arr + i);
    BSTree pTree = CreatTree(arr, num);//����������
    printf("��������ö����������Ľ����");
    Play(pTree);
    cout << endl;
    int key;
    while (true) {
        cout << "==============��ѡ��Ҫ�Դ˽��ж����������ı��=============\n";
        cout << "\t1.��������\t\n";
        cout << "\t2.��������\t\n";
        cout << "\t3.ɾ������\t\n";
        cout << "\t4.����\t\n";
        cout << "===========================================\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                printf("������Ҫ���ҵ�������");
                scanf("%d", &key);
                if (search(pTree, key))
                    printf("���ҳɹ�\n");
                else
                    printf("���Ҳ���������\n");
                continue;
            case 2:
                //�������������
                printf("������Ҫ�����������");
                scanf("%d", &key);
                if (insert(pTree, key)) {
                    printf("����ɹ���������������������");
                    Play(pTree);
                    cout << endl;
                } else
                    printf("����ʧ�ܣ��ö������������Ѿ���������%d\n", key);
                continue;
            case 3:
                //ɾ������������
                printf("������Ҫɾ����������");
                scanf("%d", &key);
                if (DeleteTree(pTree, key)) {
                    printf("ɾ���ɹ���������������������");
                    Play(pTree);
                    cout << endl;
                } else
                    printf("ɾ��ʧ�ܣ��ö����������в����ڸ�����%d\n", key);
                continue;
            case 4:
                return;
            default:
                while (choice > 4 || choice < 0)
                    cout << "�������������ѡ��!";
                continue;
        }

    }


}