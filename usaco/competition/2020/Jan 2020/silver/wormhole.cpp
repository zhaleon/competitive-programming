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

vpi adj[100001];

int cows[100001];
int farm[100001];

void floodfill(int s, int g, int w) {
	farm[s] = g;
	rep(i,0,adj[s].size()) {
		if (adj[s][i].S >= w && !farm[adj[s][i].F]) {
			floodfill(adj[s][i].F, g, w);
		}
	}
}

bool works(int w) {
	memset(farm, 0, sizeof(farm));

	int num = 1;
	rep(i,1,N+1) {
		if (!farm[i]) {
			floodfill(i, num, w);
		   	num++;	
		}
	}
	rep(i,1,N+1) {
		if (farm[i] != farm[cows[i]]) return false;
	}
	return true;
}

int main() {
	setIO("wormsort");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	rep(i,1,N+1) {
		cin >> cows[i];
	}

	int a, b, c;
	rep(i,0,M) {
		cin >> a >> b >> c;
		adj[a].PB(MP(b,c));
		adj[b].PB(MP(a,c));
	}
    
	int low = 1, high = 1e9;
	while (low+1 < high) {

		int mid = (low + high)/2;
		
		if (works(mid)) {
			low = mid;
		} else {
			high = mid;
		}
	}

	if (low == (int)1e9-1) low = -1;
	cout << low << endl;

    return 0;
}








