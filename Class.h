#pragma once


class LinkedList
{

public:

	LinkedList();
	~LinkedList();
	void push_back(int); // add to end of list
	void push_front(int); // adding to the top of the list
	void pop_back(); // delete last item
	void pop_front(); // delete first item
	void insert(int, size_t); // add item by index
	int at(size_t); //	getting item by index
	void delete_(size_t); // delete item by index
	size_t get_size(); // getting list size
	void clear(); // delete all list items
	void set(int, size_t); // replacing an item by index with a passed item
	bool isEmpty(); // check for empty list
	void insert_list(LinkedList& list_2, size_t); // insert another list in the list, starting from the specified index
	void print_to_console_hd_tl(); // direct listing
	void print_to_console_tl_hd(); // reverse listing
	bool equals(LinkedList * list);

private: 
	void add_first(int data);
	void reset_list();


	class Node
	{
	public:
		Node(int data, Node * next = nullptr, Node * prev = nullptr)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		};
		~Node() {};

		int data;
		Node * next;
		Node * prev;
	};
	Node * head;
	Node * tail;
	size_t size;
};

