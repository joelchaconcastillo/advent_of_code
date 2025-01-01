#include <bits/stdc++.h>
using namespace std;
unordered_map<string, unordered_map<string, bool> > sparse_matrix;
unordered_set<string>computers;
int solve(){
   vector<string>computers_vec;
   for(auto i:computers)computers_vec.push_back(i);
   int n = computers_vec.size(), res=0;
   for(int i = 0 ;i < n; i++){
      string A = computers_vec[i];
      for(int j = i+1; j < n; j++){
	  string B = computers_vec[j];
	  if(!sparse_matrix[A][B])continue;
	  for(int k = j+1; k< n; k++){
	      string C = computers_vec[k];
	      if(!(sparse_matrix[B][C] && sparse_matrix[A][C]) )continue;
	      if(A[0]=='t' || B[0]=='t' || C[0]=='t')
		      res++;
	  }
      }
   }
   return res;
}
int main(){
   string st;
   while(cin>>st){
     string A = st.substr(0,2), B = st.substr(3,2);
     computers.insert(A);
     computers.insert(B);
     sparse_matrix[A][B]=true;
     sparse_matrix[B][A]=true;
   }
   cout << solve()<<endl;
}
