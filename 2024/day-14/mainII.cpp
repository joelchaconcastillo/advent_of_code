#include <bits/stdc++.h>
using namespace std;
int nx, ny;
void simulate(vector<int> &lpx, vector<int> &lpy, vector<int> &lvx, vector<int> &lvy){
	for(int i = 0 ; i < lpx.size(); i++){
	   auto &px = lpx[i];
	   auto &py = lpy[i];
	   auto &vx = lvx[i];
	   auto &vy = lvy[i];
	   px=(px+nx+vx)%nx;
	   py=(py+ny+vy)%ny;
	}
}

void printGrid(vector<int>&lpx, vector<int>&lpy){
  vector<string>grid(ny, string(nx, '.'));
  cout << "============"<<endl;
   for(int i = 0; i < lpx.size(); i++){
           grid[lpy[i]][lpx[i]]='#';
   }
   for(auto row : grid){
        cout <<row<<endl;
   }
}
double knn(vector<int> &x, vector<int> &y){
       double avedist=0;
       for(int i = 0 ;i < x.size(); i++){
	   double min_dist = INT_MAX;
	   for(int j = i+1; j < x.size(); j++){
	      min_dist = min(min_dist, (double)abs(x[i]-x[j])+abs(y[i]-y[j]));
	   }
	   avedist+=min_dist;
       }
       return avedist/(double)x.size();
}
int main(){
   int px,py,vx,vy;
   //nx=11,ny=7;
   nx=101,ny=103;
   vector<int>lpx, lpy, lvx, lvy;
   while(scanf("p=%d,%d v=%d,%d\n", &px, &py, &vx, &vy)!=EOF){
	lpx.push_back(px);
	lpy.push_back(py);
	lvx.push_back(vx);
	lvy.push_back(vy);
   }
   double _knn=INT_MAX;
   int time_ast;
   auto lxTree=lpx, lyTree=lpy;
   for(int i = 0 ; i < 10000; i++){
      simulate(lpx, lpy, lvx, lvy);
      if(knn(lpx, lpy) < _knn){
	      _knn=knn(lpx, lpy);
	      time_ast=i;
	      lxTree=lpx, lyTree=lpy;
      }
   }
   printGrid(lxTree, lyTree);
   cout << time_ast+1<<endl;
   return 0;
}
