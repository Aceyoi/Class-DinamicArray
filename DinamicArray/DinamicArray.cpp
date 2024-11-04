//Сапожников Юрий ИВТ-22

#include <vector>
#include "DinamicArray.Class.h"
#include "DinamicArray.Test.h"


using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    testcheck();

    vector<int> array = { 66,84,5,56,1,32,7,65 }; // Создание векторногго массива
    size_t N = array.size();                     // Приравнивание N к размеру массива для удобного изменения
    //size_t N = 5;

    //DynamicArray<int> dynarray;           // конструктор без параметров
    //DynamicArray<int> dynarray(N);       //конструктор с одним параметром
    DynamicArray<int> dynarray(N, array); //конструктор с двумя параметрами

    cout << "Выводим созданный массив : " << endl;
    dynarray.conclusion();
    cout << "Выводим первый элемент созданный массив : " << endl;
    cout << dynarray.conclusion_up() << endl;
    cout << "Выводим последний элемент созданный массив : " << endl;
    cout << dynarray.conclusion_back() << endl;
    cout << "Выводим элемент массива по индексу 5 : " << endl;
    cout << dynarray.conclusion_index(5) << endl;

    cout << "Выводим число 56 с помощью бинарного поиска" << endl;
    cout << dynarray.search_bin(56) << endl;
    cout << "Так же выводим его индекс" << endl;
    cout << dynarray.search_bin_index(56) << endl;
    dynarray.sort_quick(); // Сортировка для интерполяционного поиска
    cout << "Выводим число 56 с помощью интерполяционного поиска" << endl;
    cout << dynarray.search_interpolation(56) << endl;
    cout << "Так же выводим его индекс" << endl;
    cout << dynarray.search_interpolation_index(56) << endl;

    cout << "Удаляем последний элемент в массиве : " << endl;
    dynarray.del_back();
    dynarray.conclusion();
    cout << "Удаляем первый элемент в массиве : " << endl;
    dynarray.del_up();
    dynarray.conclusion();
    //cout << "Удаляем элемент : " << endl;
    //dynarray.del(5);
    //dynarray.conclusion();
    cout << "Удаляем массив полность затем добавляем элемент в конец : " << endl;
    dynarray.clear();
    dynarray.add_back(9);
    dynarray.conclusion();
    cout << "Проверяем, что элемент добаляется в конец : " << endl;
    dynarray.add_back(10);
    dynarray.conclusion();
    cout << "Добавляем элемент в начало : " << endl;
    dynarray.add_up(11);
    dynarray.conclusion();
    cout << "Удаляем элемент в всередине по индексу 2" << endl;
    cout << "А затем добавляем новый элемент 13 по индексу 2: " << endl;
    dynarray.del_Index(2);
    dynarray.add_index(13, 2);
    dynarray.conclusion();

    cout << "Сортировка merge : " << endl;
    dynarray.sort_merge();
    dynarray.conclusion();

    //cout << "Сортировка quicksort : " << endl;
    //dynarray.sort_quick();
    //dynarray.conclusion();

    //cout << "Сортировка shell : " << endl;
    //dynarray.sort_shell();
    //dynarray.conclusion();

    //cout << "Сортировка bubble : " << endl;
    //dynarray.sort_bubble();
    //dynarray.conclusion();

    //cout << "Бинарный поиск : " << endl;
    //dynarray.search_bin();
    //dynarray.conclusion();

    //cout << "Интерполярный поиск : " << endl;
    //dynarray.search_interpolation();
    //dynarray.conclusion();

    return 0;
}
