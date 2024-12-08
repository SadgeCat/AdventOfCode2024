#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

// void solve() {
//     fstream input("input3.txt");
//     if (!input) {
//         cerr << "Error: Could not open input file." << endl;
//         return;
//     }

//     int sum = 0;
//     string line;
//     while(getline(input, line)){
//         int i = 0;
//         while((i = line.find("mul", i)) != string::npos){
//             if(i + 3 < line.size() && line[i + 3] == '('){
//                 int start = i + 4;
//                 int comma = line.find(',', start);
//                 int end = line.find(')', comma);

//                 if(comma != string::npos && end != string::npos && comma > start && end > comma){
//                     string num1 = line.substr(start, comma - start);
//                     string num2 = line.substr(comma + 1, end - comma - 1);

//                     bool valid = all_of(num1.begin(), num1.end(), ::isdigit) &&
//                                  all_of(num2.begin(), num2.end(), ::isdigit);
//                     if(valid){
//                         sum += stoi(num1) * stoi(num2);
//                     }
//                 }
//             }
//             i += 3;
//         }
//     }

//     cout << sum << "\n";
// }

void solve() {
    fstream input("input3.txt");
    if (!input) {
        cerr << "Error: Could not open input file." << endl;
        return;
    }

    int sum = 0;
    string line;
    string s = "";

    while(getline(input, line)){
        s += line;
    }

    int i = 0;
        vector<int> v1, v2;
        int j = 0, k = 0;
        while((j = s.find("do()", j)) != string::npos){
            v1.push_back(j);
            j += 4;
        }
        while((k = s.find("don't()", k)) != string::npos){
            v2.push_back(k);
            k += 4;
        }
        while((i = s.find("mul", i)) != string::npos){
            int jn = 0, kn = 0;
            for(int n: v1){
                if(n > jn && n < i) jn = n;
                if(n > i) break;
            }
            for(int n: v2){
                if(n > kn && n < i) kn = n;
                if(n > i) break;
            }
            if(i + 3 < s.size() && s[i + 3] == '(' && jn > kn || kn == 0){
                int start = i + 4;
                int comma = s.find(',', start);
                int end = s.find(')', comma);

                if(comma != string::npos && end != string::npos && comma > start && end > comma){
                    string num1 = s.substr(start, comma - start);
                    string num2 = s.substr(comma + 1, end - comma - 1);

                    bool valid = all_of(num1.begin(), num1.end(), ::isdigit) &&
                                 all_of(num2.begin(), num2.end(), ::isdigit);
                    if(valid){
                        sum += stoi(num1) * stoi(num2);
                    }
                }
            }
            i += 3;
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