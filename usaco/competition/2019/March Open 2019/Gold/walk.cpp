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

int N, K;

ll dist[7501];
int source[7501];
bool tree[7501];

ll cost(int x, int y) {
	if (x > y) swap(x,y);
	return (x*2019201913ll+y*2019201949ll) % 2019201997ll;
}

vector<ll> edges;

int main() {
	setIO("walk");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;

	memset(dist, 0x3f, sizeof(dist));

	rep(i,2,N+1) dist[i] = cost(1,i), source[i] = 1;
	
	source[1] = 1;
	tree[1] = 1;
	int treeSize = 1;
	
	while (treeSize < N) {
		ll nxt = 0, far = (1ll << 61);
		
		rep(i,1,N+1) if (!tree[i] && dist[i] < far) far = dist[i], nxt = i;
		
		treeSize++;
		tree[nxt] = 1;
		edges.PB(dist[nxt]);
		
		rep(i,1,N+1) if (!tree[i] && dist[i] > cost(nxt, i)) dist[i] = cost(nxt, i), source[i] = nxt;
	}

	sort(edges.begin(), edges.end(), greater<ll>());
	
	cout << edges[K-2] << endl;
    return 0;
}