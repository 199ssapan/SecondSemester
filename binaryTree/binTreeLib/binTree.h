#pragma once
#include <stdlib.h>
#include <stdio.h>


typedef struct node
{
    struct node* left;
    struct node* right;
    int data;
}node;

typedef struct binTree
{
    node* root;
}binTree;

binTree* createBinTree();
int insert(binTree* bt, int newValue);
node* createNode();
