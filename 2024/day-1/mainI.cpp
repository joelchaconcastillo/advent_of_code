#include <bits/stdc++.h>
using namespace std;
int main(){
   long long l, r;
   vector<long long> left, right;
   while(cin>>l>>r){
	   left.push_back(l);
	   right.push_back(r);
   }
   sort(left.begin(), left.end());
   sort(right.begin(), right.end());
   long long res = 0;
   for(int i = 0 ; i< left.size(); i++){
	res += labs(left[i]-right[i]);
   }
   cout << res<<endl;
   return 0;
}
