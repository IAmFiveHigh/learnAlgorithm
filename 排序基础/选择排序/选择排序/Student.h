//
//  Student.h
//  选择排序
//
//  Created by 我是五高你敢信 on 2018/6/26.
//  Copyright © 2018年 我是五高你敢信. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int score;
    
    bool operator<(const Student &otherStudent) {
        return score < otherStudent.score;
    }
    
    friend ostream& operator<<(ostream &os, const Student &student) {
        os<<"Student: " << student.name << " " << student.score << endl;
        return os;
    }
};
#endif /* Student_h */
