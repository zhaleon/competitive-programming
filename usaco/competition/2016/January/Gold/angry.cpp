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
#include <iomanip>

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

int hay[50000];

double l[50000];
double r[50000];

int main() {
	setIO("angry");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	rep(i,0,N) cin >> hay[i];
    
	sort(hay, hay+N);
	l[0] = r[N-1] = 0; 
	int cur = 0;
	rep(i,1,N) {
		//check if distance is larger than the power needed
		while (cur + 1 < i && abs(hay[i]-hay[cur]) > l[cur]+1) cur++;
		l[i] = max((double)abs(hay[i]-hay[cur]), l[cur]+1); //
	}
	cur = N-1;
	
	for (int i = N-2; i >= 0; i--) {
		while (cur-1 > i && abs(hay[i]-hay[cur]) > r[cur]+1) cur--;
		r[i] = max((double)abs(hay[i]-hay[cur]), r[cur]+1);
	}
	
	l[0] = r[N-1] = 0; 

	double ans = INF;
	int i = 0, j = N-1;
	
	while (i < j) {
		int a = hay[i], b = hay[j], d = b-a; 
		ans = min(ans, (double)max( (double)max(l[i], r[j])+1, (double)d/2));
		if (l[i+1] > r[j-1]) j--; //move to easier haybale since it's a strict subtask of getting the ones after
		else i++; 
	}
	
	cout << setprecision(1) << ans << endl;

	return 0;
}








