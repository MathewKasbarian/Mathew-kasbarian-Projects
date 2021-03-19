#include <iostream>
#include <string>

using namespace std;

//create node struct 
struct Node {
	string data;
	Node *next;  
};

class Stack {
public:
	Stack(); // constructor
	~Stack(); //deconstructor
	void push(string d); //push node onto top of stack
	string pop(); //pop the top node off of the stack
	string toString(); // display the stack's contents as 
							// a string (top->bottom)
	bool isEmpty();
	int peek();
	
	
private:	
	Node *top;
	
};

Stack::Stack() {
	//initialize stack to be empty
	top = NULL;
}

Stack::~Stack() {
	//deconstructor to delete all of the dynamic variables
	while (!isEmpty()){
		pop();
	}
}

void Stack::push(string d) {
	//need a new Node to store d in 
	Node *temp = new Node;
	temp->data = d;
	temp->next = top; //point the new node's next to the 
								//old top of the stack
	top = temp; //point top to the new top of the stack
}


string Stack::pop() {
	if (!isEmpty()) {
		string value = top->data;
		Node *oldTop = top;
		top = oldTop->next;
		delete oldTop;
		return value;
	} else {
		//cant pop form an empty stack 
		cout << "you cant pop from an empty stack!" << endl;
		exit(1);
	}
}

string Stack::toString() {
	string result = "(top) -> ";
	if (isEmpty()) {
		result = result + "NULL";
		return result;
	} else { 
		Node *current = top;
		while (current !=NULL) {
			result = result + current->data +  " -> ";
			current = current ->next;
		}	
		result = result + "(END)";
		return result;
	}
}

bool Stack::isEmpty() {
	return (top ==NULL); 
}



int main() {
	Stack *s = new Stack();
	cout << "Output when empty: " << endl 
			<< s->toString() << endl;
	s->push("chesseburger");
	s->push("pizza");
	s->push("Large Coffee");
	s->pop();
	cout << "Output when not empty: " << endl 
			<< s->toString() << endl;
			
	delete s;
	
	
	
	return 0;
}
