#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ppp;
int n, m;
long long optimalCost = INT_MAX;
pair<int, int> start, _end;
vector<long long> dist;
vector<vector<ppp>> parents;
vector<string> grid;
unordered_map<int, pair<int, int>> directions{
   {0,{0,1}}, {1,{1,0}},{2,{0,-1}}, {3,{-1,0}}
};
long long hashing(int row, int col, int dir){
   return row*1e5+col*1e2+dir;
}
void dfs(int row, int col, int dir, long long current_cost, int prevrow, int prevcol, int prevdir){
   auto key = hashing(row, col, dir);
   if(grid[row][col]=='#')return;
   if(dist[key] < current_cost)return;//prune

   if(row==_end.first  && col == _end.second){
     optimalCost = min(optimalCost, current_cost);
   }
   if(dist[key] == current_cost){
      parents[key].push_back({prevrow, prevcol, prevdir});
      return;
   }
   parents[key]= {{prevrow, prevcol, prevdir}};
   dist[key] = current_cost;
   for(int i = 0; i < 4; i++){
      long long cost = 1L;
      if(i==1 || i==3)cost+=1000L;
      else if(i==2)cost+=2000L;
      int next_dir=(dir+i)%4, 
	  next_row = row+directions[next_dir].first, 
	  next_col = col+directions[next_dir].second;
      if(grid[next_row][next_col]=='#')continue;
      dfs(next_row, next_col, next_dir, current_cost+cost, row, col,dir);
   }
}
void parse_input(){
  string line;
  while(cin>>line)grid.push_back(line);
  n = grid.size(), m = grid.front().size();
  cout << "rows... " << n << " cols..."<<m<<endl;
  for(int i = 0 ; i < n;  i++){
      for(int j = 0; j < m; j++){
	      if(grid[i][j]=='S')start = {i,j};
	      if(grid[i][j]=='E')_end = {i,j};
      }
  }
  dist.assign(hashing(n,m,4), INT_MAX);
  parents.assign(hashing(n,m,4), {});
}
//reconstruct all optimal paths
long long tracking(){
   	queue<tuple<int, int, int>>qq;
	set<pair<int, int>>paths;
	for(int dir=0; dir< 4; dir++){
	  auto key = hashing(_end.first, _end.second, i);
	  if( dist[key] !=  optimalCost)continue;//no a feasible direction!!!
	  qq.push({_end.first, _end.second, i});
	}
	while(!qq.empty()){
	     auto [row,col, dir] = qq.front(); qq.pop();
	     auto key = hashing(row, col, dir);
	     if(row==-1)continue;
	     paths.insert({row, col});
	     for(auto _to:parents[key]){
		qq.push(_to);
	     }
	}
   return paths.size();
}
int main(){
  parse_input();
  dfs(start.first, start.second, 0, 0, -1, -1, -1);
  long long bestPathCount = tracking();
  cout << optimalCost<< " " <<bestPathCount <<endl;
  return 0;
}
