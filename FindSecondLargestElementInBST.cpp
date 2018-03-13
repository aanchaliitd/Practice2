#include <iostream>
#include <stack>
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

class BinarySearchTree
{
public:
	BinarySearchTree() : _root(nullptr) {}
	void insert(int element) {
		
		if (_root == nullptr) {
			_root = new BinaryTreeNode(element);
			return;
		}
		else {
			insertRecursive(element, _root);
		}
	}
	BinaryTreeNode *getRoot() { return _root;}
private:
	BinaryTreeNode* _root;
	void insertRecursive(int element, BinaryTreeNode* current_node) {
		if (element <= current_node->value_) {
			if (!current_node->left_) {
				current_node->left_ = new BinaryTreeNode(element);
				return;
			}
			insertRecursive(element, current_node->left_);
		}
		else {
			if (!current_node->right_) {
				current_node->right_ = new BinaryTreeNode(element);
				return;
			}
			insertRecursive(element, current_node->right_);
		}
	}
};

int FindLargestElement(BinaryTreeNode *node) {
    BinaryTreeNode* current_node = node;
    if (!node) return -1;
    int current_val;
    while(current_node) {
        current_val = current_node->value_;
        current_node = current_node->right_;
    }
    return current_val;
}

int FindSecondLargestElement(BinaryTreeNode *node) {
    BinaryTreeNode* current_node = node;
    if(!node) return -1;
    if (!node->right_) return node->value_;
    BinaryTreeNode* prev_node = node;
    while(current_node->right_) {
        prev_node = current_node;
        current_node = current_node->right_;
    }
    
    if (current_node->left_ && !current_node->right_) {
        return FindLargestElement(current_node->left_);
    }
    else {
        return prev_node->value_;
    }
}

int main ()
{
	// run your function through some test cases here
	// remember: debugging is half the battle!
	BinarySearchTree *tree = new BinarySearchTree();
	for (int i = 0; i < 10; i++) {
		tree->insert(i);
	}
	tree->insert(15);
	tree->insert(13);
	tree->insert(12);
	tree->insert(14);
	tree->insert(11);
	cout << "tree building completed." << endl;
	cout << FindSecondLargestElement(tree->getRoot()) << endl;
	return 0;
}

