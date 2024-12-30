#include <bits/stdc++.h>
using namespace std;
vector<string> grid;
vector<vector<int>>directions = {
   {-1,0},
{0,-1}, {0, 1},
   {1,0}
};
pair<int, int> S, E;
int n, m;
//edmonds karp
long long bfs(vector<pair<int, int>> mustMarked){
   set<pair<int, int>>marked;
   map<pair<int, int>, pair<int, int>> _parent;
   queue<tuple<int, int> >q;//row, col
   
   q.push({S.first, S.second});
   _parent[S]={-1,-1};

   while(!q.empty()){
	 auto [row, col] = q.front(); q.pop();
	 if(row==E.first && col==E.second){
	    pair<int, int> current = E;
	    break;
	 }
	 if(marked.count({row,col})) continue;
	 marked.insert({row,col});
	 for(auto dir:directions){
	     tuple<int, int> _next(row+dir[0], col+dir[1]);
	     auto [next_row, next_col] = _next;
	     if(next_row<0 || next_row==n || next_col<0 || next_col==m)continue;
	     if(marked.count({next_row, next_col}))continue;
	     if(grid[next_row][next_col]=='#')continue;
	     _parent[{next_row, next_col}]= {row, col};
	     q.push(_next);
	 }
   }

   set<pair<int, int>>optimal;
   auto tmp = grid;
   for( auto v = E; v!=S; v=_parent[v]){
	   if(tmp[v.first][v.second]!='E')
	   tmp[v.first][v.second]='*';
	   optimal.insert(v);
   }
   cout <<optimal.size()<<endl;
   for(auto ii:mustMarked){
	   cout << ii.first<<","<<ii.second<<endl;
   }
   for(auto ii:mustMarked){
	   tmp[ii.first][ii.second]='X';
   }

	   if(optimal.size()==64)
   for(auto i:tmp){
	   cout <<i<<endl;
   }
   cout <<endl;
   long long res = optimal.size();
   for(auto ii:mustMarked){
	   tmp[ii.first][ii.second]='X';
	   if(optimal.find(ii)==optimal.end()) res=INT_MAX;
   }
   cout <<res <<endl;
   return res;
}
map<int, int> picosec_cheats;
long long solve2(){
   vector<pair<int, int>> cheat_all;
   auto reference = bfs(cheat_all);
   cout << reference<<endl;
   for(int i = 1 ;i+1 < n; i++){
      for(int j = 1; j+1 < m; j++){
	 if(grid[i][j]=='#')cheat_all.push_back({i, j});
      }
   }
   for(int i = 0; i < cheat_all.size(); i++){
       auto ii = cheat_all[i];
       grid[ii.first][ii.second]='.';
       picosec_cheats[bfs({ii})]++;
       for(int j = i+1; j<cheat_all.size(); j++){
	 auto jj = cheat_all[j];
	 if(abs(jj.first-ii.first)+abs(jj.second-ii.second)!=1)continue;
         grid[jj.first][jj.second]='.';
         picosec_cheats[bfs({ii, jj})]++;
         grid[jj.first][jj.second]='#';
       }
       grid[ii.first][ii.second]='#';
   }
   cout <<reference<<endl;
   for(auto ii:picosec_cheats){
	  cout <<reference-ii.first <<" "<<ii.first<<" " <<ii.second<<endl;
   }

   return 0;
}
int main(){
   string line;
   while(cin>>line)grid.push_back(line);
   n = grid.size(), m=grid.front().size();
   for(int i =0 ; i < n; i++){
      for(int j = 0 ;j < m; j++){
	   if(grid[i][j]=='S')S={i,j};
	   if(grid[i][j]=='E')E={i,j};
      }
   }
   cout << solve2() <<endl;
   return 0;
}
