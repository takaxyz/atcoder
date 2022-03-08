#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

using namespace std;
 
typedef long long int ll;

const ll INF=(ll)1e18;

bool isPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  bool aoki = true;
  FOR(i,a,b+1){
    bool p=false;
    FOR(j,c,d+1){
      if(isPrime(i+j))p=true;
    }
    aoki &= p;
  }

  if(aoki){
    cout << "Aoki" << endl;
  }else{
    cout << "Takahashi" << endl;
  }


}