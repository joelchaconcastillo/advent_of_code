#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>>found;
int n,m;
vector<vector<int>> direction = {
	{-1,0},
       {0,-1}  ,{0,1},
	 {1,0}
};
void solve(vector<string> &grid, pair<int, int> current){
	if(grid[current.first][current.second]=='9'){
		found.insert(current);
		return ;
	}
	int res=0;
	for(auto next:direction){
	    pair<int, int> nextcurrent = {current.first+next[0], current.second+next[1]};
	    if(nextcurrent.first<0||nextcurrent.second<0 ||nextcurrent.first>=n||nextcurrent.second>=m) continue;
	    if(grid[nextcurrent.first][nextcurrent.second]-grid[current.first][current.second] !=1)continue;
	    solve(grid, nextcurrent);
	}
}
int main(){
   vector<string> grid;
   string line;
   while(cin>>line) grid.push_back(line);
   n=grid.size(), m=grid.front().size();
   long long res = 0;
   for(int i = 0 ;i < n; i++){
       for(int j = 0 ; j < m; j++){
	   found.clear();
	   if(grid[i][j]=='0'){
		   solve(grid, {i,j});
		   res+=found.size();
	   }
       }
   }
   cout << res <<endl;
   return 0;
}
