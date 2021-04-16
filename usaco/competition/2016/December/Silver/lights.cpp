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

int grid[102][102];

int vis[102][102];

vpi m[101][101];

int ans = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
	if (vis[x][y] || x < 1 || x > N || y < 1 || y > N) return;
	vis[x][y] = 1;
	
	for (auto e : m[x][y]) {
		grid[e.F][e.S] = 1;
		bool g = 0;
		rep(i,0,4) if (vis[e.F + dx[i]][e.S + dy[i]]) g = 1;
		if (g) dfs(e.F, e.S);
	}

	rep(i,0,4) {
		if (grid[x + dx[i]][y + dy[i]]) dfs(x + dx[i], y + dy[i]);
	}

}

int main() {
	setIO("lightson");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
    
	int a,b,c,d;
	
	rep(i,0,M) {
		cin >> a >> b >> c >> d;
		m[a][b].PB(MP(c,d));
	}

	grid[1][1] = 1;
	
	dfs(1,1);

	rep(i,1,N+1) rep(j,1,N+1) if (grid[i][j]) ans++;	


	cout << ans << endl;
    return 0;
}








