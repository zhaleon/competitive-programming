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

char grid[20][20];

bool v[20][20];

int group = 0;

vector<pair<pii, pii>> pcls;

void flood(int a, int b, int c, int d, int i, int j) {
	v[i][j] = 1;
	
	if (i+1 <= b && !v[i+1][j] && grid[i+1][j] == grid[i][j]) flood(a,b,c,d,i+1,j);
	if (i-1 >= a && !v[i-1][j] && grid[i-1][j] == grid[i][j]) flood(a,b,c,d,i-1,j);
	if (j+1 <= d && !v[i][j+1] && grid[i][j+1] == grid[i][j]) flood(a,b,c,d,i,j+1);
	if (j-1 >= c && !v[i][j-1] && grid[i][j-1] == grid[i][j]) flood(a,b,c,d,i,j-1);
	
}

bool unique(pair<pii, pii> a) {

	for (auto x : pcls) {
		int l = x.S.F, r = x.S.S;
		int d = x.F.F, u = x.F.S;
			
		if (a.F.F == d && a.F.S == u && a.S.F == l && a.S.S == r) continue;

		if (a.F.F >= d && a.F.S <= u && a.S.F >= l && a.S.S <= r) return 0;
	}

	return 1;
}

int main() {
	setIO("where");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

    rep(i,0,N) {
		rep(j,0,N) {
			cin >> grid[i][j];
		}
	}

	int ans = 0;
	for (int a = 0; a < N; a++) {
		for (int b = a; b < N; b++) {
			for (int c = 0; c < N; c++) {
				for (int d = c; d < N; d++) {
					memset(v, 0, sizeof(v));
					
					group = 0;
					map<char, int> m;
					vector<char> used;

					for (int i = a; i <= b; i++) {
						for (int j = c; j <= d; j++) {
							if (!v[i][j]) {
								s.insert(grid[i][j]);
								if (!m[grid[i][j]]) used.PB(grid[i][j]);
								m[grid[i][j]]++;
							   	group++;	
							   	flood(a,b,c,d,i,j);
							}
						}
					}

					if (m.size() != 2) continue;
				   	bool hasOne = (m[used[0]] == 1 || m[used[1]] == 1);
					bool hasMore = (m[used[0]] > 1 || m[used[1]] > 1);
					if (!hasOne || !hasMore) continue;	
					pcls.PB(MP(MP(a,b), MP(c,d)));
					
				}	
			}
		}
	}

	for (int i = 0; i < pcls.size(); i++) {
		if (unique(pcls[i])) ans++; 
	}

	cout << ans << endl;
    return 0;
}








