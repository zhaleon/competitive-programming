#include <bits/stdc++.h> 

using namespace std;

ifstream fin ("test.in");

typedef int ll;

int n;
vector<pair<ll,ll>> coords;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef  pair<ll,ll> pll;



bool cmp(pll a,pll b){
    return b.second>a.second;
}


////////////////////////////////////////////fenwick
int tree[2501];
const int N=2500;
int sum(int k) {
    int su = 0;
    while (k >= 1) {
        su += tree[k];
        k -= k&-k;
    }
    return su;
}
int sum(int a, int b){
    return sum(b)-sum(a-1);
}   
void add(int k, int x) {
    while (k <= N) {
        tree[k] += x;
        k += k&-k;
    }
}
///////////////////////////////////////////////////////////   


int main(){
    cin>>n;
    for(int i=1;i<n+1;i++){
        ll a,b;
       cin>>a>>b;
        coords.push_back(make_pair(a,b));
    }


    //compress coords and sort by x;
    sort(coords.begin(),coords.end(),cmp);
    FOR(i,0,n){
        coords[i].second=i+1;
    }
    sort(coords.begin(),coords.end());
    FOR(i,0,n){
        coords[i].first=i+1;
    }
    ////////////////////////////////////////////
    
    
    int ans=0;
    FOR(i,1,n+1){
        memset( tree, 0, sizeof(tree));
        add(coords[i-1].second,1);
        FOR(j,i+1,n+1){
            add(coords[j-1].second,1);
            int above=sum(max(coords[i-1].second,coords[j-1].second),2500);
            int below=sum(min(coords[i-1].second,coords[j-1].second));
            ans+=(above)*(below);
        }
    }
    cout<<ans+n+1 << endl;
} 
