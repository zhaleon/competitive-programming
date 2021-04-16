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

ll A, B, N, M;

vector<ll> hori(1,0); //hori lines and y coords of them
vector<ll> vert(1,0); //vertical lines and x coords of them

int main() {
	setIO("fencedin");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> A >> B >> N >> M;
	
	int a;
	rep(i,0,N) {
		cin >> a;
		vert.PB(a);
	} vert.PB(B); 

	rep(i,0,M) {
		cin >> a;
		hori.PB(a);
	} hori.PB(A);
	
	sort(vert.begin(), vert.end());
	sort(hori.begin(), hori.end());
	
	rep(i,0,N+1) vert[i] = vert[i+1]-vert[i];
	rep(i,0,M+1) hori[i] = hori[i+1]-hori[i];
	
	vert.pop_back();
	hori.pop_back();
	
	sort(vert.begin(), vert.end());
	sort(hori.begin(), hori.end());
	
	ll ans = vert[0]*M + hori[0]*N; //first in each direction special case
	
	int i = 1, j = 1;
	
	while (i < N+1 && j < M+1) {
		if (vert[i] < hori[j]) ans += vert[i++]*(M+1-j);
		else ans += hori[j++]*(N+1-i);
	}
	
	cout << ans << endl;

	return 0;
}








