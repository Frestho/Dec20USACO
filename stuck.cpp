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

struct Event {
    int t, e, n, s; // format is (time, ID of east cow, ID of north cow, 0 for east stops 1 for north stops)
};
bool cmp(const Event& x, const Event& y) { return x.t < y.t; }

int main() {
    setIO();
    int N; cin >> N;

    vector<pii> east;
    //int eWhoStopped[N]; //N is just an upper bound for the size needed
    //memset(eWhoStopped, -1, sizeof(eWhoStopped));
    int eTimeStopped[N];
    fill(eTimeStopped, eTimeStopped+N, INT_MAX);
    vector<pii> north;
    int whoStopped[N];
    memset(whoStopped, -1, sizeof(whoStopped));
    int nTimeStopped[N];
    fill(nTimeStopped, nTimeStopped+N, INT_MAX);

    vi eOriginal;
    vi nOriginal;
    rep(i, 0, N) {
        char dir; int x, y;
        cin >> dir >> x >> y;
        if(dir == 'E') {
            east.pb(mp(x, y));
            eOriginal.pb(i);
        }
        else {
            north.pb(mp(x, y));
            nOriginal.pb(i);
        }
    }
    //sort(all(east)); sort(all(north));

    vector<Event> events; 
    rep(i, 0, east.size()) {
        rep(j, 0, north.size()) {
            if(east[i].f > north[j].f || north[j].s > east[i].s) continue;
            if(east[i].s - north[j].s > north[j].f - east[i].f) {
                events.pb({east[i].s - north[j].s, i, j, 1});
            } else if (east[i].s - north[j].s < north[j].f - east[i].f) {
                events.pb({north[j].f - east[i].f, i, j, 0});
            } // else, both cows meet at the same time and neither stop
        }
    }
    sort(all(events), cmp);
    trav(ev, events) {
        //cout << ev.t << " " << ev.e << " " << ev.n << " " << ev.s << endl;
        if(ev.s == 0 && eTimeStopped[ev.e] == INT_MAX) {
            //cout << nTimeStopped[ev.n] << endl;
            //makes sure the north cow didn't stop before this point
            if(nTimeStopped[ev.n] > east[ev.e].s - north[ev.n].s) {
                whoStopped[eOriginal[ev.e]] = nOriginal[ev.n];
                eTimeStopped[ev.e] = ev.t;
            }
        } else if(ev.s == 1 && nTimeStopped[ev.n] == INT_MAX) {
            if(eTimeStopped[ev.e] > north[ev.n].f - east[ev.e].f) {
                whoStopped[nOriginal[ev.n]] = eOriginal[ev.e];
                nTimeStopped[ev.n] = ev.t;
            }
        }
    }

    //answer computing phase
    int ans[N];
    fill(ans, ans+N, 0);
    rep(i, 0, N) {
        int curr = i;
        while(whoStopped[curr] != -1) {
            ans[whoStopped[curr]]++;
            curr = whoStopped[curr];
        }
    }
    trav(a, ans) cout << a << "\n";
}