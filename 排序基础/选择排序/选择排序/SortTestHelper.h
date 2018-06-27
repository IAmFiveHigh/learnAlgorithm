//
//  SortTestHelper.h
//  选择排序
//
//  Created by 我是五高你敢信 on 2018/6/26.
//  Copyright © 2018年 我是五高你敢信. All rights reserved.
//

#ifndef SortTestHelper_h
#define SortTestHelper_h
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {
    
    //生成n个随机数， 范围是从rangL到rangR
    int* generateRandomArray(int n, int rangL, int rangR) {
        
        assert(rangR >= rangL);
        
        int *arr = new int[n];
        srand(time(NULL));
        
        for (int i=0; i<n; i++) {
            arr[i] = rand() % (rangR - rangL + 1) + rangL;
        }
        return arr;
    }
    
    //生成一个几乎有序的数组
    int* generateNearlyOrderArray(int n, int swapTimes) {
        int *arr = new int[n];
        for (int i=0; i<n; i++) {
            arr[i] = i;
        }
        
        srand(time(NULL));
        for (int i=0; i<swapTimes; i++) {
            int posy = rand()%n;
            int posx = rand()%n;
            swap(arr[posy], arr[posx]);
        }
        return arr;
    }
    
    template< typename T>
    void printArray(T arr[], int n) {
        for (int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    template <typename T>
    bool isSort(T arr[], int n) {
        for (int i=0; i<n-1; i++) {
            if (arr[i] > arr[i+1]) {
                return false;
            }
        }
        return true;
    }
    
    template <typename T>
    void testSort(string funcName, void(*sort)(T[], int), T arr[], int n) {
        
        clock_t starTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        
        assert(isSort(arr, n));
        
        cout << funcName << ": " << double(endTime - starTime) / CLOCKS_PER_SEC << "s" << endl;
        
    }
    
    int *coypIntArray(int a[], int n) {
        int *array = new int[n];
        copy(a, a+n, array);
        return array;
    }
}

#endif /* SortTestHelper_h */
