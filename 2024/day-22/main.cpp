#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> sub_sequences_scores;
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
int hashing(int a, int b, int c, int d){
	a+=10, b+=10, c+=10, d+=10;
	return a+b*100+c*10000+d*1000000;
}
void generate_sequence(long long secret_number){
   vector<int> delta_sequence, scores;
   long long prev = secret_number;
   unordered_set<int>marked;
   for(int i = 0 ; i < 2000; i++){
	   secret_number = iteration(secret_number);
	   delta_sequence.push_back((secret_number%10)-(prev%10));
	   if(i>=3){
	      int key = hashing(delta_sequence[i-3], delta_sequence[i-2], delta_sequence[i-1], delta_sequence[i]);
	      if(!marked.count(key))
	      sub_sequences_scores[key] += secret_number%10;
	      marked.insert(key);
	   }
	   prev = secret_number;
   }
}
long long solve(){
   long long secret_number;
   long long res = 0;
   while(cin>>secret_number) generate_sequence(secret_number);
   //try all subsequences!!
   int cont=0;
   for(auto [_sub_seq, score]:sub_sequences_scores){
       res = max(res, (long long)score);
   }
   return res;
}
int main(){
   cout << solve() <<endl;
   return 0;
}
