#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

// void solve(){
//     fstream input("input8.txt");
//     if(!input){
//         cerr << "Error: Could not open input file." << "\n";
//         return;
//     }
//     string line;
//     vector<string> data;
//     vector<tuple<char,int,int>> v;
//     while(getline(input, line)){
//         data.push_back(line);
//     }
    
//     for(int i = 0; i < data.size(); i++){
//         for(int j = 0; j < data[0].length(); j++){
//             if(data[i][j] != '.'){
//                 tuple<char,int,int> t = make_tuple(data[i][j], i, j);
//                 v.push_back(t);
//             }
//         }
//     }

//     set<pair<int,int>> s;

//     for(int i = 0; i < v.size()-1; i++){
//         for(int j = i+1; j < v.size(); j++){
//             if(i == j) continue;
//             if(get<0>(v[i]) == get<0>(v[j])){
//                 int x1 = get<1>(v[i]), x2 = get<1>(v[j]), y1 = get<2>(v[i]), y2 = get<2>(v[j]);
//                 int leftx = 2*x1 - x2, rightx = 2*x2 - x1, lefty = 2*y1 - y2, righty = 2*y2 - y1;
//                 if(leftx >= 0 && leftx < data.size() && lefty >= 0 && lefty < data[0].length()){
//                     pair<int,int> p;
//                     p.ff = leftx;
//                     p.ss = lefty;
//                     s.insert(p);
//                 }
//                 if(rightx >= 0 && rightx < data.size() && righty >= 0 && righty < data[0].length()){
//                     pair<int,int> p;
//                     p.ff = rightx;
//                     p.ss = righty;
//                     s.insert(p);
//                 }
//             }
//         }
//     }

//     cout << s.size() << "\n";
// }

void solve(){
    fstream input("input8.txt");
    if(!input){
        cerr << "Error: Could not open input file." << "\n";
        return;
    }
    string line;
    vector<string> data;
    vector<tuple<char,int,int>> v;
    while(getline(input, line)){
        data.push_back(line);
    }
    
    for(int i = 0; i < data.size(); i++){
        for(int j = 0; j < data[0].length(); j++){
            if(data[i][j] != '.'){
                tuple<char,int,int> t = make_tuple(data[i][j], i, j);
                v.push_back(t);
            }
        }
    }

    set<pair<int,int>> s;

    for(int i = 0; i < v.size()-1; i++){
        for(int j = i+1; j < v.size(); j++){
            if(i == j) continue;
            if(get<0>(v[i]) == get<0>(v[j])){
                int x1 = get<1>(v[i]), x2 = get<1>(v[j]), y1 = get<2>(v[i]), y2 = get<2>(v[j]);
                int diffx = x1-x2;
                int diffy = y1-y2;
                int leftx = 2*x1 - x2, rightx = 2*x2 - x1, lefty = 2*y1 - y2, righty = 2*y2 - y1;
                if(leftx >= 0 && leftx < data.size() && lefty >= 0 && lefty < data[0].length()){
                    pair<int,int> p;
                    p.ff = leftx;
                    p.ss = lefty;
                    s.insert(p);
                }
                if(rightx >= 0 && rightx < data.size() && righty >= 0 && righty < data[0].length()){
                    pair<int,int> p;
                    p.ff = rightx;
                    p.ss = righty;
                    s.insert(p);
                }
                int upx = leftx + diffx, upy = lefty + diffy;
                while(upx >= 0 && upx < data.size() && upy >= 0 && upy < data[0].length()){
                    pair<int,int> p;
                    p.ff = upx;
                    p.ss = upy;
                    s.insert(p);
                    upx += diffx;
                    upy += diffy;
                }
                int downx = leftx - diffx, downy = lefty - diffy;
                while(downx >= 0 && downx < data.size() && downy >= 0 && downy < data[0].length()){
                    pair<int,int> p;
                    p.ff = downx;
                    p.ss = downy;
                    s.insert(p);
                    downx -= diffx;
                    downy -= diffy;
                }
            }
        }
    }

    cout << s.size() << "\n";
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