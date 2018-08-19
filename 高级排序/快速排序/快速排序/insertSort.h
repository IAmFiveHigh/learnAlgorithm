//
//  insertSort.h
//  归并排序
//
//  Created by 我是五高你敢信 on 2018/6/30.
//  Copyright © 2018年 我是五高你敢信. All rights reserved.
//

#ifndef insertSort_h
#define insertSort_h
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

// 对arr[l...r]范围的数组进行插入排序
template<typename T>
void insertSort(T arr[], int l, int r){
    
    for( int i = l+1 ; i <= r ; i ++ ) {
        
        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }
    
    return;
}

#endif /* insertSort_h */
