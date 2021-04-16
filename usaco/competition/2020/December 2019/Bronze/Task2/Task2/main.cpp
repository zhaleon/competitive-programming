#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <assert.h>
#include <string>
#include <math.h>
#include <deque>


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int> > vii;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i,a,b) for (int i = a; i < b; i++)

ifstream fin ("lineup.in");
ofstream fout ("lineup.out");

int N;

vector<string> cow;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cow.PB("Beatrice");
    cow.PB("Sue");
    cow.PB("Belinda");
    cow.PB("Bessie");
    cow.PB("Betsy");
    cow.PB("Blue");
    cow.PB("Bella");
    cow.PB("Buttercup");
    
    fin >> N;
    sort(cow.begin(), cow.end());
    vector<pair<string, string> > requirements;
    
    
    for (int i = 0; i < N; i++) {
        string dummy;
        string cowA, cowB;
        fin >> cowA >> dummy >> dummy >> dummy >> dummy >> cowB;
        requirements.push_back(MP(cowA, cowB));
        //cout << cowA << ' ' << cowB << endl;
    }

    while (next_permutation(cow.begin(), cow.end())) {
        bool works = true;
        for (int i = 0; i < requirements.size(); i++) {
            string a = requirements[i].F, b = requirements[i].S;
            for (int j = 0; j < cow.size() - 1; j++) {
                if ((cow[j] == a && cow[j+1] != b) || (cow[j] == b && cow[j+1] != a)) {
                    works = false;
                    if (j > 0) {
                        if ((cow[j] == a && cow[j-1] == b) || (cow[j] == b && cow[j-1] == a)) {
                            works = true;
                        } else {
                            break;
                        }
                    }
                }
            }
            if (!works) break;
        }
        if (works) {
            for (int i = 0; i < cow.size(); i++) {
                fout << cow[i] << endl;
            }
            break;
        }
    }
    
    return 0;
}



