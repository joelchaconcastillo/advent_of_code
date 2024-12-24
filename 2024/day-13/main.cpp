#include <bits/stdc++.h>
using namespace std;
int main(){
   int a1,a2,a3,b1,b2,b3;
   long long res = 0;
   while(scanf("Button A: X+%d, Y+%d\n", &a1, &b1)!=EOF){
       scanf("Button B: X+%d, Y+%d\n", &a2, &b2);
       scanf("Prize: X=%d, Y=%d\n", &a3, &b3);
       int D = a1*b2-a2*b1;
       if(D==0)continue;
       int A = (a3*b2-a2*b3)/D;
       int B = (a1*b3-a3*b1)/D;
       if(a1*A+a2*B!=a3 || b1*A+b2*B!=b3)continue;
       res += A*3+B;
   }
   printf("%lld\n",res);
   return 0;
}
