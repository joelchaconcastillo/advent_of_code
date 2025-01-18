#include <bits/stdc++.h>
using namespace std;
int n, m;
bool feasible(pair<int, int> &pos, vector<string> &grid){
   return (pos.first >=0 
		      && pos.first <n
		      && pos.second >=0
		      && pos.second <m);
}
int main(){
   vector<string> grid;
   string line;
   while(cin>>line) grid.push_back(line);
   n = grid.size(), m = grid.front().size();
   pair<int, int>current;
   for(int i = 0; i < n; i++){
      for(int j = 0 ; j < m; j++){
	  if(grid[i][j] == '^') current={i, j};
      }
   }
   grid[current.first][current.second]='.';
   auto marked=grid;
   while(true){
      //up
      while(feasible(current, grid) 
		      && grid[current.first][current.second]=='.')
	      marked[current.first--][current.second]='X';
      if(!feasible(current, grid))break;
      if(grid[current.first][current.second]=='#') current.first++;
      //right
      while(feasible(current, grid)
		      && grid[current.first][current.second]=='.')
	      marked[current.first][current.second++]='X';
      if(!feasible(current, grid))break;
      if(grid[current.first][current.second]=='#') current.second--;
      //down
      while(feasible(current, grid)
		      && grid[current.first][current.second]=='.')
	      marked[current.first++][current.second]='X';
      if(!feasible(current, grid))break;
      if(grid[current.first][current.second]=='#') current.first--;
      //left
      while(feasible(current, grid)
		      && grid[current.first][current.second]=='.')
		      marked[current.first][current.second--]='X';
      if(!feasible(current, grid))break;
      if(grid[current.first][current.second]=='#') current.second++;
   }
   int res=0;
   for(auto i:marked)for(auto j:i)res+=j=='X';
   cout <<res<<endl;
   return 0;
}
