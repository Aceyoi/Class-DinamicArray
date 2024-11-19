//Сапожников Юрий ИВТ-22
#pragma once

#include <cassert>
#include "DinamicArray.Modul.h"
#include "DinamicArray.Class.h"

using namespace std;

void testcheck() {

        vector<int> TestArray = { 65,84,5,56,1,32,7,65 };
        DynamicArray<int> testdynarray(TestArray.size(), TestArray);

    vector<int> array1 = { 1,2,3,4,5 };
    DynamicArray<int> dynarray1(array1.size(), array1);

    vector<int> array2 = { 5,4,3,2,1 };
    DynamicArray<int> dynarray2(array2.size(), array2);

    assert(testdynarray.sort_check() == false);
    assert(dynarray1.sort_check() == true);
    //assert(dynarray2.sort_check() == true);

    testdynarray.del_back();
    assert(testdynarray.conclusion_back() == 7);
    testdynarray.del_up();
    assert(testdynarray.conclusion_up() == 84);
    //dynarray.del(5);
    testdynarray.clear();
    assert(testdynarray.nullcheck() == true);
    testdynarray.add_back(9);
    assert(testdynarray.conclusion_back() == 9);
    testdynarray.add_back(10);
    assert(testdynarray.conclusion_back() == 10);
    testdynarray.add_up(11);
    assert(testdynarray.conclusion_up() == 11);
    testdynarray.del_Index(2);
    assert(testdynarray.conclusion_index(2) == 10);
    testdynarray.add_index(13, 2);
    assert(testdynarray.conclusion_index(2) == 13);
    assert(testdynarray.searchcheck(13) == true);
    assert(testdynarray.searchcheck(25) == false);
    assert(testdynarray.nullcheck() == false);
    testdynarray.clear();

    DynamicArray<int> TestArrayMerge(TestArray.size(), TestArray);
    DynamicArray<int> TestArrayQuick(TestArray.size(), TestArray);
    DynamicArray<int> TestArrayShell(TestArray.size(), TestArray);
    DynamicArray<int> TestArrayBubble(TestArray.size(), TestArray);

    TestArrayMerge.sort_merge();
    TestArrayQuick.sort_quick();
    TestArrayShell.sort_shell();
    TestArrayBubble.sort_bubble();

    assert(TestArrayMerge.sort_check() == true);
    assert(TestArrayQuick.sort_check() == true);
    assert(TestArrayShell.sort_check() == true);
    assert(TestArrayBubble.sort_check() == true);

    //TestArrayMerge.conclusion();
    //TestArrayQuick.conclusion();
    //TestArrayShell.conclusion();
    //TestArrayBubble.conclusion();

    DynamicArray<int> testarraylol(TestArray.size(), TestArray);

    assert(testarraylol.search_bin(56) == 56);
    assert(testarraylol.search_bin_index(56) == 4);
    assert(testarraylol.search_bin(100) == -1);
    assert(testarraylol.search_bin_index(100) == -1);

    assert(TestArrayQuick.search_interpolation(56) == 56);
    assert(TestArrayQuick.search_interpolation_index(56) == 5);
    assert(TestArrayQuick.search_interpolation(100) == -1);
    assert(TestArrayQuick.search_interpolation_index(100) == -1);

    vector<string> arraystringtest = { "cab","c","b","abc","aaa","a" };
    DynamicArray<string> dynarraystringtest(arraystringtest.size(), arraystringtest);

    assert(dynarraystringtest.conclusion_up()== "cab");
    assert(dynarraystringtest.conclusion_back() == "a");
    assert(dynarraystringtest.conclusion_index(5) == "aaa");
    dynarraystringtest.del_back();
    dynarraystringtest.del_up();
    assert(dynarraystringtest.conclusion_up() == "c");
    assert(dynarraystringtest.conclusion_back() == "aaa");
    dynarraystringtest.clear();
    assert(dynarraystringtest.nullcheck() == true);  

    //testdynarray.~DynamicArray();
    //dynarray1.~DynamicArray();
    //dynarray2.~DynamicArray();
    //testarraylol.~DynamicArray();
    //dynarraystringtest.~DynamicArray();
}