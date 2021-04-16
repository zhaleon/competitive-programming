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

int T;
int N, M, R, C;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N >> M >> R >> C;
		cout << max(max(abs(N-R)+abs(M-C), R-1+C-1), max(abs(N-R)+C-1, abs(M-C) + R-1)) << endl;

	}
    
    return 0;
}








