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

int cost[128][64];
int dp[2001][2001][10];
int board[2001];

void precompute() {
	
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	loop(i,0,n) {
		string a;
		cin >> a;
	    loop(j,0,7) {
		   if(a[j] == '1') {
			   board[i] += (1 << (6-j));
		   }
	    }
	}
	precompute();

	
    
    return 0;
}








