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
int grid[1001][1001];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool in_bounds(int i, int j, int k) {
	return i + dx[k] > 0 && i + dx[k] <= N && j + dy[k] > 0 && j + dy[k] <= M;
}

void flood(int i, int j, int color) {
	grid[i][j] = 2;
	rep(k,0,3)	
		if (in_bounds(i,j,k) && grid[i+dx[k]][j+dy[k]] == 1) 
			flood(i+dx[k], j+dy[k], color);
		
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	rep(i,1,N) {
		rep(j,1,M) {
			char a; cin >> a;
			if (a == '.') 
				grid[i][j] = 1;
		}
	}

	int ans = 0;
	
	rep(i,1,N) {
		rep(j,1,M) {
			if (grid[i][j] == 1) {
				flood(i,j,ans);
				ans++;
			}
		}
	}

	cout << ans << endl;

    return 0;
}








