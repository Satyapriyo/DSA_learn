// C++ code for the deleting a node from end using two
// pointer approach

#include <iostream>
using namespace std;

class LinkedList {
public:
	// structure of a node
	class Node {
	public:
		int data;
		Node* next;
		Node(int d)
		{
			data = d;
			next = NULL;
		}
	};

	// Head node
	Node* head;

	// Function for inserting a node at the beginning
	void push(int data)
	{
		Node* new_node = new Node(data);
		new_node->next = head;
		head = new_node;
	}

	// Function to display the nodes in the list.
	void display()
	{
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}

	// Function to delete the nth node from the end.
	void deleteNthNodeFromEnd(Node* head, int n)
	{
		Node* fast = head;
		Node* slow = head;

		for (int i = 0; i < n; i++) {
			fast = fast->next;
		}
		if (fast == NULL) {
			head = head->next;
			return;
		}

		while (fast->next != NULL) {
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;
		return;
	}
};

int main()
{

	LinkedList* l = new LinkedList();

	// Create a list 1->2->3->4->5->NULL
	l->push(5);
	l->push(4);
	l->push(3);
	l->push(2);
	l->push(1);
	cout << "***** Linked List Before deletion *****"
		<< endl;
	l->display();

	cout << "************** Delete nth Node from the End "
			"*****"
		<< endl;
	l->deleteNthNodeFromEnd(l->head, 2);

	cout << "*********** Linked List after Deletion *****"
		<< endl;
	l->display();

	return 0;
}

// This code is contributed by lokesh (lokeshmvs21).
