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

ll x[1000];
int N, D;
long long solve(ll D) {
	ll low = 0, high = D;
	ll ans = 0;
	while (high - low > 4) {
		ll middle = (low+high)/2;
		bool works = true;
		
		ll curDay = middle;
		for (int i = 0; i < N; i++) {
			if (curDay > D) {
				works = false;
				break;
			}
			if (curDay % x[i] == 0) {
				continue;
			} else {
				curDay = x[i] * (curDay/x[i]+1); 
			}
		}
		if (works) {
			low = middle;
		} else {
			high = middle;
		}
	}
	
	for (ll i = high; i >= low; i--) {
		bool works = true;
		ll curDay = i;
		for (int j = 0; j < N; j++) {
			if (curDay > D) { 
				works = false;
				break;
			} else if (curDay % x[i] == 0) {
				continue;
			} else {
				curDay = x[i] * (curDay/x[i]+1);
			}
		}
		if (works) return i;
	}

	
	return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int T;
	cin >> T;
	long long Case = 1;
	while(T--) {
		cin >> N >> D;
		loop(i,0,N) {
			cin >> x[i];
		}
		
		cout << "Case #" << Case << ": " << solve(D) << endl;	
		Case++;
	}

    
    return 0;
}








