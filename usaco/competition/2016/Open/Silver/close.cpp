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

vi barn[3001];

bool closed[3001];
bool vis[3001];

int open = 0;

void dfs(int cur) {
	open++;
	vis[cur] = 1;
	for (int adj : barn[cur]) if (!closed[adj] && !vis[adj]) dfs(adj);
}

int main() {
	setIO("closing");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
    
	int a, b;
	rep(i,0,M) {
		cin >> a >> b;
		barn[a].PB(b);
		barn[b].PB(a);
	}
	
	int q;

	dfs(1);
	if (open == N) cout << "YES" << endl;
	else cout << "NO" << endl;

	rep(i,1,N+1) {
		memset(vis, 0, sizeof(vis));
		cin >> q;
		closed[q] = 1;
		
		rep(j,1,N+1) if (!closed[j]) {
			open = 0;
			dfs(j);

			if (open == N-i) cout << "YES" << endl;
			else cout << "NO" << endl;

			break;
		}

	}

    return 0;
}








