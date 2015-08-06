#ifndef LINK_H
#define LINK_H

template <typename gen_type> struct Node {
	public:
		gen_type data;
		bool head;
		Node* next;
		Node();
		void showContents();
		void append(gen_type value);
		void remove(gen_type value);
		void find(gen_type value);
};

#endif
