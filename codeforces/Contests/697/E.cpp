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

const int mod = 1e9+7;

int T;
int N, K;
int arr[1001];

ll fact[1001];

ll exp(ll base, int p = mod-2) {
	ll res = 1;

	while (p > 0) {
		if (p & 1)
			(res *= base) %= mod;
		(base *= base) %= mod;
		p >>= 1;
	}

	return res;
}

ll choose(int N, int K) {
	return fact[N] * exp(fact[K]) % mod * exp(fact[N-K]) % mod;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	fact[0] = 1;
	rep(i,1,1000) fact[i] = i * fact[i-1] % mod;

	while (T--) {
		cin >> N >> K;
		rep(i,1,N) cin >> arr[i];

		sort(arr+1, arr+1+N, greater<int>());

		int L = K, R = K;
		
		while (L > 0 && arr[L-1] == arr[K]) --L;
		while (R < N && arr[R+1] == arr[K]) ++R;

		cout << choose(R-L+1, K-L+1) << '\n';
	}
    
    return 0;
}








