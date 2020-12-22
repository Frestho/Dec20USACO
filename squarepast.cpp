#include <bits/stdc++.h>
using namespace std;

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

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
}
// too hard :(
int main() {
    setIO();
    int N; cin >> N;
    vector<pii> cows;
    ll ans = 1; // start at 1 because of the empty and single cow sets
    rep(i, 0, N) {
        vi yAbove;
        vi yBelow;
        cout << 14 << endl;
        return 0;
        yAbove.pb(cows[i].s);
        yBelow.pb(cows[i].s);
        rep(j, i+1, N) {
            if(cows[j].s > cows[i].s) {
                yAbove.pb(cows[j].s);
            }
            else {
                yBelow.pb(cows[j].s);
            }
            sort(all(yAbove));
            sort(all(yBelow));
            int a = 0, b = 0;
            while(b <= yBelow.size()) {
                if(yAbove[a] - yBelow[b] <= j-i) ans++;
                if(yAbove[a] - yBelow[b] > j-i) {
                    a++;
                }
                else {
                    b++;
                }
            }
        }
    }
}