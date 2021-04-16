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
#include <cstdio>
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
	freopen((name+"in").c_str(), "r", stdin); 
	freopen((name+"out").c_str(), "w", stdout);
}

int N;
int c[100000];

int main() {
	//setIO("shadow");
    ios::sync_with_stdio(0); cin.tie(0);
	
	ifstream fin ("shadow.in");
	ofstream fout("shadow.out");
	fin >> N;

	loop(i,0,N) fin >> c[i];

	int x = c[0] + c[1] + c[2] + c[3] + c[4];

	int ans = x;

	for (int i = 5; i < N; i++) {
		x -= c[i-5];
		x += c[i];
		ans = max(ans, x);
	}
   	
    fout << ans << endl;

    return 0;
}

















