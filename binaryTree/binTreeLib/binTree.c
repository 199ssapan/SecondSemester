#include "binTree.h"

binTree* createBinTree()
{
    binTree* bt = (binTree*)malloc(sizeof(binTree));
    if (bt == NULL)
        return NULL;
    return bt;
}

node* createNode()
{
    node* n = (node*)malloc(sizeof(node));
    if (n == NULL)
        return NULL;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int insert(binTree* bt, int value)
{
    if (bt == NULL)
        return 0;
    if (bt->root == NULL)
    {
        bt->root = (node*)malloc(sizeof(node));
        if (bt->root == NULL)
            return 0;
        bt->root->left = NULL;
        bt->root->right = NULL;
        bt->root->data = value;
        return 1;
    }
    node* current = bt->root;
    for (;;)
    {
        if (value >= current->data && current->right != NULL)
        {
            current = current->right;
        }
        else if (value >= current->data && current->right == NULL)
        {
            node* currentRight = createNode();
            currentRight->data = value;
            current->right = currentRight;
            return 1;
        }
        else if (value < current->data && current->left != NULL)
        {
            current = current->left;
        }
        else 
        {
            node* currentLeft = createNode();
            currentLeft->data = value;
            current->left = currentLeft;
            return 1;
        }
    }
}

int isElemInTree(binTree* bt, int value)
{
    if (bt == NULL)
        return -1;
    if (bt->root == NULL)
        return -1;
    node* current = bt->root;
    for (;;)
    {
        if (value == current->data)
            return 1;
        else if (value >= current->data && current->right != NULL)
        {
            current = current->right;
        }
        else if (value >= current->data && current->right == NULL)
        {
            return 0;
        }
        else if (value < current->data && current->left != NULL)
        {
            current = current->left;
        }
        else
        {
            return 0;
        }
    }

}