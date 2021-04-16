/*
 ID: lionz202
 TASK: humble
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <climits>

using namespace std;

ifstream fin("humble.in");
ofstream fout("humble.out");

int K, N;

struct comp {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};

//vector<int> prime;
int prime[121];
priority_queue<long, vector<long>, comp> answer;
unordered_map<long, int> used;


int main()
{
    fin >> K >> N;
    int holder;
    for (int i = 0; i < K; i++) {
        fin >> holder;
        answer.push(holder);
        prime[i] = holder;
        //prime.push_back(holder);
    }
    if (K == 1) {
        long answer = 1;
        for (int i = 0; i < N; i++) {
            answer *= prime[0];
        }
        fout << answer << endl;
        return 0;
    }
    int finalIndex = N;
    long largest = prime[0];
    
    while(finalIndex > 1) {
        long long current = answer.top();
        assert(largest > 0);
        answer.pop();
        finalIndex--;
        for (int i = 0; i < K; i++) {
            double cur = (current*prime[i]);
            if (cur < 0) continue;
            if ((answer.size() > finalIndex && cur > largest) || used[(long)cur] == 1) continue;
            used[(long)cur] = 1;
            answer.push((long)cur);
            largest = (cur > largest) ? cur : largest;
        }
    }
    
    for (int i = 0; i < finalIndex-1; i++) {
        answer.pop();
    }
    
    fout << answer.top() << endl;
    return 0;
}

