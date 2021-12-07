#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 50;

vector<pair<int, int>> lx[N], ly[N];
vector<pair<pair<int, int>, int>> Ly, Lx;
vector<int> Grp[20];
bool chk[1000];
int d[N], u[N], x[N], y[N], l[N], r[N], op[N];
int covx[N];
int fa[N];
void init(int n) {
    for(int i = 1; i <= n; ++i) fa[i] = i;
}
int getf(int n) {
    return fa[n] == n ? fa[n] : fa[n] = getf(fa[n]);
}
void cnet(int x, int y) {
    int fx = getf(x), fy = getf(y);
    fa[fx] = fy;
}

bool chkT(vector<int> G) {
    if(G.size() != 2) return 0;
    int l1 = G[0], l2 = G[1]; // 2 1
    // cout << l1 << " " << l2 << endl;
    // cout << " >>>>>" << d[l1] << " " << u[l1] << " " << x[l1] << " " << l[l2] << " " << r[l2] << " " << y[l2] << endl;
    if(d[l1] < y[l2] && y[l2] == u[l1] && l[l2] < x[l1] && x[l1] < r[l2]) return 1; 
    return 0;
}

bool chkH(vector<int> G) {
    if(G.size() != 3) return 0;
    int l1 = G[0], l2 = G[1], l3 = G[2]; // 3 5 4 / 5 3 4
    if(l2 > 8) return 0;
    if(d[l1] == d[l2] && d[l2] < y[l3] && y[l3] < u[l1] && u[l1] == u[l2] && x[l1] == l[l3] && l[l3] < r[l3] && r[l3] == x[l2]) return 1;
    swap(l1, l2);
    if(d[l1] == d[l2] && d[l2] < y[l3] && y[l3] < u[l1] && u[l1] == u[l2] && x[l1] == l[l3] && l[l3] < r[l3] && r[l3] == x[l2]) return 1;
    return 0;
}

bool chkU(vector<int> G) {
    if(G.size() != 3) return 0;
    int l6 = G[0], l7 = G[2], l8 = G[1];
    if(l6 > 8 || l8 > 8 || l7 <= 8) return 0;
    if(d[l6] == d[l8] && d[l8] == y[l7] && y[l7] < u[l6] && u[l6] == u[l8] && x[l6] == l[l7] && l[l7] < r[l7] && r[l7] == x[l8]) return 1;
    swap(l6, l8);
    if(d[l6] == d[l8] && d[l8] == y[l7] && y[l7] < u[l6] && u[l6] == u[l8] && x[l6] == l[l7] && l[l7] < r[l7] && r[l7] == x[l8]) return 1;
    return 0;
}

bool chkP(vector<int> G) {
    if(G.size() != 4) return 0;
    int l9 = G[0], l10 = G[2], l11 = G[3], l12 = G[1];
    if(l9 > 8 || l12 > 8 || l11 <= 8 || l10 <= 8) return 0;
    if(d[l9] < y[l11] && y[l11] == d[l12] && d[l12] < u[l9] && u[l9] == y[l10] && y[l10] == u[l12] && x[l9] == l[l10] && l[l10] == l[l11] && l[l11] < r[l10] && r[l10] == r[l11] && r[l11] == x[l12]) return 1;
    swap(l9, l12);
    if(d[l9] < y[l11] && y[l11] == d[l12] && d[l12] < u[l9] && u[l9] == y[l10] && y[l10] == u[l12] && x[l9] == l[l10] && l[l10] == l[l11] && l[l11] < r[l10] && r[l10] == r[l11] && r[l11] == x[l12]) return 1;
    swap(l10, l11);
    if(d[l9] < y[l11] && y[l11] == d[l12] && d[l12] < u[l9] && u[l9] == y[l10] && y[l10] == u[l12] && x[l9] == l[l10] && l[l10] == l[l11] && l[l11] < r[l10] && r[l10] == r[l11] && r[l11] == x[l12]) return 1;
    swap(l9, l12);
    if(d[l9] < y[l11] && y[l11] == d[l12] && d[l12] < u[l9] && u[l9] == y[l10] && y[l10] == u[l12] && x[l9] == l[l10] && l[l10] == l[l11] && l[l11] < r[l10] && r[l10] == r[l11] && r[l11] == x[l12]) return 1;
    return 0;
}

