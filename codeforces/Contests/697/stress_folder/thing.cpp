#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(),(x).end()
#define pb push_back

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    vector<array<int, 2>> apps(n);
    int tot = 0;
    for(int i = 0; i < n; ++i) {
      cin >> apps[i][0];
      tot += apps[i][0];
    }
    for(int i = 0; i < n; ++i) {
      cin >> apps[i][1];
    }
    vector<int> ones, twos;
    for(int i = 0; i < n; ++i) {
      if(apps[i][1] == 1) {
        ones.pb(apps[i][0]);
      } else {
        twos.pb(apps[i][0]);
      }
    }
    sort(all(ones));
    sort(all(twos));
    if(tot < m) {
      cout << "-1\n";
      continue;
    }
    int cur = 0, ans =0;
    while(cur < m) {
      if(twos.size() == 0) {
        cur += ones.back();
        ++ans;
        ones.pop_back();
        continue;
      }
      if(ones.size() == 0) {
        ans += 2;
        cur += twos.back();
        twos.pop_back();
      } else if(ones.size() == 1) {
        if(cur + ones.back() >= m) {
          ++ans;
          break;
        }
        ans += 2;
        cur += twos.back();
        twos.pop_back();
      } else {
        if(cur + ones.back() >= m) {
          ++ans;
          break;
        }
        int l2 = ones[ones.size() - 1] + ones[ones.size() - 2];
        if(l2 >= twos.back()) {
          cur += ones.back();
          ones.pop_back();
          ++ans;
        } else {
          cur += twos.back();
          twos.pop_back();
          ans += 2;
        }
      }
    }
    cout << ans << "\n";
  }
}
