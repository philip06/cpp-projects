#include <cstddef>
#include <iostream>
#include <climits>

#include "link.hpp"

Node::Node() {
	Node::head = true;
	Node::next = NULL;
}

void Node::append(int value) {
	if (this->next == NULL) {
		Node *node = new Node; // new = add to heap || without new it puts it on stack and is deleted after function is ran
		node->data = value;
		node->head = false;
		this->next = node;
		std::cout << "Node Data Added: " << node->data << std::endl;
	} else {
		Node::next->append(value);
	}
}

void Node::remove(int value) {
	if (Node::next->data == value) {
		Node* temp;
		if (Node::next->next == NULL) {
			temp = Node::next;
			Node::next = NULL;
			delete temp;
			std::cout << "Node Data Removed: " << value << std::endl;
		} else if (Node::head == true) {
			temp = Node::next;
			Node::next = Node::next->next;
			delete temp;
			std::cout << "Node Data Removed: " << value << std::endl;
		} else {
			temp = Node::next;
			Node::next = Node::next->next;
			delete temp;
			std::cout << "Node Data Removed: " << value << std::endl;
		}
	} else if (this->data != value) {
		Node::next->remove(value);
	}
}

bool Node::find(int value) {
	if (value == this->data) {
		return true;
	} else if (this->next != NULL) {
		Node::next->find(value);
	}
	return false;
}

void Node::showContents() {
	if (Node::head == false) {
		if (Node::next != NULL) {
			std::cout << "Data: "  << Node::data << ", This: " << this << ", Next: " << Node::next << ", Head: " << Node::head << std::endl;
			Node::next->showContents();
		} else {
			std::cout << "Data: "  << Node::data << ", This: " << this << ", Next: " << Node::next << ", Head: " << Node::head << std::endl;
		}
	} else {
		//std::cout << "Data: "  << Node::data << ", This: " << this << ", Next: " << Node::next << ", Head: " << Node::head << std::endl;
		Node::next->showContents();
	}
}
