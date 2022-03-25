
//完成二叉排序树算法的实现
#include<iostream>
using namespace std;
typedef struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
} NODE, *BSTree;


/*
在指针pTree所指的二叉排序树中递归查找关键字为key的元素，
若查找成功，则返回指向该元素节点的指针，否则返回NULL
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
将查找路径上访问的最后一个节点指针保存在p中。
查找路径上访问的当前节点的父节点
该函数用来被后面的插入函数调用。
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
当在pTree所指向的二叉排序树中查找不到关键字为key的数据元素时，
将其插入该二叉排序树，并返回ture，否则返回false。
树空时插入会改变根节点的值，因此要传入引用。
*/
bool insert(BSTree &pTree, int key) {
    BSTree p;
    if (!Search(pTree, key, NULL, p))
    {
        //为新节点分配空间，并对各域赋值
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
采用第一种算法从二叉排序树中删除指针p所指向的节点,
并在保持二叉排序树有序的情况下，将其左右子树重接到该二叉排序树中.
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
若pTree所指向的二叉排序树中查找到关键字为key的数据元素，则删除该元素对应的节点
 如果要删除的恰好是根节点，则会改变根节点的值，因此要传入引用
*/
bool DeleteTree(BSTree &pTree, int key) {
    //不存在关键字为key的节点
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
根据所给的长为len的arr数组，按数组中元素的顺序构建一棵二叉排序树
*/
BSTree CreatTree(int *arr, int len) {
    BSTree pTree = NULL;
    int i;
    //按顺序逐个节点插入到二叉排序树中
    for (i = 0; i < len; i++)
        insert(pTree, arr[i]);
    return pTree;
}

/*
递归中序遍历二叉排序树，得到元素从小到大有序排列的序列
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
递归销毁二叉排序树
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
    printf("请输入要插入的节点个数：");
    cin >> num;
    int *arr = (int *) malloc(num * sizeof(int));
    printf("请依次输入这%d个整数（互不相等）：", num);
    for (int i = 0; i < num; i++)
        scanf("%d", arr + i);
    BSTree pTree = CreatTree(arr, num);//创建二叉树
    printf("中序遍历该二叉排序树的结果：");
    Play(pTree);
    cout << endl;
    int key;
    while (true) {
        cout << "==============请选择要对此进行二叉树操作的编号=============\n";
        cout << "\t1.查找数据\t\n";
        cout << "\t2.插入数据\t\n";
        cout << "\t3.删除数据\t\n";
        cout << "\t4.返回\t\n";
        cout << "===========================================\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                printf("请输入要查找的整数：");
                scanf("%d", &key);
                if (search(pTree, key))
                    printf("查找成功\n");
                else
                    printf("查找不到该整数\n");
                continue;
            case 2:
                //插入给定的整数
                printf("请输入要插入的整数：");
                scanf("%d", &key);
                if (insert(pTree, key)) {
                    printf("插入成功，插入后的中序遍历结果：");
                    Play(pTree);
                    cout << endl;
                } else
                    printf("插入失败，该二叉排序树中已经存在整数%d\n", key);
                continue;
            case 3:
                //删除给定的整数
                printf("请输入要删除的整数：");
                scanf("%d", &key);
                if (DeleteTree(pTree, key)) {
                    printf("删除成功，插入后的中序遍历结果：");
                    Play(pTree);
                    cout << endl;
                } else
                    printf("删除失败，该二叉排序树中不存在该整数%d\n", key);
                continue;
            case 4:
                return;
            default:
                while (choice > 4 || choice < 0)
                    cout << "输入错误！请重新选择!";
                continue;
        }

    }


}