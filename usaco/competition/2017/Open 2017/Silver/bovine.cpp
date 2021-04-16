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

int N, M;

map<char, int> m;

int v[64]; 

string spot[500];
string plain[500];

bool works(int a, int b, int c) {
	memset(v, 0, sizeof(v));
	
	rep(i,0,N) {
		v[16*m[spot[i][a]] + 4*m[spot[i][b]] + m[spot[i][c]]] = 1;
	}

	rep(i,0,N) {
		int id = 16*m[plain[i][a]] + 4*m[plain[i][b]] + m[plain[i][c]]; 
		if (v[id]) return false;
	}
	return true;
}

int main() {
	setIO("cownomics");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	rep(i,0,N) cin >> spot[i];
	rep(i,0,N) cin >> plain[i];

	m['A'] = 1;
	m['G'] = 2;
	m['T'] = 3;

	int ans = 0;

	for (int a = 0; a < M; a++) {
		for (int b = a+1; b < M; b++) {
			for (int c = b+1; c < M; c++) {
				if (works(a,b,c)) ans++;
			}
		}
	}
    
	cout << ans << endl;

    return 0;
}








