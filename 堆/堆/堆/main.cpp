//
//  main.cpp
//  堆
//
//  Created by 我是五高你敢信 on 2018/8/19.
//  Copyright © 2018年 我是五高你敢信. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

template <typename Item>
class MaxHeap {
private:
    Item * data;
    int count;
    
public:
    MaxHeap (int capacity) {
        data = new Item[capacity + 1];
        count = 0;
    }
    
    ~MaxHeap() {
        delete [] data;
    }
    
    int size() {
        return count;
    }
    
    bool isEmpty() {
        return count == 0;
    }
};


int main(int argc, const char * argv[]) {
    
    MaxHeap<int> maxHeap = MaxHeap<int>(100);
    cout << maxHeap.size() << endl;
    
    return 0;
}
