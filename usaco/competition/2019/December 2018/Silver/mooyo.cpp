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
#include <chrono>
#include <unordered_set>
#include <thread>
#include <stdio.h>

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

FILE* fin = fopen("mooyomooyo.in", "r");
FILE* fout = fopen("mooyomooyo.out", "w");

int N, K;

int board[10][100];
int fall[10];

bool hasRegion = 0;

int floodmap[10][100];
int curSize = 0;
int sizes[1001];

void flood(int a, int b, int g) {
	curSize++;
	floodmap[a][b] = g;
	if (a+1 < 10 && board[a+1][b] == board[a][b] && !floodmap[a+1][b]) flood(a+1,b,g);
  	if (a-1 >= 0 && board[a-1][b] == board[a][b] && !floodmap[a-1][b]) flood(a-1,b,g);
	if (b+1 < N && board[a][b+1] == board[a][b] && !floodmap[a][b+1]) flood(a,b+1,g);
  	if (b-1 >= 0 && board[a][b-1] == board[a][b] && !floodmap[a][b-1]) flood(a,b-1,g);
}

void printBoard() {
	rep(j,0,N) {
		rep(i,0,10) {
			fprintf(fout, "%d", board[i][j]);
		}
		fprintf(fout, "\n");
	}
}

void floodfill() {
	memset(floodmap, 0, sizeof(floodmap));
	memset(sizes, 0, sizeof(sizes));

	int group = 1;
	rep(i,0,10) {
		rep(j,0,N) {
			if (!floodmap[i][j] && board[i][j]) {
				flood(i,j,group);
				sizes[group] = curSize;
				if (curSize >= K) hasRegion = 1;
				curSize = 0;
				group++;
			}
		}
	}
	rep(i,0,10) {
		rep(j,0,N) {
			if (sizes[floodmap[i][j]] >= K) board[i][j] = 0;
		}
	}
}

void updateBoard() {
	rep(i,0,10) {
		for (int j = N-1; j >= 0; j--) {	
			if (board[i][j] == 0) continue;
			int t = j;
			while (t < N-1 && board[i][t+1] == 0) {
				t++;
			}
			//printBoard(); printf("\n\n\n");
			swap(board[i][j], board[i][t]);
		}
	}
}



int main() {
	//setIO("mooyomooyo");
    //ios::sync_with_stdio(0); cin.tie(0);
	
	fscanf(fin, "%i %i\n", &N, &K);
	rep(j,0,N) {
		rep(i,0,10) {
			if (i == 9) fscanf(fin, "%1d", &board[i][j]);
			else fscanf(fin, "%1d", &board[i][j]);
		}
	}	
	std::chrono::milliseconds timespan(5000); 
	
	
	floodfill();
	//hasRegion = 0;
	while (hasRegion) {
		
		hasRegion = 0;
		updateBoard();
		floodfill();
		
	}
	
	printBoard();
	
	fclose(fin);
	fclose(fout);

    return 0;
}

















