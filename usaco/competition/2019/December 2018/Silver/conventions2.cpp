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
	int a, t, s;
	cow() {};
	cow(int a1, int t1, int s1) : a(a1), t(t1), s(s1) {};
} cow;

auto pcomp = [](cow a, cow b) -> bool {return a.s > b.s;};
bool comp (cow a, cow b) {
	return a.a < b.a;
}

priority_queue<cow, vector<cow>, decltype(pcomp)> q(pcomp); 

int N;
cow cows[100000];

int main() {
	setIO("convention2");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	int a, b;
	rep(i,0,N) {
		cin >> a >> b;
		cows[i] = cow(a, b, i);
	}	

	sort(cows, cows+N, comp);

	int ans = 0, time = 0;
	
	cow curCow = cows[0];
	time += curCow.a;
	int i = 1;
	int j = 0;
	while (i < N || !q.empty()) {	
		while (i < N && (cows[i].a <= time + curCow.t)) {
			q.push(cows[i]);
			i++;
		}
		//cow i does not have to wait for curCow to finish

		time += curCow.t;
		//cout << i <<  " CURCOW: " << curCow.a <<  " TIME: " << time << endl;

	    if (!q.empty()) {	
			curCow = q.top();
			//cout << "ARRIVE: " << curCow.a << " DURATION: " << curCow.t << endl;
			q.pop();
			ans = max(ans, (time - curCow.a));
		} else {
			j++;
			curCow = cows[i];
			assert(curCow.a >= time);
			time = curCow.a;
			i++;
		}
		//cout << curCow.a << endl;
		//i++; 
	}
	cout << ans << endl;
	
	return 0;
}








