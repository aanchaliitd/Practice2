#include <iostream>
using namespace std;

class LinkedListNode
{
public:
    int intValue_;
    LinkedListNode* next_;

    LinkedListNode(int intValue) :
        intValue_(intValue),
        next_(nullptr)
    {
    }
};

void PrintList(LinkedListNode *node) {
    LinkedListNode *currentNode = node;
    while(currentNode) {
        cout << currentNode->intValue_ << " ";
        currentNode = currentNode->next_;
    }
    cout << endl;
}

LinkedListNode *kthToLastNode(int k, LinkedListNode *head) {
    LinkedListNode *fastNode = head;
    LinkedListNode *slowNode = head;
    
    for (int i = 0; i < k; i++) {
        if (!fastNode) return nullptr;
        fastNode = fastNode->next_;
    }
    
    while(fastNode) {
        slowNode = slowNode->next_;
        fastNode = fastNode->next_;
    }
    
    return slowNode;
    
}

int main ()
{
    LinkedListNode* a = new LinkedListNode(1);
    LinkedListNode* b = new LinkedListNode(2);
    LinkedListNode* c = new LinkedListNode(3);
    LinkedListNode* d = new LinkedListNode(4);
    LinkedListNode* e = new LinkedListNode(5);

    a->next_ = b;
    b->next_ = c;
    c->next_ = d;
    d->next_ = e;

    PrintList(a);
    PrintList(kthToLastNode(3, a));
    return 0;
}
