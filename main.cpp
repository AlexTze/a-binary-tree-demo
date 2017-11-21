#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct BinaryTreeNode {
    BinaryTreeNode *leftchild, *rightchild;
    char data;
} node, *tree;

void menu() {
    system("cls");
    cout << "========= 二叉树演示 =========" << endl;
    cout << "1.前序遍历建立二叉树" << endl;
    cout << "2.前序遍历输出二叉树内容" << endl;
    cout << "3.中序遍历输出二叉树内容" << endl;
    cout << "4.后序遍历输出二叉树内容" << endl;
    cout << "5.求二叉树高" << endl;
    cout << "6.求二叉树叶子个数" << endl;
    cout << "7.求二叉树大小" << endl;
    cout << "8.退出" << endl;
    cout << "=============================" << endl;
    cout << "输入数字来选择：";
}

void CreateBinaryTree(tree &T) {
    char ch;
    cin >> ch;
    if(ch == '$')
        T = nullptr;
    else {
        T = new node;
        T->data = ch;
        CreateBinaryTree(T->leftchild);
        CreateBinaryTree(T->rightchild);
    }
}//create binary tree with pre-order traverse

void preOrderTraverse(tree &T) {
    if(T) {
        cout << T->data;
        preOrderTraverse(T->leftchild);
        preOrderTraverse(T->rightchild);
    } else {
        cout << "$";
    }
}

void inOrderTraverse(tree &T) {
    if(T) {
        inOrderTraverse(T->leftchild);
        cout << T->data;
        inOrderTraverse(T->rightchild);
    } else {
        cout << "$";
    }
}

void postOrderTraverse(tree &T) {
    if(T) {
        postOrderTraverse(T->leftchild);
        postOrderTraverse(T->rightchild);
        cout << T->data;
    } else {
        cout << "$";
    }
}

int getHeight(tree &T) {
    if(T == nullptr)
        return 0;
    else {
        int lheight, rheight;
        lheight = getHeight(T->leftchild);
        rheight = getHeight(T->rightchild);
        return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
    }
}

int getLeaves(tree &T) {
    if(T == nullptr)
        return 0;
    else if(T->leftchild == nullptr && T->rightchild == nullptr)
        return 1;
    else
        return (getLeaves(T->leftchild) + getLeaves(T->rightchild));
}

int getSize(tree &T) {
    if(T == nullptr)
        return 0;
    else
        return getSize(T->leftchild) + getSize(T->rightchild) + 1;
}

int main() {
    tree T;
    menu();
    char selection;
    while (cin >> selection) {
        switch (selection) {
            case '1':
                cout << "请输入前序遍历二叉树，使用'$'代表空结点：" << endl;
                CreateBinaryTree(T);
                break;
            case '2':
                preOrderTraverse(T);
                cout << endl;
                system("pause");
                break;
            case '3':
                inOrderTraverse(T);
                cout << endl;
                system("pause");
                break;
            case '4':
                postOrderTraverse(T);
                cout << endl;
                system("pause");
                break;
            case '5':
                cout << getHeight(T) << endl;
                system("pause");
                break;
            case '6':
                cout << getLeaves(T) << endl;
                system("pause");
                break;
            case '7':
                cout << getSize(T) << endl;
                system("pause");
                break;
            case '8':
                exit(0);
            default:
                cout << "输入错误，请重试。" << endl;
                system("pause");
                break;
        }
        menu();
    }
    return 0;
}
