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
#include <cmath>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

FILE* fin = fopen("perimeter.in", "r");
FILE* fout = fopen("perimeter.out", "w");

int N;
char ice[1002][1002];
int blob[1001][1001];

int curArea = 0, curPerimeter = 0;
int finalA = 0, finalP = 0;

void flood(int a, int b) {
	curArea++;
	if (ice[a+1][b] == '.' || a == N) curPerimeter++;
	if (ice[a-1][b] == '.' || a == 1) curPerimeter++;
	if (ice[a][b+1] == '.' || b == N) curPerimeter++;
	if (ice[a][b-1] == '.' || b == 1) curPerimeter++;

	blob[a][b] = 1;

	if (ice[a][b-1] == '#' && !blob[a][b-1]) flood(a, b-1); 
	if (ice[a][b+1] == '#' && !blob[a][b+1]) flood(a, b+1); 
	if (ice[a-1][b] == '#' && !blob[a-1][b]) flood(a-1, b); 
	if (ice[a+1][b] == '#' && !blob[a+1][b]) flood(a+1, b); 

}

void ans() {
	rep(i,1,N+1) {
		rep(j,1,N+1) {
			if (blob[i][j] == 0 && ice[i][j] == '#') {
				curArea = 0, curPerimeter = 0;
				flood(i, j);
				if (finalA == curArea) {
					finalP = curPerimeter;
				} else if (curArea > finalA) {
					finalA = curArea;
					finalP = curPerimeter;
				}
			}			
		}
	}
}

int main() {
    //ios::sync_with_stdio(0); cin.tie(0);
	
	fscanf(fin, "%i\n", &N);

	rep(j,1,N+1) {
		rep(i,1,N+1) {
			fscanf(fin, "%c", &ice[i][j]);
		} fscanf(fin, "\n");
	}

   	ans();

	fprintf(fout, "%i %i\n", finalA, finalP);


    return 0;
}








