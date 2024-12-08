#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

// void solve(){
//     fstream input("input1.txt");
//     vector<int> v1, v2;
//     if(!input){
//         cerr << "Error: Could not open input file." << "\n";
//         return;
//     }
//     string line;
//     while(getline(input, line)){
//         stringstream ss(line);
//         string n1, n2;
//         if(ss >> n1 >> n2){
//             int k1 = stoi(n1);
//             int k2 = stoi(n2);
//             v1.push_back(k1);
//             v2.push_back(k2);
//         }
//     }
//     sort(v1.begin(), v1.end());
//     sort(v2.begin(), v2.end());
//     int sum = 0;
//     for(int i = 0; i < v1.size(); i++){
//         sum += abs(v1[i] - v2[i]);
//     }
//     cout << sum << "\n";
// }

void solve(){
    fstream input("input1.txt");
    map<int, int> m1, m2;
    if(!input){
        cerr << "Error: Could not open input file." << "\n";
        return;
    }
    string line;
    while(getline(input, line)){
        stringstream ss(line);
        string n1, n2;
        if(ss >> n1 >> n2){
            int k1 = stoi(n1);
            int k2 = stoi(n2);
            m1[k1]++;
            m2[k2]++;
        }
    }
    int sum = 0;
    for(auto p: m1){
        if(m2.find(p.ff) != m2.end()) sum += p.ff * p.ss * m2[p.ff];
    }
    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
