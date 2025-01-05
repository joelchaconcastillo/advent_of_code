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
long long solve_iterative_dp(string &word){
   vector<long long> DP(word.size()+1, 0LL);
   DP[0]=1LL;
   for(int i = 0 ; i < word.size(); i++){
      if(!DP[i])continue;
      for(auto &item:availableTowels){
	 if(i+item.size() > word.size())continue;
	 if(word.substr(i, item.size()) != item)continue;
	 DP[i+item.size()]+=DP[i];
      }
   }
   return DP.back();
}
long long solve(){
   long long res = 0;
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
