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

int N, M, R;

ll cows[100001];
pair<ll, ll> store[100001];
ll rents[100001];

ll sell[200001]; //best by selling milk from best i cows
ll rent[200001]; //best by renting worst i cows

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
	return a.S > b.S; 
}

int main() {
	setIO("rental");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M >> R;
    
	rep(i,1,N+1) cin >> cows[i];
	rep(i,1,M+1) cin >> store[i].F >> store[i].S;
	rep(i,1,R+1) cin >> rents[i];

	sort(cows+1, cows+1+N, greater<int>());
	sort(rents+1, rents+1+R, greater<int>());
	sort(store+1, store+1+M, comp);

	ll curStore = 1, leftOvers = 0;
	rep(i,1,N+1) {
		sell[i] += sell[i-1];
		if (curStore > M) break;
		if (cows[i] >= store[curStore].F) {
			leftOvers += cows[i]-store[curStore].F;
			sell[i] += store[curStore].F * store[curStore].S;	
			store[curStore].F = 0;
			curStore++;
			while (curStore <= M && leftOvers > 0) {
				if (leftOvers >= store[curStore].F) {
					sell[i] += store[curStore].F*store[curStore].S;
					leftOvers -= store[curStore].F;
					store[curStore].F = 0;
					curStore++;
				} else {
					sell[i] += leftOvers*store[curStore].S;
					store[curStore].F -= leftOvers;
					leftOvers = 0;
				}
			}
		} else {
			sell[i] += cows[i]*store[i].S;
			//if (i == 1) cout << "WHAT: " << sell[i] << endl;
			store[i].F -= cows[i];
		}
	}  
	rep(i,1,N+1) {
		rent[i] = rent[i-1] + rents[i];
	}
	ll ans = 0;
	rep(i,1,N+1) {
		if (ans < sell[i] + rent[N-i]) {
			ans = sell[i] + rent[N-i];
		}
	}
	cout << ans << endl;
    return 0;
}








