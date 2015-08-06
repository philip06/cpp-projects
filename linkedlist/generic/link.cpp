#include <cstddef>
#include <iostream>
#include <climits>

#include "link.hpp"

template <typename gen_type>
Node<gen_type>::Node() {
	Node::head = true;
	Node::next = NULL;
}

template <typename gen_type>
void Node<gen_type>::append(gen_type value) {
	if (this->next == NULL) {
		Node<gen_type> *node = new Node<gen_type>; // new = add to heap || without new it puts it on stack and is deleted after function is ran
		node->data = value;
		node->head = false;
		this->next = node;
		std::cout << "Node Data Added: " << node->data << std::endl;
	} else {
		Node::next->append(value);
	}
}

template <typename gen_type>
void Node<gen_type>::remove(gen_type value) {
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

template <typename gen_type>
void Node<gen_type>::find(gen_type value) {
	if (value == this->data) {
		std::cout << "Value: " << Node::data << std::endl;
	} else if (this->next != NULL) {
		Node::next->find(value);
	} else {
		std::cout << "Linked list is fucked up." << std::endl;
	}
}

template <typename gen_type>
void Node<gen_type>::showContents() {
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
