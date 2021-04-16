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

int N, r, c, a, b;

int grid[1001][1001];

vpi nets;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	

	ifstream cin ("capture.in");
	ofstream cout ("capture.out");
	
	cin >> N >> r >> c >> a >> b;

	
	int e, d;

	rep(i,0,N) {
		cin >> e >> d;
		nets.PB(MP(e,d));
	}
   
	int ans = 0;
	int dist;
	

	for (int row = 0; row <= r-a; row++) { //rows
		for (int col = 0; col <= c-b; col++) { //cols
			dist = INF;
			for (auto x : nets) {
				if (x.F >= row && x.F <= row+a-1 && x.S >= col && x.S <= col+b-1) {
					dist = 0;
					break;
				} else {
					if (x.F <= row+a-1 && x.F >= row) {
						dist = min(dist, min(abs(x.S-col), abs(x.S-(col+b-1))));
					} else if (x.S >= col && x.S <= col+b-1) {
						dist = min(dist, min(abs(x.F-row), abs(x.F-(row+a-1))));
					} else {
						dist = min(dist, min( abs(row-x.F) + abs(col-x.S), abs(row+a-1 - x.F) + abs(col-x.S)));
						dist = min(dist, min( abs(row-x.F) + abs(col+b-1-x.S), abs(row+a-1-x.F) + abs(col+b-1-x.S)));
					}
				}
			}
			ans = max(ans, dist);
		}
	}
	
	cout << ans << endl;

    return 0;
}








