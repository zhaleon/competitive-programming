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
#define loop(i,a,b) for (int i = a; i < b; i++)

ll f[100001], id[100001]; 
unordered_map<int, bool> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	ll N, K;
	const int MOD = 1e9 + 7;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> id[i];
		m[id[i]] = 1;
	}
	f[1] = 2;
	f[2] = 3;
	for (int i = 3; i <= N; i++) {
		f[i] = f[i-1] + f[i-2];
		f[i] %= MOD;
	}
	sort(id, id+N+1);
	ll answer = 1;
	int noChain = N;
	//loop(i,0,N+1) cout << id[i] << ' ';
	//cout << endl;
	for (int i = 1; i <= N; i++) {
		if (m[id[i]+K]) {
			int y = id[i];
			int c = 0;
			while (m[y]) {
	//			cout << y << endl;
				m[y] = 0;
				y += K;
				c++;
			}
			//cout << "C " << c << endl; 
			answer *= f[c];
			answer %= MOD;
			noChain -= c;
		} else {
			
		}
	}
	long long x = 1;
	bool MSB = 1;
	for (int i = 30; i >= 0; i--) {
		if (noChain & (1 << i)) {
			if (MSB) {
				MSB = 0;
				x *= 2;
				x %= MOD;
			} else {
				x *= x;
				x *= 2;
				x %= MOD;
			}
		} else {
			if (!MSB) {
				x *= x;
				x %= MOD;
			}
		}
	}
	cout << ((answer * x) % MOD - 1) << endl;

    
    return 0;
}








