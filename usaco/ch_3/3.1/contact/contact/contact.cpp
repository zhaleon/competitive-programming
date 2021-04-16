/*
 ID: lionz202
 TASK: contact
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
#include <bitset>

using namespace std;

ifstream fin("contact.in");
ofstream fout("contact.out");

int A, B, N;

typedef struct pattern pattern;
struct pattern {
    string str;
    int frequency;
    pattern(bitset<13> pat, int id) {
        int firstOne = 0;
        for (int i = 12; i >= 0; i--) {
            if (pat[i] == 1) {
                firstOne = i;
                break;
            }
        }
        frequency = id;
        str = (pat.to_string()).substr(13-firstOne);
    }
};

int best[10000];

bool comparator(const pattern& a, const pattern& b) {
    if (a.frequency != b.frequency) return a.frequency > b.frequency;
    if (a.str.size() != b.str.size()) return a.str.size() < b.str.size();
    return a.str < b.str;
}

int main()
{
    fin >> A >> B >> N;
    string read = "";
    string holder;
    
    while(fin >> holder) {
        read += holder;
    }
    vector<pattern> patterns;

    for (int i = A; i <= B; i++) {
        //string current = read.substr(0,i);
        for (int j = 0; j < ((int)read.length())-i+1; j++) {
            //if (j + i < read.length()) {
                bitset<13> current = bitset<13>(read.substr(j,i));
                current[i] = 1;
                //fout << current << ' ' << read.substr(j,i) << ' ' << current.to_ulong() << endl;
                if (current.to_ulong() > 10000) {
                    continue;
                }
                best[current.to_ulong()]++;
            //}
        }
    }
    
    for (int i = 0; i < 10000; i++) {
        if (best[i] == 0) continue;
        patterns.push_back(pattern(bitset<13>(i), best[i]));
    }
    
    sort(patterns.begin(), patterns.end(), comparator);
    
//    for (int i = 0; i < 10000; i++) {
//        fout << patterns[i].str << ' ' << patterns[i].frequency << endl;
//    }
    //fout << patterns.size() << endl;
    
//    bool same = false;
//    for (int i = 0; i < 10000 && N > 0 && i < patterns.size(); i++) {
//        if (!same) {
////            N--;
//            fout << patterns[i].frequency << endl;
//        }
////        if (patterns[i].frequency == patterns[i+1].frequency) {
////            same = true;
////        }
////        if (same) {
////            int temp = patterns[i].frequency;
////            while (patterns[i].frequency == temp) {
////                fout << patterns[i].str;
////                i++;
////                if (patterns[i].frequency != temp) {
////                    fout << endl;
////                } else {
////                    fout << ' ';
////                }
////            }
////            same = false;
////        } else {
////            fout << patterns[i].str << endl;
////        }
//
//        fout << patterns[i].str;
//        if (patterns[i].frequency == patterns[i+1].frequency && N > 0) {
//            same = true;
//            fout << ' ';
//        } else {
//            N--;
//            fout << endl;
//            same = false;
//        }
//    }
//    //fout << endl;
    int x = 0;
    while (N-- && x < (int)patterns.size()) {
        fout << patterns[x].frequency << endl;
        fout << patterns[x].str;
        x++;
        if (x == patterns.size()) {
            fout << '\n';
            break;
        }
        int sofar = 1;
        for (int i = x; patterns[i].frequency == patterns[i-1].frequency; i++) {
            if (sofar % 6 == 0) {
                fout << endl << patterns[i].str;
            } else {
                fout << ' ' << patterns[i].str;
            }
            sofar++;
            x++;
        }
        fout << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}

