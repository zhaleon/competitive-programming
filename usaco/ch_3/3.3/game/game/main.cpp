/*
ID: lionz202
TASK: game1
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <assert.h>
#include <string>
#include <cstring>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <deque>


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;
typedef vector<vector<int>> vii;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i,a,b) for (int i = a; i < b; i++)

ifstream fin ("game1.in");
ofstream fout ("game1.out");

int N;
int board[101];

int dp[101][101];
int sums[101];

int main() {
    fin >> N;
    loop(i,1,N+1) {
        fin >> board[i];
        dp[i][i] = board[i];
        sums[i] = board[i] + sums[i-1];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j+i <= N; j++) {
            dp[j][j+i] = max(board[j] + sums[j+i]-sums[j] - dp[j+1][j+i], board[j+i] + sums[j+i-1]-sums[j-1] - dp[j][j+i-1]);
        }
    }
    
//    loop(i,1,N+1) {
//        fout << sums[i] << ' ';
//    } fout << endl;
    
    fout << dp[1][N] << ' ' << sums[N] - dp[1][N] << endl;
    
    return 0;
}



