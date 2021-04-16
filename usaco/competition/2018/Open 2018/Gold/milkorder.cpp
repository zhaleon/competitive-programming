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

vi adj[100001];
int color[100001];
vi observe[50001];
int numParents[100001];

bool good;

void dfs(int cur) {
	if (color[cur] == 2) return;
	if (color[cur] == 1) {
		good = 0;
		return;
	}
	color[cur] = 1;
	for (auto edge : adj[cur]) dfs(edge);
	color[cur] = 2;
}

bool possible(int test) {
	rep(i,1,N+1) color[i] = 0;
	rep(i,1,N+1) adj[i].clear();
	rep(i,1,test+1) {
		rep(j,0,(int)observe[i].size()-1) {
			int a = observe[i][j], b = observe[i][j+1];
			adj[a].PB(b);
		}
	}
	good = true;
	rep(i,1,N+1) {
		if (!color[i]) {
			dfs(i);
		}	
	}
	return good;
}

vi toposort;

int main() {
	setIO("milkorder");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	
	int m, a;
	rep(i,1,M+1) {
		cin >> m;
		rep(j,0,m) {
			cin >> a;
			observe[i].PB(a);
		} 
	}

	int low = 1, high = M+1;
	
	while (low+1 < high) {
		int mid = (low+high)/2;
		if (possible(mid)) {
			low = mid;
		} else {
			high = mid;
		}	
	}
	
	rep(i,1,N+1) adj[i].clear();
	
	rep(i,1,low+1) {
		rep(j,0,(int)observe[i].size()-1) {
			int a = observe[i][j], b = observe[i][j+1];
			numParents[b]++;
			adj[a].PB(b);
		}
	}
	
	priority_queue<int, vi, greater<int>> pq;
	
	rep(i,1,N+1) if (!numParents[i]) pq.push(i);
	//rep(i,1,N+1) if(adj[i].size() > 0) sort(adj[i].begin(), adj[i].end(), greater<int>());
	
	rep(i,1,N+1) {
		int cur = pq.top(); pq.pop();
		toposort.PB(cur);
		for (auto edge : adj[cur]) {
			numParents[edge]--;
			if (!numParents[edge]) pq.push(edge);
		}
	}
	
	for (int i = 0; i < toposort.size(); i++) {
		cout << toposort[i];
		if (i < N-1) cout << ' ';
		else cout << '\n';
	}
	
    return 0;
}