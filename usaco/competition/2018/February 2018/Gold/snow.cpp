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

int N, B;
pii snow[100001];

pii depth[100001];
int dist[100001];

bool works[100001];

int aft[100001];
int bef[100001];

bool comp(int a, int b) {
	return depth[a] < depth[b];
}

int main() {
	setIO("snowboots");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> B;
	
	rep(i,1,N+1) cin >> snow[i].F;
	rep(i,1,B+1) cin >> depth[i].F >> dist[i];
	
	rep(i,1,N+1) snow[i].S = i;
	rep(i,1,B+1) depth[i].S = i;
	
	sort(depth+1, depth+1+N);
	sort(snow+1, snow+1+N);
	
	rep(i,1,N+1) aft[i] = i+1, bef[i] = i-1;
	
	int curTile = N, largest = 1;
	for (int i = N; i; i--) {
		int step = 0;
		while (curTile && depth[i].F < snow[curTile].F) {
			int cur = snow[curTile].S;
			aft[bef[cur]] = aft[cur]; 
			bef[aft[cur]] = bef[cur];
			largest = max(largest, aft[cur] - bef[cur]);
			curTile--;
		}
		if (largest <= dist[depth[i].S]) works[depth[i].S] = 1;
	}

	
	rep(i,1,B+1) {
		if (works[i]) cout << 1 << endl;
		else cout << 0 << endl;
	}

    return 0;
}