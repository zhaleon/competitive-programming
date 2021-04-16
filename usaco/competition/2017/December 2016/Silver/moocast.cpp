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

pii pos[201];
int rad[201];

vi adj[201];

double dist(pii a, pii b) {
	return sqrt((a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S));
}

int v[201];

int size = 0;
void flood(int cur, int g) {
	size++;
	v[cur] = g;

	for (auto e : adj[cur]) {
		if (!v[e]) flood(e, g);
	}
}

int main() {
	setIO("moocast");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	rep(i,1,N+1) {
		cin >> pos[i].F >> pos[i].S >> rad[i];
	}

	rep(i,1,N+1) {
		rep(j,i+1,N+1) {
			if (dist(pos[i], pos[j]) < rad[i]) {
				adj[i].PB(j);
			}
			if (dist(pos[i], pos[j]) < rad[j]) {
				adj[j].PB(i);
			}
		}
	}
    int ans = 0;
	int group = 1;

	rep(i,1,N+1) {
			flood(i, group);
			group++;
			ans = max(ans, size);
			size = 0;
			memset(v, 0, sizeof(v));
	}
	
	cout << ans << endl;
    return 0;
}








