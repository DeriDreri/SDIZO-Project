#include <stdio.h>
#include "array.cpp"
#include <iostream>
#include <cmath>

class TreeNode{
    public:
        TreeNode(int value);
        int key;
        TreeNode* parent;
        TreeNode* left;
        TreeNode* right;
};

class Tree{
    TreeNode* root;
    public:
        Tree();
        void addNode(int value);
        void display();
        void printNode(TreeNode * node, int depth);
        bool searchValue(int value);
        TreeNode* findMinumumKey(TreeNode* node);
        TreeNode* findMaximumKey(TreeNode* node);
        TreeNode* findSuccessor(TreeNode * node);
        TreeNode* findPredecessor(TreeNode* node);
        bool deleteNodeOfValue(int value);
        void rotateRight(TreeNode* node);
        void rotateLeft(TreeNode* node);
};
