#ifndef LINK_H
#define LINK_H

struct Node {
	public:
		Node();
		void showContents();
		void append(int value);
		void remove(int value);
		bool find(int value);
		int data;
		bool head;
		Node* next;
};

#endif
