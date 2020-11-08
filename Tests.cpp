#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include "Sort.hpp"
#include <string>


Sequence<int>* int_seq_for_test(const int choice) {
	
	if (choice == 1) {
		ArraySequence<int>* int_ar = new ArraySequence<int>();
		for (int i = 99; i >= 0; i--)
		{
			int_ar->Prepend(i);
		}
		return int_ar;
	}
	else {
		ArraySequence<int>* int_li = new ArraySequence<int>();
		for (int i = 99; i >= 0; i--)
		{
			int_li->Prepend(i);
		}
		return int_li;
	}
}

Sequence<double>* double_seq_for_test(const int choice) {
	
	if (choice == 1) {
		ArraySequence<double>* double_ar = new ArraySequence<double>();
		for (double i = 99; i >= 0; i--)
		{
			double_ar->Prepend(i);
		}
		return double_ar;
	}
	else {
		ArraySequence<double>* double_li = new ArraySequence<double>();
		for (double i = 99; i >= 0; i--)
		{
			double_li->Prepend(i);
		}
		return double_li;
	}
}

Sequence<std::string>* string_seq_for_test(const int choice) {
	std::string str;
	if (choice == 1) {
		ArraySequence<std::string>* string_ar = new ArraySequence<std::string>();
		for (int i = 9; i >= 0; i--)
		{	str = std::to_string(i);
			string_ar->Prepend(str);
			
		}
		return string_ar;
	}
	else {
		ArraySequence<std::string>* string_li = new ArraySequence<std::string>();
		for (int i = 9; i >= 0; i--)
		{
			str = std::to_string(i);
			string_li->Prepend(str);
		}
		return string_li;
	}
}


template <typename T>
void test_quicksort(Sequence<T>* seq) {
	bool check = true;
	QuickSort1(seq, 0, 99);
	for (int i = 0; i < 100; i++) {
		if (seq->Get(i) != i)
			check = false;
	}
	if (check)
		std::cout << "Quick sort SUCCESS" << std::endl;
	else
		std::cout << "Quick sort FAILED" << std::endl;
}

template <typename T>
void test_shellsort(Sequence<T>* seq) {
	bool check = true;
	ShellSort(seq, 100);
	for (int i = 0; i < 100; i++) {
		if (seq->Get(i) != i)
			check = false;
	}
	if (check)
		std::cout << "Shell sort SUCCESS" << std::endl;
	else
		std::cout << "Shell sort FAILED" << std::endl;
}

template <typename T>
void test_shakersort(Sequence<T>* seq) {
	bool check = true;
	ShakerSort(seq, 100);
	for (int i = 0; i < 100; i++) {
		if (seq->Get(i) != i)
			check = false;
	}
	if (check)
		std::cout << "Shaker sort SUCCESS" << std::endl;
	else
		std::cout << "Shaker sort FAILED" << std::endl;
}


// test sorts string
void test_quicksort(Sequence<std::string>* seq) {
	bool check = true;
	std::string str;
	QuickSort1(seq, 0, 9);
	for (int i = 0; i < 10; i++) {
		str = std::to_string(i);
		if (seq->Get(i) != str)
			check = false;	
	}
	if (check)
		std::cout << "Quick sort SUCCESS" << std::endl;
	else
		std::cout << "Quick sort FAILED" << std::endl;
}


void test_shellsort(Sequence<std::string>* seq) {
	bool check = true;
	std::string str;
	ShellSort(seq, 10);
	for (int i = 0; i < 10; i++) {
		str = std::to_string(i);
		if (seq->Get(i) != str)
			check = false;
	}
	if (check)
		std::cout << "Shell sort SUCCESS" << std::endl;
	else
		std::cout << "Shell sort FAILED" << std::endl;
}


void test_shakersort(Sequence<std::string>* seq) {
	bool check = true;
	std::string str;
	ShakerSort(seq, 10);
	for (int i = 0; i < 10; i++) {
		str = std::to_string(i);
		if (seq->Get(i) != str)
			check = false;
	}
	if (check)
		std::cout << "Shaker sort SUCCESS" << std::endl;
	else
		std::cout << "Shaker sort FAILED" << std::endl;
}

void testAS() {
	std::cout <<  "Integer tests:" << std::endl;
	test_quicksort(int_seq_for_test(1));
	test_shellsort(int_seq_for_test(1));
	test_shakersort(int_seq_for_test(1));

	std::cout << "\n" << "Double tests:" << std::endl;
	test_quicksort(double_seq_for_test(1));
	test_shellsort(double_seq_for_test(1));
	test_shakersort(double_seq_for_test(1));

	std::cout << "\n" << "String tests:" << std::endl;
	test_quicksort(string_seq_for_test(1));
	test_shellsort(string_seq_for_test(1));
	test_shakersort(string_seq_for_test(1));
}

void testLS() {
	std::cout << "Integer tests:" << std::endl;
	test_quicksort(int_seq_for_test(2));
	test_shellsort(int_seq_for_test(2));
	test_shakersort(int_seq_for_test(2));

	std::cout << "\n" << "Double tests:" << std::endl;
	test_quicksort(double_seq_for_test(2));
	test_shellsort(double_seq_for_test(2));
	test_shakersort(double_seq_for_test(2));

	std::cout << "\n" << "String tests:" << std::endl;
	test_quicksort(string_seq_for_test(2));
	test_shellsort(string_seq_for_test(2));
	test_shakersort(string_seq_for_test(2));
}


int main() {
	std:: cout << "Tests of ArraySequence: " << std:: endl;
	testAS();
	std::cout <<"\n"<< "Tests of ListSequence: " << std::endl;
	testLS();
	return 0;
}