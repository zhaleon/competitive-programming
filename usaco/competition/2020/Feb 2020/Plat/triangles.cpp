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
#define rep(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

int N;

bool grid[301][301];
int lef[601][301]; //diagonal from bottom left to top right
int rig[601][301];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	rep(i,1,N+1) {
		rep(j,1,N+1) {
			char a; cin >> a;
			grid[i][j] = a == '.';
		}
	}

	for (int sum = 2; sum <= 2*N; sum++) {
		for (int i = 1; i < sum; i++) {
			lef[sum][i] = lef[sum][i-1] + grid[sum-1][i];
		}
	}
    
    return 0;
}








