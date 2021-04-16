/*
 ID: lionz202
 TASK: fracdec
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
#include <assert.h>
#include <cstring>

using namespace std;

FILE *fin=fopen("fracdec.in","r");
FILE *fout = fopen("fracdec.out", "w");
ofstream stuff("fracdec.out");

int N, D, remainders[1000001], counter = 0, repeat;
bool needsDecimal = true, needsLeft = true, hasCycle;
bool afterDecimal = false;
string answer = "";


void divide(int current) {
    counter++;
   // assert(counter != 8836);
    
    if (current == 0) return;
    if (remainders[current]) {
        repeat = current/D;
        hasCycle = true;
        answer += ")";
        return;
    }
    
    remainders[current] = 1;
    
    
    
//    if (current < D) {
//        while (current < D) {
//            current *= 10;
//            if (current >= D) {
//                break;
//            }
//            answer += "0";
//        }
//        remainders[current] = 1;
//    }
    
    answer += to_string(current/D);
    
    if (current < D && needsDecimal) {
        needsDecimal = false;
        answer += ".";
    }
    if (current < D) {
        divide(current * 10);
    } else {
        divide((current % D)*10);
    }
}

int main()
{
    fscanf(fin, "%i %i\n", &N, &D);
    if (N % D == 0) {
        stuff << N/D << ".0" << endl;
        exit(0);
    } else if (N < D) {
        divide(N);
    } else {
        answer += to_string(N/D);
        needsDecimal = false;
        answer += ".";
        divide((N%D)*10);
    }
    
    string newAnswer = "";
    bool leftP = false;
    afterDecimal = false;
    for (int i = 0; i < answer.length(); i++) {
        if (answer[i] == '.') {
            afterDecimal = true;
        }
        
        if (afterDecimal && int(answer[i]-'0') == repeat && hasCycle) {
            leftP = true;
            afterDecimal = false;
            newAnswer += "(";
        }
        if (answer[i] == '.') {
            newAnswer += ".";
        } else if (answer[i] == ')') {
            newAnswer += ")";
        } else {
            newAnswer += to_string(answer[i]-'0');
        }
        //stuff << answer[i];
    }
    for (int i = 0; i < newAnswer.length(); i++) {
        stuff << newAnswer[i];
        if ((i+1) % 76 == 0 && i != newAnswer.length()-1) {
            stuff << endl;
        }
    }
    stuff << endl;
    return 0;
}
