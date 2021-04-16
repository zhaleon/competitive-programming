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

int N;

bool cows[1000][1000];

void flipRow(int r) {
	rep(i,0,N) cows[i][r] = !cows[i][r];
}

void flipCol(int c) {
	rep(i,0,N) cows[c][i] = !cows[c][i];
}

int main() {
	setIO("leftout");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;	
	
	string row;
	
	for (int j = N-1; j >= 0; j--) {
		cin >> row;
		for (int i = 0; i < N; i++) {
			if (row[i] == 'L') cows[i][j] = 0;
			else cows[i][j] = 1;
		}
	}
   	
	if (!cows[0][N-1]) flipRow(N-1);
	
	for (int j = N-1; j>= 0; j--) {
		for (int i = 0; i < N; i++) {
			//cout << cows[i][j];
		} //cout << endl;
	} //cout << "\n\n";

	rep(i,1,N) {
		if (!cows[0][i-1]) flipRow(i-1);
		if (!cows[i][N-1]) flipCol(i);
	}
	
	int sum = 0;
	rep(i,0,N) {
		rep(j,0,N) {
			sum += cows[i][j];
		}
	}

	for (int j = N-1; j>= 0; j--) {
		for (int i = 0; i < N; i++) {
			//cout << cows[i][j];
		} //cout << endl;
	}
	if (sum == N*N) {
		cout << -1 << endl; return 0;
	} else if (sum == 2*N-1) {
		cout << 1 << ' ' << 1 << endl; return 0;
	} else if (sum == N*N-1) {
		for (int j = N-1; j >= 0; j--) {
			for (int i = 0; i < N; i++) {
				if (!cows[i][j]) {
					cout << N-j << ' ' << i+1 << endl;
					//cout << i+1 << ' ' << N-j << endl;
					return 0;
				}
			}
		}
	} else if (sum == N*N-N+1) {
		for (int i = 1; i < N; i++) {
			int sum = 0;
			for (int j = N-2; j >= 0; j--) {
				sum += cows[i][j];
			}
			if (sum == 0) {
				cout << 1 << ' ' << i+1 << endl;
				return 0;
			}
		}

		for (int j = 0; j < N-1; j++) {
			int sum = 0;
			for (int i = 1; i < N; i++) {
				sum += cows[i][j];
			}
			if (sum == 0) {
				cout << N-j << ' ' << 1 << endl;
				return 0;
			}
		}
	} else {
		cout << -1 << endl;
	}



    return 0;
}








