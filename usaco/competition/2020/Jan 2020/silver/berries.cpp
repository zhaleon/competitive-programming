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

int baskets[1000];
int trees[1000];
int N, K;

int berries(int s) {
	int curTree = 0, baskets = K/2, lastTreeBerries = 0;
	vi remaining;
	while (baskets > 0 && curTree < N) {
		if (trees[curTree] < s) {
			return 0;
			baskets--;
			curTree++;
			continue;
		}

		if (baskets <= trees[curTree]/s) {
			lastTreeBerries = trees[curTree] - baskets*s;
			baskets = 0;
			//remaining.PB(lastTreeBerries);
			curTree++;
			continue;
		}

		baskets -= trees[curTree]/s;
		remaining.PB(trees[curTree]%s);
		curTree++;
	}
	baskets = K/2;
	int i = 0, r = 0;
	bool used = 0;
	while (curTree < N) {
		if (trees[curTree] < lastTreeBerries && !used) {
			if (baskets*s <= lastTreeBerries) {
				r += baskets*s;
				baskets = 0;
				break;
			} else if (lastTreeBerries < s) {
				remaining.PB(lastTreeBerries);
			} else {
				baskets -= lastTreeBerries/s;
				r += lastTreeBerries/s * s;
				remaining.PB(lastTreeBerries%s);
			}
			used = 1;
			continue;
		}
		if (trees[curTree] < s) {
			remaining.PB(trees[curTree]);
			curTree++;
			continue;
		}
		if (baskets*s <= trees[curTree]) {
			remaining.PB(trees[curTree]-baskets*s);
			r += baskets*s;
			baskets = 0;
			break;
		}
		baskets -= trees[curTree]/s;
		r += (trees[curTree]-trees[curTree]%s);
		remaining.PB(trees[curTree] % s);
		curTree++;
	}

	sort(remaining.begin(), remaining.end(), greater<int>());	
	
	while (i < remaining.size() && baskets > 0) {
		if (remaining[i] < s) {
			baskets--;
			r += remaining[i];
		} else {
			baskets -= remaining[i]/s;
			r += (remaining[i]-remaining[i]%s);
		}
		i++;
	}

	return r;

}

int main() {
	setIO("berries");
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	int bigTree = 0;
	rep(i,0,N) {
		cin >> trees[i];
		bigTree = max(bigTree, trees[i]);
	}

	sort(trees, trees+N, greater<int>());
   
   	int ans = 0;
	rep(i,1,1001) {
		//cout << i << ' ' << berries(i) << endl;
		ans = max(ans, berries(i));
	}
	cout << ans << endl;	
    return 0;
}








