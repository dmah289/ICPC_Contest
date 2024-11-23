#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e5 + 5;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

vector<ll> arr(MAXN);

void findSubsetsSum(vector<int> a, unordered_map<int, vector<int>> &map){
    int totalSubsets = 1 << a.size();

    for(int i = 1 ; i < totalSubsets ; i++){
        int sum = 0;
        for(int j = 0; j < a.size(); j++){
            if(i & (1 << j)){
                sum += a[j];
            }
        }
        map[sum].push_back(i);
    } 
}

int main() {
    fast_io;
    
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    unordered_map<int, vector<int>> subsetSums;
    findSubsetsSum(a, subsetSums);

    set<int> res;

    for(auto& pair : subsetSums){
        vector<int>& tmp = pair.second;

        int len = tmp.size();

        for(int i = 0 ; i < len ; i++){
            for(int j = i+1 ; j < len ; j++){
                if((tmp[i] & tmp[j]) == 0){
                    res.insert(pair.first);
                    break;
                }
            }
            if(res.find(pair.first) != res.end()) break;
        }
    }

    cout << res.size() << endl;
    for(int x : res) cout << x << " ";
    cout << endl;

    return 0;
}