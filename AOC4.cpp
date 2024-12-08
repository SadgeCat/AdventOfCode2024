#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

// void solve(){
//     fstream input("input4.txt");
//     if(!input){
//         cerr << "Error: Could not open input file." << "\n";
//         return;
//     }
//     vector<string> v;
//     string line;
//     while(getline(input, line)){
//         v.push_back(line);
//     }
//     int cnt = 0;
//     int n = v.size(), m = v[0].length();
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(v[i][j] == 'X'){
//                 if(j > 2){
//                     if(v[i][j-1] == 'M' && v[i][j-2] == 'A' && v[i][j-3] == 'S') cnt ++;
//                 }
//                 if(j < m-3){
//                     if(v[i][j+1] == 'M' && v[i][j+2] == 'A' && v[i][j+3] == 'S') cnt ++;
//                 }
//                 if(i > 2){
//                     if(v[i-1][j] == 'M' && v[i-2][j] == 'A' && v[i-3][j] == 'S') cnt ++;
//                 }
//                 if(i < n-3){
//                     if(v[i+1][j] == 'M' && v[i+2][j] == 'A' && v[i+3][j] == 'S') cnt ++;
//                 }
//                 if(j > 2 && i > 2){
//                     if(v[i-1][j-1] == 'M' && v[i-2][j-2] == 'A' && v[i-3][j-3] == 'S') cnt ++;
//                 }
//                 if(j < m-3 && i < n-3){
//                     if(v[i+1][j+1] == 'M' && v[i+2][j+2] == 'A' && v[i+3][j+3] == 'S') cnt ++;
//                 }
//                 if(j > 2 && i < n-3){
//                     if(v[i+1][j-1] == 'M' && v[i+2][j-2] == 'A' && v[i+3][j-3] == 'S') cnt ++;
//                 }
//                 if(j < m-3 && i > 2){
//                     if(v[i-1][j+1] == 'M' && v[i-2][j+2] == 'A' && v[i-3][j+3] == 'S') cnt ++;
//                 }
//             }
//         }
//     }

//     cout << cnt << "\n";
// }

void solve(){
    fstream input("input4.txt");
    if(!input){
        cerr << "Error: Could not open input file." << "\n";
        return;
    }
    vector<string> v;
    string line;
    while(getline(input, line)){
        v.push_back(line);
    }
    int cnt = 0;
    int n = v.size(), m = v[0].length();
    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < m-1; j++){
            if(v[i][j] == 'A'){
                if(v[i-1][j-1] == 'M' && v[i-1][j+1] == 'M' && v[i+1][j-1] == 'S' && v[i+1][j+1] == 'S') cnt++;
                if(v[i-1][j-1] == 'S' && v[i-1][j+1] == 'S' && v[i+1][j-1] == 'M' && v[i+1][j+1] == 'M') cnt++;
                if(v[i-1][j-1] == 'S' && v[i-1][j+1] == 'M' && v[i+1][j-1] == 'S' && v[i+1][j+1] == 'M') cnt++;
                if(v[i-1][j-1] == 'M' && v[i-1][j+1] == 'S' && v[i+1][j-1] == 'M' && v[i+1][j+1] == 'S') cnt++;
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