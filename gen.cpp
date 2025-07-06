#include "bits/stdc++.h"
using namespace std;


#define ll long long
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rnd(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

int main() {
    int n = rnd(1, 15), q = rnd(1, 15);
    cout << n << endl;
    for (int i = 1; i <= n; ++i) cout << rnd(1, 20) << " ";
    cout << endl << q << endl;
    for (int i = 1; i <= q; ++i) {
        int l = rnd(1, n);
        cout << l << " " << rnd(l, n) << endl;
    }
}
