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

int poles[1000];
int dif[1000];

auto compare = [](int &a, int& b) { return a > b;};
priority_queue<int, vector<int>, decltype(compare)> dijkstras(compare);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int N;
	cin >> N;
	loop(i,0,N) cin >> poles[i];
	loop(i,0,N-1) dif[i] = poles[i+1] - poles[i];
	//loop(i,0,N-1) cout << dif[i] << ' ';
	//cout << endl;
	int answer = 1;
	
    
	cout << answer << endl;

    return 0;
}








