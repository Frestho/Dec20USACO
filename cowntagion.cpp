#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 69;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define trav(a, x) for(auto& a : x)
using pii = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
}

vi adj[MAX_N];
int ans = 0;

void dfs(int node, int prev) {
    int cows = 1;
    if(prev == -1) {
        while(cows - 1 < adj[node].size()) {
            cows *= 2;
            ans++;
        }
    } else {
        while(cows - 1 < adj[node].size() - 1) {
            cows *= 2;
            ans++;
        }
    }
    
    trav(a, adj[node]) {
        if(a != prev) {
            ans++;
            dfs(a, node);
        }
    }
}

int main() {
    setIO();
    int N; cin >> N;
    rep(i, 1, N) {
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    dfs(1, -1);
    cout << ans << "\n";
}