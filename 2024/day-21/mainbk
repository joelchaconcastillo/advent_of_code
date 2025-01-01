#include <bits/stdc++.h>
using namespace std;
int max_robots=25;
vector<string> keypad = {
	"789","456", "123", "X0A"
};
vector<string> directionalKeypad = {
	"X^A", "<v>"
};
vector<vector<int>>direction={
      {-1,0},
   {0,-1}, {0,1},
      {1,0}
};
map<char, pair<int, int>> deltas= {
    {'^', {-1, 0}},
    {'<', {0, -1}},
    {'>', {0, 1}},
    {'v', {1, 0}}
};

map<char, pair<int, int>> keyPadPositions = {
    {'7', {0, 0}}, {'8', {0, 1}}, {'9', {0, 2}},
    {'4', {1, 0}}, {'5', {1, 1}}, {'6', {1, 2}},
    {'1', {2, 0}}, {'2', {2, 1}}, {'3', {2, 2}},
    {'0', {3, 1}}, {'A', {3, 2}}
};
map<char, pair<int, int>> directionalKeyPadPositions= {
    {'^', {0, 1}},
    {'A', {0, 2}},
    {'<', {1, 0}},
    {'v', {1, 1}},
    {'>', {1, 2}}
};
void backtrack(string &st, int start, vector<string> &res){
   if(start==st.size()){
     res.push_back(st);
     return;
   }
   bool used[256] = {false};
   for(int i = start; i < st.size(); i++){
       if(used[st[i]])continue;
       used[st[i]]=true;
       swap(st[start], st[i]);
       backtrack(st, start+1, res);
       swap(st[start], st[i]);
   }
}
vector<string> generateFixedCombinations(string &st){
  sort(st.begin(), st.end());
  vector<string> res;
  backtrack(st, 0, res);
  return res;
}
vector<string> generate_unique_permutations(char a, char b, map<char, pair<int, int> > &track, vector<string> &board){
     string instructions="";
     int n = board.size(), m = board.front().size();
     int delta_row = track[a].first-track[b].first, delta_col = track[a].second-track[b].second;
     if(delta_row>0) instructions += string(delta_row,'^');
     else if(delta_row<0)instructions += string(-delta_row, 'v');
     if(delta_col>0) instructions += string(delta_col, '<');
     else if(delta_col<0) instructions += string(-delta_col, '>');
     auto possible_combinations = generateFixedCombinations(instructions);
     vector<string> combinations;
     for(auto comb : possible_combinations){
	 bool valid=true;
         auto current_location = track[a];
	 for(auto move:comb){
	     current_location.first += deltas[move].first;
	     current_location.second += deltas[move].second;
	     if(current_location.first <0 || current_location.first>=n || current_location.second<0 || current_location.second>=m )valid=false;
	     if(valid && board[current_location.first][current_location.second]=='X')valid=false;
	 }
	 if(valid) combinations.push_back(comb+"A");
     }
     return combinations;
}
map<tuple<char, char, int>, long long> memo;

long long dp(char a, char b, int depth, bool useNumericKeyPad=true){
   tuple<char, char, int> state(a,b,depth);
   if(memo.count(state))return memo[state];
   if(depth==0){ //use the keypath! base
     auto combs = generate_unique_permutations(a, b, directionalKeyPadPositions, directionalKeypad);
     long long minLen=1LL<<60;
     for(auto st:combs) minLen = min(minLen, (long long) st.size());
     return memo[state]=minLen;
   }
   vector<string> combs;
   if(useNumericKeyPad)
     combs = generate_unique_permutations(a, b, keyPadPositions, keypad);
   else
     combs = generate_unique_permutations(a, b, directionalKeyPadPositions, directionalKeypad);

   long long best_cost= 1LL<<60;//~LONG_MAX
   for(auto seq:combs){
       seq = "A"+seq;
       long long current_cost = 0;
       for(int i = 0; i+1< seq.size(); i++){
          current_cost += dp(seq[i], seq[i+1], depth-1, false);
       }
       best_cost = min(best_cost, current_cost);
   }
   return memo[state] = best_cost;
}
long long solve(string st){
    auto input = st;
    st = "A"+st;
    long long cost = 0 ;
    for(int i = 0 ;i+1<st.size(); i++){
	 cost += dp(st[i], st[i+1], max_robots);
    }
    return stoll(input)*cost;
}
int main(){
   string line;
   long long sum = 0;
   while(cin>>line){
	   sum+=solve(line);
   }
   cout << sum<<endl;
   return 0;
}
