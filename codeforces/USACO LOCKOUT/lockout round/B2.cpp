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
int a, b, c;
int rations[] = {1,2,3,1,3,2,1};
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b >> c;

	int weeks = 0;
	weeks = min(min(a/3, b/2), c/2);	
    
	a -= weeks*3;
	b -= weeks*2;
	c -= weeks*2;
	int best = -1;
	for (int i = 0; i < 7; i++) {
		int a1 = a, b1 = b, c1 = c;
		int curTry = 0;
		for (int j = i; j < i+7; j++) {
			if (rations[j%7] == 1) { 
				if (a1 == 0) break;
			   	a1--;
			}
			if (rations[j%7] == 2){ 
			   	if (b1 == 0) break;
				b1--;
			}
			if (rations[j%7] == 3){ 
				if (c1 == 0) break;
			   	c1--;
			}
			curTry++;
		}
		best = max(curTry, best);
	}
	cout << weeks*7 + best << endl;
    return 0;
}








