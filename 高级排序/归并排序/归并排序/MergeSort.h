//
//  MergeSort.h
//  归并排序
//
//  Created by 我是五高你敢信 on 2018/7/1.
//  Copyright © 2018年 我是五高你敢信. All rights reserved.
//

#ifndef MergeSort_h
#define MergeSort_h
#include "insertSort.h"

using namespace std;

template <typename T>
void __merge(T arr[], int l, int mid, int r) {
    T axu[r-l+1];
    // T *axu = new T[r-l+1];
    
    //生成另外的空间
    for (int i=l; i<=r; i++) {
        axu[i-l] = arr[i];
    }
    
    int i=l, j=mid+1;
    for (int k=l; k<=r; k++) {
        
        if (i>mid) {
            arr[k] = axu[j-l];
            j+=1;
        }else if (j>r) {
            arr[k] = axu[i-l];
            i+=1;
        }else if (axu[i-l] < axu[j-l]){
            arr[k] = axu[i-l];
            i+=1;
        }else {
            arr[k] = axu[j-l];
            j+=1;
        }
    }
}

template <typename T>
void __mergeSort(T arr[], int l, int r) {
    if (r - l < 15) {
        insertSort(arr, l, r);
        return;
    }
    
    int mid = (r - l) / 2 + l;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    if (arr[mid] > arr[mid + 1]) {
        __merge(arr, l, mid, r);
    }
    
}

template <typename T>
void mergeSort(T arr[], int n) {
    
    __mergeSort(arr, 0, n-1);
}

#endif /* MergeSort_h */
