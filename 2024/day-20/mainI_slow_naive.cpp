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
long long bfs(){
   set<pair<int, int>>marked;
   queue<tuple<int, int, int>>q;//row, col, time
   q.push({S.first, S.second, 0});
   while(!q.empty()){
	 auto [row, col, time] = q.front(); q.pop();
	 if(row==E.first && col==E.second){
	   return time;
	 }
	 if(marked.count({row,col})) continue;
	 marked.insert({row,col});
	 for(auto dir:directions){
	     tuple<int, int, int> _next(row+dir[0], col+dir[1], time+1);
	     auto [next_row, next_col, next_time] = _next;
	     if(next_row<0 || next_row==n || next_col<0 || next_col==m)continue;
	     if(grid[next_row][next_col]=='#')continue;
	     q.push(_next);
	 }
   }
   return 0;
}
map<int, int> picosec_cheats;
set<pair<int, int>>marked;
map<pair<int, int>, int> minTime;

long long solve(){
   auto reference = bfs();
   int max_cheat_time=2;
   cout << "reference "<< reference<<endl;
   vector<unordered_map<int, unordered_map<int, bool>>> marked; marked.push_back({});
   queue<tuple<int, int, int, int, int> >q;//row, col, time, cheat, markedidx
   q.push({S.first, S.second, 0, max_cheat_time, 0});
   int save=0;
   while(!q.empty()){
	 auto [row, col, time, cheat, idx_marked] = q.front(); q.pop();
	 if( time > reference-save)continue;
	 if(row==E.first && col==E.second){
	   picosec_cheats[time]++;
	   continue;
	 }
	 if(time%1000==0)cerr <<time<<" - "<<marked.size()<<endl;
	 if(grid[row][col]=='#' && cheat<=0)continue;
	 if(marked[idx_marked][row].count(col)) continue;
	 marked[idx_marked][row][col]=true;
	 for(auto dir:directions){
	     tuple<int, int, int, int, int > _next(row+dir[0], col+dir[1], time+1, cheat, idx_marked);
	     auto [next_row, next_col, next_time, next_cheat, next_idx_marked] = _next;
	     if(next_row<0 || next_row==n || next_col<0 || next_col==m)continue;
	     if(marked[idx_marked][next_row].count(next_col))continue;
	     if(grid[next_row][next_col]=='#' && cheat==2){
	       marked.push_back(marked[idx_marked]);
	       q.push({next_row, next_col, next_time, next_cheat-1, marked.size()-1});
	     }else if(cheat==1){
	       marked.push_back(marked[idx_marked]);
	       q.push({next_row, next_col, next_time, next_cheat-1, marked.size()-1});
	     }
	     else q.push(_next);
	 }
   }
   long long res=0;
   for(auto ii:picosec_cheats){
       if(reference-ii.first>=save){
	  res+=ii.second;
	  cout <<reference-ii.first <<" "<<ii.second<<endl;
       }
   }
   return res;
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
   cout << solve() <<endl;
   return 0;
}
