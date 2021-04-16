#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

// multisource bfs

int N, D;

int grid[1001][1001];
int best[1001][1001]; //store best time

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y) {
	return x <= N && x > 0 && y <= N && y > 0 && !grid[x][y]; 
}

struct data {
	int x, y, t;
	data() {};
	data(int x, int y, int t) : x(x), y(y), t(t) {};
};

int pref_l[2001][2001]; //row + col - 1
int pref_r[2001][2001]; //row - col + N

bool has_rock(int x, int y, int r, int k) {
	if (k == 0) {
	


			
	} else if (k == 1) {

	} else if (k == 2) {

	} else {
	
	}
	return 1;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> D;

	queue<data> bfs;

	rep(i,1,N) {
		rep(j,1,N) {
			char a;
			cin >> a;
			if (a == '#') {
				grid[i][j] = 1;
				pref_l[i+j-1][i]++;
				pref_r[i-j+N][i]++;
			} else if (a == 'S') {
				bfs.push(data(i,j,0));
				best[i][j] = 1;
			}
		}
	}

	rep(i,1,2*N-1) {
		rep(j,1,N) {
			pref_l[i][j] += pref_l[i][j-1];
			pref_r[i][j] += pref_r[i][j-1];
		}
	}

	while (bfs.size()) {
		data cur = bfs.front(); bfs.pop();

		for (int k = 0; k < 4; k++) {
			int x = cur.x + dx[k], y = cur.y + dy[k];

			if (valid(x,y) && best[x][y]) {
				best[x][y] = max(cur.t+1);

			}
			if (valid(x,y) && !best[x][y]) {
				best[x][y] = cur.t + 1;
				if (!has_rock(x,y,k, (cur.t + 1)/D))
					bfs.push(data(x,y,cur.t + 1));
			}
		}
	}

    
    return 0;
}








