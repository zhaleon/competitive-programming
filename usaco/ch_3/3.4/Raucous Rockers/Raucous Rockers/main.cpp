/*
ID: lionz202
TASK: rockers
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
typedef vector<vector<int> > vii;
typedef vector<pair<int, int> > vpi;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i,a,b) for (int i = a; i < b; i++)

ifstream fin ("rockers.in");
ofstream fout ("rockers.out");

int N, T, M;
int len[21];

int dp[21][21][21]; //store first N discs, minutes used on last disc, last song on last disc

int main() {
    fin >> N >> T >> M;
    
    loop(i,1,N+1) {
        fin >> len[i];
    }
    int best = 0;
    loop(a, 0, M) { //current last disc
        loop(b, 0, T+1) { //minutes used so far on last disc
            loop(c, 0, N+1) { // try last song
                loop(d, c+1, N+1) {
                    if (b+len[d] <= T) {
                        dp[a][b+len[d]][d] = max(dp[a][b+len[d]][d], dp[a][b][c]+1);
                    } else {
                        if (len[d] <= T) {
                            dp[a+1][len[d]][d] = max(dp[a+1][len[d]][d], dp[a][b][c]+1);
                        }
                    }
                }
                best = max(best, dp[a][b][c]);
            }
        }
    }
    loop(a, 0, 21) {
        loop(b, 0, 21) {
            loop(c, 0, 21) {
                //best = max(best, dp[a][b][c]);
                if (dp[a][b][c] == 10) fout << a << ' ' << b << ' ' << c << endl;
            }
        }
    }
    
    fout << best << endl;
    
    fin.close();
    fout.close();
    return 0;
}



