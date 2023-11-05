/*
 * time: 2022.10.5
 * provider: QQ_532530422 星河kk
 *           Comes from Ways and Examples of C 338191797
 *
 * issues：按先序遍历序列创建二叉树，以#号代表节点为空。
 *
 * solves: CSDN有C版本（不会C++不影响填空部分）
 *         https://blog.csdn.net/Getugly/article/details/83963812
 *
 */

#include <iostream>
using namespace std;

typedef char TElemType;

typedef struct BiNode {
    TElemType data;
    BiNode *lchild, *rchild;  // ① 二叉树的二叉链表存储表示
} BiNode;

typedef struct BiNode* BiTree;

// 功能: 创建二叉树
//  @param [BiTree&] 指向结构体指针的引用
void CreateBiTree(BiTree& T) {
    char ch;
    cin >> ch;
    if (ch == '#') {
        T = NULL;  // ② 空结点, 结束递归
        return;
    } else {
        T = new BiNode;
        T->data = ch;             // 结点存储的信息
        CreateBiTree(T->lchild);  // ③ 递归创建左子树
        CreateBiTree(T->rchild);  // ④ 递归创建右子树
    }
}

void outputPLR(BiTree t);  // 函数原型声明

int main() {
    BiNode* tree = new BiNode;
    CreateBiTree(tree);

    cout << "二叉树创建完成, 先序变量如下: \n";
    outputPLR(tree);
    return 0;
}

// 功能: 按先序遍历PLR输出
void outputPLR(BiTree t) {
    if (t == NULL) {
        cout << "#\n";
        return;  // 空结点忽略
    }
    cout << t->data;
    outputPLR(t->lchild);
    outputPLR(t->rchild);
}

/* 经验:
 1. 改变指针的值必须要用指针的指针或指针的引用

*/
