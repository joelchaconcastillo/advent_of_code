#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> direction = {
	{-1,0},
       {0,-1}  ,{0,1},
	 {1,0}
};
long long solve(vector<string> &grid, pair<int, int> current){
	if(grid[current.first][current.second]=='9'){
		return 1;
	}
	long long res=0;
	for(auto next:direction){
	    pair<int, int> nextcurrent = {current.first+next[0], current.second+next[1]};
	    if(nextcurrent.first<0||nextcurrent.second<0 ||nextcurrent.first>=n||nextcurrent.second>=m) continue;
	    if(grid[nextcurrent.first][nextcurrent.second]-grid[current.first][current.second] !=1)continue;
	    res+=solve(grid, nextcurrent);
	}
	return res;
}
int main(){
   vector<string> grid;
   string line;
   while(cin>>line) grid.push_back(line);
   n=grid.size(), m=grid.front().size();
   long long res = 0;
   for(int i = 0 ;i < n; i++){
       for(int j = 0 ; j < m; j++){
	   if(grid[i][j]=='0'){
		   res+=solve(grid, {i,j});
	   }
       }
   }
   cout << res <<endl;
   return 0;
}
