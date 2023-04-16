#include "tree.h"

Tree::Tree(){
    root = nullptr;
}


void Tree::addNode(int value){
    TreeNode* nodeToInsert = new TreeNode(value); 
    TreeNode* parent = nullptr;
    TreeNode* node = root;
    
    //Szukanie rodzica, do którego należy podpiąć nowy węzeł
    //Po wykonaniu pętli:
    //  node - pusty liść, który zastąpi dodawany
    //  parent - węzeł, którego potomkiem ejst pusty list
    while(node != nullptr){
        parent = node;
        if (nodeToInsert -> key < node -> key)
            node = node -> left;
        else
            node = node -> right;
    }
    
    nodeToInsert -> parent = parent;

    if (parent == nullptr)                              //Przypadek pustego drzewa
        root = nodeToInsert;
    else{
        if (nodeToInsert -> key < parent -> key)
            parent -> left = nodeToInsert;
        else   
            parent -> right = nodeToInsert;
    }
}

TreeNode* Tree::searchValue(int value){
    TreeNode * node = root;
    while(node != nullptr){
        if(value == node -> key) return node;
        if(value < node -> key)
            node = node -> left;
        else 
            node = node -> right;
    }
    return nullptr;
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

bool Tree::deleteNodeOfValue(int value){
    TreeNode* nodeToDelete = searchValue(value);
    TreeNode* nodeToReplace = nullptr;
    TreeNode* childNode = nullptr;
    if(nodeToDelete == nullptr) return false;                                       //Brak węzła o podanej wartości
    
    if(nodeToDelete -> left == nullptr || nodeToDelete -> right == nullptr)         //W przypadku braku dwóch potomków, rozpatrujemy prostszy przypadek
        nodeToReplace = nodeToDelete;   
    else   
        nodeToReplace = findSuccessor(nodeToDelete);                                //W przypadku dwóch potomków musimy znaleźć następnika
    if (nodeToReplace -> left != nullptr)                                           //Możemy uprościć kod wiedząc, że następnik może mieć co najwyżej jednego potomka
        childNode = nodeToReplace -> left;
    else 
        childNode = nodeToReplace -> right;
    if(childNode != nullptr)                                                        //Jeśli następnik lub nasz węzeł mają potomka, to zastępujemy nasz 
        childNode -> parent = nodeToReplace -> parent;                              //węzeł potomkiem lub następnikiem
    if(nodeToReplace -> parent == nullptr)                                          //Jeśli usuwany węzeł jest korzeniem, musimy ustawić nowy korzeń
        root = nodeToReplace;
    else
        if(nodeToReplace == nodeToReplace -> parent -> left)
            nodeToReplace -> parent -> left = childNode;
        else
            nodeToReplace -> parent -> right = childNode;
    if(nodeToReplace != nodeToDelete)
        nodeToDelete -> key = nodeToReplace -> key;
    
    return true;
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

void Tree::rotateRight(TreeNode* node){
    TreeNode* rotated = node -> left;
    if(rotated == nullptr) return;                           //Rotacja niemożliwa
    node -> left = rotated -> right;                         //Podpięcie prawego drzewa obracanego pod lewego potomka wzgledem obracanego
    node -> left -> parent = node;                           //Zmiana rodzica prawego drzewa
    rotated -> parent = node -> parent;                       //Podpięcie obracanego do rodzica

    if(node -> parent -> right == node)
        node -> parent -> right = rotated;
    else   
        node -> parent -> left = rotated;

    rotated -> right = node;                                 //UStawienie obracanego jako rodzica węzła
    node -> parent = rotated;

}
void Tree::rotateLeft(TreeNode* node){
TreeNode* rotated = node -> right;
    if(rotated == nullptr) return;                           //Rotacja niemożliwa
    node -> right = rotated -> left;                         //Podpięcie prawego drzewa obracanego pod lewego potomka wzgledem obracanego
    node -> right -> parent = node;                           //Zmiana rodzica prawego drzewa
    rotated -> parent = node -> parent;                       //Podpięcie obracanego do rodzica

    if(node -> parent -> right == node)
        node -> parent -> right = rotated;
    else   
        node -> parent -> left = rotated;

    rotated -> left = node;                                 //UStawienie obracanego jako rodzica węzła
    node -> parent = rotated;
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
    testTree.rotateLeft(testTree.searchValue(0));
    testTree.display();
    std::cout << testTree.findSuccessor(testTree.findMinimumKey()) -> key << std::endl;
    std::cout << testTree.findPredecessor(testTree.findMaximumKey()) -> key << std::endl;
    return 0;
}