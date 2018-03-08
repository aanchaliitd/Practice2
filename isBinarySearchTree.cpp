#include <iostream>
using namespace std;

class BinaryTreeNode
{
public:
    int value_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;

    BinaryTreeNode(int value) :
        value_(value),
        left_(nullptr),
        right_(nullptr)
    {
    }

    ~BinaryTreeNode()
    {
        delete left_;
        delete right_;
    }

    BinaryTreeNode * insertLeft(int value)
    {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode * insertRight(int value)
    {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};

    bool isBinarySearchTree(BinaryTreeNode* node,
                            const int lowerBound = numeric_limits<int>::min(),
                            const int upperBound = numeric_limits<int>::max())
    {
        if (node == nullptr) return true;
        
        if (node->value_ >= upperBound || node->value_ <= lowerBound) return false;
        
        return (isBinarySearchTree(node->left_, lowerBound, node->value_) &&
                isBinarySearchTree(node->right_,node->value_, upperBound ));
    }



int main ()
{
    // run your function through some test cases here
    // remember: debugging is half the battle!
    BinaryTreeNode *mainTree = new BinaryTreeNode(60);
    BinaryTreeNode *leftTree = new BinaryTreeNode(30);
    BinaryTreeNode *rightTree = new BinaryTreeNode(80);
    
    leftTree->insertLeft(20);
    leftTree->insertRight(50);
    
    rightTree->insertLeft(70);
    rightTree->insertRight(90);
    
    mainTree->left_ = leftTree;
    mainTree->right_ = rightTree;
    
    cout << isBinarySearchTree(mainTree) << endl;
    cout << isBinarySearchTree(leftTree) << endl;
    cout << isBinarySearchTree(rightTree) << endl;
    return 0;
}
