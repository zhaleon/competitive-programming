/*
 ID: lionz202
 TASK: stamps
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
#include <utility>
#include <queue>
#include <string.h>
#include <cstring>

using namespace std;

ifstream fin("stamps.in");
ofstream fout("stamps.out");

int K, N;

int stamps[201];
int best[2000001];
int main()
{
    fin >> K >> N;
    for (int i = 0; i < N; i++) {
        fin >> stamps[i];
    }
    int i, j;
    for (i = 1; i <= K*10000; i++) {
        best[i] = 10000000;
        for (j = 0; j < N; j++) {
            if (stamps[j] <= i) {
                best[i] = min(best[i], best[i-stamps[j]] + 1);
            }
        }
        if (best[i] > K) {
            fout << i - 1 << endl;
            break;
        }
    }
    
//    for (int i = 1; i <= K*10000; i++) {
//        if (best[i] == 0) {
//            fout << i-1 << endl;
//            break;
//        }
//    }
    
    fin.close();
    fout.close();
    return 0;
}
