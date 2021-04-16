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
#define loop(i,a,b) for (int i = a; i < b; i++)

int n, k;

vi adj[200001];
int visited[200001];
int depth[2000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> k;
	ll sum = 0;
	loop(i,0,n-1) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}
		queue<pii> q;
		q.push(MP(1,0));
		while(!q.empty()) {
			pii cur = q.front();
			q.pop();
			depth[cur.S]++;
			visited[cur.F] = 1;
			for (int j = 0; j < adj[cur.F].size(); j++) {
				if (!visited[adj[cur.F][j]]) {
					q.push(MP(adj[cur.F][j], cur.S + 1));
				}
			}

		}
		for (int j = n; j>= 0; j--) {
			if (k == 0) break;
			if (k > depth[j]) {
				k -= depth[j];
				sum += depth[j]*j;
			} else {
				sum += k*j;
				k = 0;
			}
		}
	
	cout << sum << endl; 
	return 0;
}








