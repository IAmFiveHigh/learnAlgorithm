//
//  main.cpp
//  归并排序
//
//  Created by 我是五高你敢信 on 2018/6/30.
//  Copyright © 2018年 我是五高你敢信. All rights reserved.
//

#include <iostream>
#include "SortTestHelper.h"
#include "insertSort.h"
#include "MergeSort.h"

using namespace std;



int main(int argc, const char * argv[]) {
    
    int n = 50000;
    
    int *a = SortTestHelper::generateRandomArray(n, 0, n);
    int *b = SortTestHelper::coypIntArray(a, n);

    SortTestHelper::testSort("归并排序", mergeSort, a, n);
    SortTestHelper::testSort("插入排序", insertSort, b, n);

    delete [] a;
    delete [] b;

    a = SortTestHelper::generateNearlyOrderArray(n, 10);
    b = SortTestHelper::coypIntArray(a, n);

    SortTestHelper::testSort("归并排序", mergeSort, a, n);
    SortTestHelper::testSort("插入排序", insertSort, b, n);

    delete [] a;
    delete [] b;
    
    return 0;
}
