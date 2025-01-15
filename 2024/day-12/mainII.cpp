#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> markedArea, markedPerimeter;
vector<string> grid;
vector<vector<int>>component_ids;
map<int, int>areas, sides;
int n,m;
vector<vector<int>> movement = {
  {-1,0},
 {0,-1}, {0,1},
   {1,0}
};

void get_components(){
   vector<vector<bool> >marked(n, vector<bool> (m, false));
   component_ids.assign(n, vector<int>(m, 0));
   int component_id=0;
   for(int i = 0 ;i < n; i++){
      for(int j = 0; j < m; j++){
	   int size_component = 0;
	   if(marked[i][j])continue;
	   queue<pair<int, int> > q;
	   q.push({i,j});
	   while(!q.empty()){
	      auto [r,c] = q.front(); q.pop();
	      if(marked[r][c])continue;
	      if(grid[r][c]!=grid[i][j])continue;
	      marked[r][c]=true;
	      component_ids[r][c]=component_id;
	      size_component++;
	      for(auto delta:movement){
		    int next_row = r+delta[0], next_col = c+delta[1];
		    if(next_row<0||next_row>=n ||next_col<0 || next_col>=m)continue;
		    if(marked[next_row][next_col])continue;
		    if(grid[next_row][next_col] != grid[i][j])continue;
		    q.push({next_row, next_col});
	      }
	   }
	   areas[component_id] = size_component;
	   component_id++;
      }
   }
}
bool outGrid(pair<int, int> &loci){
    return loci.first < 0 || loci.second< 0 || loci.first>=n || loci.second>=m;
}
void get_sides(){
   vector<vector<bool>> hasLeft(n, vector<bool> (m, false));
   auto hasRight=hasLeft; auto hasDown=hasLeft; auto hasUp=hasLeft;
   for(int i = 0 ; i < n; i++){
      for(int j = 0; j < m; j++){
	  unordered_map< char, pair<int, int> > side = {
	    {'U',{i-1,j}}, {'D', {i+1,j}}, {'L', {i, j-1}}, {'R', {i, j+1}}
	  };
	  //left
	  if(outGrid(side['L']) || grid[side['L'].first][side['L'].second] != grid[i][j]){
	       hasLeft[i][j]=true;
	       sides[component_ids[i][j]] += outGrid(side['U']) || grid[side['U'].first][side['U'].second]!=grid[i][j] || (!hasLeft[side['U'].first][side['U'].second]);
	  }
	  //right
	  if(outGrid(side['R']) || grid[side['R'].first][side['R'].second] != grid[i][j]){
	       hasRight[i][j]=true;
	       sides[component_ids[i][j]] += outGrid(side['U']) || grid[side['U'].first][side['U'].second]!=grid[i][j] || (!hasRight[side['U'].first][side['U'].second]);
	  }
	  //Up
	  if(outGrid(side['U']) || grid[side['U'].first][side['U'].second] != grid[i][j]){
	       hasUp[i][j]=true;
	       sides[component_ids[i][j]] += outGrid(side['L']) || grid[side['L'].first][side['L'].second]!=grid[i][j] || (!hasUp[side['L'].first][side['L'].second]);
	  }
	  //down
 	  if(outGrid(side['D']) || grid[side['D'].first][side['D'].second] != grid[i][j]){
	       hasDown[i][j]=true;
	       sides[component_ids[i][j]] += outGrid(side['L']) || grid[side['L'].first][side['L'].second]!=grid[i][j] || (!hasDown[side['L'].first][side['L'].second]);
	  }
      }
   }

}
int main(){
   string line;
   while(cin>>line) grid.push_back(line);
   n=grid.size(), m = grid.front().size();
   long long res=0;
   get_components();//compute compontes and ids...
   get_sides();
   for(auto ii:areas){
	   res += ii.second *sides[ii.first];
   }
   cout << res <<endl;
   return 0;
}
