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

ll N, K, M;

bool works(ll X) {
	ll tot = 0;
	for (ll i = 0; i < K && tot < N;) {
		ll Y = (N-tot)/X;
		if (Y <= M) {
			return (K-i)*M + tot >= N;
		}
		
		ll numDays = (((double)(N-tot))/X - Y)*X/Y+1;
	   	i += numDays;	
		tot += numDays*Y;
	}
	return tot >= N;
}

int main() {
	setIO("loan");
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K >> M;

	ll low = 1, high = 1e12;
   	while (low+1 < high) {
		ll mid = (low + high)/2;
	   	if (works(mid)) {
			low = mid;
		} else {
			high = mid;
		}
	}

	cout << low << endl;
    return 0;
}








