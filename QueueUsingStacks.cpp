#include <iostream>
#include <stack>
using namespace std;

template <typename type>
class queue {
public:
	queue() : _stack1(), _stack2(){}
	
	void enqueue(const type& element) {
		_stack1.push(element);
	}
	
	type dequeue() {
		if (_stack2.empty()) {
			while (!_stack1.empty()) {
				_stack2.push(_stack1.top());
				_stack1.pop();
			}
		}
		
		type result = _stack2.top();
		_stack2.pop();
		return result;
	}
 
private:
	stack<type> _stack1;
	stack<type> _stack2;
};

string myFunction (const string& arg)
{
	// write the body of your function here
	return "running with " + arg;
}

int main ()
{
	queue<int> testQueue;
	testQueue.enqueue(1);
	testQueue.enqueue(2);
	testQueue.enqueue(3);
	testQueue.enqueue(4);
	testQueue.enqueue(5);
	
	cout << testQueue.dequeue() << " "
	<< testQueue.dequeue() << " "
	<< testQueue.dequeue() << " "
	<< testQueue.dequeue() << " ";
	
	testQueue.enqueue(6);
	cout << testQueue.dequeue() << " " << testQueue.dequeue() << endl;
	return 0;
}
