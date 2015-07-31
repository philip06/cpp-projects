#ifndef LINK_H
#define LINK_H

struct Node {
	public:
		int data;
		Node* next;
		Node();
		void append(int value);
		void remove(int value);
		void displayValue(int value);
};

#endif
