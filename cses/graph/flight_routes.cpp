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
typedef pair<ll, ll> pii;
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

int n, m, k;

vector<pii> adj[100001];
int seen[100001];

auto comp = [](pii a, pii b) { return a.S > b.S; };

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k; 
    
	ll a, b, c;
	rep(i,0,m) {
		cin >> a >> b >> c;
		adj[a].PB(MP(b,c));
	}

	priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);
	vector<ll> ans;

	pq.push(MP(1, 0));
	while (!pq.empty()) { 
		pii cur = pq.top(); pq.pop();
		
		seen[cur.F]++;
		if (cur.F == n) ans.PB(cur.S); 
		
		if (seen[cur.F] <= k) {
			for (auto edge : adj[cur.F]) {
				pq.push(MP(edge.F, cur.S + edge.S));
			}
		}

	}
	sort(ans.begin(), ans.end());
	
    for (int i = 0; i < ans.size() && i < k; i++) cout << ans[i] << ' ';
	cout << endl;
	
	return 0;
}








