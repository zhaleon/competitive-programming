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

int N, K, R;

int farm[101][101][4]; // N, E, W, S
int visited[101][101];

int dy[] = {1, 0, 0, -1};
int dx[] = {0, 1, -1, 0};

vpi locations;

bool distant(pii a, pii b) {
	memset(visited, 0, sizeof(visited));
	
	queue<pii> bfs;
	pii cur = a; bfs.push(a);	
	visited[a.F][a.S] = 1;

	while (!bfs.empty()) {
		cur = bfs.front(); bfs.pop();
		if (cur.F == b.F && cur.S == b.S) return true;
		rep(i,0,4) {
			if (cur.S + dy[i] > N || cur.S + dy[i] < 1) continue;
			if (cur.F + dx[i] > N || cur.F + dx[i] < 1) continue;

			if (!farm[cur.F][cur.S][i] && !visited[cur.F + dx[i]][cur.S + dy[i]]) {
				bfs.push(MP(cur.F + dx[i], cur.S + dy[i]));
				visited[cur.F + dx[i]][cur.S + dy[i]] = 1;
			}	
		}
	}

	return false;
}

int main() {
	setIO("countcross");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K >> R;
    
	int a,b,c,d;

	rep(i,0,R) {
		cin >> a >> b >> c >> d;
		
		if (c == a+1) {
			farm[a][b][1] = 1;
			farm[c][d][2] = 1;
		} else if (c == a-1) {
			farm[a][b][2] = 1;
			farm[c][d][1] = 1;
		} else if (d == b-1) {
			farm[a][b][3] = 1;
			farm[c][d][0] = 1;
		} else if (d == b+1) {
			farm[a][b][0] = 1;
			farm[c][d][3] = 1;
		}
	}
	

	rep(i,0,K) {
		cin >> a >> b;
		locations.PB(MP(a,b));
	}
	
	int ans = 0;

	rep(i,0,locations.size()) {
		rep(j,i+1, locations.size()) {
			if (!distant(locations[i], locations[j])) ans++;
		}
	}

	cout << ans << endl;

    return 0;
}








