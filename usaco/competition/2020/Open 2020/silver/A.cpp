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

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

ll N, M;
pair<ll, ll>  grass[100000];

bool works(ll D) {
	int cows = N;
	ll lastCow;
	for (int i = 0; i < M && cows > 0; i++) {
		if (i > 0) {
			if (grass[i].S < lastCow + D) {
				continue;
			} else if (grass[i].F < lastCow + D) {
				ll numCows = (grass[i].S - lastCow - D)/D + 1;
				cows -= numCows;
				lastCow += (numCows-1)*D + D;
			} else {
				ll numCows = (grass[i].S-grass[i].F)/D + 1;
				cows -= numCows;
				lastCow = grass[i].F + (numCows-1)*D;
			}
		} else {
			ll numCows = (grass[i].S-grass[i].F)/D + 1;
			cows -= numCows;
			if (i == 0) lastCow = grass[i].F + (numCows-1)*D;
		}
	}
	if (cows <= 0) return 1;
	return 0;
}

int main() {
	setIO("socdist");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	loop(i,0,M) {
		cin >> grass[i].F >> grass[i].S;
	}
	sort(grass, grass+M);
	
	ll low = 0, high = 1e18;
	while (low+1 < high) {
		ll mid = (low + high)/2;
		//cout << mid << ' ' << (works(mid)) << endl;
		if (works(mid)) {
			low = mid;
		} else {
			high = mid;
		}
	}
	
   	cout << ((works(low)) ? low : high) << endl;
   	//cout << works(69) << endl;
	//cout << low << ' ' << high << endl;
	return 0;
}

















