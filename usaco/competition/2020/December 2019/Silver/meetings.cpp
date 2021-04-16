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

typedef struct cow {
	int x, w, d;
	cow() {};
	cow(int a, int b, int c) : w(a), x(b), d(c) {};
} cow;

int N, L;
int totalWeight = 0, numLeft = 0;

cow cows[50000];

bool comp(cow a, cow b) {
	return a.x < b.x;
}

int getTime() {
	vpi all;
	rep(i,0,N) {
		int l = 0, r = numLeft-1;
		r = 0;
		if (cows[i].d == -1) {
			all.PB(MP(cows[i].x, cows[i].d));
			l++;
		} else {
			all.PB(MP(L-cows[i].x, cows[i].d));
			r++;
		}
	}
	sort(all.begin(), all.end());
	
	int weightSoFar = 0;
	int l = 0, r = 0;
	rep(i,0,all.size()) {
		if (all[i].S > 0) {
			weightSoFar += cows[N-1-r].w;
			r++;
		} else {
			weightSoFar += cows[l].w;
			l++;
		}
		//weightSoFar += all[i].S;
		//cout << i << '\t' << weightSoFar << endl;
		//cout << i << '\t' << all[i].F << '\t' <<  all[i].S << endl;
		if (weightSoFar*2 >= totalWeight) return all[i].F;
	}
	return 0;
}

int main() {
    setIO("meetings");
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> L;
   	
   	int a, b, c;	
	rep(i,0,N) {
		cin >> a >> b >> c;
		cows[i] = cow(a,b,c);
		//weights[i] = a;
		totalWeight += a;
		if (c < 0) numLeft++;
	}
	sort(cows, cows+N, comp);

	int t = getTime();
	
	queue<int> moveRight;
	int ans = 0, timeSoFar = 0;
	
	rep(i,0,N) {
		if (cows[i].d == 1) {
			moveRight.push(i);
		} else {
			//int leftMost = moveRight.front(); 
			while (!moveRight.empty() && cows[i].x - cows[moveRight.front()].x > 2*t ) { 
				//timeSoFar += (cows[i].x - cows[leftMost].x);
				moveRight.pop();
				//leftMost = moveRight.front();
			}
			ans += moveRight.size();
		}
	}
	//cout << t << " TEST" << endl;
	cout << ans << endl;

    return 0;
}








