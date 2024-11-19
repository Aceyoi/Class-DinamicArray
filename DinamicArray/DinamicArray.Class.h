//Сапожников Юрий ИВТ-22
#pragma once

#include <iostream>
#include <vector>
#include "DinamicArray.Modul.h"

using namespace std;

//Шаблонный класс динамического массива
template <typename T>
class DynamicArray {
public: // Поля класса 
	T* array;         // Указатель на элементтв массиве
	size_t capacity; // Емкость массива
	size_t length;  // Текущий размер массива


	//Метод увеличение выделенной под массив памяти
	void re_memory() {
		this->capacity = length * 30; //Увеличение емкости массива 
		T* arr = new T[capacity];	   //Создание подмассива и выделение под него нового места	
		memcpy(arr, this->array, sizeof(T) * length);
		//*Функция копирует sizeof(T) * length байт из области памяти, на которую указывает array, в область памяти, на которую указывает arr. 
		//*Функция возвращает адрес назначения arr. 		
		delete[] this->array;						  //Очищение памяти старого массива array
		this->array = arr;							  //Присваивание старой памяти array нового указателя на массиве arr
	}


public:
	//Конструктор без параметров
	DynamicArray() {
		this->length = 0;
		this->array = new T;// Выделяет место под один элемент 
		this->capacity = 1;
	}

	//Конструктор с параметром
	//len - длина массива
	DynamicArray(size_t len) {
		this->length = len;
		this->capacity = len;
		this->array = new T[capacity];

	}

	//Конструктор с параметрами
	//len длина массива
	//arr - массив
	DynamicArray(size_t len, vector<T>& arr) {
		this->length = len;
		this->capacity = len;
		this->array = new T[capacity];

		memcpy(array, arr.data(), sizeof(T) * len);
	}

	//Конструктор копирования
	DynamicArray(DynamicArray<T>& arr) : DynamicArray{ arr.size(), arr.get_array() } {}

	//Деструктор, очищает память, выделенную под массив
	~DynamicArray() {
		delete[] this->array;
	}

	//Метод вывода динамического массива 
	void conclusion() {
		for (int i = 0; i < length; i++) {
        cout << array[i] << ' ';}
        cout << endl;
	};

	//Метод вывода последнего элемента динамического массива 
	T conclusion_back() {
		return array[length-1];
	};

	//Метод вывода первого элемента динамического массива 
	T conclusion_up() {
		return array[0];
	};

	//Метод вывода элемента динамического массива //Нужно для вывода массива в int
	T conclusion_int(int i) {
		return array[i];
	};

	//Метод вывода первого элемента динамического массива 
	T conclusion_index(size_t pos) {
		return array[pos-1];
	};

	//Метод полного очищения динамического массива
	void clear() {
		delete[] this->array;
		this->length = 0;
		this->array = new T;
		this->capacity = 1;
	}

	//Метод удаление элемента из конца динамического массива
	void del_back() {
		if (length > 0) {
			this->length--;
			if (length * 4 < capacity) { //выделяем под массив меньше памяти, если массив становится достаточно мал
				re_memory();
			}
		}
	}

	//Метод удаление элемента из начала динамического массива
	void del_up() {
		if (length > 0) {
			for (size_t i = 0; i < length; i++) { //Сдвигаем элемент пока он не окажется последним в массиве, затем удаляем
				array[i] = array[i + 1];
			}
			this->length--;
			if (length * 4 < capacity) { //выделяем под массив меньше памяти, если массив становится достаточно мал
				re_memory();
			}
		}
	}

	//Метод удаление элемента по адресу pos из динамического массива
	void del_Index(size_t pos) {
		if (length > 0) {

			for (size_t i = pos-1; i < length; i++) { //сдвиг элементов после pos на одну позицию вправо
				array[i] = array[i+1];
			}
			this->length--;

			if (length * 4 < capacity) {//выделяем под массив меньше памяти, если массив становится достаточно мал
				re_memory();
			}
		}
	}

	//Метод удаление элемента по элементу X из динамического массива
	void del(size_t X) {
		if (length > 0) {

			for (size_t i = 0; i < array[X]; i++) {
				array[X] = array[i-1];
				this->length--;
			}

			if (length * 4 < capacity) {//выделяем под массив меньше памяти, если массив становится достаточно мал
				re_memory();
			}
		}
	}

	//Метод проверки есть ли число в динамическом массиве
	bool searchcheck(T find) {
		for (size_t i = 0; i < length; i++) { 
			if (array[i] == find) {               
				return true;                      
			}
		}
		return false;
	}

	//Метод проверки пустой ли динамический массив
	bool nullcheck() {
			if (length == 0) {
				return true;
			}
		return false;
	}

	//Метод добавления элемента X в конец динамического массива
	void add_back(T X) {
		if (length == this->capacity) {//если выделенная память уже заполнена 
			re_memory();
		}		//то производится выделение новой памяти

		array[length] = X;
		this->length++;
	}

	//Метод добавления элемента X в начало динамического массива
	void add_up(T X) {
		if (length == capacity) {//если выделенная память уже заполнена 
			re_memory();
		}		//то производится выделение новой памяти

		for (size_t i = length; i > 0; i--) { //сдвиг элементов после pos на одну позицию вправо
			array[i] = array[i - 1];
		}
		array[0] = X;
		this->length++;
	}

	//Метод добавления элемента X по адресу pos в динамическом массиве
	void add_index(T elem, size_t pos) {
			if (length == capacity) { //если выделенная память уже заполнена 
				re_memory();		  //то производится выделение новой памяти 
			}

			for (size_t i = length; i+1 > pos; i--) { //сдвиг элементов после pos на одну позицию вправо
				array[i] = array[i - 1];
			}
			array[pos-1] = elem;
			this->length++;
	}

	//Метод на проверку сортировки от max к min или от min к max в динамическом массиве
	bool sort_check() {
		if (array[1] < array[2]) {
			for (size_t i = 0; i < this->length - 1; i++) {
				if (array[i] < array[i + 1]) {
					return true;
				}
			};
		}
		return false;
	}
	
	//Метод сортировки слиянием в динамическом массиве
	void sort_merge() {
		mergesort(this->array, 0, this->length);
	}
	//Метод быстрой сортировки в динамическом массиве
	void sort_quick() {
		quicksort(this->array, 0, this->length-1);
	}
	//Метод сортировки Шелла в динамическом массиве
	void sort_shell() {
		shellsort(this->array, 0, this->length-1);
	}
	//Метод сортировки пузырьком в динамическом массиве
	void sort_bubble() {
		bubblesort(this->array, 0, this->length-1);
	}
	//Метод бинарного поиска числа в динамическом массиве и выводом числа
	int search_bin(int X) {
		return binsearch(this->array, 0, this->length, X);
	}
	//Метод бинарного поиска числа в динамическом массиве и выводом индекса
	int search_bin_index(int X) {
		return binsearchindex(this->array, 0, this->length, X);
	}
	//Метод интерполярного поиска числа в динамическом массиве и вывода числа
	int search_interpolation(int X) {
		return interpolationsearch(this->array, 0, this->length, X);
	}
	//Метод интерполярного поиска числа в динамическом массиве и вывода индекса
	int search_interpolation_index(int X) {
		return interpolationsearchindex(this->array, 0, this->length, X);
	}
};

