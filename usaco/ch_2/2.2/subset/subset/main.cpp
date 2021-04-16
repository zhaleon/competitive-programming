/*
 ID: lionz202
 TASK: subset
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
ofstream fout ("subset.out");
ifstream fin ("subset.in");

int memo[40][392];

int dp(int i, int sum) {
    if (sum < 0 || i <= 0) {
        return 0;
    } else if (memo[i][sum] != -1) {
        return memo[i][sum];
    } else if (sum == 0) {
        return memo[i][sum] = 1;
    }
    return memo[i][sum] = dp(i-1, sum-i) + dp(i-1, sum);
}

int main() {
    int N;
    fin >> N;
    fin.close();
    
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 391; j++) {
            memo[i][j] = -1;
        }
    }
    
    
    if (N*(N+1)/2 % 2 == 1) {
        fout << 0 << endl;
    } else {
        fout << dp(N, N*(N+1)/4) << endl;
        //fout << answer << endl;
    }
    
    return 0;
}
