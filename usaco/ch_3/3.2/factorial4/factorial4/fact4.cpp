/*
 ID: lionz202
 TASK: fact4
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

using namespace std;

ifstream fin("fact4.in");
ofstream fout("fact4.out");

int getFirst(int a) {
    while(a / 10 > 0) {
        a/=10;
    }
    return a;
}

int main()
{
    int N;
    fin >> N;
    int cur = 1;
    for (int i = 1; i <= N; i++) {
        if (i % 10 == 0) {
            int a = i;
            while (a % 10 == 0) {
                a /= 10;
            }
            cur *= a;
        } else {
            cur *= (i % 1000);
        }
        while (cur % 10 == 0) {
            cur /= 10;
        }
        cur %= 1000;
    }
    fout << cur % 10 << endl;
    fin.close();
    fout.close();
    return 0;
}

