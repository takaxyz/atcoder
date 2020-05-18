#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};


mint mpow(int x, int n){
  if(n==0)return 1;

  mint y = mpow(x, n/2);
  y *= y;

  if(n%2==1) y *=x;
  return y;
}

struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
} c(200005);

// ll gcd(ll a, ll b)
// {
//    if (a%b == 0)
//    {
//        return(b);
//    }
//    else
//    {
//        return(gcd(b, a%b));
//    }
// }

int main(){
  int n;
  cin >> n;

  vector<ll> a(n), b(n);
  REP(i,n)cin >> a[i] >> b[i];

  map<pair<ll, ll>, int> mp;
  int zcnt=0;
  REP(i,n){
    if(a[i]==0 && b[i]==0){
      zcnt++;
    }else if(b[i]==0){
      mp[make_pair(-1,0)]++;
    }else if(a[i]==0){
      mp[make_pair(0,1)]++;
    }else{
      ll g = gcd(a[i], b[i]);
      a[i] /= g;
      b[i] /= g;
      if(b[i]<0){
        a[i] = -a[i];
        b[i] = -b[i];
      }
      mp[make_pair(a[i],b[i])]++;
    }
  }

  mint ans =1;

  set<pair<ll, ll>> visited;

  for(auto v: mp){
    pair<ll, ll> p = v.first;
    //if(p.first < 0 )continue;
//    cout << p.first << " " << p.second << " " << v.second << endl;
    
    if(visited.count(p))continue;

    pair<ll, ll> q;
    if(p.first < 0){
      q = make_pair(p.second, -p.first);
    }else{
      q = make_pair(-p.second, p.first);
    }

    if(mp.find(q) != mp.end() && visited.count(q)==0){
//      cout << mp[p] << " " << mp[q] << " " << ((mpow(2,mp[p])-1) + (mpow(2,mp[q])-1) + 1).x << endl;
      visited.insert(q);
      ans *= (((mpow(2,mp[p])-1) + (mpow(2,mp[q])-1) + 1));
    }else{
      ans *= (mpow(2,mp[p]));
    }
//    cout << ans.x << endl;
  }

  ans -= 1;
  ans += zcnt;
  cout << ans.x << endl;
}

