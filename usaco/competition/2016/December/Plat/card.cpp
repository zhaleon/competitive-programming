#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
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
bool has[50001];

vi b;
vi e;

int pref[50001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    
    rep(i,0,N) {
        int card;
        cin >> card;
        e.PB(card);
        has[card] = 1;
    }
    
    rep(i,1,N+1) if (!has[card]) b.PB(i);
    
    sort(b.begin(), b.end(), greater<int>());
    
    int ans = 0;
    
    rep(i,1,N+1) {
        pref[i] = pref[i-1];
        
    }
    return 0;
}