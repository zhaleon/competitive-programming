/*
 ID: lionz202
 TASK: preface
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
using namespace std;

string toRoman(int x) {
    auto romanDigit = [&](char one, char five, char ten, int x) {
        if (x <= 3)
            return string().assign(x,one);
        if (x <= 5)
            return string().assign(5 - x, one) + five;
        if (x <= 8)
            return five + string().assign(x-5, one);
        return string().assign(10-x, one) + ten;
    };
    if (x >= 1000) {
        return "M" + toRoman(x-1000);
    }
    if (x >= 100) {
        return romanDigit('C', 'D', 'M', x/100) + toRoman(x%100);
    }
    if (x >= 10) {
        return romanDigit('X', 'L', 'C', x/10) + toRoman(x%10);
    }
    return romanDigit('I', 'V', 'X', x);
}

int letters[7];

int main() {
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    int N; fin >> N;
    fin.close();
    for (int i = 1; i <= N; i++) {
        string current = toRoman(i);
        //fout << current << endl;
        for (int i = 0; i < current.length(); i++) {
            if (current[i] == 'I') {
                letters[0]++;
            } else if (current[i] == 'V') {
                letters[1]++;
            } else if (current[i] == 'X') {
                letters[2]++;
            } else if (current[i] == 'L') {
                letters[3]++;
            } else if (current[i] == 'C') {
                letters[4]++;
            } else if (current[i] == 'D') {
                letters[5]++;
            } else if (current[i] == 'M') {
                letters[6]++;
            }
        }
    }
    for (int i = 0; i < 7; i++) {
        if (letters[i] != 0) {
            switch(i) {
                case 0 : {
                    fout << "I " << letters[i] << endl;
                    break;
                }
                case 1 : {
                    fout << "V " << letters[i] << endl;
                    break;
                }
                case 2 : {
                    fout << "X " << letters[i] << endl;
                    break;
                }
                case 3 : {
                    fout << "L " << letters[i] << endl;
                    break;
                }
                case 4 : {
                    fout << "C " << letters[i] << endl;
                    break;
                }
                case 5 : {
                    fout << "D " << letters[i] << endl;
                    break;
                }
                case 6 : {
                    fout << "M " << letters[i] << endl;
                    break;
                }
            }
        } else {
            break;
        }
    }
    //fout << toRoman(20);
    return 0;
}
