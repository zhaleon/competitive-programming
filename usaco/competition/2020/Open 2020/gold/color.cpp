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
//set<int> adj[200001];
vi adj[200001];

int parent[200001];

queue<int> q; //queue for processing

int colors[200001];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	
	if (adj[a].size() < adj[b].size()) swap(a,b);
	rep(i,0,(int)adj[b].size()) adj[a].PB(adj[b][i]);
	
	parent[b] = a;
	
	if (adj[a].size() > 1) q.push(a);
	adj[b].clear();
} 

int main() {
	setIO("fcolor");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	rep(i,1,N+1) size[i] = 1, parent[i] = i;
	
	rep(_,0,M) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
	}
	rep(i,1,N+1) {
		if (adj[i].size() > 1) {
			rep(j,0,(int)adj[i].size()-1) merge(adj[i][j], adj[i][j+1]);
		}
	}
	
	while (!q.empty()) {
		int cur = q.front(); 
		if (adj[cur].size() < 2) {
			q.pop();
			continue;
		}
		
		int back = adj[cur].back(); adj[cur].pop_back();
		if (find(back) == find(adj[cur].back())) continue;
		merge(back, adj[cur].back());
	}
	
	int color = 1;
	
	rep(i,1,N+1) {
		if (!colors[find(i)]) {
			cout << color << endl;
			colors[find(i)] = color++;
		} else {
			cout << colors[find(i)] << endl;
		}
	}

    return 0;
}