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


bool f2(ll x, ll y, ll a, ll b){
  ll z = (a + x - 1)/x;
  if((y - z) * x >= b)return true;
  else return false;
}

bool f1(ll x,ll y, ll a, ll b, ll c){
  ll z = (a + x - 1)/x;
  if(y-z <= 0)return false;

  if(f2(y-z, x, b, c)){
    return true;
  }else{
    return f2(x,y-z,b,c);
  }
}


int main(){
  ll x,y,a,b,c;
  cin >> x >> y >> a >> b >> c;

  REP(_,2){
    REP(__,3){
      if(f1(x,y,a,b,c)){
        cout << "Yes" << endl;
        return 0;
      }
      swap(a,b); swap(b,c);
    }
    swap(x,y);
  }

  cout << "No" << endl;
}

