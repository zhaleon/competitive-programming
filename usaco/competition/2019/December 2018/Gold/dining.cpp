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

int N, M, K;

vector<pair<ll, ll>> adj[50001];
ll hay[50001];

ll dist[50001];
ll dist2[50001];

vector<pair<ll, ll>> reroute;

auto comp = [](int a, int b) {return dist[a] > dist[b];};
auto comp2 = [](int a, int b) {return dist2[a] > dist2[b];};

int main() {
	setIO("dining");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> K;
	
	rep(_,0,M) {
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a].PB(MP(b,c));
		adj[b].PB(MP(a,c));
	}

	rep(_,0,K) {
		ll a, b;
		cin >> a >> b;
		hay[a] = b;
	}

	memset(dist, 0x3f, sizeof(dist));
	dist[N] = 0;
	
	priority_queue<int, vi, decltype(comp)> pq(comp);
	pq.push(N);

	while (!pq.empty()) {
		int cur = pq.top(); pq.pop();
		for (auto edge : adj[cur]) {
			if (dist[cur] + edge.S < dist[edge.F]) {
				dist[edge.F] = dist[cur] + edge.S;
				pq.push(edge.F);
			}
		}
	}
	
	priority_queue<int, vi, decltype(comp2)> pq2(comp2);
	
	rep(i,1,N) if (hay[i] > 0) reroute.PB(MP(i, dist[i]-hay[i]));
	memset(dist2, 0x3f, sizeof(dist2));
	
	for (auto edge : reroute) { //start at all the pastures with haybales
		if (edge.S < dist2[edge.F]) {
			dist2[edge.F] = edge.S;
			pq2.push(edge.F);
		}
	}

	while (!pq2.empty()) {
		int cur = pq2.top(); pq2.pop();
		for (auto edge : adj[cur]) {
			if (dist2[cur] + edge.S < dist2[edge.F]) {
				dist2[edge.F] = dist2[cur] + edge.S;
				pq2.push(edge.F);
			}
		}
	}

	rep(i,1,N) {
		if (dist[i] >= dist2[i]) cout << 1 << endl;
		else cout << 0 << endl;
	}
	
    return 0;
}