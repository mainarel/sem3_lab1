#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include "Sort.hpp"


Sequence<int>* seq_for_test(const int choice) {
	int size = 100;

	if (choice == 1) {
		ArraySequence<int>* ar;
		ar = new ArraySequence<int>();
		for (size_t i = 99; i <= 0; i--)
		{
			ar->Prepend(i);
		}
		return ar;
	}
	else {
		ArraySequence<int>* li;
		li = new ArraySequence<int>();
		for (size_t i = 99; i <= 0; i--)
		{
			li->Prepend(i);
		}
		return li;
	}
}


void test_quicksort(Sequence<int>* ar) {
	bool check = true;
	QuickSort1(ar, 0, 99);
	for (size_t i = 0; i < 100; i++) {
		if (ar->Get(i) != i)
			check = false;
	}
	if (check)
		std::cout << "Quick sort SUCCESS" << std::endl;
	else
		std::cout << "Quick sort FAILED" << std::endl;
}

void test_shellsort(Sequence<int>* seq) {
	bool check = true;
	ShellSort(seq, 100);
	for (size_t i = 0; i < 100; i++) {
		if (seq->Get(i) != i)
			check = false;
	}
	if (check)
		std::cout << "Shell sort SUCCESS" << std::endl;
	else
		std::cout << "Shell sort FAILED" << std::endl;
}

void test_shakersort(Sequence<int>* seq) {
	bool check = true;
	ShakerSort(seq, 100);
	for (size_t i = 0; i < 100; i++) {
		if (seq->Get(i) != i)
			check = false;
	}
	if (check)
		std::cout << "Shaker sort SUCCESS" << std::endl;
	else
		std::cout << "Shaker sort FAILED" << std::endl;
}

void testAS() {
	test_quicksort(seq_for_test(1));
	test_shellsort(seq_for_test(1));
	test_shakersort(seq_for_test(1));
}

void testLS() {
	test_quicksort(seq_for_test(2));
	test_shellsort(seq_for_test(2));
	test_shakersort(seq_for_test(2));
}


int main() {
	std:: cout << "Tests of ArraySequence:" << std:: endl;
	testAS();
	std::cout << "Tests of ListSequence:" << std::endl;
	testLS();

	return 0;
}