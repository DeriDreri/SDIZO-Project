#include <stdio.h>
#include "array.cpp"
#include <iostream>
#include <cmath>

class Tree{
    TreeNode* root;
    public:
        Tree();
        void addNode(int value);
};

class TreeNode{
    int key;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value);
};