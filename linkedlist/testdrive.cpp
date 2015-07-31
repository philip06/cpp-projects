#include <iostream>
#include "link.hpp"

namespace {
void nodeClean(Node* headnode) {
        Node* node = headnode;
        Node* temp;
        while (node->next != NULL) {
                temp = node;
                delete node;
                node = temp->next;
        }
}
}

int main() {
	Node node();
	node.append(7);
	node.append(3);
	node.append(9);
	node.find(3);
	node.find(7);
	node.find(9);
	node.remove(0);
	node.displayValue(0);
	nodeClean(&node);
}
