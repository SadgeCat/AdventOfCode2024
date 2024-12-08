#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

// bool evaluate(vector<int> numbers, int index, ll current_value, ll target){
//     if(index == numbers.size()){
//         return current_value == target;
//     }

//     if(evaluate(numbers, index + 1, current_value + numbers[index], target)){
//         return true;
//     }

//     if(evaluate(numbers, index + 1, current_value * numbers[index], target)){
//         return true;
//     }

//     return false;
// }

// void solve(){
//     fstream input("input7.txt");
//     if(!input){
//         cerr << "Error: Could not open input file." << "\n";
//         return;
//     }
//     string line;
//     ll sum = 0;
//     while(getline(input, line)){
//         stringstream ss(line);
//         string token;
//         vector<string> v;
//         while(getline(ss, token, ' ')){
//             v.push_back(token);
//         }
//         ll val = stoll(v[0].substr(0, v[0].length()-1));
//         v.erase(v.begin());
//         vector<int> v2;
//         for(int i = 0; i < v.size(); i++){
//             v2.push_back(stoi(v[i]));
//         }
//         if(evaluate(v2, 1, v2[0], val)){
//             sum += val;
//         }
//     }

//     cout << sum << "\n";
// }

#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

bool evaluate(vector<int> numbers, int index, ll c, ll target){
    if(index == numbers.size()){
        return c == target;
    }

    if(evaluate(numbers, index + 1, c + numbers[index], target)){
        return true;
    }

    if(evaluate(numbers, index + 1, c * numbers[index], target)){
        return true;
    }

    ll cVal = stoll(to_string(c) + to_string(numbers[index]));
    if (evaluate(numbers, index + 1, cVal, target)) {
        return true;
    }

    return false;
}

void solve(){
    fstream input("input7.txt");
    if(!input){
        cerr << "Error: Could not open input file." << "\n";
        return;
    }
    string line;
    ll sum = 0;
    while(getline(input, line)){
        stringstream ss(line);
        string token;
        vector<string> v;
        while(getline(ss, token, ' ')){
            v.push_back(token);
        }
        ll val = stoll(v[0].substr(0, v[0].length()-1));
        v.erase(v.begin());
        vector<int> v2;
        for(int i = 0; i < v.size(); i++){
            v2.push_back(stoi(v[i]));
        }
        if(v2.size() > 1){
            ll cVal = stoll(to_string(v2[0]) + to_string(v2[1]));
            if(evaluate(v2, 2, cVal, val)){
                sum += val;
                continue;
            }
        }
        if(evaluate(v2, 0, 0, val)){
            sum += val;
        }
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