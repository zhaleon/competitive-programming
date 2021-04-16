#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

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

double dist(pii a, pii b) {
	return sqrt((b.F-a.F)*(b.F-a.F) + (b.S-a.S)*(b.S-a.S));
}

double area(pii a, pii b, pii c) {
	return 0.5 * abs(a.F * b.S + b.F * c.S + c.F * a.S - a.S * b.F - b.S * c.F - c.S * a.F);
}

ll N, R;

pii points[1000001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> R;

	rep(i,1,N+1) cin >> points[i].F >> points[i].S;
	sort(points+1, points+1+N);
	double ans = 0;
	if (N > 1000) {
	for (int i = 1; i <= 1000; i++) {
		for (int j = N-1000; j <= N; j++) {
			if (dist(points[i], points[j]) > R) continue;
			for (int k = 300000; k <= 700000; k++) {
				if (max(max(dist(points[i], points[j]), dist(points[i], points[k])), dist(points[j], points[k])) <= R) {
					ans = max(ans, area(points[i], points[j], points[k]));
				}
			}
		}
	
	}
	return 0;
	}



	for (int i = 1; i <= N; i++) {
		for (int j = i+1; j <= N; j++) {
			if (dist(points[i], points[j]) > R) continue;
			for (int k = j+1; k <= N; k++) {
				if (max(max(dist(points[i], points[j]), dist(points[i], points[k])), dist(points[j], points[k])) <= R) {
					ans = max(ans, area(points[i], points[j], points[k]));
				}
			}
		}
	}
   
   	cout << (ll)(1000*ans + 0.5) << endl;	
    return 0;
}








