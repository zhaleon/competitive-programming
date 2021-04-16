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
double x;

typedef struct line {
	int index;
	ll A, B, C;
	pair<ll, ll> l, r; 
	line() {};
	line(ll a, ll b, ll c, pair<ll, ll> _l, pair<ll, ll> _r, int ind) : A(a), B(b), C(c), l(_l), r(_r), index(ind) {};
} line;

vector<pair<pair<ll, ll>, int>> points;
line lines[100001];

bool comp(pair<pair<ll, ll>, int> a, pair<pair<ll, ll>, int> b) {
	return a.F.F < b.F.F;
}

bool intersect(line a, line b) {
	double det = a.A*b.B - b.A*a.B;
	double eps = 1e-5;
	if (abs(det) <= eps) return 0;
	double x = (b.B*a.C - a.B*b.C)/det;
	double y = (a.A*b.C - b.A*a.C)/det;
	if (x <= max(a.l.F, a.r.F) && x >= min(a.l.F, a.r.F) && y <= max(a.l.S, a.r.S) && y >= min(a.l.S, a.r.S) && x <= max(b.l.F, b.r.F) && x >= min(b.l.F, b.r.F) && y <= max(b.l.S, b.r.S) && y >= min(b.l.S, b.r.S)) {
		//cout << a.index << ' ' << b.index << endl;
		//cout << det << endl;	
		//cout << "\t" << x << ' ' << y << endl; 
		//cout << "\t" << max(a.l.S, a.r.S) << ' ' << min(a.l.S, a.r.S) << endl;
		//cout << "\t" << max(a.l.F, a.r.F) << ' ' << min(a.l.F, a.r.F) << endl << endl;
		return 1;
	}
	return 0;
}

ll getAns(line a, line b) {
	//cout << "TEST" << endl;
	int one = 0, two = 0;
	rep(i,1,N+1) {
		one += intersect(lines[i], a);
		two += intersect(lines[i], b);
	}

	if (one == two) return min(a.index, b.index);
	if (one > two) return a.index;
	return b.index;
}

double yval(line a) {
	return (double)a.l.S + (double)(a.r.S-a.l.S) * (double)(x-a.l.F) / (double)(a.r.F-a.l.F);
}

bool operator<(line a, line b) {return yval(a) < yval(b);}
bool operator==(line a, line b) {return a.index == b.index;}

int main() {
	setIO("cowjump");
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
	ll a,b,c,d;

	rep(i,1,N+1) {
		cin >> a >> b >> c >> d;
		points.PB(MP(MP(a,b),i));
		points.PB(MP(MP(c,d),i));
		lines[i] = line(b-d, c-a, (b-d)*a + (c-a)*b, MP(a,b), MP(c,d), i);
	}
	set<line> s;
	sort(points.begin(), points.end(), comp);
	rep(i,0,points.size()) {
		int cur = points[i].S;
		x = points[i].F.F;
		auto it = s.find(lines[cur]);
		if (it == s.end()) {
			it = s.lower_bound(lines[cur]);
			if (it != s.end() && intersect(lines[cur], *it)) {
				cout << getAns(lines[cur], *it) << endl;
				return 0;
			} 
			if (it != s.begin()) {
				it--;
				if (intersect(lines[cur], *it)) {
					cout << getAns(lines[cur], *it) << endl;
					return 0;
				}
			}
			s.insert(lines[cur]);
		} else {
			if (it != s.begin()) {
				auto prev = it;
				prev--;
				if (intersect(lines[cur], *it)) {
					cout << getAns(lines[cur], *prev) << endl;
					return 0;
				}
			}
			if (it != s.end()) {
				auto next = it;
				next++;
				if (intersect(lines[cur], *next)) {
					cout << getAns(lines[cur], *next) << endl;
					return 0;			
				}
			}
			s.erase(lines[cur]);	
				
		}
	}


    return 0;
}








