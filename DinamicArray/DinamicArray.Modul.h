//Сапожников Юрий ИВТ-22
#pragma once

#include <exception>
#include <iostream>
#include <vector>

using namespace std;

///Производит слияние двух половин области массива а между begin и end
///a - обрабатываемый массив
///begin - левая граница рассматриваемой области
///end - правая граница рассматриваемой области
template<typename T>
void merging(T* a, size_t begin, size_t mid, size_t end) {
	T* c = new T[end - begin];					//буфер для хранения результата слияния

        size_t
		left = begin,						//индекс элемента из левой области
		right = mid,							//индекс элемента из правой области
		i = 0;								//индекс массива c 

	while (left < mid && right < end) {			//пока не достигнут конец одной из областей
		if (a[left] <= a[right]) {				//сравниваются значения из областей

			c[i] = a[left];						// если left меньше right, то в индекс i массива с помещаем значение из левой области
			left++;
		}
		else {
			c[i] = a[right];					//в противном случае из правой
			right++;
		}
		i++;
	}
	//помещаем оставшиеся значения в массив c
	if (left == mid) {							//если был достигнут конец левой части

		while (right < end) {					//то помещаем значения из правой

			c[i] = a[right];
			right++;
			i++;
		}
	}
	else if (right == end) {					//если же был достигнут конец правой части

		while (left < mid) {				// то помеащем знаяения из левой

			c[i] = a[left];
			left++;
			i++;
		}
	}

	size_t j = 0;
	while (j < end - begin) {					//помещение значений из массива с в массив а
		a[begin + j] = c[j];
		j++;
	}
	delete[] c;
}

///рекурсивная функция сортировки слиянием по возрастанию
/// a - сортируемыймассив
///left - левая граница сортировки
/// right - правая граница сортировки
/// 
/// BigO = O(n log(n)) для всех случаев
template<typename T>
void mergesort(T* a, size_t left, size_t right) {

	if (left < right - 1) {
		size_t mid = left + (right - left) / 2;
		mergesort(a, left, mid);	//сортировка левой половины сортируемой области
		mergesort(a, mid, right);  //сортировка правйо половины сортируемой области
		merging(a, left, mid, right);
	}
}


///рекурсивная функция быстрой сортировки по возрастанию, в качетсве опорного элемента берется первый элемент
/// arr - сортируемый массив
///begin - левая граница сортировки
/// end - правая граница сортировки
/// 
/// BigO = O(n2) для худшего случая
/// BigO = O(n log n) для среднего и лучшего случая
template <typename T>
void quicksort(T* arr, size_t begin, size_t end) {
	if (begin >= end) return;

	size_t base = begin; //опорный элемент
	size_t current = begin;//элемент который перемещается влево от опорного

	for (size_t i = begin + 1; i <= end; i++) {
		if (arr[i] < arr[base]) {				//если элемент arr[i] меньше опорного
			swap(arr[i], arr[++current]);  //меняем его и опорный элемент местами
		}
	}
	swap(arr[base], arr[current]);     //опорный элемент ставится на место последнего перемещеного

	if (current > begin) {
		quicksort(arr, begin, current - 1);//вызов функции для левой части массива
	}
	if (end > current + 1) {
		quicksort(arr, current + 1, end);//вызов функции для правой части массива
	}
}

// Метод пузырьковой сортировки
template <typename T>
void bubblesort(T* arr, size_t begin, size_t end) {
	if (begin >= end) return;
	for (size_t i = begin; i < end -1 ; i++) {
		for (size_t j = begin; j < end; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// Метод сортировки Шелла
template <typename T>
void shellsort(T* arr, size_t begin, size_t end) {
	for (size_t gap = end / 2; gap > 0; gap /= 2) {
		for (size_t i = gap; i < end+1; i++) {
			T temp = arr[i];
			size_t j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}

// Метод бинарного поиска
template <typename T>
int binsearch(T* arr, size_t begin, size_t end, T value) {
	size_t left = begin;
	size_t right = end - 1;

	while (left <= right) {
		size_t mid = left + (right - left) / 2; // Находим середину

		if (arr[mid] == value) { // Если найден
			return value; // Возвращаем индекс
		}
		else if (arr[mid] < value) { // Если значение больше, ищем справа
			left = mid + 1;
		}
		else { // Если значение меньше, ищем слева
			right = mid - 1;
		}
	}
	return -1; // Если не найден
}


// Метод бинарного поиска
template <typename T>
int binsearchindex(T* arr, size_t begin, size_t end, T value) {
	size_t left = begin;
	size_t right = end -1;

	while (left <= right) {
		size_t mid = left + (right - left) / 2; // Находим середину

		if (arr[mid] == value) { // Если найден
			return mid+1; // Возвращаем индекс
		}
		else if (arr[mid] < value) { // Если значение больше, ищем справа
			left = mid + 1;
		}
		else { // Если значение меньше, ищем слева
			right = mid - 1;
		}
	}
	return -1; // Если не найден
}

// Метод интерполяционного поиска
template <typename T>
int interpolationsearch(T* arr, size_t begin, size_t end, T value) {
	size_t left = begin;
	size_t right = end - 1;

	while (left <= right && value >= arr[left] && value <= arr[right]) {
		// Находим позицию, используя интерполяцию
		size_t pos = left + ((value - arr[left]) * (right - left) / (arr[right] - arr[left]));

		if (arr[pos] == value) { // Если найден
			return value; // Возвращаем индекс
		}
		else if (arr[pos] < value) { // Если значение больше, ищем справа
			left = pos + 1;
		}
		else { // Если значение меньше, ищем слева
			right = pos - 1;
		}
	}
	return -1; // Если не найден
}

// Он предполагает, что значения данных равномерно распределены.Алгоритм оценивает, где может находиться искомое значение, 
// на основе распределения значений, и перемещается к этому предполагаемому индексу, затем повторяет процесс.

//BigO = O(n) для худшего случая
//BigO = O(log(log n)) для среднего случая
//BigO = O(1) для лучшего случая
// Метод интерполяционного поиска
template <typename T>
int interpolationsearchindex(T* arr, size_t begin, size_t end, T value) {
	size_t left = begin;
	size_t right = end - 1;

	while (left <= right && value >= arr[left] && value <= arr[right]) {
		// Находим позицию, используя интерполяцию
		size_t pos = left + ((value - arr[left]) * (right - left) / (arr[right] - arr[left]));

		if (arr[pos] == value) { // Если найден
			return pos+1; // Возвращаем индекс
		}
		else if (arr[pos] < value) { // Если значение больше, ищем справа
			left = pos + 1;
		}
		else { // Если значение меньше, ищем слева
			right = pos - 1;
		}
	}
	return -1; // Если не найден
}