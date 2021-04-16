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

int T;
string l, r;

vi process(string& k) {
	ll res = 0;
	ll cur = 1;

	vector<int> digs;

	for (int i = 0; i < k.length(); i++) {
		if ((k[i]-'0')%2 == (i+1)%2) 
			digs.PB(k[i]-'0');
		else 
			if (k[i] == '0') digs.PB(1);
			else digs.PB(k[i]-'0'-1); 
	}	

	return digs;
}

ll search(vi &a, int pos = 0, bool bigger = 1, bool odd = 1) {
	
	if (pos == (int)a.size()-1) {
		if (bigger)
			return (pos == 0) ? 1 : (a[pos]+!odd)/2 + !odd;
		else
			return 5ll;
	}
	
	
	ll res = 0;
	if (bigger) 
		res += search(a, pos+1, 1, !odd) + (pos > 0) * (a[pos]+!odd)/2*search(a, pos+1, 0, !odd);
	else
		res += 5 * search(a, pos+1, 0, !odd);

	return res;
}

ll exp(ll base, int p) {
	ll res = 1;
	while (p > 0) {
		if (p & 1)
			res *= base;
		base *= base;
		p >>= 1;
	}
	return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	int Case = 1;
	

	while(T--) {
		cin >> l >> r;
		l = to_string(stoi(l)-1);
		ll ans = 0;
		vi digs = process(r);
			
		ans += search(digs);
		for (int i = 1; i < digs[0]; i += 2)
			ans += search(digs, 0, digs.size()==1);	

		ans += (exp(5, (int)digs.size()-1)-1)/4*5;

		cout << "WHAT " << ans << endl;
		
		digs = process(l);
		ans -= search(digs);

		for(int i = 1; i < digs[0]; i += 2)
			ans -= search(digs, 0, digs.size()==1);

		ans -= (exp(5, (int)digs.size()-1)-1)/4*5;

		cout << "TEST " << ans << endl;

	}


    
    return 0;
}








