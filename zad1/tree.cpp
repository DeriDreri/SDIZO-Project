#include "tree.h"

Tree::Tree(){
    root = nullptr;
}


void Tree::addNode(int value){
    TreeNode* nodeToInsert = new TreeNode(value); 
    TreeNode* parent = nullptr;
    TreeNode* node = root;
    while(node != nullptr){
        parent = node;
        if (nodeToInsert -> key < node -> key)
            node = node -> left;
        else
            node = node -> right;
    }
    
    nodeToInsert -> parent = parent;

    if (parent == nullptr)
        root = nodeToInsert;
    else{
        if (nodeToInsert -> key < parent -> key)
            parent -> left = nodeToInsert;
        else   
            parent -> right = nodeToInsert;
    }
}

bool Tree::searchValue(int value){
    TreeNode * node = root;
    while(node != nullptr){
        if(value == node -> key) return true;
        if(value < node -> key)
            node = node -> left;
        else 
            node = node -> right;
    }
    return false;
}

TreeNode* Tree::findMinimumKey(){
    return findMinimumKey(root);
}

TreeNode* Tree::findMaximumKey(){
    return findMaximumKey(root);
}

TreeNode* Tree::findMinimumKey(TreeNode* node){
    while (node -> left != nullptr)
        node = node -> left;
    return node;
}

TreeNode* Tree::findMaximumKey(TreeNode* node){
    while (node -> right != nullptr)
        node = node -> right;
    return node;
}

TreeNode* Tree::findSuccessor(TreeNode * node){
    if(node -> right != nullptr)
        return findMinimumKey(node -> right);
    TreeNode* parentNode = node -> parent;
    while(parentNode != nullptr && parentNode -> left != node){
        node = parentNode;
        parentNode = parentNode -> parent;
    }
    return parentNode;
}

TreeNode* Tree::findPredecessor(TreeNode* node){
    if(node -> left != nullptr)
        return findMaximumKey(node -> left);
    TreeNode* parentNode = node -> parent;  
    while(parentNode != nullptr && parentNode -> right != node){
        node = parentNode;
        parentNode = parentNode -> parent;
    }
    return parentNode;
}

void Tree::printNode(TreeNode* node, int depth){
    for(int i = 0; i < depth; i++){
            if(i == depth -1){ 
                if(node -> parent != nullptr &&  node -> parent -> left == node)     //Dla lewego potomka
                    std::cout << "├── ";
                else 
                    std::cout << "└── ";                                            //Dla prawego potomka
                }                
            else
                std::cout << "│   ";
        }
        std::cout << node -> key << std::endl;
        if(node -> left != nullptr)
            printNode(node -> left, depth+1);
        if(node -> right != nullptr) 
            printNode(node -> right, depth+1);   
}

void Tree::display(){
    printNode(root, 0);
}


TreeNode::TreeNode(int value){
    key = value;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

int main(){
    Tree testTree = Tree();
    testTree.addNode(20);
    testTree.addNode(212);
    testTree.addNode(12);
    testTree.addNode(0);
    testTree.addNode(2);
    testTree.addNode(1);
    testTree.addNode(4);
    testTree.addNode(5);
    testTree.addNode(8);
    testTree.addNode(13);
    testTree.display();
    std::cout << testTree.findSuccessor(testTree.findMinimumKey()) -> key << std::endl;
    std::cout << testTree.findPredecessor(testTree.findMaximumKey()) -> key << std::endl;
    return 0;
}