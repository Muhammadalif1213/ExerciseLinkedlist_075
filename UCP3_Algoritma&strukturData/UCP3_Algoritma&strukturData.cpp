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

