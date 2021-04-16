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

int N, xL, yL, xB, yB; 

typedef struct fence {
	int id, x, y;
	fence() {};
	fence(int a, int b, int c) : x(a), y(b), id(c) {};
} fence;

vector<fence> p;

bool X(fence a, fence b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool Y(fence a, fence b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

int dist[200005];
bool v[200005];

vpi adj[200005];

int main() {
	setIO("lasers");
    ios::sync_with_stdio(0); cin.tie(0);

    
	cin >> N >> xL >> yL >> xB >> yB;

	int a, b;

	p.PB(fence(xL, yL, 0));
	p.PB(fence(xB, yB, 1));
	rep(i,2,N+2) {
		cin >> a >> b;
		p.PB(fence(a,b,i));
	}

	sort(p.begin(), p.end(), X); 

	map<int, fence> lastY;
	map<int, fence> lastX;

	rep(i,0,N+2) {
		adj[i].PB(MP(i+N+2, 1));
		adj[i+N+2].PB(MP(i, 1));
	}

	rep(i,0,p.size()) {
		int cur = p[i].y;
		auto it = lastY.find(cur);

		if (it != lastY.end()) {
			adj[p[i].id].PB(MP(it->S.id,0));
			adj[it->S.id].PB(MP(p[i].id,0));
		} 
		lastY[cur] = p[i];
	}
		
	sort(p.begin(), p.end(), Y);

	rep(i,0,p.size()) {
		int cur = p[i].x;
		auto it = lastX.find(cur);
		if (it != lastX.end()) {
			adj[p[i].id+N+2].PB(MP(it->S.id+N+2,0));
			adj[it->S.id+N+2].PB(MP(p[i].id+N+2,0));
		}
		lastX[cur] = p[i];
	}
	
	deque<int> bfs;
	
	bfs.push_front(0);
	bfs.push_front(N+2);

	v[0] = v[N+2] = 1;

	while (!bfs.empty()) {
		int cur = bfs.front(); bfs.pop_front();
		
		for (auto nxt : adj[cur]) {
			if (!v[nxt.F]) {
				v[nxt.F] = 1;
				dist[nxt.F] = dist[cur]+nxt.S;
				if (nxt.S) bfs.push_back(nxt.F);
				else bfs.push_front(nxt.F);
			}
		}
	}

	cout << min(dist[1], dist[N+3]) << endl;

    return 0;
}








