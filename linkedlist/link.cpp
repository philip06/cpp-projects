#include <cstddef>
#include <iostream>

#include "link.hpp"

Node::Node() {
	Node::next = NULL;
}
void Node::append(int value) {
	if (this->next == NULL) {
		Node *node = new Node(value); // new = add to heap || without new it puts it on stack and is deleted after function is ran
		node->data = value;
		this->next = node;
		std::cout << "Node Data: " << node->data << std::endl;

	} else {
		Node::next->append(value);
	}
}

void Node::remove(int value) {
	if (Node::next->data == value) {
		if (Node::next->next == NULL) {
			Node::data = Node::next->data;
			Node::next = NULL;
		} else if () {
			Node::next = Node::next->next;
		} else {
			Node::next = Node::next->next;
		}
	} else if (this->data == value) {
		delete this;
	}
}

void Node::find(int value) {
	if (value == this->data) {
		std::cout << "Value: " << Node::data << std::endl;
	} else if (this->next != NULL) {
		Node::next->displayValue(value);
	} else {
		std::cout << "Linked list is fucked up." << std::endl;
	}
}
