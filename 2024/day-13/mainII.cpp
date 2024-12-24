#include <bits/stdc++.h>
using namespace std;
int main(){
   long long a1,a2,a3,b1,b2,b3;
   long long res = 0;
   while(scanf("Button A: X+%lld, Y+%lld\n", &a1, &b1)!=EOF){
       scanf("Button B: X+%lld, Y+%lld\n", &a2, &b2);
       scanf("Prize: X=%lld, Y=%lld\n", &a3, &b3);
       a3+=10000000000000;
       b3+=10000000000000;
       long long D = a1*b2-a2*b1;
       if(D==0)continue;
       long long A = (a3*b2-a2*b3)/D;
       long long B = (a1*b3-a3*b1)/D;
       if(a1*A+a2*B!=a3 || b1*A+b2*B!=b3)continue;
//       if(A*3+B != AB)cout << A<< " "<<B<<endl;
       res += A*3+B;
   }
   printf("%lld\n",res);
   return 0;
}
