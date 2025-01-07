#include <bits/stdc++.h>
using namespace std;
int nx, ny;
void simulate(int &px, int &py, int vx, int vy){
   for(int i = 0 ; i < 100; i++){
	   px=(px+nx+vx)%nx;
	   py=(py+ny+vy)%ny;
   }
}
int main(){
   int px,py,vx,vy;
   nx=101,ny=103;
   vector<int>lpx, lpy;
   while(scanf("p=%d,%d v=%d,%d\n", &px, &py, &vx, &vy)!=EOF){
	simulate(px, py, vx, vy);
	lpx.push_back(px);
	lpy.push_back(py);
   }
   long long q1=0,q2=0,q3=0,q4=0;
   for(int i = 0 ; i < lpx.size(); i++){
       if(lpx[i] > nx/2 && lpy[i]<ny/2)q1++;
       else if(lpx[i] < nx/2 && lpy[i]<ny/2)q2++;
       else if(lpx[i] < nx/2 && lpy[i]>ny/2)q3++;
       else if(lpx[i] > nx/2 && lpy[i]>ny/2)q4++;
   }
   cout << q1*q2*q3*q4<<endl;
   return 0;
}
