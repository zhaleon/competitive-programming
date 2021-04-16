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

int nums[1000002];
int pref0[1000002];
int pref1[1000002];

int parent[1000008];

bool valid(int i, int j) {
	return (pref0[j]-pref0[i-1]) == (j-i+1) || (pref1[j]-pref1[i-1]) == (j-i+1);
}

int find(int x) {
	if (x > N) return N;
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

int main() {
    //ios::sync_with_stdio(0); cin.tie(0);

	scanf("%i\n", &N);
	
	char a;
	rep(i,1,N+1) {
		scanf("%c", &a);
		if (a == '1') nums[i] = 1;
		else if (a == '0') nums[i] = 0;
		else nums[i] = 2;
	}
	
	rep(i,1,N+1) {
		pref0[i] = pref0[i-1];
		pref1[i] = pref1[i-1];
		if (nums[i] != 1) pref0[i]++;
		if (nums[i] != 0) pref1[i]++;
	}
	
	rep(i,1,N+5) parent[i] = i; 
	
	printf("%i ", N);
	rep(i,2,N+1) {
		int ans = 0;
		
		rep(j,1,N+2-i) {
			
			if (find(j) != j) j = find(j);
			
			if (valid(j, j+i-1)) {
				j += i-1;
				ans++;
			} else {
				parent[j] = find(j+1);
			}
		}
		
		printf("%i ", ans);
	}
    return 0;
}