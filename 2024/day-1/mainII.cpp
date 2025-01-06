#include <bits/stdc++.h>
using namespace std;
int main(){
   long long l, r;
   vector<long long> left, right;
   while(cin>>l>>r){
	   left.push_back(l);
	   right.push_back(r);
   }
   unordered_map<int, int> rightCount;
   for(auto i:right)rightCount[i]++;
   long long res = 0;
   for(int i = 0 ; i< left.size(); i++){
	  res += left[i]*rightCount[left[i]];
   }
   cout << res<<endl;
   return 0;
}
