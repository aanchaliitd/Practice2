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

void PrintList(LinkedListNode *list) {
    LinkedListNode *current_node = list;
    while (current_node) {
        cout << current_node->intValue_ << " ";
        current_node = current_node->next_;
    }
    cout << endl;
}

LinkedListNode *ReverseList(LinkedListNode *head) {
    LinkedListNode *prev_node = nullptr;
    LinkedListNode *current_node = head;
    
    while (current_node) {
        LinkedListNode *temp = current_node->next_;
        current_node->next_ = prev_node;
        prev_node = current_node;
        current_node = temp;
    }
    
    return prev_node;
}

int main ()
{
    LinkedListNode *a = new LinkedListNode(1);
    LinkedListNode *b = new LinkedListNode(2);
    LinkedListNode *c = new LinkedListNode(3);
    LinkedListNode *d = new LinkedListNode(4);
    a->next_ = b;
    b->next_ = c;
    c->next_ = d;
    PrintList(a);
    LinkedListNode *result = ReverseList(a);
    PrintList(result);
    return 0;
}
