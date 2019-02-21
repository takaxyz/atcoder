#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#include <cassert>


typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<llll> vllll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define eb  emplace_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define repC3(vari,varj,vark,n)  for(int vari=0;vari<(n)-2;++vari)for(int varj=vari+1;varj<(n)-1;++varj)for(int vark=varj+1;vark<(n);++vark)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair

template<class T> inline void amin(T & a, T const & b) { a = min(a, b); }
template<class T> inline void amax(T & a, T const & b) { a = max(a, b); }
template<typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template<typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }


ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }

const ll MOD=1000000007LL;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

#define INTSPACE 12
char _buf[INTSPACE*1000000 + 3];

int loadint() {
    if (fgets(_buf, INTSPACE+3, stdin)==NULL) return 0;
    return atoi(_buf);
}

int loadvec(vector<int>& v, int N=-1) {
    if (N == 0) {
        v.clear();
        return 0;
    }
    if (N == -1) {
        N = loadint();
        if (N==0) return 0;
    }
    int bufsize = INTSPACE*N + 3;
    if (fgets(_buf, bufsize, stdin)==NULL) return 0;
    v.resize(N);

    int i=0;
    bool last = false;
    for (char *p=&_buf[0]; ;) {
        char *q = p;
        while (*q > ' ') ++q;
        if (*q == 0x0D || *q == 0x0A) last = true;
        *q = 0;
        v[i++] = atoi(p);
        if (last || i == N) break;
        p = q+1;
    }
    return i;
}
void read_cr() {
    fgets(_buf, 256, stdin);
}



typedef enum { MINIMUM, MAXIMUM } MinMax;

template <typename T>
class SegmentTree {
public:
    int bit_, N;
    vector<T> buf_;
    T invalid;
    MinMax mode;

    SegmentTree(int size, MinMax mode=MINIMUM) : mode(mode) {
        N = 1;
        bit_ = 0;
        while (N < size) {
            N *= 2;
            ++bit_;
        }

        switch (mode) {
            case MINIMUM:
                if (sizeof(T) == 4) {
                    invalid = INT_MAX;
                } else if (sizeof(T) == 8) {
                    invalid = LLONG_MAX;
                }
                break;
            case MAXIMUM:
                if (sizeof(T) == 4) {
                    invalid = INT_MIN;
                } else if (sizeof(T) == 8) {
                    invalid = LLONG_MIN;
                }
                break;
        }
        buf_.assign(N*2, invalid);
    }

    T merge(T l, T r) {
        switch (mode) {
            case MINIMUM:
                return min(l, r);
            case MAXIMUM:
                return max(l, r);
        }
    }

    void update(int i, T x) {
        i = N + i - 1;

        if (merge(buf_[i], x) != x) return;

        buf_[i] = x;
        while (i > 0) {
			i = (i - 1) / 2;
			buf_[i] = merge(buf_[i*2+1], buf_[i*2+2]);
        }
    }

    T query(int lo, int hi) {
        return query(lo, hi, 0, 0, N);
    }
    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return invalid;

        if (a <= l && r <= b) {
            return buf_[k];
        } else {
			T lv = query(a, b, 2*k+1, l, (l+r)/2);
			T rb = query(a, b, 2*k+2, (l+r)/2, r);
			return merge(lv, rb);
        }
    }

    void dump() {
    }
};


ll solve(int N, vi& h, vi& a) {
    int hmax = *max_element(ALL(h));
    SegmentTree<ll> st(hmax+1, MAXIMUM);

    rep(i,N){
        ll maxval = max(0LL, st.query(0, h[i]));
        ll newval = maxval + a[i];
        st.update(h[i], newval);

        st.dump();
    }

    return st.query(0, hmax+1);
}

int main() {
    int N; scanf("%d",&N); read_cr();
    vi h(N), a(N);
    loadvec(h,N);
    loadvec(a,N);
    cout << solve(N,h,a) << endl;
    return 0;
}

