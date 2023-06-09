#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}

	void addNode();
	bool search(int rollno, Node** aqilah, Node** alifian);
	bool listEmpty();
	bool delNode();
	void traverse();

};

void CircularLinkedList::addNode() {
	int rollNo;
	string name;

	cout << "input number :";
	cin >> rollNo;
	cout << "input name :";
	cin >> name;

	Node* newNode = new Node();
	newNode->rollNumber = rollNo;
	newNode->name = name;

	if (listEmpty()) {
		newNode->next = newNode;
		LAST = newNode;
	}
	else {
		Node* alifian = LAST->next;
		Node* aqilah = NULL;

		do {
			aqilah = alifian;
			alifian = alifian->next;
		} while (alifian != LAST && alifian->rollNumber < rollNo);
		
		if (alifian == LAST && alifian->rollNumber < rollNo)
		{
			newNode->next = LAST->next;
			LAST->next = newNode;
			LAST = newNode;
		}
	}
	cout << "node added !\n";
}

bool CircularLinkedList::search(int rollno, Node** aqilah, Node** alifian) {
	*aqilah = LAST->next;
	*alifian = LAST->next;

	while (*alifian != LAST) {
		if (rollno == (*alifian)->rollNumber) {
			return true;
		}
		*aqilah = *alifian;
		*alifian = (*alifian)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty(){
	return LAST == NULL;
}

bool CircularLinkedList::delNode() {

}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nlist is empty\n";
	}
	else {
		cout << "\nRecord in the list are: \n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << "" << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << "" << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "menu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";

			char ch;
			cin >> ch;

			switch (ch) {
			case '1':{
					obj.addNode();
					break;
				}
			case '2':{
					obj.delNode();
					break;
				}
			case '3':{
					obj.traverse();
					break;
				}
			case '4': {
				return 0;
			}
			default: {
				cout << "invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}