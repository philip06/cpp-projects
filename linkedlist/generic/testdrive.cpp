#include <iostream>
#include "link.hpp"

namespace {
template <typename gen_type>
void nodeClean(Node<gen_type>* headnode) {
	Node<gen_type>* node = headnode;
        Node<gen_type>* temp;
        while (node != NULL) {
		if (node->head == false) {
                	temp = node;
                	delete node;
                	node = temp->next;
		} else {
			temp = node;
			node = temp->next;
		}
        }
}
}

int main() {
	Node<int> node;
	std::cout << "Appending Data: " << std::endl;
	node.append(1);
	//node.append(2);
	//node.append(3);
	//node.append(4);
	std::cout << "Displaying Data: " << std::endl;
	node.showContents();
	//std::cout << "Removing Data: " << std::endl;
	//node.remove(4);
	//node.remove(2);
	//node.remove(1);
	//std::cout << "Displaying Data: " << std::endl;
	//node.showContents();
	nodeClean(&node);
}
