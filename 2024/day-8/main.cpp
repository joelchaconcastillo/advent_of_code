#include <bits/stdc++.h>
using namespace std;
int main(){
   vector<string> grid;
   string line;
   while( cin>>line){
      grid.push_back(line);
   }
   int n = grid.size(), m = grid.front().size();
   unordered_map<char, vector<pair<int, int>>> pos;
   for(int i = 0 ; i <n; i++){
      for(int j = 0; j < m; j++){
	  if(grid[i][j]=='.')continue;
	  pos[grid[i][j]].push_back({i, j});
      }
   }
   set<pair<int, int>> res;
   for(auto positions:pos){
       for(auto ii:positions.second){
	   for(auto jj:positions.second){
		   if(ii==jj)continue;
		int deltaRows = -ii.first+jj.first;
		int deltaCols = -ii.second+jj.second;
		int R = ii.first - deltaRows;
		int C = ii.second - deltaCols;
		if(R<0||R>=n||C<0||C>=m)continue;
		res.insert({R, C});
	   }
       }
   }
   cout <<res.size()<<endl;
   return 0;
}
