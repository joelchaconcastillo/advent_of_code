#include <bits/stdc++.h>
using namespace std;
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
map<pair<int, int>, char>delta2symbol;
map<char, map<char, vector<string>>> shortPathKeyPad, shortPathKeyPadDirectional;
vector<string> getShortestPaths(char start, char end, map<char, pair<int, int>> &key2Pos, int n, int m, vector<string> &keyPadType){
   string res = "";
   queue<tuple<int, int, string>>q;
   set<pair<int, int>>marked;
   q.push({key2Pos[start].first, key2Pos[start].second, ""});
   while(!q.empty()){
	 auto [row, col, path] = q.front(); q.pop();//instead of path we can keep parent pointer
	 if(marked.count({row,col}))continue;
	 marked.insert({row,col});
	 if(keyPadType[row][col]==end){
	    return path;
	 }
	 for(auto delta:direction){
	     int next_row = row+delta[0], next_col = col+delta[1];
	     if(next_row<0||next_row>=n ||next_col<0||next_col>=m)continue;
	     if(keyPadType[next_row][next_col]=='X')continue;
	     q.push({next_row, next_col, path+delta2symbol[{delta[0], delta[1]}]});
	 }
   }
   return res;
}
void computeAllPaths(){
   map<char, pair<int, int>>key2Pos;
   key2Pos['7'] = {0,0}; key2Pos['8'] = {0,1}; key2Pos['9'] = {0,2};
   key2Pos['4'] = {1,0}; key2Pos['5'] = {1,1}; key2Pos['5'] = {1,2};
   key2Pos['1'] = {2,0}; key2Pos['2'] = {2,1}; key2Pos['3'] = {2,2};
   key2Pos['0'] = {3,1}; key2Pos['A'] = {3,2};
   string starts = "0123456789A";
   for(auto i:starts){
      for(auto j:starts){
	  shortPathKeyPad[i][j] = getShortestPaths(i, j, key2Pos, keypad.size(), keypad.front().size(), keypad);
      }
   }
   map<char, pair<int, int>>key2PosDirectional;
   key2PosDirectional['^'] = {0,1};
   key2PosDirectional['A'] = {0,2};
   key2PosDirectional['<'] = {1,0};
   key2PosDirectional['v'] = {1,1};
   key2PosDirectional['>'] = {1,2};
   string startsDirectional = "^<>Av";
   for(auto i:startsDirectional){
      for(auto j:startsDirectional){
	  shortPathKeyPadDirectional[i][j] = getShortestPaths(i, j, key2PosDirectional, directionalKeypad.size(), directionalKeypad.front().size(), directionalKeypad);
      }
   }
}
string layerKeyPad(string st){
  vector<string> res;
  st = "A"+st;
  for(int i = 0 ; i+1 < st.size(); i++){
      res += shortPathKeyPad[st[i]][st[i+1]]+"A";
  }
  return res;
}
string layerKeyPadDirectional(string st){
  string res = "";
  st = "A"+st;
  for(int i = 0 ; i+1 < st.size(); i++){
      res += shortPathKeyPadDirectional[st[i]][st[i+1]]+"A";
  }
  return res;
}
long long solve(string st){
   long long term = stoll(st);
   computeAllPaths();
   vector<string> layer1, layer2, layer3;
   layer1 = layerKeyPad(st);	
   for(auto coded:layer1) layerKeyPadDirectional(coded, layer2);
   for(auto coded:layer2) layerKeyPadDirectional(coded, layer3);
   long long mins=INT_MAX;
   for(auto ii:layer3) mins=min(mins, (long long) ii.size);
   return mins*term;
}
int main(){
delta2symbol[{-1,0}]='^';
delta2symbol[{0,-1}]='<';
delta2symbol[{0,1}]='>';
delta2symbol[{1,0}]='v';

   string line;
   long long sum = 0;
   while(cin>>line){
	   sum+=solve(line);
   }
   cout << sum<<endl;
   return 0;
}
