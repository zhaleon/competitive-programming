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

int T, N, M;
int c[300001];
int k[300001];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N >> M;
		rep(i,1,N) cin >> k[i];
		rep(i,1,M) cin >> c[i];
		
		ll res = 0;
		rep(i,1,N) {
			int cost = c[k[i]];
		}
	}
   

    return 0;
}








