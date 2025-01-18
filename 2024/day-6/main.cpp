#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> grid;
void _print(vector<string> &_grid){
   for(auto line:_grid){
       cout << line << endl;
   }
   cout <<endl;
}
bool feasible(pair<int, int> &pos, vector<string> &grid){
   return (pos.first >=0 
		      && pos.first <n
		      && pos.second >=0
		      && pos.second <m);
}
bool hasExit(pair<int, int> current){
   auto marked=grid;
   int steps = 0;
   while(steps<n*m){
      //up
      while(feasible(current, grid) 
		      && grid[current.first][current.second]=='.')
	      marked[current.first--][current.second]='X', steps++;
      if(!feasible(current, grid)) return false;
      if(grid[current.first][current.second]=='#') current.first++;
      //right
      while(feasible(current, grid)
		      && grid[current.first][current.second]=='.')
	      marked[current.first][current.second++]='X', steps++;
      if(!feasible(current, grid)) return false;
      if(grid[current.first][current.second]=='#') current.second--;
      //down
      while(feasible(current, grid)
		      && grid[current.first][current.second]=='.')
	      marked[current.first++][current.second]='X', steps++;
      if(!feasible(current, grid)) return false;
      if(grid[current.first][current.second]=='#') current.first--;
      //left
      while(feasible(current, grid)
		      && grid[current.first][current.second]=='.')
		      marked[current.first][current.second--]='X', steps++;
      if(!feasible(current, grid)) return false;
      if(grid[current.first][current.second]=='#') current.second++;
   }
   return true;
}
int main(){
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
   int res=0;
   for(int i = 0 ; i < n; i++){
      for(int j = 0; j < m; j++){
	  if(grid[i][j]=='#')continue;
	  grid[i][j]='#';
	  res += hasExit(current);
//	  _print(grid);
	  grid[i][j]='.';
      }
   }
   cout <<res<<endl;
   return 0;
}