bool chkC(vector<int> G) {
    if(G.size() != 3) return 0;
    int l13 = G[0], l14 = G[1], l15 = G[2];
    if(l13 > 8 || l14 <= 8 || l15 <= 8) return 0;
    if(d[l13] == y[l15] && y[l15] < u[l13] && u[l13] ==y[l14] && x[l13] == l[l14] && l[l14] == l[l15] && l[l15] < r[l14] && r[l14] == r[l15]) return 1;
    swap(l14, l15);
    if(d[l13] == y[l15] && y[l15] < u[l13] && u[l13] ==y[l14] && x[l13] == l[l14] && l[l14] == l[l15] && l[l15] < r[l14] && r[l14] == r[l15]) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;

    vector<int> mx, my;
    for(int i = 1; i <= n; ++i) {
        cin >> op[i];
        if(op[i] == 1) cin >> d[i] >> u[i] >> x[i], mx.push_back(x[i]), my.push_back(d[i]), my.push_back(u[i]);
        if(op[i] == 0) cin >> l[i] >> r[i] >> y[i], my.push_back(y[i]), mx.push_back(l[i]), mx.push_back(r[i]);
    }
    sort(mx.begin(), mx.end()); int nx = unique(mx.begin(), mx.end()) - mx.begin(); mx.resize(nx);
    sort(my.begin(), my.end()); int ny = unique(my.begin(), my.end()) - my.begin(); my.resize(ny);
    for(int i = 1; i <= n; ++i) {
        if(op[i] == 0) {
            l[i] = lower_bound(mx.begin(), mx.end(), l[i]) - mx.begin() + 1;
            r[i] = lower_bound(mx.begin(), mx.end(), r[i]) - mx.begin() + 1;
            y[i] = lower_bound(my.begin(), my.end(), y[i]) - my.begin() + 1;
            ly[y[i]].push_back(make_pair(l[i], r[i]));
        } else if(op[i] == 1) {
            d[i] = lower_bound(my.begin(), my.end(), d[i]) - my.begin() + 1;
            u[i] = lower_bound(my.begin(), my.end(), u[i]) - my.begin() + 1;
            x[i] = lower_bound(mx.begin(), mx.end(), x[i]) - mx.begin() + 1;
            lx[x[i]].push_back(make_pair(d[i], u[i]));
        }
    }
    for(int i = 1; i <= nx; ++i) sort(lx[i].begin(), lx[i].end());
    for(int i = 1; i <= ny; ++i) sort(ly[i].begin(), ly[i].end());
    for(int i = 1; i <= nx; ++i) {
        vector<pair<int, int>> tmp;
        int ll = -1, lr = -1;
        for(pair<int, int> x : lx[i]) {
            if(x.first <= lr) lr = max(lr, x.second);
            else {
                if(ll != -1) tmp.push_back(make_pair(ll, lr));
                ll = x.first;
                lr = x.second;
            }
        }
        if(ll != -1) tmp.push_back(make_pair(ll, lr));
        lx[i] = tmp;
    }
    for(int i = 1; i <= ny; ++i) {
        vector<pair<int, int>> tmp;
        int ll = -1, lr = -1;
        for(pair<int, int> x : ly[i]) {
            if(x.first <= lr) lr = max(lr, x.second);
            else {
                if(ll != -1) tmp.push_back(make_pair(ll, lr));
                ll = x.first;
                lr = x.second;
            }
        }
        if(ll != -1) tmp.push_back(make_pair(ll, lr));
        ly[i] = tmp;
    }

    for(int i = 1; i <= nx; ++i) {
        for(pair<int, int> x : lx[i]) {
            Lx.push_back(make_pair(x, i));
        }
    } 
    for(int i = 1; i <= ny; ++i) {
        for(pair<int, int> y : ly[i]) {
            Ly.push_back(make_pair(y, i));
        }
    }

    // puts("SS");

    // cout << Lx.size() << " " << Ly.size() << endl;

    // for(auto x : Lx) {
    //     cout << x.first.first << " " << x.first.second << " " << x.second << "\n";
    // }
    // for(auto x : Ly) {
    //     cout << x.first.first << " " << x.first.second << " " << x.second << "\n";
    // }

  //  cout << Lx.size() << " " << Ly.size() << endl;

    if(Lx.size() != 8 && Ly.size() != 7) {
        puts("No");
        return 0;
    }

    init(15);

    for(int i = 0; i < Lx.size(); ++i) {
        for(int j = 0; j < Ly.size(); ++j) {
            if(Ly[j].first.first <= Lx[i].second && Lx[i].second <= Ly[j].first.second &&
               Lx[i].first.first <= Ly[j].second && Ly[j].second <= Lx[i].first.second) {
                cnet(i + 1, j + 9);
            }
        }
    }

    int cnt = 0;

    for(int i = 1; i <= 8; ++i) {
        d[i] = Lx[i - 1].first.first;
        u[i] = Lx[i - 1].first.second;
        x[i] = Lx[i - 1].second;
    }

    for(int i = 1; i <= 7; ++i) {
        l[i + 8] = Ly[i - 1].first.first;
        r[i + 8] = Ly[i - 1].first.second;
        y[i + 8] = Ly[i - 1].second;
    }

    for(int i = 1; i <= 15; ++i) {
        Grp[getf(i)].push_back(i);
        if(fa[i] == i) ++cnt;
    }

    // cout << cnt << "\n";

    if(cnt != 5) {
        puts("No");
        return 0;
    }

    for(int i = 1; i <= 15; ++i) {
        // for(auto x : Grp[i]) {
        //     cout << x << " ";
        // }
        // cout << endl;
        if(chkT(Grp[i])) chk['T'] = 1;
        if(chkH(Grp[i])) chk['H'] = 1;
        if(chkU(Grp[i])) chk['U'] = 1;
        if(chkP(Grp[i])) chk['P'] = 1;
        if(chkC(Grp[i])) chk['C'] = 1;
    }

    // cout << chk['T'] << " " << chk['H'] << " " << chk['U'] << " " << chk['P'] << " " << chk['C'] << "\n";

    if(chk['T'] && chk['H'] && chk['U'] && chk['P'] && chk['C']) puts("Yes");
    else puts("No");
    return 0;
}