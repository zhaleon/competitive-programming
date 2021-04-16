/*
ID: lionz202
TASK: fence
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

ifstream fin ("fence.in");
ofstream fout ("fence.out");

int adj[501][501];
int f;

int circ[1025];
int circuitPos = 0;
int degree[501];

void circuit(int pos) {
    for (int i = 1; i < 501; i++) {
        if (adj[pos][i] > 0) {
            adj[pos][i]--;
            adj[i][pos]--;
            circuit(i);
        }
    }
    circ[circuitPos] = pos;
    circuitPos++;
}

int main() {
    fin >> f;
    
    int a, b;
    loop(i,0,f) {
        fin >> a >> b;
        adj[a][b]++;
        adj[b][a]++;
        
        degree[a]++;
        degree[b]++;
    }
    int start = 1;
    loop(i,1,501) {
        if (degree[i] % 2 == 1) {
            start = i;
            break;
        }
    }
    circuit(start);
    
    for (int i = circuitPos-1; i >= 0; i--) {
        fout << circ[i] << endl;
    }
    
    
    fin.close();
    fout.close();
    return 0;
}



