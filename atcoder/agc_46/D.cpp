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

typedef struct node {
	int val;
	node* prev = NULL;
} node;

int a[101], K;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> K;
	int low = INF;
	int high = -1;
	loop(i,1,K+1) {
		cin >> a[i];
		low = min(low, a[i]);
		high = max(high, a[i]);
	}
    if (high > low*2) {
		cout << -1 << endl;
		return 0;
	}

	node head;
	head.val = 1;

    return 0;
}








