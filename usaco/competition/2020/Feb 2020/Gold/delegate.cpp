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
vi adj[100001];
int v[100001];

int k, height = 0;

int num[100001];
int depth[100001];

int source = 0, deg = 0;
int t = 0; //check num vertices that have degree 2 or less

vi branch;

void dfs2(int cur, int d) {
	if (adj[cur].size() <= 2) t++;
	v[cur] = 1; 
	depth[cur] = d; 
	height = max(height, d);
	for (auto edge : adj[cur]) if (!v[edge]) dfs2(edge, d+1);
	if (adj[cur].size() == 1 && cur != 1) branch.PB(d);
}


int dfs(int cur) {
	v[cur] = 1;
	unordered_map<int, int> m;
	int c = 0; 
	vi hold;
	
	for (auto edge : adj[cur]) {
		if (v[edge]) continue;
				
		int a = dfs(edge);
		
		if (a < 0) return -1;
		a = (a+1)%k;
		if (a == 0) continue;

		if (m[k-a] > 0) {
			c--;
			m[k-a]--;
		} else {
			hold.PB(a);
			m[a]++;
			c++;
		}
	}

	if (c == 0) return 0;
	if (c > 1) return -1;
	for (auto x : hold) if (m[x]) return x;
}

int main() {
	setIO("deleg");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	
	int a,b;
	rep(i,0,N-1) {
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	
	rep(i,1,N+1) {
		if (adj[i].size() > deg) {
			deg = adj[i].size();
			source = i;
		} 
	}
	dfs2(source,0);
	
	if (t >= N-1) { //star
		cout << 1;
		for (int i = 2; i < N; i++) {
			if ((N-1) % i > 0) cout << 0;
			else {
				k = i;
				unordered_map<int, int> m;
				int c = 0;
				for (auto x : branch) {
					int a = x%k;
					if (a == 0) continue;
					if (m[k-a] > 0) {
						m[k-a]--;
						c--;
					} else { 
						m[a]++;
						c++;
					}
				}
				if (c > 0) cout << 0;
				else cout << 1;
			}
		}
		cout << endl;
		return 0;
	}
	
	
	cout << 1;
	int i;
	for (i = 2; i < min(N/2+1, height*2 + 1); i++) {
		if ((N-1) % i > 0) cout << 0; 
		else {
			memset(v, 0, sizeof(v));
			k = i;
			if (dfs(1) == 0) cout << 1;
			else cout << 0;
		}
	}
	
	for (; i < N; i++) cout << 0;

	cout << endl;


    return 0;
}








