//
//  main.cpp
//  插入排序
//
//  Created by 我是五高你敢信 on 2018/6/27.
//  Copyright © 2018年 我是五高你敢信. All rights reserved.
//

#include <iostream>
#include "SortTestHelper.h"

//插入排序
template <typename T>
void insertSort(T arr[], int n) {
    
    for (int i=1; i<n; i++) {
        T e = arr[i];
        int j; //j 保存e应该插入的位置
        for (j=i; j>0 && arr[j-1]>e; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

//选择排序
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
    
    int n = 1000;
    int *array = SortTestHelper::generateNearlyOrderArray(n, 100);
    
    int *array2 = SortTestHelper::coypIntArray(array, n);
    
    SortTestHelper::testSort("插入排序", insertSort, array, n);
    SortTestHelper::testSort("选择排序", selectionSort, array2, n);
    
    delete [] array;
    delete [] array2;
    return 0;
}
