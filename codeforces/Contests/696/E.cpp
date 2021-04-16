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

int T, N;

int arr[100001];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while(T--) {
		cin >> N;
		ll score = 0;
	
		iota(arr+1, arr+1+N, 1);
		
		vpi ops;

		rep(i,1,N-1) {
			if (N-i > i-1) {
				swap(arr[i], arr[N]);
				ops.PB({N, i});
			} else {
				swap(arr[i], arr[1]);
				ops.PB({1, i});
			}

			score += max((ll)(N-i)*(N-i), (ll)(i-1)*(i-1));
		}

		reverse(ops.begin(), ops.end());

		cout << score << endl;
		rep(i,1,N) cout << arr[i] << " \n"[i == N];

		cout << N-1 << endl;
		for (auto &p : ops) 
			cout << p.S << ' ' << p.F << endl;
	}

    return 0;
}








