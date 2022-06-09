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
  string s;
  cin >> n >> s;

  priority_queue<int> q;
  int cnt1=0;

  FOR(i, 1, n-1){
    if(s.substr(i-1,3)=="ARC"){
      int l = i-1;
      int r = i+1;

      while(l - 1 >= 0 && s[l-1]=='A')l--;
      while(r +  1 < n && s[r+1]=='C')r++;
      int x = min(i-l, r-i);
      if(x==1)cnt1++;
      else q.emplace(x);
    }

  }

  int ans=0;
  while(true){
    if(ans%2==0){
      if(q.size()){
        int v = q.top(); q.pop();
        v--;
        if(v==1)cnt1++;
        else q.emplace(v);
      }else{
        if(cnt1==0)break;
        cnt1--;
      }
    }else{
      if(cnt1>0)cnt1--;
      else{
        if(q.size()==0)break;
        q.pop();        
      }
    }
    ans++;
  }
  cout << ans << endl;
}

