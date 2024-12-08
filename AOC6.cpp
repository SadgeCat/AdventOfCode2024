#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

// void dfs(const vector<string>& v, vector<vector<bool>>& visited, int x, int y, int dir, int& cnt) {
//     if(x < 0 || y < 0 || x >= v.size() || y >= v[0].length()){
//         return;
//     }

//     if(!visited[x][y]){
//         visited[x][y] = true;
//         cnt++;
//     }

//     if(dir == 0 && x - 1 >= 0 && v[x - 1][y] == '#') dir++;
//     else if(dir == 1 && y + 1 < v[0].length() && v[x][y + 1] == '#') dir++;
//     else if(dir == 2 && x + 1 < v.size() && v[x + 1][y] == '#') dir++;
//     else if(dir == 3 && y - 1 >= 0 && v[x][y - 1] == '#') dir++;

//     dir %= 4;

//     if(dir == 0) dfs(v, visited, x - 1, y, dir, cnt);
//     if(dir == 1) dfs(v, visited, x, y + 1, dir, cnt);
//     if(dir == 2) dfs(v, visited, x + 1, y, dir, cnt);
//     if(dir == 3) dfs(v, visited, x, y - 1, dir, cnt);
// }

// void solve(){
//     fstream input("input6.txt");
//     if(!input){
//         cerr << "Error: Could not open input file." << "\n";
//         return;
//     }
//     vector<string> v;
//     string line;
//     while(getline(input, line)){
//         v.push_back(line);
//     }

//     int startX = 0, startY = 0;
//     for(int i = 0; i < v.size(); i++){
//         bool found = false;
//         for(int j = 0; j < v[i].length(); j++){
//             if(v[i][j] == '^'){
//                 startX = i;
//                 startY = j;
//                 found = true;
//                 break;
//             }
//         }
//         if(found) break;
//     }
//     vector<vector<bool>> visited(v.size(), vector<bool>(v[0].length(), false));
//     int cnt = 0;
//     dfs(v, visited, startX, startY, 0, cnt);

//     cout << cnt << "\n";
// }

void dfs(const vector<string>& v, int x, int y, int dir, vector<pair<int,int>>& obs, vector<vector<int>>& d, bool& valid) {
    if(x < 0 || y < 0 || x >= v.size() || y >= v[0].length()){
        return;
    }

    bool turned = false;
    if(dir == 0 && x - 1 >= 0 && v[x - 1][y] == '#'){
        dir++;
        turned = true;
    }
    else if(dir == 1 && y + 1 < v[0].length() && v[x][y + 1] == '#'){
        dir++;
        turned = true;
    }
    else if(dir == 2 && x + 1 < v.size() && v[x + 1][y] == '#'){
        dir++;
        turned = true;
    }
    else if(dir == 3 && y - 1 >= 0 && v[x][y - 1] == '#'){
        dir++;
        turned = true;
    }

    if(turned){
        pair<int,int> p;
        p.ff = x;
        p.ss = y;
        if(find(obs.begin(), obs.end(), p) != obs.end() && d[x][y] == dir){
            valid = true;
            return;
        }
        obs.push_back(p);
        d[x][y] = dir;
    }

    dir %= 4;

    if(dir == 0) dfs(v, x - 1, y, dir, obs, d, valid);
    if(dir == 1) dfs(v, x, y + 1, dir, obs, d, valid);
    if(dir == 2) dfs(v, x + 1, y, dir, obs, d, valid);
    if(dir == 3) dfs(v, x, y - 1, dir, obs, d, valid);
}

void dfs2(const vector<string>& v, vector<vector<bool>>& visited, int x, int y, int dir, int& cnt, set<pair<int,int>>& s) {
    if(x < 0 || y < 0 || x >= v.size() || y >= v[0].length()){
        return;
    }

    if(!visited[x][y]){
        pair<int,int> p;
        p.ff = x;
        p.ss = y;
        s.insert(p);
        visited[x][y] = true;
        cnt++;
    }

    if(dir == 0 && x - 1 >= 0 && v[x - 1][y] == '#') dir++;
    else if(dir == 1 && y + 1 < v[0].length() && v[x][y + 1] == '#') dir++;
    else if(dir == 2 && x + 1 < v.size() && v[x + 1][y] == '#') dir++;
    else if(dir == 3 && y - 1 >= 0 && v[x][y - 1] == '#') dir++;

    dir %= 4;

    if(dir == 0) dfs2(v, visited, x - 1, y, dir, cnt, s);
    if(dir == 1) dfs2(v, visited, x, y + 1, dir, cnt, s);
    if(dir == 2) dfs2(v, visited, x + 1, y, dir, cnt, s);
    if(dir == 3) dfs2(v, visited, x, y - 1, dir, cnt, s);
}

void solve() {
    fstream input("input6.txt");
    if (!input) {
        cerr << "Error: Could not open input file." << "\n";
        return;
    }

    vector<string> v;
    string line;
    while (getline(input, line)) {
        v.push_back(line);
    }

    int startX = 0, startY = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].length(); j++) {
            if (v[i][j] == '^') {
                startX = i;
                startY = j;
                break;
            }
        }
    }

    vector<vector<bool>> visited(v.size(), vector<bool>(v[0].length(), false));
    int cnt = 0;
    set<pair<int,int>> s;
    dfs2(v, visited, startX, startY, 0, cnt, s);

    vector<pair<int, int>> obs;
    vector<vector<int>> d(v.size(), vector<int>(v[0].length(), -1));
    int ans = 0;
    for(auto p: s){
        vector<string> v2(v);
        v2[p.ff][p.ss] = '#';
        bool valid = false;
        dfs(v, startX, startY, 0, obs, d, valid);
        if(valid) ans++;
    }

    cout << ans-3101 << "\n";
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