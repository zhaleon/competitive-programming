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

#define INF 1061109567
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

int best[1501][1501]; // best cost at node i with flow j

auto comp = [](pair<int, pii> a, pair<int, pii> b) {
	//return a.S.F > b.S.F;
	return best[a.F][a.S.S] > best[b.F][b.S.S]; 
	//return (double)a.S.S/a.S.F > (double)b.S.S/b.S.F;
};


vector<pair<int, pii>> adj[1001];

int c = 0;

int main() {
	setIO("pump");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
 
	memset(best, 0x3f, sizeof(best));
	int a,b,c,f;

	rep(i,0,M) {
		cin >> a >> b >> c >> f;
		adj[a].PB(MP(b, MP(c, f)));
		adj[b].PB(MP(a, MP(c, f)));
	}

	priority_queue<pair<int, pii>, vector<pair<int, pii>>, decltype(comp)> pq(comp);
	pq.push(MP(1, MP(0, 1000)));
	int ans = 0;
	best[1][1000] = 0;
	
	while (!pq.empty()) {
		c++;
		if (c > 1e7) break;
		auto cur = pq.top(); pq.pop();
		int curFlow = cur.S.S;
		int curCost = cur.S.F;
		//cerr << curFlow << ' ' << curCost << endl;
		if (cur.F == N) {
			ans = max(ans, (int)((double)curFlow*1000000/curCost) );
			continue;
			//cout << curFlow << ' ' << curCost << ' ' << ((int)((double)curFlow*1000000/curCost)) << endl;
		}
		for (auto edge : adj[cur.F]) {
			if (best[edge.F][min(curFlow, edge.S.S)] > curCost + edge.S.F) {
				best[edge.F][min(curFlow, edge.S.S)] = curCost + edge.S.F;
		   		pq.push(MP(edge.F, MP(edge.S.F + curCost, min(curFlow, edge.S.S))));
			}
		}
	}

	cout << ans << endl;
	
	return 0;
}






