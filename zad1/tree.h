#include <stdio.h>
#include "array.cpp"
#include <iostream>
#include <cmath>

class TreeNode{
    public:
        TreeNode(int value);
        int key;
        short balance;
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
        TreeNode* searchValue(int value);
        TreeNode* findMinimumKey();
        TreeNode* findMaximumKey();
        TreeNode* findMinimumKey(TreeNode* node);
        TreeNode* findMaximumKey(TreeNode* node);
        TreeNode* findSuccessor(TreeNode * node);
        TreeNode* findPredecessor(TreeNode* node);
        bool deleteNodeOfValue(int value);
        void rotateRight(TreeNode* node);
        void rotateLeft(TreeNode* node);
        short calculateNodeLength(TreeNode* node);
        void calculateBalance(TreeNode* node);
        void fixTree(TreeNode* node);

};
