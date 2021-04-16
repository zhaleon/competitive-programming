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

int X, Y, K, M;

int vis[101][101];

void search(int i, int j, int c) {
	if (c > K) return;
	vis[i][j] = c;

	if (!vis[0][j] || vis[0][j] > c) search(0, j, c+1);
	if (!vis[X][j] || vis[X][j] > c) search(X, j, c+1);
	if (!vis[i][0] || vis[i][0] > c) search(i, 0, c+1);
	if (!vis[i][Y] || vis[i][Y] > c) search(i, Y, c+1);
	if (!vis[i+min(j,X-i)][j-min(j,X-i)] || vis[i+min(j,X-i)][j-min(j,X-i)] > c) search(i+min(j,X-i), j-min(j,X-i), c+1);
	if (!vis[i-min(i,Y-j)][j+min(i,Y-j)] || vis[i-min(i,Y-j)][j+min(i,Y-j)] > c) search(i-min(i,Y-j), j+min(i,Y-j), c+1);
}

int main() {
	setIO("pails");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> X >> Y >> K >> M;
    
	search(0,0,0);

	int ans = INF;
	
	rep(i,0,101) {
		rep(j,0,101) {
			if (vis[i][j]) ans = min(ans, abs(M-(i+j))); 
		}
	}
	
	cout << ans << endl;

    return 0;
}








