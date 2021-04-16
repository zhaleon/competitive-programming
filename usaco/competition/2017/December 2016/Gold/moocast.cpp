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

pii cows[1000];
vpi adj[1000];

bool tree[1000];

auto comp = [](pii a, pii b) { return a.S > b.S; };

int main() {
	setIO("moocast");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	rep(i,0,N) {
		cin >> cows[i].F >> cows[i].S;
	}

	rep(i,0,N) {
		rep(j,i+1,N) {
			int dist = (cows[i].F-cows[j].F)*(cows[i].F-cows[j].F) + (cows[i].S-cows[j].S)*(cows[i].S-cows[j].S);
			adj[i].PB(MP(j, dist));
			adj[j].PB(MP(i, dist));
		}
	}

	tree[0] = 1;
    int nodes = 1;
	int ans = 0;

	priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);

	for (auto x : adj[0]) {
		pq.push(x);
	}

	while (nodes < N) {
		auto cur = pq.top(); pq.pop();
		if (tree[cur.F]) continue;
		ans = max(ans, cur.S);
		nodes++;
		tree[cur.F] = 1;
			
		for (auto x : adj[cur.F]) {
			pq.push(x);
		}

	}
	
	cout << ans << endl;
	
    return 0;
}








