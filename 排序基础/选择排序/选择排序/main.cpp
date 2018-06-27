//
//  main.cpp
//  选择排序
//
//  Created by 我是五高你敢信 on 2018/6/26.
//  Copyright © 2018年 我是五高你敢信. All rights reserved.
//

#include <iostream>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"


using namespace std;

template<typename T>
void selectionSort( T arr[], int n) {
    for (int i=0; i<n; i++) {
        
        int minIndex = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main(int argc, const char * argv[]) {

    int n = 10000;
    int* array = SortTestHelper::generateRandomArray(n, 0, n);

    SortTestHelper::testSort("选择排序", selectionSort, array, n);
        
    delete [] array;
    
    float arr[10] = {1.3, 3.1, 1.0, 2.22, 5.1, 11, 23, 15, 9, 10};
    selectionSort(arr, 10);
    for (int i=0; i<10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    string c[5] = {"A", "D", "C", "B", "E"};
    selectionSort(c, 5);
    for (int i=0; i<5; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    
    Student d[4] = { {"mike", 90}, {"lili", 87}, {"tracy", 97}, {"tom", 92} };
    selectionSort(d, 4);
    for (int i=0; i<4; i++) {
        cout << d[i];
    }
    cout << endl;
    
    
    
    return 0;
}
