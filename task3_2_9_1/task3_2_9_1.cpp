#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

class CoolStack {
	// Description:
	// This is the coolest stack you have ever used!
private:
	int CAPACITY; //The capacity of stack. It mustn't be changed!
	int size; // How many elements in stack
	int* coolStack;
	string name;
public:
	CoolStack(string name, int capacity) {
		this->name = name;
		this->CAPACITY = capacity;
		coolStack = new int[CAPACITY]{};
		this->size = 0;
	}

	// Method to add number to stack
	bool push(int num) {
		if (size < CAPACITY) {
			coolStack[size] = num;
			size++;
			return true;
		}
		else return false;
		
	}

	bool push() {
		if (size < CAPACITY) return true;
		else return false;
	}

	// Method to delete number from stack
	bool pop() {
		if (size > 0) {
			coolStack[size] = 0;
			size--;
			return true;
		}
		else return false;	
	}


	// Method to get number from stack without deleting
	int peek() {
		return coolStack[size-1];
	}

	int getSize() {
		return size;
	}

	int getCapacity() {
		return CAPACITY;
	}

	string getName() {
		return name;
	}

};

int main() {
	setlocale(LC_ALL, "Russian");
	
	string stackName1;
	int stackSize1;
	cin >> stackName1 >> stackSize1;
	CoolStack stack1(stackName1, stackSize1);

	string stackName2;
	int stackSize2;
	cin >> stackName2 >> stackSize2;
	CoolStack stack2(stackName2, stackSize2);

	int minStackSize = min(stackSize1, stackSize2);

	while (true) {
		int num;
		cin >> num;
		if (!(stack1.push(num))) break;
		if (!(stack2.push(num))) break;
	}

	cout << stack1.getName() << " " << stack1.getCapacity() << endl;
	cout << stack2.getName() << " " << stack2.getCapacity() << endl;

	cout << setw(15) << left << stack1.getName() << setw(15) << left << stack2.getName() << endl;

	while (stack1.getSize() > 0 || stack2.getSize() > 0) {
		if (stack1.getSize() > 0) {
			cout << setw(15) << right << stack1.peek();
			stack1.pop();
		}
		if (stack2.getSize() > 0) {
			cout << setw(15) << right << stack2.peek() << endl;
			stack2.pop();
		}
		
	}

}