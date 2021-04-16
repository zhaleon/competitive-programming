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

vi b;
vi e;

bool used[500001];

int main() {
	setIO("cardgame");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	int a;
	rep(i,0,N) { 
	   	cin >> a; 
		e.PB(a);
		used[a]=1;
	}

	for (int i = 2*N; i > 0; i--) {
		if (!used[i]) b.PB(i);
	}
	
	sort(b.begin(), b.begin() + N/2);
	sort(b.begin() + N/2, b.end(), greater<int>());
	
	sort(e.begin(), e.begin() + N/2);
	sort(e.begin() + N/2, e.end(), greater<int>());

	int ans = 0;
	
	int p = 0, p2 = 0;
	
	while (p < N/2 && p2 < N/2) {
		while (p < N/2 && b[p] < e[p2]) p++;
		if (p == N/2) break;
		ans++;
		p++; p2++;
	}
	
	p = N/2; p2 = N/2; 
	
	while (p < N && p2 < N) {
		while (p < N && b[p] > e[p2]) p++;
		if (p == N) break;
		ans++;
		p++; p2++;
	}
	
	cout << ans << endl;	


	return 0;
}








