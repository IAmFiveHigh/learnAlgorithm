//
//  main.cpp
//  快速排序
//
//  Created by 我是五高你敢信 on 2018/7/24.
//  Copyright © 2018年 我是五高你敢信. All rights reserved.
//

#include <iostream>
#include "MergeSort.h"
#include "insertSort.h"
#include "SortTestHelper.h"

using namespace std;

template <typename T>
int __partition(T arr[], int l, int r) {
    
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    
    T v = arr[l];
    //arr[l+1 ... j] < v  arr[j+1 ... i) > v
    
    int j = l;
    for (int i=l+1; i<=r; i++) {
        if (arr[i] < v)
            swap(arr[++j], arr[i]);
    }
    swap(arr[l], arr[j]);
    return j;
}

template <typename T>
void __quickSort(T arr[], int l, int r) {
    if (r - l <= 15) {
        insertSort(arr, l, r);
        return;
    }
    
    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n) {
    
    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}

int main(int argc, const char * argv[]) {
    int n = 1000000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::coypIntArray(arr, n);
    
    SortTestHelper::testSort("快速排序", quickSort, arr, n);
    SortTestHelper::testSort("归并排序", mergeSort, arr2, n);
    
    delete [] arr;
    delete [] arr2;
    
    int *nearArray = SortTestHelper::generateNearlyOrderArray(n, 100);
    int *copyNearArray = SortTestHelper::coypIntArray(nearArray, n);
    
    cout << "-------------" << endl;
    
    SortTestHelper::testSort("快速排序", quickSort, nearArray, n);
    SortTestHelper::testSort("归并排序", mergeSort, copyNearArray, n);
    
    delete [] nearArray;
    delete [] copyNearArray;
    
    return 0;
}
