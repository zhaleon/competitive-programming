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

int N, D;

typedef struct pie {
	int b, e, idx;
	pie() {};
	pie(int a, int d, int c) : b(a), e(d), idx(c) {};
} pie;

pie pies[200001];

int dist[200001];

bool comp1(pie a, pie b) {
	return a.b < b.b;
}

bool comp2(pie a, pie b) {
	return a.e < b.e;
}

bool works(int v, bool bessie, int val) {
	if (bessie) return val - pies[v].b <= D && val >= pies[v].b;
	return val - pies[v].e <= D && val >= pies[v].e;
}

pii bounds(int val, int idx) { // if idx <= N, then bessie is giving 
	int c = 1;
	pii res;
	int add = 0;
	bool bessie = (idx <= N);
	if (bessie) add = N;
	
	int low = add + 1, high = N + add + 1;
	
	while (low+1 < high) {
		int mid = (low+high)/2;
		if (bessie) {
			if (pies[mid].b > val) high = mid;
			else low = mid;
		} else {
			if (pies[mid].e > val) high = mid;
			else low = mid;
		}
	}
	
	if (bessie && pies[add+1].b > val) return MP(1,0); //see if everything is bigger
	else if (!bessie && pies[add+1].e > val) return MP(1,0);
	
	int end = low-add;
	low = add, high = end + add;
	while (low + 1 < high) {
		int mid = (low+high)/2;	
		if (works(mid, bessie, val)) {
			high = mid;
		} else {
			low = mid;
		}
	}
	res.F = high;
	if (!works(end+add, bessie,val)) res.F = INF; //everything too small
	
	low = high, high = N + add + 1;
	while (low + 1 < high) {
		int mid = (low+high)/2;	
		if (works(mid, bessie, val)) {
			low = mid;
		} else {
			high = mid;
		}
	}		
	res.S = low;
	return res;
}

int main() {
	setIO("piepie");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> D;
	
	int a, b, c;
	rep(i,1,N+1) { //bessie in the first N
		cin >> a >> b;
		pies[i] = pie(a,b,i);
	}
	rep(i,N+1,2*N+1) {
		cin >> a >> b;
		pies[i] = pie(a,b,i);
	}
	
	sort(pies+1, pies+1+N, comp2);
	sort(pies+1+N, pies+1+2*N, comp1);
	
	queue<pie> bfs;
	
	rep(i,1,2*N+1) dist[i] = -1;
	
	rep(i,1,2*N+1) {
		if (i <= N) {
			if (pies[i].e == 0) {
				dist[pies[i].idx] = 1;
				bfs.push(pies[i]);
			}
		} else {
			if (pies[i].b == 0) {
				dist[pies[i].idx] = 1;
				bfs.push(pies[i]);
			}
		}
	}

	while (!bfs.empty()) {
		pie cur = bfs.front(); bfs.pop();
		pii nxt;
		
		if (cur.idx <= N) nxt = bounds(cur.b, cur.idx);
		else nxt = bounds(cur.e, cur.idx);
		
		for (int i = nxt.F; i <= nxt.S; i++) {
			if (dist[pies[i].idx] < 0) {
				dist[pies[i].idx] = dist[cur.idx]+1;
				assert(dist[pies[i].idx] > 0);
				bfs.push(pies[i]);
			}
		}
	}
	
	for (int i = 1; i <= N; i++) cout << dist[i] << endl;
	
    return 0;
}