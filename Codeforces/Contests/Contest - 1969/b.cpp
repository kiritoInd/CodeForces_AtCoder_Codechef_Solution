#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <numeric>
#include <limits>
#include <functional>
#include <utility>
#include <unordered_map>
#include <unordered_set>


using namespace std;
#define  int          long long
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()
#define  enl  	  '\n'

vector<int> count_divisors_to_n(int n){
    vector<int> res(n + 1);
    for(int i = 1 ; i <= n ; i++){
        for(int j = i ; j <= n; j += i){
            res[j]++;
        }
    }
    return res;
}
int count_divisors(int n){
    int count = 0;
    for(int i = 1 ; i * i <= n;i++){
        if(n % i == 0){
            count++;
            if(n/i != i){
                count++;
            }
        }

    }
    return count;
}
template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << '(' << p.first << ',' << p.second << ')'; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << '['; for(int i = 0; i < v.size(); i++) {if (i) cout << ','; cout << v[i];} return cout << ']';}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

const long long mod = 1e9+7;
const long long inf = 1e18;

int solve() {
        string s;
        cin >> s;
        vector<int> t;
        for(int i = 0 ; i < s.size(); i++){
            int c = 0;
            while(i < s.size() &&  s[i] == '1'){
                i++;
                c++;
            }
            t.push_back(c);
            if(i < s.size() && c != 0)t.push_back(0);
            c = 0;
        }
        vector<int> prf(t.size() , 0);
        prf[0] = t[0];
        for(int i = 1 ;i < t.size() ;i++){
            prf[i] = (t[i] + prf[i - 1]);
        }
        int cost = 0;
        for(int i = 1 ; i< prf.size() ;i++){
            if(prf[i] == 0) continue;
            if(prf[i] == prf[i - 1]){
                cost += prf[i] + 1;
            }
        }
        cout<<cost<<enl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}