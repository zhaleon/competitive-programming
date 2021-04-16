/*
 ID: lionz202
 TASK: nocows
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

ofstream fout ("nocows.out");
ifstream fin ("nocows.in");
int N, K, tree[201][101], allsubtree[201][101];


int main() {
    fin >> N >> K;
    //memset(tree, -1, sizeof(tree));
    tree[1][1] = 1;
    int mirror;
    for (int height = 2; height <= K; height++) {
        for (int nodes = 1; nodes <= N; nodes+=2) {
            for (int i = 1; i <= nodes-1-i; i++) {
                if (i != nodes-i-1) {
                    mirror = 2;
                } else {
                    mirror = 1;
                }
                tree[nodes][height] += mirror*(allsubtree[nodes-i-1][height-2]*tree[i][height-1] + allsubtree[i][height-2]*tree[nodes-i-1][height-1] + tree[nodes-i-1][height-1]*tree[i][height-1]);
                tree[nodes][height] %= 9901;
//                if (tree[nodes][height] < 0) {
//                    fout << nodes << ' ' << height << ' ' << i << endl;
//                    //fout << tree[nodes][height] << endl;
//                    fout << allsubtree[nodes-i-1][height-2] << endl;
//                    fout << allsubtree[i][height-2] << endl;
//                    fout << tree[nodes-i-1][height-1] << endl;
//                    fout << tree[i][height-1] << endl;
//                    exit(0);
//                }
            }
        }
        for (int i = 1; i <= N; i++) {
            allsubtree[i][height-1] += (allsubtree[i][height-2] + tree[i][height-1]);
            allsubtree[i][height-1] %= 9901;
        }
    }
    
//    for (int i = 1; i <= K; i++) {
//        for (int j = 1; j<=N; j++) {
//            fout << tree[i][j] << ' ';
//        }
//        fout << endl;
//    }
    
    if (N % 2 == 0) {
        fout << 0 << endl;
    } else {
        fout << tree[N][K] % 9901 << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}
