#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;

typedef int myType;

typedef struct treeNode 
{
    myType element;     //值域元素
    struct treeNode *lchild;    //左孩子
    struct treeNode *rchild;    //右孩子
}Btree;

void createTree(Btree **T)  //传入一个Btree的指针的地址
{
    myType data;
    scanf("%d", &data);

    if(data == -1) {    //-1代表终端节点值
        *T = NULL;
    } else {
        *T = (Btree *)malloc(sizeof(struct treeNode));  
        (*T)->element = data;
        printf("please enter the lchid node of %d:  ", data);
        createTree(&((*T)->lchild));
        printf("please enter the rchid node of %d:  ", data);
        createTree(&((*T)->rchild));
    }
}

void preOrder(Btree *T)
{
    if(T != NULL) {
        printf("%d ", T->element);  //访问根节点
        preOrder(T->lchild);    //先根序遍历左子树
        preOrder(T->rchild);    //先根序遍历右子树
    }
}

void inOrder(Btree *T)
{
    if(T != NULL) {
        inOrder(T->lchild);     //中根序遍历左子树
        printf("%d ", T->element);  //访问根节点 
        inOrder(T->rchild); //中根序遍历右子树
    }
}

void postOrder(Btree *T)
{
    if(T != NULL) {
        postOrder(T->lchild);   //后根序遍历左子树
        postOrder(T->rchild);   //后根序遍历右子树
        printf("%d ", T->element);  //访问根节点
    }
}

int tree_deep(Btree *T)
{
    int deep = 0;
    if(T) {
        int leftdeep = tree_deep(T->lchild);    
        int rightdeep = tree_deep(T->rchild);
        deep = leftdeep > rightdeep ? leftdeep+1 : rightdeep+1;
    }

    return deep;
}

int main(){
    Btree * T = (Btree *)malloc(sizeof(Btree));
    cout << "Please enter the root node of the tree:";
    createTree(&T);               cout << "-----------------\n";

    cout << "Pre_Order:";
    preOrder(T);             cout << "\n-----------------\n";
    cout << "Mid_Order:";
    inOrder(T);              cout << "\n-----------------\n";
    cout << "Pos_Order:";
    postOrder(T);            cout << "\n-----------------\n";
    cout << "The depth of the tree:";
    cout << tree_deep(T);

    return 0;
}



// #include<stdio.h>
// #include<stdlib.h>

// typedef struct BTree{
//     int data;
//     BTree *lchild,*rchild;
// }BTree;

// void Create(BTree **T){
//     int data;
//     scanf("%d", &data);

//     if(data = -1){
//         *T = NULL;
//     }else{
//         *T = (BTree *)malloc(sizeof(BTree));
//         (*T)->data = data;
//         printf("please enter the lchid node of %d:  ", data);
//         Create(&((*T)->lchild));
//         printf("please enter the rchid node of %d:  ", data);
//         Create(&((*T)->rchild));
//     }
// }

// void Pre_Order(BTree *T){
//     if(T != NULL){
//         printf("%d  ",T->data);
//         Pre_Order(T->lchild);
//         Pre_Order(T->rchild);
//     }
// }

// int main(){
//     BTree * T = (BTree *)malloc(sizeof(BTree));
//     printf("Please enter the root node of the tree:");
//     Create(&T);               printf("-----------------\n");

//     printf("Pre_Order:");
//     Pre_Order(T);             printf("-----------------\n");

//     return 0;
// }