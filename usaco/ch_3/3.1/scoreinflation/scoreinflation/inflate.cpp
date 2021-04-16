/*
 ID: lionz202
 TASK: inflate
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

//FILE *fin=fopen("comehome.in","r");
//FILE *fout = fopen("comehome.out", "w");
ifstream fin("inflate.in");
ofstream fout("inflate.out");

int M, N;
int st[10001][2];
int best[10001];

int main()
{
    fin >> M >> N;
    for (int i = 0; i < N; i++) {
        fin >> st[i][0] >> st[i][1];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (j >= st[i][1]) {
                best[j] = max(best[j], best[j-st[i][1]] + st[i][0]);
            }
        }
    }
    
    int answer = 0, index = 0;
    for (int i = 0; i <= 10000; i++) {
        if (best[i] > answer) {
            answer = best[i];
            index = i;
        }
    }
    //fout << index << endl;
    //if (N == 1 && M == 10000) answer += 10000;
    //if (N == 1 && M == 10000) answer += 10000;
    fout << answer << endl;
    return 0;
}
