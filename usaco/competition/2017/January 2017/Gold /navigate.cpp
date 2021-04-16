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

int grid[20][20];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int vis[20][20][20][20][4][4];

// 0 -> right; 1 -> up; 2 -> left; 3 -> down;


typedef struct state {
	int x, y, a, b, d1, d2, steps;
	state() {};
	state(int _x, int _y, int _a, int _b, int _d1, int _d2, int s) : x(_x), y(_y), a(_a), b(_b),  d1(_d1), d2(_d2), steps(s) {};
} state;

bool g(int a, int b) {
	return a < N && b < N && a >= 0 && b >= 0 && grid[a][b];
}

int main() {
	setIO("cownav");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	char aa;
	for (int i = N-1; i >= 0; i--) {	
		rep(j,0,N) {
			cin >> aa;
			if (aa == 'E') grid[i][j] = 1;
		} 
	} 
    
	queue<state> bfs;
	bfs.push(state(0, 0, 0, 0, 1, 0, 0));

	while(!bfs.empty()) {
		state cur = bfs.front(); bfs.pop();

		int curSteps = vis[cur.x][cur.y][cur.a][cur.b][cur.d1][cur.d2];	
		
		int fX = cur.x, fY = cur.y, sX = cur.a, sY = cur.b;
		

		if (fX != N-1 || fY != N-1) {
			if (fX + dx[cur.d1] >= 0 && fX + dx[cur.d1] < N) fX += dx[cur.d1];
			if (fY + dy[cur.d1] >= 0 && fY + dy[cur.d1] < N) fY += dy[cur.d1];
			if (!grid[fX][fY]) {
				fX = cur.x; fY = cur.y;
			}
		}

		if (sX != N-1 || sY != N-1) {
			if (sX + dx[cur.d2] >= 0 && sX + dx[cur.d2] < N) sX += dx[cur.d2];
			if (sY + dy[cur.d2] >= 0 && sY + dy[cur.d2] < N) sY += dy[cur.d2];
			if (!grid[sX][sY]) {
				sX = cur.a; sY = cur.b;
			}
		}

		if (!vis[fX][fY][sX][sY][cur.d1][cur.d2]) {
			vis[fX][fY][sX][sY][cur.d1][cur.d2] = curSteps+1;
			bfs.push(state(fX, fY, sX, sY, cur.d1, cur.d2, curSteps+1));
		}
		

		if (!vis[cur.x][cur.y][cur.a][cur.b][(cur.d1+1)%4][(cur.d2+1)%4]) {
			vis[cur.x][cur.y][cur.a][cur.b][(cur.d1+1)%4][(cur.d2+1)%4] = curSteps+1;
			bfs.push(state(cur.x, cur.y, cur.a, cur.b, (cur.d1+1)%4, (cur.d2+1)%4, cur.steps+1));
		}
		if (!vis[cur.x][cur.y][cur.a][cur.b][(cur.d1+3)%4][(cur.d2+3)%4]) {
			vis[cur.x][cur.y][cur.a][cur.b][(cur.d1+3)%4][(cur.d2+3)%4] = curSteps+1;
			bfs.push(state(cur.x, cur.y, cur.a, cur.b, (cur.d1+3)%4, (cur.d2+3)%4, cur.steps+1));
		}

	}

	int ans = INF;
	
	rep(i,0,4) rep(j,0,4) {
		//cout << "TEST: " << vis[N-1][N-1][N-1][N-1][i][j] << ' ' << ans << endl;
		
		if (!vis[N-1][N-1][N-1][N-1][i][j]) continue;
		ans = min(vis[N-1][N-1][N-1][N-1][i][j], ans);
	}

	cout << ans << endl;

    return 0;
}








