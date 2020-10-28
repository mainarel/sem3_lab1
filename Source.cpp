#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include "Sort.hpp"
#include<iostream>

using namespace std;

void Print(Sequence<int>* seq, const int& length){
	cout << "It is your sequence: " << endl;
	for (size_t i = 0; i < length; i++) {
		cout << seq->Get(i) << " ";
	}
	cout << endl;
}

template <typename T>
Sequence<T>* testQuickSort(Sequence<T>* seq, const int& length) {
	cout << "TESTS QUICKSORT:" << endl;
	QuickSort1(seq, 0, length-1 );
	return seq;
}
template <typename T>
Sequence<T>* testShellSort(Sequence<T>* seq, const int& length) {
	cout << "TESTS SHELLSORT: " << endl;
	ShellSort(seq, length);
	return seq;
}
template <typename T>
Sequence<T>* testShakerSort(Sequence<T>* seq, const int& length) {
	cout << "TESTS SHAKERSORT: " << endl;
	ShakerSort(seq, length);
	return seq;
}
ArraySequence<int>* createArray(const int& length) {
	int choose_input;
	cout << "How do you want to fill the sequence? " << endl << "1. By hand" << endl << "2. Random" << endl;
	ArraySequence<int>* array;
	array = new ArraySequence<int>();
	cin >> choose_input;
	switch (choose_input) {
	case 1: int value;

		cout << "Enter the values: " << endl;
		for (size_t i = 0; i < length; i++)
		{
			cin >> value;
			array->Prepend(value);
		}

		break;
	case 2:

		for (size_t i = 0; i < length; i++)
		{
			array->Prepend(rand());
		}
		break;
	}
	return array;
}
ListSequence<int>* createList(const int& length) {
	int choose_input;
	cout << "How do you want to fill the sequence? " << endl << "1. By hand" << endl << "2. Random" << endl;
	ListSequence<int>* list;
	list = new ListSequence<int>();
	cin >> choose_input;
	switch (choose_input) {
	case 1: int value;
		cout << "Enter the values: " << endl;
		for (size_t i = 0; i < length; i++)
		{
			cin >> value;
			list->Prepend(value);
		}
		break;
	case 2:

		for (size_t i = 0; i < length; i++)
		{
			list->Prepend(rand());
		}
		break;
	}
	return list;
}
void TestArraySequence (ArraySequence<int>* arr, const int& length) {
	
	Print(arr, length);
	cout << "Choose the type of sort:" << endl <<
		"1. QuickSort" << endl << "2. ShellSort" << endl << "3. ShakerSort" << endl;
	int g;
	cin >> g;
	switch (g) {
	case 1: 
		time_sort(arr, g,length);
		Print(arr, length); 
		break; 
	
	case 2: 
		time_sort(arr,g,length);
		Print(arr, length);
		break;

	case 3: 
		time_sort(arr, g,length);
		Print(arr, length);
		break;
	}
}
void TestListSequence(ListSequence<int>* list, const int& length) {

	Print(list, length);
	cout << "Choose the type of sort:" << endl <<
		"1. QuickSort" << endl << "2. ShellSort" << endl << "3. ShakerSort" << endl;
	int g;
	cin >> g;
	switch (g) {
	case 1:
		time_sort(list, g, length);
		Print(list, length);
		break;

	case 2:
		time_sort(list, g, length);
		Print(list, length);
		break;

	case 3: 
		time_sort(list, g, length);
		Print(list, length);
		break;
	}
}

void Test() {
	int length, g;
	cout << "Write the length of sequence:" << endl;
	cin >> length;
	if (length < 0) {
		cout << "The length cannot be negative" << endl;
		exit;
	}

	cout << "What do you want to use for sort?" << endl
		<< "1. ArraySequence" << endl << "2. ListSequence" << endl;
	cin >> g;
	switch (g) {

	case 1:
		TestArraySequence(createArray(length), length);
		//Test();
	case 2:
		TestListSequence(createList(length), length);
		//break;
	}
}


int main() {
	Test();
	return 0;
 }