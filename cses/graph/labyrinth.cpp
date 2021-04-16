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

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

int N, M;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int grid[1001][1001];
int  dir[1001][1001];

bool unseen(int i, int j, int k) {
	return i+dx[k] > 0 && i+dx[k] <= N && j+dy[k] > 0 && j+dy[k] <= M && grid[i+dx[k]][j+dy[k]] == 1; 	
}


void search(int i, int j) {
	queue<pii> q;
	q.push(MP(i,j));
	int v = 0;
	while (q.size()) {
		auto cur = q.front(); q.pop();
		grid[cur.F][cur.S] = 0;

		rep(k,0,3) {
			if (unseen(cur.F, cur.S, k) && dir[cur.F + dx[k]][cur.S + dy[k]] > 5) {
				dir[cur.F + dx[k]][cur.S + dy[k]] = k;
				q.push(MP(cur.F+dx[k], cur.S+dy[k]));
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	int sx, sy, fx, fy;
	memset(dir, 0x3f, sizeof(dir));

	rep(i,1,N) {
		rep(j,1,M) {
			char a; cin >> a;
			if (a != '#')
				grid[i][j] = 1;
			if (a == 'A')
				sx = i, sy = j;
			else if (a == 'B')
				fx = i, fy = j;
		} 
	}

	search(sx, sy);
	
	if (dir[fx][fy] > 5) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		string ans = "";

		while (fx != sx || fy != sy) {
			assert(dir[fx][fy] < 5);
			if (dir[fx][fy] == 0)
				ans += "D";
			else if (dir[fx][fy] == 1)
				ans += "U";
			else if (dir[fx][fy] == 2)
				ans += "R";
			else
				ans += "L";
			
			int k = dir[fx][fy];
			fx -= dx[k], fy -= dy[k];
		}
		
		reverse(ans.begin(), ans.end());

		cout << ans.length() << endl;
		cout << ans << endl;
	}

    return 0;
}








