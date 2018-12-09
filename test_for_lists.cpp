#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AaDS_labka_2_(2.0)/Class.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test_for_lab_aads_2
{
	TEST_CLASS(UnitTestsForLists)
	{
	public:
		TEST_METHOD(Empty_or_not_true) //check for emptiness
		{
			LinkedList list;
			Assert::IsTrue(list.isEmpty());
		}
		TEST_METHOD(Empty_or_not_false) //check for emptiness
		{
			LinkedList list;
			list.push_front(1);
			Assert::IsFalse(list.isEmpty());
		}
		TEST_METHOD(check_get_size_true)// correctness of checking the list size
		{
			LinkedList list;

			list.push_front(1);
			list.push_front(2);
			list.push_front(3);
			list.push_front(4);
			list.push_front(5);
			Assert::IsTrue(list.get_size() == 5);

		}
		TEST_METHOD(check_get_size_false)// correctness of checking the list size
		{
			LinkedList list;

			list.push_front(1);
			list.push_front(2);
			list.push_front(3);
			list.push_front(4);
			list.push_front(5);
			Assert::IsFalse(list.get_size() == 4);
		}
		TEST_METHOD(check_get_item_by_index_true)// output element by index
		{
			LinkedList list;
			list.push_front(1);
			list.push_front(2);
			list.push_front(3);
			list.push_front(4);
			list.push_front(5);
			Assert::IsTrue(list.at(0) == 5);
		}
		TEST_METHOD(check_get_item_by_index_false)//  output element by index
		{
			LinkedList list;
			list.push_front(1);
			list.push_front(2);
			list.push_front(3);
			list.push_front(4);
			list.push_front(5);
			Assert::IsFalse(list.at(0) == 1);
		}
		TEST_METHOD(check_push_front_true)//   checking the list filled in by type "add to the beginning"
		{
			LinkedList list;
			list.push_front(1);
			list.push_front(2);
			list.push_front(3);
			Assert::IsTrue(list.at(2) == 1);
		}
		TEST_METHOD(check_push_back_true)// checking the list filled in by type "add to the end"
		{
			LinkedList list;
			list.push_back(1);
			list.push_back(2);
			list.push_back(3);
			Assert::IsTrue(list.at(2) == 3);
		}
		TEST_METHOD(check_is_clean_true)// delete list
		{
			LinkedList list;
			list.push_front(1);
			list.push_front(2);
			list.push_front(3);
			list.push_front(4);
			list.push_front(5);
			list.clear();
			Assert::IsTrue(list.isEmpty());
		}
		TEST_METHOD(equals_or_not)//   check for sameness 2 lists
		{
			LinkedList list_1;
			list_1.push_back(1);
			list_1.push_back(2);
			list_1.push_back(3);
			list_1.push_back(4);

			LinkedList list_2;
			list_2.push_back(1);
			list_2.push_back(2);
			list_2.push_back(3);
			list_2.push_back(4);

			Assert::IsTrue(list_1.equals(&list_2));
		}

		TEST_METHOD(equals_different_sizes)//   check for sameness 2 lists of different sizes
		{
			LinkedList list_1;
			list_1.push_back(1);
			list_1.push_back(2);

			LinkedList list_2;
			list_2.push_back(1);
			list_2.push_back(2);
			list_2.push_back(3);
			list_2.push_back(4);

			Assert::IsFalse(list_1.equals(&list_2));
		}
		TEST_METHOD(check_delete_elem_true)//  delete item by index
		{
			LinkedList list_1;
			list_1.push_back(1);
			list_1.push_back(2);
			list_1.push_back(3);
			list_1.push_back(4);
			list_1.delete_(2);

			LinkedList list_2;
			list_2.push_back(1);
			list_2.push_back(2);
			list_2.push_back(4);

			Assert::IsTrue(list_1.equals(&list_2));
		}
		TEST_METHOD(check_delete_all_elem_true)//  delete item by index(all)
		{
			LinkedList list_1;
			list_1.push_back(1);
			list_1.push_back(2);
			list_1.push_back(3);
			list_1.push_back(4);
			list_1.delete_(3);
			list_1.delete_(2);
			list_1.delete_(1);
			list_1.delete_(0);

			Assert::IsTrue(list_1.isEmpty());
		}
		TEST_METHOD(check_delete_elem_false)//  delete item by wrong index
		{
			LinkedList list_1;
			list_1.push_back(1);
			list_1.push_back(2);
			list_1.push_back(3);
			list_1.push_back(4);
			

			try
			{
				list_1.delete_(8);
			}
			catch (const std::out_of_range error)
			{
				Assert::AreEqual(error.what(), "Index is greater then list size");

			}

		}
		TEST_METHOD(delete_index_greater_than_list) // delete by index exceeding list sizes
		{
			LinkedList list_1;
			list_1.push_back(1);
			list_1.push_back(2);
			list_1.push_back(3);
			try
			{
				list_1.delete_(8);
			}
			catch (const std::out_of_range error)
			{
				Assert::AreEqual(error.what(), "Index is greater then list size");

			}
		}
		TEST_METHOD(check_pop_front)//remove 1st item
		{
			LinkedList list_1;
			list_1.push_back(1);
			list_1.push_back(2);
			list_1.push_back(3);
			list_1.push_back(4);
			list_1.push_back(5);
			list_1.pop_front();

			LinkedList list_2;
			list_2.push_back(2);
			list_2.push_back(3);
			list_2.push_back(4);
			list_2.push_back(5);
			Assert::IsTrue(list_1.equals(&list_2));
		}
		TEST_METHOD(check_pop_front_empty_list)// remove 1st item from empty list
		{
			LinkedList list_1;
			try {
				list_1.pop_front();

			}
			catch (const std::out_of_range error){

				Assert::AreEqual(error.what(), "List is empty");
			}
		}
		TEST_METHOD(check_pop_back)// remove last item
		{
			LinkedList list_1;
			list_1.push_back(1);
			list_1.push_back(2);
			list_1.push_back(3);
			list_1.push_back(4);
			list_1.push_back(5);
			list_1.pop_back();

			LinkedList list_2;
			list_2.push_back(1);
			list_2.push_back(2);
			list_2.push_back(3);
			list_2.push_back(4);
			Assert::IsTrue(list_1.equals(&list_2));
		}
		TEST_METHOD(check_pop_back_empty_list)//remove last item from empty list
		{
			LinkedList list_1;
			try {
				list_1.pop_back();

			}
			catch (const std::out_of_range error)
			{

				Assert::AreEqual(error.what(), "List is empty");
			}
		}

		TEST_METHOD(check_set_true)// replace item by index
		{
			LinkedList list_1;
			list_1.push_back(1);
			list_1.push_back(2);
			list_1.push_back(3);
			list_1.push_back(4);
			list_1.set(-1, 0);
			list_1.set(-2, 1);
			list_1.set(-3, 2);
			list_1.set(-4, 3);

			LinkedList list_2;
			list_2.push_back(-1);
			list_2.push_back(-2);
			list_2.push_back(-3);
			list_2.push_back(-4);
			Assert::IsTrue(list_1.equals(&list_2));
		}
		
		TEST_METHOD(check_set_false_index)// replace item by index(index is larger than the list size)
		{
			LinkedList list_1;
			list_1.push_back(1);
			list_1.push_back(2);
			list_1.push_back(3);
			list_1.push_back(4);
			try
			{
				list_1.set(7, 7);
			}
			catch (const std::out_of_range error)
			{
				Assert::AreEqual(error.what(), "Index is greater then list size");
			}
		}

		TEST_METHOD(check_at_true)//check getting item by index
		{
			LinkedList list_1;
			list_1.push_back(1);
			list_1.push_back(2);
			list_1.push_back(3);
			list_1.push_back(4);
			int help_variable = list_1.at(3);
			Assert::IsTrue(help_variable==4);
		}
		TEST_METHOD(check_at_large_index)//check getting item by index (index is larger than the list size)
		{
			LinkedList list_1;
			list_1.push_back(1);
			list_1.push_back(2);
			list_1.push_back(3);
			list_1.push_back(4);
			try
			{
				list_1.at(7);
			}
			catch (const std::out_of_range error)
			{
				Assert::AreEqual(error.what(), "Index is greater then list size");

			}
		}

	

		TEST_METHOD(check_insert_list_true)// check list insert list (middle)
		{
			LinkedList list_1;
			list_1.push_back(1);
			list_1.push_back(2);
			list_1.push_back(7);
			list_1.push_back(8);

			LinkedList list_2;
			list_2.push_back(3);
			list_2.push_back(4);
			list_2.push_back(5);
			list_2.push_back(6);

			list_1.insert_list(list_2, 2);
			LinkedList list_3;
			list_3.push_back(1);
			list_3.push_back(2);
			list_3.push_back(3);
			list_3.push_back(4);
			list_3.push_back(5);
			list_3.push_back(6);
			list_3.push_back(7);
			list_3.push_back(8);

			Assert::IsTrue(list_1.equals(&list_3));
		}


		TEST_METHOD(check_insert_list_in_the_middle_f)//check list insert list (middle)
		{
			LinkedList list_1;
			list_1.push_back(1);
			list_1.push_back(2);
			list_1.push_back(7);
			list_1.push_back(8);

			LinkedList list_2;
			list_2.push_back(3);
			list_2.push_back(4);
			list_2.push_back(5);
			list_2.push_back(6);

			list_1.insert_list(list_2, 0);
			LinkedList list_3;
			list_3.push_back(1);
			list_3.push_back(2);
			list_3.push_back(3);
			list_3.push_back(4);
			list_3.push_back(5);
			list_3.push_back(6);
			list_3.push_back(7);
			list_3.push_back(8);

			Assert::IsFalse(list_1.equals(&list_3));
		}


		TEST_METHOD(check_insert_list_to_the_begining_t)// check list insert list (at the beginning)
		{
			LinkedList list_1;
			list_1.push_back(5);
			list_1.push_back(6);
			list_1.push_back(7);
			list_1.push_back(8);

			LinkedList list_2;
			list_2.push_back(1);
			list_2.push_back(2);
			list_2.push_back(3);
			list_2.push_back(4);

			list_1.insert_list(list_2, 0);
			LinkedList list_3;
			list_3.push_back(1);
			list_3.push_back(2);
			list_3.push_back(3);
			list_3.push_back(4);
			list_3.push_back(5);
			list_3.push_back(6);
			list_3.push_back(7);
			list_3.push_back(8);

			Assert::IsTrue(list_1.equals(&list_3));
		}

		TEST_METHOD(check_insert_list_to_the_end_true)// check list insert list (in the end) 
		{
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
		LinkedList list_3;
		list_3.push_back(1);
		list_3.push_back(2);
		list_3.push_back(3);
		list_3.push_back(4);
		list_3.push_back(5);
		list_3.push_back(6);
		list_3.push_back(7);
		list_3.push_back(8);

		Assert::IsTrue(list_1.equals(&list_3));
		}

		TEST_METHOD(check_insert_list_empty_list_true)// check the insertion of an empty list into the list
		{
		LinkedList list_1;
		list_1.push_back(1);
		list_1.push_back(2);
		list_1.push_back(3);
		list_1.push_back(4);

		LinkedList list_2;

		list_1.insert_list(list_2, 0);
		LinkedList list_3;
		list_3.push_back(1);
		list_3.push_back(2);
		list_3.push_back(3);
		list_3.push_back(4);

		Assert::IsTrue(list_1.equals(&list_3));
		}




		TEST_METHOD(check_insert_elem_in_the_end_true)// add list node by index to end
		{
		LinkedList list_1;
		list_1.push_back(1);
		list_1.push_back(2);
		list_1.push_back(3);
		list_1.insert(4,3);


		LinkedList list_2;
		list_2.push_back(1);
		list_2.push_back(2);
		list_2.push_back(3);
		list_2.push_back(4);

		Assert::IsTrue(list_1.equals(&list_2));
		}

		TEST_METHOD(check_insert_elem_in_the_begining_true)// add list node by index to the beginning
		{
		LinkedList list_1;
		list_1.push_back(1);
		list_1.push_back(2);
		list_1.push_back(3);
		list_1.insert(0, 0);


		LinkedList list_2;
		list_2.push_back(1);
		list_2.push_back(2);
		list_2.push_back(3);
		list_2.push_front(0);

		Assert::IsTrue(list_1.equals(&list_2));
		}

		TEST_METHOD(check_insert_elem_in_the_middle_true)// add list node by index
		{
		LinkedList list_1;
		list_1.push_back(1);
		list_1.push_back(2);
		list_1.push_back(4);
		list_1.insert(3, 2);


		LinkedList list_2;
		list_2.push_back(1);
		list_2.push_back(2);
		list_2.push_back(3);
		list_2.push_back(4);

		Assert::IsTrue(list_1.equals(&list_2));
		}

		
	};
}