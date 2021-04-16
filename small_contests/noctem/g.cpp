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

int N;

ll m[4000];

int L[4000];

//vector<ll> dp[4000];

//pair<vector<ll>, ll> dp[4000];

ll dp[4000]; 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

   	ifstream fin ("spring.in");
   	ofstream fout ("spring.out");

	fin >> N;

	rep(i,0,N) fin >> m[i];
	rep(i,0,N) dp[i] = m[i];
	//dp[0].PB(m[0]);


	rep(i,1,N+1) {
		rep(j,0,i) {
			if (dp[i] <= dp[j] + m[i] && m[i] >= m[j]) dp[i] = dp[j] + m[i];
		}
	}

	ll ans = 0;

	rep(i,0,N) {
		ans = max(ans, dp[i]);
	}	
	
	fout << ans << endl;


    return 0;
}








