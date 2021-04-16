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

int used[100001];

vi e;
vi b;

int main() {
	setIO("highcard");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	int a;
	rep(i,0,N) {
		cin >> a;
		e.PB(a);
		used[a] = 1;
	}
    
	rep(i,1,2*N+1) {
		if (!used[i]) b.PB(i);
	}

	sort(e.begin(), e.end());
	sort(b.begin(), b.end());

	int ans = 0;

	int p1 = 0, p2 = 0;

	while (p1++ < N && p2++ < N) {
		while (p2 < N && b[p2] < e[p1]) p2++;
		ans++; 
	}
	cout << ans << endl;
    return 0;
}








