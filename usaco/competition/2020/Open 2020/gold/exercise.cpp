#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <assert.h>
#include <string>
#include <cstring>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <deque>
#include <cmath>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

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

int N, M;

ll test = 0;

bool isPrime[10001];
vi primes;

unordered_map<ll, bool> m;

void search(int k, ll res, ll product) { //current power, total sum so far
	if (!m[product]) {
		test += product;
		test %= M;
	} 
	m[product] = 1;
	if (k == primes.size()) return;
	search(k+1, res, product);
	for (ll cur = primes[k]; res + cur <= N; cur *= primes[k]) {
		search(k+1, res + cur, product * cur);
	}
}

ll dp[1230][10001]; // dp[i][j] = sum of numbers with [use i primes][sum j]

int main() {
	setIO("exercise");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	
	rep(i,2,10001) isPrime[i] = 1;
	
	for (int i = 2; i <= N; i++) {
		if (isPrime[i]) {
			primes.PB(i);
			for (int j = i*i; j <= N; j += i) {
				isPrime[j] = 0;
			}
		}
	}
	
	//search(0, 0, 1);
	//cout << test << endl;
	rep(i,0,N+1) dp[0][i] = 1;
	for (int p = 0; p < primes.size(); p++) {
		for (int i = 0; i <= N; i++) {
			dp[p+1][i] = dp[p][i]; //not using this prime
			ll cur = primes[p];
			while (cur <= i) {
				dp[p+1][i] += (cur * dp[p][i-cur]);
				dp[p+1][i] %= M;
				cur *= primes[p];
			}
		}
	}
	
	cout << dp[primes.size()][N] << endl;
	
    return 0;
}