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

ll N, M, mod = 1e9 + 7;

ll block;

int op[100001];
ll arr[100001]; 

pair<ll, ll> res[320];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	block = sqrt(N);

	rep(i,1,N+1) {
		char a;
		cin >> a;
		cin >> arr[i];
		if (a == '+') op[i] = 1;
		else if (a == '*') op[i] = 2;
		else op[i] = 3;
	}
	
	rep(i,0,320) res[i].F = 1;
	
	rep(i,0,320) {
		if (i > block+1) break;
		for (int j = block*i + 1; j <= min(block*(i+1), N); j++) {
			if (op[j] == 1) { //addition
				res[i+1].S += arr[j];
				if (res[i+1].S > mod) res[i+1].S -= mod;
			} else if (op[j] == 2) { //multiplication
				res[i+1].F *= arr[j];
				res[i+1].F %= mod;
			} else if (op[j] == 3) { //subtraction
				res[i+1].S -= arr[j];
				if (res[i+1].S < 0) res[i+1].S += mod; 
			}
		}
	}
	
	rep(_,0,M) {
		char a, o;
		int b, c, d;
		cin >> a;
		
		if (a == 'q') {
			cin >> b >> c;
			ll cur = b;
			int i;
			for (i = 1; i*block < c; i++) {
				cur *= res[i].F;
				cur %= mod;
				cur += res[i].S;
				cur %= mod;
			}
			for (; i <= c; i++) {
				if (op[i] == 1) {
					cur += arr[i];
				} else if (op[i] == 2) {
					cur %= arr[i];
				} else {
					cur -= arr[i];
				}
				if (cur < 0) cur += mod;
				cur %= mod;
			}
			cout << cur << endl;
		} else {
			cin >> b >> c >> o;
			
			arr[b] = c;
			if (o == '+') op[b] = 1;
			else if (o == '*') op[b] = 2;
			else op[b] = 3;
			
			int curBlock = b/block+1;
			
			res[curBlock].F = 1;
			res[curBlock].S = 0;
			for (int j = curBlock*block + 1; j <= min((curBlock+1)*block, N); j++) {
				if (op[j] == 1) { //addition
					res[curBlock].S += arr[j];
					if (res[curBlock].S > mod) res[curBlock].S -= mod;
				} else if (op[j] == 2) { //multiplication
					res[curBlock].F *= arr[j];
					res[curBlock].F %= mod;
				} else if (op[j] == 3) { //subtraction
					res[curBlock].S -= arr[j];
					if (res[curBlock].S < 0) res[curBlock].S += mod; 
				}
			}
		}
		
	}

    return 0;
}