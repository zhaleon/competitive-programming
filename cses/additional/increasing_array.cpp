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
#define rep(i,a,b) for (int i = a; i <= b; i++)

int N;
ll arr[200001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    rep(i,1,N) cin >> arr[i];
    rep(i,1,N) arr[i] += N-i;
    
    sort(arr+1, arr+1+N);
    ll median = arr[(N+1)/2];
    
    ll ans = 0;
    
    rep(i,1,N) ans += abs(arr[i] - median);
    
    cout << ans << endl;
    
    return 0;
}