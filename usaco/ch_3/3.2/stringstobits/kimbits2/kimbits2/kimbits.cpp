/*
 ID: lionz202
 TASK: kimbits
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <bitset>
#include <map>

using namespace std;

ifstream fin("kimbits.in");
ofstream fout("kimbits.out");

unsigned int N, L, I,  checked[33][33];

int numBits(unsigned int n) {
    int c;
    for (c = 0; n; c++) {
        n &= n - 1;
    } return c;
}

void update() {
    int i,j;
    for (int i = 0; i < 32; i++) {
        checked[0][i] = 1;
    }
    for (i = 1; i < 32; i++) {
        for (j = 0; j < 32; j++) {
            if (j == 0) {
                checked[i][j] = 1;
            } else {
                checked[i][j] = checked[i-1][j-1] + checked[i-1][j];
            }
        }
    }
}

void search(int n, int l){//}, int currentBit) {
    if (n == 0) return;
    int oof = checked[n-1][l];
    if (oof < I) {
        fout << "1";
        I -= oof;
        search(n-1, l-1);//, currentBit);
    } else {
        fout << "0";
        search(n-1, l);//, currentBit);
    }
}

int main()
{
    fin >> N >> L >> I;
    
    update();
    search(N, L);
    fout << endl;
//    unsigned int current = 0;
//    while (I > 1) {
//        current++;
//        if (numBits(current) <= L) {
//            I--;
//        }
//    }
    
//    bitset<31> answer = bitset<31>(current);
//    fout << answer.to_string().substr(31-N) << endl;
    
    fin.close();
    fout.close();
    return 0;
}

