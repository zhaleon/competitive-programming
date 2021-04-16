#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <assert.h>
#include <string>
#include <cstring>
#include <stack>
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

int N, M;
int c[100001][2];
int a[100001]; // Who gets each cereal 

int numCows = 0;
void bump(int cereal, int cow) {
	if (!a[cereal]) {
		numCows++;
		a[cereal] = cow;
	} else if (a[cereal] < cow) {
		return;
	} else {
		int curCow = a[cereal];
		a[cereal] = cow;
		if (a[c[curCow][1]] == a[c[curCow][0]]) return;
		bump(c[curCow][1], curCow);
	}	

}

int main() {
	setIO("cereal");
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
    loop(i,1,N+1) cin >> c[i][0] >> c[i][1];
	
	stack<int> answer;

	for (int i = N; i > 0; i--) {
		bump(c[i][0], i);
		answer.push(numCows);	
	}
	while(!answer.empty()) {
		cout << answer.top() << endl;
		answer.pop();
	}
    return 0;
}








