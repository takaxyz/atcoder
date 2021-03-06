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
  ll n,k;
  cin >> n >> k;

  VI bit(42,0);
  vector<ll> a(n);
  REP(i,n){
    cin >> a[i];
    ll b = a[i];
    REP(j,42){
      bit[j] += b % 2;
      b = (b >> 1);
    }
  }

  //bit[0]: 1ビット目の1の数

  ll kk=k+1;

  for(int i = 41; i>=0; i--){
    if(((kk>>i)&1) == 0)continue;
    ll mask = ~((1<<(i+1)) - 1);

    if( (kk & mask) == 0)continue;

    REP(j,i){
      
    }


    cout << i << " " << kk << " " <<  (kk & mask) << " " << mask << endl;
  }   


}

