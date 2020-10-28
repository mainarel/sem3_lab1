#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include <chrono>

template<typename T>
void time_sort(Sequence<T>* seq, const int& choice_sort, const int& length) {

	auto start = std::chrono::high_resolution_clock::now();
	if (choice_sort == 1)  QuickSort1(seq, 0, length-1);
    else if (choice_sort == 2)  ShellSort(seq, length);
 	else if (choice_sort == 3)  ShakerSort(seq, length);
	auto finish = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(finish - start);
	double time_sort = duration.count();
	std:: cout << "Time of this sort = "<< time_sort <<" microseconds " <<std::endl;
}

template<typename T>
void Swap(Sequence<T>* seq, const int& index1, const int& index2)
{
	T item = seq->Get(index1);
	seq->Set(index1, seq->Get(index2));
	seq->Set(index2, item);
}

template <typename T>
Sequence<T>* QuickSort1(Sequence<T>* seq, const int& first, const int& last) {
	if (last + 1 == 0) return seq;
		T index;
		int mid, count;
		int f = first, l = last;
		mid = seq->Get((l + f) / 2); //вычисление опорного элемента 
		do
		{
			while (seq->Get(f) < mid) f++;
			while (seq->Get(l) > mid) l--;
			if (f <= l) //перестановка элементов 
			{
				Swap(seq,l,f);
				/*count = seq->Get(f);
				seq->Set(f, seq->Get(l));
				seq->Set(l, count);*/
				f++;
				l--;
			}
		} while (f < l);
		if (first < l) QuickSort1(seq, first, l);
		if (f < last) QuickSort1(seq, f, last);


		return seq;
	}




template <typename T>
Sequence<T>* ShellSort(Sequence<T>* seq, const int& length) {
	int i, j, d, count;
	d = length;
	d = d / 2;
	while (d > 0)
	{
		for (i = 0; i < length - d; i++)
		{
			j = i;
			while (j >= 0 && seq->Get(j) > seq->Get(j + d))
			{
				Swap(seq,j,j+d);
				/*count = seq->Get(j);
				seq->Set(j, seq->Get(j+d));
				seq->Set(j+d,count);*/
				j--;
			}
		}
		d = d / 2;
		
	}

	return seq;
}
template <typename T>
Sequence<T>* ShakerSort(Sequence<T>* seq, const int& length) {
	int left = 0, right = length - 1; 
	int flag = 1;  // флаг наличия перемещений
	// Выполнение цикла пока левая граница не сомкнётся с правой
	// и пока в массиве имеются перемещения
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //двигаемся слева направо
		{
			if (seq->Get(i) > seq->Get(i + 1)) // если следующий элемент меньше текущего,
			{             // меняем их местами

				Swap(seq,i,i+1);
				/*int t = seq->Get(i);
				seq->Set(i, seq->Get(i+1));
				seq->Set(i+1, t);*/
				flag = 1;      // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--)  //двигаемся справа налево
		{
			if (seq->Get(i - 1) > seq->Get(i)) // если предыдущий элемент больше текущего,
			{            // меняем их местами

				Swap(seq,i,i-1);
				/*int t = seq->Get(i);
				seq->Set(i, seq->Get(i - 1));
				seq->Set(i - 1, t);*/
				flag = 1;    // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
	return seq;

}

