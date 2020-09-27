#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("No"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;



int main() {
  int n;
  scanf("%d",&n);
  vi a(n), b(n);
  cin>>a>>b;
  vi c(MX); // aとbの値の数を数える
  rep(i,n) c[a[i]]++;
  rep(i,n) c[b[i]]++;
  priority_queue<P> q;
  rep(i,MX) if (c[i]) q.emplace(c[i],i); // {個数, 値}のペアを優先度キューにつっこむ
  if (q.top().fi > n) dame; //優先度キューの先頭＝一番個数が多いものがnより大きい場合はNoで終了
  cout<<"Yes"<<endl;
  int rn = n;

  multiset<int> sa, sb; // aとbの値をマルチセットで持つ
  map<int,int> ma, mb; // aとbの値をマップで持つ（値と個数）
  rep(i,n) sa.insert(a[i]);
  rep(i,n) sb.insert(b[i]);
  rep(i,n) ma[a[i]]++;
  rep(i,n) mb[b[i]]++;

  set<P> ps;
  rep(i,n) ps.emplace(a[i],i);  //aの値と位置のペアをセットでもつ
  vi ans(n);

  auto del = [&](int i) {
    c[i]--;
    if (c[i]) q.emplace(c[i],i);
  };
  auto put = [&](int x, int y) {
    sa.erase(sa.find(x));
    sb.erase(sb.find(y));
    del(x);
    del(y);
    ma[x]--;
    if (ma[x] == 0) ma.erase(x);
    mb[y]--;
    if (mb[y] == 0) mb.erase(y);
    auto it = ps.lower_bound(P(x,-1));
    ans[it->se] = y;
    ps.erase(it);
  };

  while (rn) {
    while (c[q.top().se] != q.top().fi) q.pop();
    P p1 = q.top(); q.pop();
    int x = p1.se;
    while (c[q.top().se] != q.top().fi) q.pop();
    if (q.top().fi == rn) {
      P p2 = q.top(); q.pop();
      int y = p2.se;
      if (sa.find(x) == sa.end()) swap(x,y);
      put(x,y);
    } else {
      int y = 0;
      if (sa.find(x) != sa.end()) {
        for (auto it = mb.begin();; ++it) {
          if (it->fi != x) {
            y = it->fi;
            break;
          }
        }
      } else {
        y = x;
        for (auto it = ma.begin();; ++it) {
          if (it->fi != y) {
            x = it->fi;
            break;
          }
        }
      }
      put(x,y);
    }
    --rn;
  }

  cout<<ans<<endl;
  return 0;
}



