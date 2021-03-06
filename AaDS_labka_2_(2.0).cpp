#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "Class.h"


using namespace std;

int main()
{
	cout << "Laboratory work 2" << endl << "Option 4" << endl;
	cout << "Author: Fomchenkova N.A." << '\ n' << "Group: 7301" << endl;
	cout << "List type: doubly connected" << endl << "Realizable functions: 1-12, 14" << endl;
	LinkedList list;

	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
	list.push_front(4);
	list.push_front(3);
	list.push_front(2);
	list.push_front(1);
	list.push_front(0);
	
	list.print_to_console_hd_tl();
	list.print_to_console_tl_hd();
	cout << "List size:" << list.get_size() << endl << endl;

	cout << "Removing an element from the beginning" << endl;
	list.pop_front();
	list.print_to_console_hd_tl();
	cout << "List size:" << list.get_size() << endl;

	cout << "Removing an element from the end" << endl;
	list.pop_back();
	list.print_to_console_hd_tl();
	cout << "List size:" << list.get_size() << endl << endl;
	cout << "Working with a list through the index" << endl;

	list.delete_(2);
	list.insert(3, 2);
	
	list.insert(0, 0);
	


	list.print_to_console_hd_tl();
	cout << "List size:" << list.get_size() << endl;
	cout << "Element output by index" << endl;
	cout << "Element with intex 5:" << list.at(5) << endl;
	

	list.set(-10, 0);
	list.set(-10, 7);
	list.set(-10, 5);
	list.print_to_console_hd_tl();

	list.clear();
	cout << "Check for emptiness:" << list.isEmpty() << endl;
	cout << endl << "Adding a list to the list after 2 nodes:" << endl;
	LinkedList list_1;
	list_1.push_back(1);
	list_1.push_back(2);
	list_1.push_back(3);
	list_1.push_back(4);

	LinkedList list_2;
	list_2.push_back(5);
	list_2.push_back(6);
	list_2.push_back(7);
	list_2.push_back(8);

	list_1.insert_list(list_2, 4);
	list_1.print_to_console_hd_tl();
	list_1.print_to_console_tl_hd();
	_getch();
    return 0;
}

