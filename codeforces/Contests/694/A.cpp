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

int T, N, X;
ll arr[100001];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N >> X;
		rep(i,1,N) cin >> arr[i];
	
		ll res = 0;
		ll tot = 0;

		rep(i,1,N) {
			res += (arr[i]+X-1)/X;
			tot += arr[i];
		}

		cout << tot/X << ' ' << res << endl;

	}
    
    return 0;
}








