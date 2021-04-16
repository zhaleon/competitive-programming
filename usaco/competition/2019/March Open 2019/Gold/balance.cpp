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

bool arr[200000];

int main() {
	setIO("balance");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	rep(i,0,2*N) cin >> arr[i]; 

	int b = 0, e = 0;
	
	int leftOnes = 0, leftZeros = 0, rightOnes = 0, rightZeros = 0, zeros = 0;
	rep(i,0,N) { //left side
		if (arr[i]) leftOnes++;
		else b += leftOnes, leftZeros++;
	} 
	rep(i,N,2*N) {
		if (arr[i]) rightOnes++;
		else e += rightOnes, rightZeros++;
	} 	
	zeros = leftZeros + rightZeros;

	ll dif = e-b, ans = INF;
	
	if (dif == 0) {
		cout << 0 << endl; 
		return 0;
	}
	
	ans = min(ans, abs(dif));
	
	int lef = N-1, rig = N; //maintain pointer at left sides 1 and right sides 0
	while (lef > 0 && !arr[lef]) lef--;
	while (rig < 2*N && arr[rig]) rig++;
	
	ll cost = 0;
	ll curDif = e-b;
	for (int i = 1; i <= min(rightZeros, leftOnes); i++) { //move ones from left to right side
		
		curDif += ((N-1-lef) - (rig-N) + (zeros-N));
		cost += (N-1-lef) + (rig-N) + 1;
		
		//advance pointers to next 1 and 0 respectively
		if (i < min(rightZeros, leftOnes)) {
			do {lef--;} while(lef > 0 && !arr[lef]);
			do {rig++;} while(rig < 2*N && arr[rig]);
		}
		
		ans = min(ans, cost + abs(curDif)); //making no more swaps across middle
	}
	
	lef = N-1, rig = N;
	curDif = e-b;
	cost = 0;
	
	while (lef > 0 && arr[lef]) lef--;
	while (rig < 2*N && !arr[rig]) rig++;
	
	for (int i = 1; i <= min(leftZeros, rightOnes); i++) { //move zeros from left to right
		
		curDif += (-1*(N-1-lef) + (rig-N) - (zeros-N));
		cost += (N-1-lef) + (rig-N) + 1;
		
		if (i < min(leftZeros, rightOnes)) {
			do {lef--;} while(lef > 0 && arr[lef]);
			do {rig++;} while(rig < 2*N && !arr[rig]);
		}
		
		ans = min(ans, cost + abs(curDif));
	}

	cout << ans << endl;

    return 0;
}