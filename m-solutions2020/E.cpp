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

int main(){
  int n;
  cin >> n;

  multiset<pair<pair<int,int>, int> > ms;

  REP(i,n){
    ll x,y,p;
    cin >> x >> y >> p;
    if(x==0 || y == 0)continue;
    ms.insert(make_pair(make_pair(x,y), p));
  }

  REP(i,n+1){
    if(ms.size()==0){
      cout << 0 << endl;
    }

    ll dist = LINF;
    for(auto v1: ms){
      ll tmp=0;
      ll xx = v1.first.first;
      ll yy = v1.first.second;
      for(auto v2: ms){
        int x  = v2.first.first;
        int y  = v2.first.second;
        int p  = v2.second;
        if(xx==x || yy=y)continue;

        tmp += min(abs(xx-x), abs(yy-y)) * p;
      }


    }
  }

}

