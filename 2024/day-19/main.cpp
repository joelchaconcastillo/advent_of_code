#include <bits/stdc++.h>
using namespace std;
set<string> availableTowels;//although we can use a trie, this will work for now..
vector<string>towelGoals;
int n, m;
void load_data(){
   string line;
   getline(cin, line);
   stringstream ss(line);
   string towel;
   while(getline(ss, towel,' ')){
	   if(towel.back()==',')towel.pop_back();
	   availableTowels.insert(towel);
   }
   while(getline(cin, line)){
	   if(line.empty())continue;
	   towelGoals.push_back(line);
   }
}
unordered_map<int, bool>dp;
bool backT(int idx, string &word){
   if(idx==word.size())return true;
   if(dp.count(idx))return dp[idx];
   for(auto &item:availableTowels){
      if(idx+item.size()>word.size()) continue;
      if(word.substr(idx, item.size()) != item) continue;
      if(backT(idx+item.size(), word)) return dp[idx]=true;
   }
   return dp[idx]=false;
}
int solve_backtracking_dp(){
   int res = 0;
   for(auto &towel: towelGoals){
      dp.clear();
      res += backT(0, towel);
   }
   return res;
}
int solve_iterative_dp(string &word){
   vector<bool> DP(word.size()+1, false);
   DP[0]=true;
   for(int i = 0 ; i < word.size(); i++){
      if(!DP[i])continue;
      for(auto &item:availableTowels){
	 if(i+item.size() > word.size())continue;
	 if(word.substr(i, item.size()) != item)continue;
	 DP[i+item.size()]=true;
      }
   }
   return DP.back();
}
int solve(){
   int res = 0;
   for(auto &item: towelGoals) res += solve_iterative_dp(item);
   return res;
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   load_data();
   n = availableTowels.size();
   m = towelGoals.size();
   cout << n << " "<<m <<endl;
   cout << solve()<<endl;
   return 0;
}
