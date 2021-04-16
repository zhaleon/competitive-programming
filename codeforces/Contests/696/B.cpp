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

int T, D;

bool is_prime[200001];
vector<ll> primes;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;

	rep(i,2,200000) {
		if (is_prime[i]) {
			primes.PB(i);
			for (int j = i + i; j <= 200000; j += i) {
				is_prime[j] = 0;
			}
		}
	}

	cin >> T;
	
	while (T--) {
		cin >> D;

		ll ans = 1;
	
		ll a = *lower_bound(primes.begin(), primes.end(), D+1);
		ll b = *lower_bound(primes.begin(), primes.end(), a+D);

		cout << min(a*b, a*a*a) << '\n'; 
	}

    return 0;
}








