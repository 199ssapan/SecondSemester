#include "/home/maxim/Документы/GitHub/SecondSemester/binaryTree/binTreeLib/binTree.h"
//доделать доп функции по приколу
int main()
{
    binTree* bt = createBinTree();
    insert(bt, 8);
    insert(bt, 9);
    insert(bt, 6);
    insert(bt, 5);
    insert(bt, 1);
    insert(bt, 1);
    insert(bt, 0);
    printf("%d\n", bt->root->data);
    printf("%d\n", bt->root->left->data);
    printf("%d\n", bt->root->right->data);
    printf("%d\n", bt->root->left->left->data);
    printf("%d\n", bt->root->left->left->left->data);
    printf("%d\n", bt->root->left->left->left->left->data);
    printf("%d\n", bt->root->left->left->left->right->data);
    return 0;
}