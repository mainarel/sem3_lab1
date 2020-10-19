#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include <chrono>

template<typename T>
void time_sort(Sequence<T>* mas, const int& choice_sort) {

	auto start = std::chrono::high_resolution_clock::now();
	if (choice_sort == 1)  QuickSort1(mas, 0, mas->GetLength()-2);
    else if (choice_sort == 2)  ShellSort(mas, mas->GetLength()-1);
 	else if (choice_sort == 3)  ShakerSort(mas,mas->GetLength()-1);
	auto finish = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
	double time_sort = duration.count();
	std:: cout << "Time of this sort = "<< time_sort <<" seconds " <<std::endl;
}



template <typename T>
Sequence<T>* QuickSort1(Sequence<T>* mas, const int& first, const int& last) {
	//if (last + 1 == 0) return mas;
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
Sequence<T>* ShellSort(Sequence<T>* mas, const int& length) {
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
template <typename T>
Sequence<T>* ShakerSort(Sequence<T>* mas, const int& length) {
	int left = 0, right = length - 1; // левая и правая границы сортируемой области массива
	int flag = 1;  // флаг наличия перемещений
	// Выполнение цикла пока левая граница не сомкнётся с правой
	// и пока в массиве имеются перемещения
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //двигаемся слева направо
		{
			if (mas->Get(i) > mas->Get(i + 1)) // если следующий элемент меньше текущего,
			{             // меняем их местами
				int t = mas->Get(i);
				mas->InsertAt(i, mas->Get(i+1));
				mas->InsertAt(i+1, t);
				flag = 1;      // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--)  //двигаемся справа налево
		{
			if (mas->Get(i - 1) > mas->Get(i)) // если предыдущий элемент больше текущего,
			{            // меняем их местами
				int t = mas->Get(i);
				mas->InsertAt(i, mas->Get(i - 1));
				mas->InsertAt(i - 1, t);
				flag = 1;    // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
	return mas;

}

