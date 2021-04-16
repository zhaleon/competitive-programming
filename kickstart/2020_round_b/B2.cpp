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
ll N, D;

ll x[1000];
ll solve() {
	ll low = 1, high = D;
	ll ans = 1;
	while (high - low > 4 && D > 100) {
		ll middle = (low+high)/2;
		bool works = true;
		
		ll curDay = middle;
		for (int i = 0; i < N; i++) {
			if (curDay % x[i] == 0) {
				continue;
			} else {
				curDay = x[i] * (curDay/x[i]+1); 
			}
			if (curDay > D) {
				works = 0;
				break;
			}

		}
		
		if (works) {
			low = middle;
		} else {
			high = middle-1;
		}
	}
	
	for (ll B = high; B >= low; B--) {
	    bool works = true;
		ll curDay = B;
		for (int i = 0; i < N; i++) {
			if (curDay % x[i] == 0) {
				continue;
			} else {
				curDay = x[i] * (curDay/x[i]+1); 
			}
			if (curDay > D) {
				works = false;
				break;
			}

		}
		if (works) return B;
	}

	//cout << high << endl;	
	return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   	int T;
	cin >> T;
	int Case = 1;
	while (T--) {
		cin >> N >> D;

		loop(i,0,N) {
			cin >> x[i];
		}
		
		cout << "Case #" << Case << ": " << solve() << endl;

		Case++;
	}

		

    return 0;
}











