#include<iostream>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;
 
typedef long long int ll;

const ll INF=(ll)1e18;

int A,B,C,D,E,F;

int main(){
    cin >> A >> B >> C >> D >> E >> F;

    double lim = (double)E / (100+E);

    double m = 0.0;
    int ans_sw = 0;
    int ans_s = 0;
    REP(i,31){
        REP(j,31){
            if(i == 0 && j == 0)continue;

            if((i*A+j*B)*100 > F)break;


            REP(k,3000){
                REP(l,3000){
                    if(k*C+l*D+100*i*A+100*j*B > F)break;

                    double tmp = (double)(k*C+l*D) / (k*C+l*D+(i*A+j*B)*100);
                    if(lim < tmp)continue;

                    if(m<tmp){
                        m = tmp;
                        ans_sw = k*C+l*D+(i*A+j*B)*100;
                        ans_s = k*C+l*D;
                    }
                }
            }
        }
    }
    if(ans_sw > 0){
        cout << ans_sw << " " << ans_s << endl;
    }else{
        cout << A*100 << " " << 0 << endl;
    }
}

