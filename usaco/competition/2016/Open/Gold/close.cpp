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

vi adj[200001];

int parent[200001];
int size[200001];
int active[200001];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

int merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (size[a] > size[b]) swap(a,b);
	parent[a] = b;
	size[b] += size[a];
	return size[b];
}

int main() {
	setIO("closing");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	int a, b;
	rep(i,0,M) {
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	
	rep(i,1,N+1) parent[i] = i;
	rep(i,1,N+1) size[i] = 1;

	vi q;	
	vi ans;
	
	rep(i,0,N) {
		cin >> a;
		q.PB(a);
	}	
	
	reverse(q.begin(), q.end());
	
	int large = 1;
	rep(i,0,N) {
		active[q[i]] = 1;
		if (i == 0) {
			ans.PB(1);
			continue;
		}
		for (auto edge : adj[q[i]]) {
			if (active[edge] && find(q[i]) != find(edge)) {
				large = max(large, merge(q[i], edge));
			}
		}
		if (large == i+1) ans.PB(1);
		else ans.PB(0);
	}
	
	reverse(ans.begin(), ans.end());
	
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
    return 0;
}








