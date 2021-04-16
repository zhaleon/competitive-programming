/*
 ID: lionz202
 TASK: kimbits
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
#include <bitset>
#include <map>

using namespace std;

ifstream fin("kimbits.in");
ofstream fout("kimbits.out");

unsigned int N, L, I;

typedef struct skip {
    unsigned int a;
    unsigned int b;
} skip;

int numBits(unsigned int n) {
//    int temp = 0;
//    while (n > 0) {
//        if (n & 1) {
//            temp++;
//        }
//        n >>= 1;
//    }
//    return temp;
    int c;
    for (c = 0; n; c++) {
        n &= n - 1;
    }
    return c;
}

unsigned int choose(int k) {
    if (k == 0 || k == N) return 1;
    unsigned long temp = 1;
    for (int i = N; i > N-k; i--) {
        temp *= i;
        temp /= (N+1-i);
    }
    return (unsigned int)temp;
}

int main()
{
    fin >> N >> L >> I;
    
    unsigned int total = 0, max = 0;
    for (int i = 0; i <= L; i++) {
        total += choose(i);
    }
    for (int i = 0; i < L; i++) {
        max += (1 << (N-i-1));
    }
    unsigned int current = (I > total/2) ? max : 0;
    
    map<unsigned int, unsigned int> holder;
    
   // vector<skip> hold;
    int temp = (1 << (N-1));
    for (int i = N-2; i > 0; i--) {
        if (numBits(temp) >= L) {
//            skip d;
//            d.a = temp;
//            d.b = (1 << (i+1));
//            hold.push_back(d);
            holder[temp] = (1 << (i+1));
        }
        temp += (1 << i);
    }

    if (current == 0) {
        while (I > 1) {
            for (int i = 0; i < N; i++) {
                
            }
            if (holder[current] != 0) {
                current += holder[current];
            }
//            int temp = (1 << (N-1));
//            for (int i = N-2; i > 0; i--) {
//                if (temp == current && numBits(current) >= L) {
//                    current += (1 << (i+1));
//                    break;
//                }
//                temp += (1 << i);
//            }
            
//            for (int i = 0; i < hold.size(); i++) {
//                if (current == hold[i].a) {
//                    current += hold[i].b;
//                    break;
//                }
//            }
            
            current++;
            if (numBits(current) <= L) {
                I--;
            }
        }
    } else {
        while (total > I) {
            current--;
            if (numBits(current) <= L) {
                I++;
            }
        }
    }
    //fout << current << endl;
    
    bitset<31> answer = bitset<31>(current);
    fout << answer.to_string().substr(31-N) << endl;
    
    fin.close();
    fout.close();
    return 0;
}

