#include "stdafx.h"
#include "Class.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void LinkedList::reset_list()
{
	head = nullptr;
	tail = nullptr;
}

LinkedList::LinkedList() 
{	
	reset_list();
	size = 0;
}

LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::push_front(int data)
{
	if (size == 0)
		add_first(data);
	else
	{
		head = new Node(data, head);
		head->next->prev = head;
	}
	size++;
}

void LinkedList::push_back(int data)
{
	if (size == 0)
		add_first(data);
	else
	{
		tail= new Node(data, nullptr,tail);
		tail->prev->next = tail;
	}
	size++;
}

void LinkedList::add_first(int data)
{
	head = new Node(data);
	tail = head;
}

void LinkedList::pop_front()
{
	if (size == 0)
		throw out_of_range("List is empty");
	if (size == 1)
	{
		delete head;
		reset_list();

	}
	else
	{
		Node * current = head;
		head = head->next;
		delete current;
		head->prev = nullptr;
	}
	size--;
}

void LinkedList::pop_back()
{
	if (size == 0)
	{
		throw out_of_range("List is empty");
	}
	if (size == 1)
	{
			delete head;
			reset_list();

	}
	else
	{
		Node * current = tail;
		tail = tail->prev;
		delete current;
		tail->next = nullptr;
		size--;
	}	
}

void LinkedList::insert(int number, size_t index)
{
	if (index > size)
		throw out_of_range("Index is greater then list size");

	size_t index_help = 0;
	Node * current = head;
	while (index_help != index) {
		current = current->next;
		index_help++;
	}
	if (index_help == 0) {
		push_front(number);
	}
	else {
		if (index_help == size) {
			push_back(number);
		}
		else {
			Node * new_elem = new Node(number, current, current->prev);
			current->prev->next = new_elem;
			current->prev = new_elem;
			size++;
		}
	}
}

void LinkedList::print_to_console_hd_tl()
{
	Node * current = head;
	while (current != NULL) {
		cout << current->data << " ";
		current = current->next;

	}
	cout << endl;
}

void LinkedList::print_to_console_tl_hd()
{
	Node * current = tail;
	while (current != NULL) {
		cout << current->data << " ";
		current = current->prev;

	}
	cout << endl;

}

int LinkedList::at(size_t index) 
{
	if (size <= index)
	{
		throw out_of_range("Index is greater then list size");
	}	
	size_t index_help = 0;
	Node * current = head;
	while (current != NULL && index_help != index)
	{
		current = current->next;
		index_help++;
	}
		return current->data;
}

void LinkedList::delete_(size_t index)
{

		if (index >= size)
		{
			throw out_of_range("Index is greater then list size");
		}
		else
		{
			if (size == 0)
			{
				throw out_of_range("List is empty");
			}
			else {
				Node * current = head;
				size_t index_help = 0;
				while ((current != NULL) && (index_help != index))
				{
					current = current->next;
					index_help++;
				}
				if (current == head)
				{
					pop_front();
					return;
				}
				else
				{
					if (current == tail)
					{
						pop_back();
						return;
					}
					else
					{
						current->prev->next = current->next;
						current->next->prev = current->prev;
						delete current;
						size--;
					}
				}
			}
		}

}
	
size_t LinkedList::get_size()
{
	return size;
}


void LinkedList::clear()
{	
	if (size == 0) return;
	if (size == 1) {
		reset_list();
		delete head;
		delete tail;
	}
	else {
		while (head != nullptr) {
			pop_front();
		}
		reset_list();
		delete head;
		delete tail;
	}
}




void LinkedList::set(int number, size_t index)
{
	if (index >= size) {
		throw out_of_range("Index is greater then list size");
	}
	else {
		size_t index_help = 0;
		Node * current = head;
		if (index == 0)
		{
			Node * new_elem = new Node(number, head->next);
			head->next->prev = new_elem;
			delete head;
			head = new_elem;
		}
		else
		{
			if (index == size - 1)
			{
				Node * new_elem = new Node(number, nullptr, tail->prev);
				tail->prev->next = new_elem;
				delete tail;
				tail = new_elem;
			}
			else
			{
				Node * current = head;
				while (index_help != index) {
					current = current->next;
					index_help++;
				}
				Node * new_elem = new Node(number, current->next, current->prev);
				current->prev->next = new_elem;
				current->next->prev = new_elem;
				delete current;
			}
		}
	}
}


bool LinkedList::isEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}

void LinkedList::insert_list(LinkedList& list_2, size_t index)
{
	if (size < index)
	{ 
		throw out_of_range("Index is greater then list size");
	}
	else
	{
		if (list_2.get_size() == 0)
		{
			return;
		}
		else
		{
			if (size == 0)
			{
				
				Node * current = list_2.head; // pointer for old list 
				LinkedList main_list;
				Node * help_elem = new Node(current->data, nullptr, nullptr);
				main_list.head = help_elem;
				main_list.tail = help_elem;
				current = current->next;
				Node * cur_help = help_elem; // pointer for new list 
				while (current != NULL)
				{
					Node *help_elem = new Node(current->data, nullptr, main_list.tail);
					cur_help->next = help_elem;
					cur_help = cur_help->next;
					main_list.tail = cur_help;
					current = current->next;
				}
				head = main_list.head;
				tail = main_list.tail;
				size = list_2.size;
				return;
			}
			else {
				Node * current = head;
				if (index == 0)
				{
					current->prev = list_2.tail;
					list_2.tail->next = current;
					head = list_2.head;
				}
				else {
					if (index == size)
					{
						current = tail;
						list_2.head->prev = current;
						current->next = list_2.head;
						tail = list_2.tail;
					}
					else
					{
						size_t index_help = 0;
						while (index_help != index) {
							current = current->next;
							index_help++;
						}
						list_2.tail->next = current;
						list_2.head->prev = current->prev;
						current->prev->next = list_2.head;
						list_2.head->prev = current->prev;
						current->prev = list_2.tail;
					}
				}
				
				LinkedList main_list;
				current = head;

				Node * help_elem = new Node(current->data, nullptr, nullptr);
				main_list.head = help_elem;
				main_list.tail = help_elem;
				current = current->next;
				Node * cur_help = help_elem; // pointer for new list 
				while (current != NULL)
				{
					Node *help_elem = new Node(current->data, nullptr, main_list.tail);
					cur_help->next = help_elem;
					cur_help = cur_help->next;
					main_list.tail = cur_help;
					current = current->next;
				}
				
				head = main_list.head;
				tail = main_list.tail;

				}
				size += list_2.size;
			}

	}
}

bool LinkedList::equals(LinkedList * list)
{
	if (size != list->size)
		return false;
	for (size_t i = 0; i < size; i++)
	{
		if (list->at(i) != at(i))
			return false;
	}
	return true;
}


