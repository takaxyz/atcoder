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

map<int, int > prime_factor(int n) {
  map<int, int > ret;
  for(int i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main(){
  int n;
  cin >> n;
  bool pairwise=true;
  vector<int> cnt(1000001,0);
  REP(i,n){
    int a;
    cin >> a;
    map<int, int> mp = prime_factor(a);
    for(auto v: mp){
      int p = v.first;
      if(cnt[p] != 0){
        pairwise=false;
      }
      cnt[p]++;
    }
  }
  if(pairwise){
    cout << "pairwise coprime" << endl;
  }else{
    bool setwise=true;
    FOR(i,2,1000001){
      if(cnt[i]==n)setwise=false;
    }
    if(setwise){
      cout << "setwise coprime" << endl;
    }else{
      cout << "not coprime" << endl;
    }
  }
}

