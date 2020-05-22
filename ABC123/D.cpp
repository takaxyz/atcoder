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

int main(){
  int x,y,z,k;
  cin >> x >> y >> z >> k;

  vector<ll> a(x), b(y), c(z);

  REP(i,x)cin >> a[i];
  REP(i,y)cin >> b[i];
  REP(i,z)cin >> c[i];
  sort(a.rbegin(), a.rbegin());
  sort(b.rbegin(), b.rbegin());
  sort(c.rbegin(), c.rbegin());

  vector<ll> ab, abc;
  REP(i, min(k,(int)a.size()))REP(j,min(k,(int)b.size()))ab.emplace_back(a[i]+b[j]);
  sort(ab.rbegin(), ab.rend());
  REP(i,min(k,(int)ab.size()))REP(j,min(k,(int)c.size()))abc.emplace_back(ab[i]+c[j]);
  sort(abc.rbegin(), abc.rend());

  REP(i,k)cout << abc[i] << endl;
}

