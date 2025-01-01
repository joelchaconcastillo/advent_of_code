#include <bits/stdc++.h>
using namespace std;
long long MOD=16777216LL;
long long mix(long long secret, long long to_mix){
   return secret^to_mix;
}
long long prune(long long secret){
   return secret%MOD;
}
long long iteration(long long secret_number){
   secret_number = prune(mix(secret_number, secret_number*64LL));
   secret_number = prune(mix(secret_number, secret_number/32LL));
   return prune(mix(secret_number, secret_number*2048LL));
}
long long solve(long long secret_number){
   for(int i = 0 ; i < 2000; i++){
	   secret_number = iteration(secret_number);
   }
   return secret_number;
}
int main(){
   vector<long long> buyers;
   long long secret_numbers, res=0;
   while(cin>>secret_numbers) buyers.push_back(secret_numbers);   
   for(auto secret:buyers){
       res +=solve(secret);
   }
   cout << res<<endl;
   return 0;
}
