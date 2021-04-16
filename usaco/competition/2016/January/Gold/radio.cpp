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
string a, b;

int fx, fy, bx, by;

int pos(int x, int y) {
	return 1001*x + y;
}

ll dist(int x, int y) {
	return (x % 1001 - y % 1001) * (x % 1001 - y % 1001) + (x / 1001 - y / 1001) * (x/1001 - y/1001);
}

ll dp[1001][1001];
int l[1001];
int h[1001];

map<char, int> dx;
map<char, int> dy;

int main() {
	setIO("radio");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> fx >> fy >> bx >> by;
	cin >> a >> b;

	dx['N'] = 0; dy['N'] = 1;
	dx['E'] = 1001; dy['E'] = 0;
	dx['S'] = 0; dy['S'] = -1;
	dx['W'] = -1001; dy['W'] = 0;

	int f = pos(fx, fy);
	int c = pos(bx, by);
	l[0] = f;
	h[0] = c;
	rep(i,1,N+1) l[i] = l[i-1] + dx[a[i-1]] + dy[a[i-1]];	
	rep(i,1,M+1) h[i] = h[i-1] + dx[b[i-1]] + dy[b[i-1]];

	rep(i,0,1001) rep(j,0,1001) dp[i][j] = INF;
	
	dp[0][0] = 0;	
	rep(i,0,N) {
		rep(j,0,M) {
			dp[i+1][j] = min(dp[i+1][j], dp[i][j] + dist(l[i+1], h[j]));
			dp[i][j+1] = min(dp[i][j+1], dp[i][j] + dist(l[i], h[j+1]));
			dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + dist(l[i+1], h[j+1]));
		}
	}
	cout << dp[N][M] << endl;
    return 0;
}








