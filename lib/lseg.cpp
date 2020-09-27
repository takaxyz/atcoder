#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second

#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

using ll = long long int;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;
template <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat, lazy;
    RMQ(int n_) : n(), dat(n_ * 4, INF), lazy(n_ * 4, INF) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }
    /* lazy eval */
    void eval(int k) {
        if (lazy[k] == INF) return;  // 更新するものが無ければ終了
        if (k < n - 1) {             // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = lazy[k];
            lazy[k * 2 + 2] = lazy[k];
        }
        // 自身を更新
        dat[k] = lazy[k];
        lazy[k] = INF;
    }
    void update(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = x;
            eval(k);
        } else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return INF;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    /* debug */
    inline T operator[](int a) { return query(a, a + 1); }
    void print() {
        for (int i = 0; i < 2 * n - 1; ++i) {
            cout << dat[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 2 * n - 1; ++i) {
            cout << lazy[i] << " ";
        }
        cout << endl;
    }
};

int main(){
  RMQ<int> rmq(8);
  rmq.update(0,1,3);
  rmq.update(1,2,5);
  rmq.update(2,3,2);
  rmq.update(3,4,11);
  rmq.update(4,5,9);
  rmq.update(5,6,1);
  rmq.update(6,7,20);
  rmq.update(7,8,8);
  rmq.print();
  rmq.update(3,7,2);
  rmq.print();
}

