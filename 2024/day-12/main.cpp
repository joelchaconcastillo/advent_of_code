#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> markedArea, markedPerimeter;
int n,m;
vector<vector<int>> movement = {
  {-1,0},
 {0,-1}, {0,1},
   {1,0}
};
int dfsArea(pair<int, int> node, vector<string> &grid, char type){
   if(node.first<0 ||node.second<0 ||node.first>=n || node.second>=m)return 0;
   if(grid[node.first][node.second]!=type)return 0;
   if(markedArea.find(node)!=markedArea.end())return 0;
   markedArea.insert(node);
   int res = 1;
   for(auto move_to:movement){
       pair<int, int> next(move_to[0]+node.first, move_to[1]+node.second);
       res += dfsArea(next, grid, type);
   }
   return res;
}
int perimeterCell(pair<int, int> node, vector<string> &grid, char type){
   int totalPerimeter = 0;
   //up
   if(node.first==0)totalPerimeter++;
   else if(grid[node.first-1][node.second]!=type)totalPerimeter++;
   //down
   if(node.first+1==n)totalPerimeter++;
   else if(grid[node.first+1][node.second]!=type)totalPerimeter++;
   //left
   if(node.second==0)totalPerimeter++;
   else if(grid[node.first][node.second-1]!=type) totalPerimeter++;
   //right
   if(node.second+1==m)totalPerimeter++;
   else if(grid[node.first][node.second+1]!=type) totalPerimeter++;
   return totalPerimeter;
}
int dfsPerimeter(pair<int, int> node, vector<string> &grid, char type){
   if(node.first<0 ||node.second<0 ||node.first>=n || node.second>=m)return 0;
   if(grid[node.first][node.second]!=type)return 0;
   if(markedPerimeter.find(node)!=markedPerimeter.end())return 0;
   markedPerimeter.insert(node);
   int res = perimeterCell(node, grid, type);
   for(auto move_to:movement){
       pair<int, int> next(move_to[0]+node.first, move_to[1]+node.second);
       res += dfsPerimeter(next, grid, type);
   }
   return res;
}
int main(){
   vector<string> grid;
   string line;
   while(cin>>line) grid.push_back(line);
   n=grid.size(), m = grid.front().size();
   long long res=0;
   for(int i = 0 ; i < n; i++){
       for(int j  = 0 ;j  < m; j++){
	   int area = dfsArea({i, j}, grid, grid[i][j]);
	   int perimeter = dfsPerimeter({i,j}, grid, grid[i][j]);
	   res += area*perimeter;
       }
   }
   cout << res <<endl;
   return 0;
}
