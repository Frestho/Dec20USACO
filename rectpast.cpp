#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
using pii = pair<int,int>;
#define f first
#define s second
#define mp make_pair
typedef tree<int, null_type, less<int>, rb_tree_tag,  
            tree_order_statistics_node_update> indexed_set;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
}

int main() {
    setIO();
    int N; cin >> N;
    vector<pii> cows;
    rep(i, 0, N) {
        int a, b; cin >> a >> b;
        cows.pb(mp(a, b));
    }
    sort(all(cows));
    ll ans = N+1; // start at N+1 because of the empty and single cow sets
    rep(i, 0, N) {
        indexed_set yAbove;
        indexed_set yBelow;
        rep(j, i+1, N) {
            if(cows[j].s > cows[i].s) {
                yAbove.insert(cows[j].s);
                ans += (yAbove.size() - yAbove.order_of_key(cows[j].s)) * (yBelow.size() + 1);
            }
            else {
                yBelow.insert(cows[j].s);
                ans += (yBelow.order_of_key(cows[j].s) + 1) * (yAbove.size() + 1);
            }
        }
    }
    cout << ans << "\n";
}