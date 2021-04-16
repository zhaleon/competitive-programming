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
#define rep(i,a,b) for (int i = a; i <= b; ++i)

int N;
int freq[200001];
int arr[200001];
vi ind_list[200001];

int pre[200001];

int bit[200001];

void upd(int pos, int delta) {
    while (pos < N+1) {
        bit[pos] += delta;
        pos += pos & -pos;
    }
}

int sum(int i) {
    int res = 0;
    while (i > 0) {
        res += bit[i];
        i -= i & -i;
    }
    return res;
}

int sum(int i, int j) {
    if (i > j) return 0;
    if (i == j) return 1;
    return sum(j) - sum(i-1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    rep(i,1,N) cin >> arr[i], ind_list[arr[i]].PB(i);
    rep(i,1,N) ++freq[arr[i]];
    rep(i,1,N) ind_list[i].PB(N+1);

    ll ans = 0;
    /* rep(i,1,N) ans += (freq[i] > 0) * (freq[i] - 1); */

    auto comp = [&](pii a, pii b) {
        return a.S < b.S;
    };
    
    vpi queries;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j + 1 < (int) ind_list[i].size(); ++j) {
            queries.PB({ind_list[i][j]+1, ind_list[i][j+1]-1});
            /* cout << ind_list[i][j] << ' ' << ind_list[i][j+1] << endl; */
        }
    }

    sort(queries.begin(), queries.end(), comp);

    int i = 1;
    for (auto [l,r] : queries) {
        while (i <= r) {
            if (pre[arr[i]]) upd(pre[arr[i]], -1); 
            pre[arr[i]] = i;
            upd(i, +1);
            ++i;
        }
        ans += sum(l,r);
        /* printf("(%i,%i) = %i\n", l,r,sum(l,r)); */
        /* rep(i,1,N) cout << bit[i] << ' '; cout << endl; */
    }

    cout << ans << endl;
    
    return 0;
}








