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

int N, Q;

int arr[100001];

int segtree[60][100001];

vi primes;

bool is_prime[100001];
int divisor[100001];

void sieve() {
	is_prime[0] is_prime[1] = 0;
	for (int i = 2; i <= N; i++) {
		if (is_prime[i] && (ll)i*i <= N) {
			primes.PB(i);
			for (int j = i*i; j <= N; j+= i) is_prime[j] = 0;
		}
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	memset(is_prime, 1, sizeof(is_prime));
    
	

    return 0;
}








