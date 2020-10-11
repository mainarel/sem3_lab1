#include "ArraySequence.hpp"
#include "ListSequence.hpp"

template <typename T>
Sequence<T>* QuickSort1(Sequence<T>* mas, int first, int last) { 
 T index; 
 int mid, count; 
 int f = first, l = last; 
 mid = mas->Get((l + f) / 2); //вычисление опорного элемента 
 do 
 { 
 while (mas->Get(f) < mid) f++; 
 while (mas->Get(l) > mid) l--; 
 if (f <= l) //перестановка элементов 
 { 
 count = mas->Get(f); 
 
 mas->InsertAt(f, mas->Get(l)); 
 mas->InsertAt(l, count); 
 f++; 
 l--; 
 } 
 } while (f < l); 
 if (first < l) QuickSort1(mas, first, l); 
 if (f < last) QuickSort1(mas, f, last); 
 
 
 return mas; 
 }


template <typename T>
Sequence<T>* QuickSort2(Sequence<T>* mas, int left, int right) {

	if (left == right) return mas;
	if (right == -1 || left > right) exit;

	T index; 
	int l_hold(left), r_hold(right); 
	index = mas->Get(left); 

	while (left < right) { 
		while ((left < right) && (mas->Get(right) >= index))
			right--; 
		if (left != right) {  
			mas->InsertAt( left, mas->Get(right) );
			left++;
		}
		while ((left < right) && (mas->Get(left) <= index))
			left++; 
		if (left != right) {
			mas->InsertAt(right,mas->Get(left));
			right--;
		}
	}

	mas->InsertAt(left, index );
	int index2 = left; 
	left = l_hold;
	right = r_hold;

	if (left < index2)
		QuickSort(mas, left, index2 - 1);
	if (right > index2)
		QuickSort(mas, index2 + 1, right);

	return mas;
}

template <typename T>
Sequence<T>* ShellSort(Sequence<T>* mas, int length) {
	int i, j, d, count;
	d = length;
	d = d / 2;
	while (d > 0)
	{
		for (i = 0; i < length - d; i++)
		{
			j = i;
			while (j >= 0 && mas->Get(j) > mas->Get(j + d))
			{
				count = mas->Get(j);
				mas->InsertAt(j,mas->Get(j+d));
				mas->InsertAt(j+d,count);
				j--;
			}
		}
		d = d / 2;
		
	}
	return mas;
}



