#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

// void solve(){
//     fstream input("input5.txt");
//     if(!input){
//         cerr << "Error: Could not open input file." << "\n";
//         return;
//     }
//     vector<pair<int, int>> v;
//     vector<vector<int>> ins;
//     string line;
//     while(getline(input, line)){
//         if(!line.empty() && line.find('|') != string::npos){
//             pair<int, int> p;
//             p.ff = stoi(line.substr(0,2));
//             p.ss = stoi(line.substr(3));
//             v.push_back(p);
//         } else if(!line.empty()){
//             vector<int> s;
//             stringstream ss(line);
//             string token;
//             while(getline(ss, token, ',')){
//                 s.push_back(stoi(token));
//             }
//             ins.push_back(s);
//         }
//     }
//     int sum = 0;
//     for(int i = 0; i < ins.size(); i++){
//         bool valid = true;
//         for(int j = 0; j < ins[i].size()-1; j++){
//             for(int k = j+1; k < ins[i].size(); k++){
//                 pair<int, int> p;
//                 p.ff = ins[i][j];
//                 p.ss = ins[i][k];
//                 if(find(v.begin(), v.end(), p) == v.end()){
//                     valid = false;
//                 }
//             }
//         }
//         if(valid) sum += ins[i][ins[i].size() / 2];
//     }

//     cout << sum << "\n";
// }

void solve(){
    fstream input("input5.txt");
    if(!input){
        cerr << "Error: Could not open input file." << "\n";
        return;
    }
    vector<pair<int, int>> v;
    vector<vector<int>> ins;
    string line;
    while(getline(input, line)){
        if(!line.empty() && line.find('|') != string::npos){
            pair<int, int> p;
            p.ff = stoi(line.substr(0,2));
            p.ss = stoi(line.substr(3));
            v.push_back(p);
        } else if(!line.empty()){
            vector<int> s;
            stringstream ss(line);
            string token;
            while(getline(ss, token, ',')){
                s.push_back(stoi(token));
            }
            ins.push_back(s);
        }
    }
    int sum = 0;
    for(int i = 0; i < ins.size(); i++){
        bool valid = true;
        for(int j = 0; j < ins[i].size()-1; j++){
            for(int k = j+1; k < ins[i].size(); k++){
                pair<int, int> p;
                p.ff = ins[i][j];
                p.ss = ins[i][k];
                if(find(v.begin(), v.end(), p) == v.end()){
                    valid = false;
                    int temp = ins[i][j];
                    ins[i][j] = ins[i][k];
                    ins[i][k] = temp;
                }
            }
        }
        if(!valid) sum += ins[i][ins[i].size() / 2];
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