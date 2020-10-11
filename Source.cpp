#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include "Sort.hpp"
using namespace std;
#include<iostream>
#include "Header1.h"

void Print(ArraySequence<int>* ar,const int& length){
	cout << "It is your sequence: " << endl;
	for (size_t i = 0; i < length; i++) {
		cout << ar->Get(i) << " ";
	}
	cout << endl;
}

template <typename T>
Sequence<T>* testQuickSort(Sequence<T>* ar,int length) {
	cout << "TESTS QUICKSORT:" << endl;
	QuickSort1(ar, 0, length - 1); 
	//QuickSort2(ar, 0, length - 1); 
	return ar;
}

template <typename T>
Sequence<T>* testShellSort(Sequence<T>* ar, int length) {
	cout << "TESTS SHELLSORT: " << endl;
	ShellSort(ar, length);
	return ar;
}

void TestArraySequence(const int length) {
	
	ArraySequence<int>* array;
	array = new ArraySequence<int>();
	
	if (length < 0) {
		cout << "The length cannot be negative";
	}

    for (size_t i = 0; i < length; i++)
	{
		array->Prepend(rand());
		//array->Append(i);
	}
	Print(array, length);
	
	cout << "Choose the type of sort:" << endl <<
		"1. QuickSort" << endl << "2. ShellSort" << endl;
	int g;
	cin >> g;
	switch (g) {
	case 1: 
		testQuickSort(array, length);
		Print(array, length); 
		break; 
	
	case 2: testShellSort(array,length);
		Print(array, length);
		break;
		//case 3: test_Sort (array);
	}


	
}
void TestListSequence(const int length) {

}






int main() {
	int length;
	int g;
	cout << "Write the length of sequence:" << endl;
	cin >> length;
	cout << "What do you want to use for sort?" << endl
		<< "1. ArraySequence" << endl << "2. ListSequence" << endl;
	cin >> g;
	switch (g) {

	case 1: 
		TestArraySequence(length);
		break;
			
	
	case 2: 
		//TestListSequence(length);
		break;
	
	}

	return 0;
 }