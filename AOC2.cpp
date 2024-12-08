#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

// void solve(){
//     fstream input("input2.txt");
//     if(!input){
//         cerr << "Error: Could not open input file." << "\n";
//         return;
//     }
//     string line;
//     int cnt = 0;
//     while(getline(input, line)){
//         stringstream ss(line);
//         string num;
//         vector<int> v;
//         while(ss >> num){
//             v.push_back(stoi(num));
//         }
//         bool valid1 = true;
//         bool valid2 = true;
//         for(int i = 0; i < v.size()-1; i++){
//             int a = v[i];
//             int b = v[i+1];
//             if(!(a < b && abs(a-b) <= 3)) valid1 = false;
//             if(!(a > b && abs(a-b) <= 3)) valid2 = false;
//         }
//         if(valid1 || valid2) cnt++;
//     }
//     cout << cnt << "\n";
// }

bool isValid(vector<int>& v, bool increasing){
    for(int i = 0; i < v.size(); ++i){
        vector<int> temp = v;
        temp.erase(temp.begin() + i);

        bool valid = true;
        for(int j = 0; j < temp.size() - 1; ++j){
            if(increasing){
                if(!(temp[j] < temp[j + 1] && abs(temp[j] - temp[j + 1]) <= 3)){
                    valid = false;
                    break;
                }
            } else{
                if(!(temp[j] > temp[j + 1] && abs(temp[j] - temp[j + 1]) <= 3)){
                    valid = false;
                    break;
                }
            }
        }

        if(valid) return true;
    }
    return false;
}

void solve(){
    fstream input("input2.txt");
    if(!input){
        cerr << "Error: Could not open input file." << "\n";
        return;
    }

    string line;
    int cnt = 0;
    while(getline(input, line)){
        stringstream ss(line);
        string num;
        vector<int> v;

        while(ss >> num){
            v.push_back(stoi(num));
        }

        if(isValid(v, true) || isValid(v, false)){
            cnt++;
        }
    }

    cout << cnt << "\n";
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