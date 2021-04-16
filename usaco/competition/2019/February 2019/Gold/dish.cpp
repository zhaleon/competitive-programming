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
#include <stack>

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
int plates[100001];

deque<int> pile[100001];

int main() {
	setIO("dishes");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	rep(i,0,N) cin >> plates[i];
	
	int left = 0, biggest = 0; //track leftmost stack in pile array and largest plate cleaned
	
	rep(i,0,N) {
		//cout << plates[i] << ' ' << biggest << ' ' << left << endl;
		if (plates[i] < biggest) {
			cout << i << endl;
			return 0;
		}
		int cur = left;
		while (pile[cur].size() && pile[cur].front() < plates[i]) cur++; //find earliest stack with bottom bigger
		
		if (pile[cur].empty()) pile[cur].push_back(plates[i]); //new stack
		else if (plates[i] > pile[cur].back()) {
			for (; left < cur; left++) biggest = max(biggest, pile[left].front()); //clean earlier stacks
			while (plates[i] > pile[cur].back()) {
				biggest = max(biggest, pile[cur].back());
				pile[cur].pop_back();
			}
		} else {
			pile[cur].push_back(plates[i]); //just put on without any actions
		}
	}

	cout << N << endl;
	
    return 0;
}