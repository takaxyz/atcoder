#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

#define pb push_back
#define eb emplace_back
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

int chk_digits(int x){
  int d = 1;
  while(x/10 > 0){
    d++;
    x/=10;
  }
  return d;
}

int main(){
  int a,n;
  cin >> a >> n;

  int m = 1;
  while(m<=n)m*=10;

  vi d(m,-1);


  queue<int> q;
  q.push(1);
  d[1]=0;

  while(q.size()){
    ll v = q.front();
    q.pop();

    if(v >= 10 && v%10!=0){
      string s = to_string(v);
      string s1 = s.substr(s.size()-1,1) + s.substr(0,s.size()-1);
      int v2 = stoi(s1);
      if(v2 < m && d[v2]==-1 ){
        d[v2]=d[v]+1;
        q.push(v2);
      }
    }

    if(v*a < m && d[v*a]==-1){
      d[v*a] = d[v]+1;
      q.push(v*a);
    }
  }

  cout << d[n] << endl;
}

