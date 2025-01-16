#include <bits/stdc++.h>
using namespace std;
map<pair<long long, int>, long long>memo;

long long dp(long long number, int ite){
   if(ite==0)return 1;
   pair<long long, int> key(number, ite);
   if(memo.count(key)) return memo[key];

   if(number==0) return memo[key] = dp(1, ite-1);
   auto num_str = to_string(number);
   if(num_str.size()%2==0){
      auto left_side = num_str.substr(0, num_str.size()/2);
      auto right_side = num_str.substr(num_str.size()/2, num_str.size()/2);
      return memo[key] = dp(stol(left_side), ite-1) + dp(stol(right_side), ite-1);
   }
   return memo[key] = dp(number*2024, ite-1);
}
int main(){
   vector<long long> stones;
   long long stone;
   while(cin>>stone)stones.push_back(stone);
   long long sum = 0;
   for(auto ii:stones){
       sum += dp(ii, 75);
   }
   cout << sum <<endl;
   return 0;
}
