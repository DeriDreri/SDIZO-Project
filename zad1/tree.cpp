#include "tree.h"

Tree::Tree(){
    root = nullptr;
}

TreeNode::TreeNode(int value){
    key = value;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

int main(){
    Tree testTree = Tree();
    return 0;
}