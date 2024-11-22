#include <iostream>
#include <memory>

class Stack {
	int top{-1};
	int size{128};
	std::unique_ptr<int[]> arr;

	public:
		Stack()
		{
			arr = std::make_unique<int[]>(size);
		}

		Stack(int size): size(size)
		{
			arr = std::make_unique<int[]>(size);
		}

		bool isEmpty()
		{
			return (top == -1);
		}

		bool isFull()
		{
			return (top == size - 1);
		}

		void push(int data)
		{
			if (isFull()) {
				std::cout << "stack is FULL\n";
				return;
			}
			arr[++top] = data;
		}

		int pop(void)
		{
			if (isEmpty()) {
				std::cout << "stack is EMPTY\n";
				return -1;
			}	
			return arr[top--];
		}

		int getTop(void)
		{
			if (isEmpty()) {
				std::cout << "stack is EMPTY\n";
				return -1;
			}
			return arr[top];
		}

		void print()
		{
			std::cout << "stack = ";
			if (isEmpty()) {
				std::cout << "empty\n"; 
				return;
			}
			for (int i = 0; i < size; i++) {
				std::cout << arr[i] << " ";
				if (i == top) {
					break;
				}
			}
			std::cout << "\n";
		}

};

int main()
{
	Stack s{4};

	std::cout << "isEmpty = " <<  s.isEmpty() << "\n";

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	s.print();

	std::cout << "popped element = " << s.pop() << "\n";
	std::cout << "popped element = " << s.pop() << "\n";

	std::cout << "top element = " << s.getTop() << "\n";

	s.print();

	std::cout << "popped element = " << s.pop() << "\n";
	std::cout << "popped element = " << s.pop() << "\n";
	std::cout << "popped element = " << s.pop() << "\n";

	s.print();
	return 0;
}
