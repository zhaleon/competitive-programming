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

int N, Q;

vpi adj[5001];
int visited[5001];

int answer(int s, int K) {
	memset(visited, 0, sizeof(visited));
	int ans = 0;
	visited[s] = 1;
	queue<int> bfs;
	bfs.push(s);
	while (!bfs.empty()) {
		int cur = bfs.front(); bfs.pop();
		rep(i,0,adj[cur].size()) {
			if (adj[cur][i].S >= K && !visited[adj[cur][i].F]) {
				bfs.push(adj[cur][i].F);
				visited[adj[cur][i].F] = 1;
				ans++;
			}
		}
	}
	return ans;
}
int main() {
	setIO("mootube");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;
    
	int a,b,c;
	rep(i,0,N-1) {
		cin >> a >> b >> c;
		adj[a].PB(MP(b,c));
		adj[b].PB(MP(a,c));
	}

	rep(i,0,Q) {
		cin >> a >> b;
		cout << answer(b, a) << endl;
	}
    return 0;
}








