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

int p[1000001];
int s[1000001];

map<int, int> m;


int bit[1000001];

void upd(int po, int sz) {
	while (po < sz) {
		bit[po] += 1;
		po += po & -po;
	}
}

int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}

int rangeSum(int i, int j) {
	return sum(j) - sum(i-1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	ifstream fin ("stonks.in");
	ofstream fout ("stonks.out");

	fin >> N;

	rep(i,1,N+1) { 
	   	fin >> p[i];
    	s[i] = p[i];
	}

	sort(p+1, p+1+N);

	rep(i,1,N+1) {
		m[p[i]] = i;
	}
	
	int ans = 0;
	int day = 0;
		
	for (int i = N; i > 0; i--) {
		upd(m[s[i]], N+1);
		//cout << s[i] << ' ' << m[s[i]] << endl;
		
		int goodDay = rangeSum(m[s[i]], N);

		if (goodDay > ans) {
			day = i;
			//cout << day << " " << goodDay << endl;
			ans = goodDay;
		}

	}
		
	fout << day << endl;
    return 0;
}








