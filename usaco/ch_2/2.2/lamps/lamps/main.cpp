/*
 ID: lionz202
 TASK: lamps
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


int N, C, validSol = 0, works[] = {1,2,0,4,8,9,10,12};
bool lamps[10001], impossible = true;
//int lamp[8];

typedef struct levers {
    int index;
    int sort;
} levers;

levers lamp[16];

void lever1() {
    for (int i = 1; i <= N; i++) {
        lamps[i] = !lamps[i];
    }
}

void lever2() {
    for (int i = 1; i <= N; i+=2) {
        lamps[i] = !lamps[i];
    }
}

void lever3() {
    for (int i = 2; i <= N; i+=2) {
        lamps[i] = !lamps[i];
    }
}

void lever4() {
    for (int i = 1; i <= N; i+=3) {
        lamps[i] = !lamps[i];
    }
}

int comparator(const void* a, const void* b) {
    levers c, d;
    c = *(levers*)a;
    d = *(levers*)b;
    if (c.sort > d.sort) return -1;
    if (c.sort < d.sort) return 1;
    return 0;
}

int main() {
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");
    
    fin >> N >> C;
    vector<int> off, on;
    
    int a;
    while (true) {
        fin >> a;
        if (a == -1) {
            break;
        } else {
            on.push_back(a);
        }
    }
    
    while (true) {
        fin >> a;
        if (a == -1) {
            break;
        } else {
            off.push_back(a);
        }
    }
    
    
    for (int i = 0; i < 8; i++) {
        fill_n(lamps, sizeof(bool)*10001, 1);
        int count = 0, k;
        for (int j = 0; j < 4; j++) {
            if (works[i] & (1 << j)) {
                count++;
                switch(j) {
                    case 0 : {lever1(); break;}
                    case 1 : {lever2(); break;}
                    case 2 : {lever3(); break;}
                    case 3 : {lever4(); break;}
                }
            }
        }
        
        if (count > C) continue;
        
        for (k = 0; k < on.size(); k++) {
            if (!lamps[on[k]]) {
                break;
            }
        }
        if (k < on.size()) continue;
        
        for (k = 0; k < off.size(); k++) {
            if (lamps[off[k]]) {
                break;
            }
        }
        if (k < off.size()) continue;
        
        //fout << i << ":\t";
        lamp[i].index = works[i];
        for (int j = 1; j <= 6; j++) {
            if (lamps[j]) {
                lamp[i].sort += 2 << (6-j);
            }
            //fout << lamps[j];
        }
        //fout << endl;
        validSol++;
        impossible = false;
        
    }
    
    qsort(lamp, 16, sizeof(levers), comparator);
    
    for (int i = validSol-1; i >= 0; i--) {
        //fout << lamp[i].index << ' ' << lamp[i].sort << endl;
        fill_n(lamps, sizeof(bool)*10001, 1);

        for (int j = 0; j < 4; j++) {
            if (lamp[i].index & (1 << j)) {
                switch(j) {
                    case 0 : {lever1(); break;}
                    case 1 : {lever2(); break;}
                    case 2 : {lever3(); break;}
                    case 3 : {lever4(); break;}
                }
            }
        }

        for (int j = 1; j <= N; j++) {
            fout << lamps[j];
        }
        fout << endl;
    }
    
    
    if (impossible) fout << "IMPOSSIBLE" << endl;
    fin.close();
    fout.close();
    return 0;
}
