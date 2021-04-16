/*
ID: lionz202
TASK: range
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

//ifstream fin ("range.in");
//ofstream stuff ("range.out");

FILE *fin=fopen("range.in","r");
FILE *fout = fopen("range.out", "w");

int farm[251][251];
int sums[251][251];
int N;

int sum(int r1, int c1, int r2, int c2) {
    //fprintf(fout, "%i %i %i %i ", sums[r2][c2], sums[r1-1][c1-1], sums[r1-1][c2], sums[r2][c1-1]);
    return sums[r2][c2] + sums[r1-1][c1-1] - sums[r1-1][c2] - sums[r2][c1-1];
}

int ans[251];

int main() {
    
    //fin >> N;
    fscanf(fin, "%i\n", &N);
    
    loop(i,1,N+1) {
        loop(j,1,N+1) {
            fscanf(fin, "%1d", &farm[i][j]);
            //fin >> farm[i][j];
            sums[i][j] = sums[i][j-1] + farm[i][j];
        } fscanf(fin, "\n");
        loop(j,1,N+1) {
            sums[i][j] += sums[i-1][j];
        }
    }
    
    unordered_map<int, int> m;
    
    loop(i,1,N+1) {
        loop(j,i+1,N+1) {
            int l = j-i+1;
            loop(k,1,N-l+2) {
                if (sum(i,k,j,k+l-1) == l*l) ans[l]++;
//                if (i == 1 && j == 2) {
//                    fprintf(fout, "%i %i %i %i %i\n", i, k, j, k+l-1, sum(i,k,j,k+l-1));
//                }
            }
//            if (i == 1 && j == 2) {
//                loop(i,2,N+1) {
//                    if (ans[i] == 0) continue;
//                    fprintf(fout, "%i %i\n", i, ans[i]);
//                }
//            }
        }
    }
    
//    loop(i,1,N+1) {
//        loop(j,1,N+1) {
//            fprintf(fout, "%i ", sums[i][j]);
//        }
//        fprintf(fout, "\n");
//    } fprintf(fout, "%i\n", sum(3,3,5,5));
    
    loop(i,2,N+1) {
        if (ans[i] == 0) continue;
        fprintf(fout, "%i %i\n", i, ans[i]);
    }
    return 0;
}



