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

int N, Q;

vector<pair<pii, int>> queries, edges;
vpi answers;

int parent[100001];
int size[100001];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (size[a] > size[b]) swap(a,b);
	parent[a] = b;
	size[b] += size[a];
}

bool edgeSort(pair<pii, int> a, pair<pii, int> b) {
	return a.S > b.S;
}

bool querySort(pair<pii, int> a, pair<pii, int> b) {
	return a.F.F > b.F.F;
}

int main() {
	setIO("mootube");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;
	
	int a, b, c;
	
	rep(_,0,N-1) {
		cin >> a >> b >> c;
		edges.PB(MP(MP(a,b), c));
	}

	rep(i,0,Q) {
		cin >> a >> b;
		queries.PB(MP(MP(a,b), i));
	}

	rep(i,1,N+1) parent[i] = i, size[i] = 1;

	sort(edges.begin(), edges.end(), edgeSort);
	sort(queries.begin(), queries.end(), querySort);

	int cur = 0;
	
	rep(i,0,Q) {
		while (cur < N-1 && edges[cur].S >= queries[i].F.F) {
			if (find(edges[cur].F.F) != find(edges[cur].F.S)) merge(edges[cur].F.F, edges[cur].F.S);
			cur++;			
		}
		answers.PB(MP(queries[i].S, size[find(queries[i].F.S)]-1));
	}
	
	sort(answers.begin(), answers.end());
	
	for (auto ans : answers) cout << ans.S << endl;
    return 0;
}