#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>>opcode;
vector<int>input;
map<string, long long> registers;
long long getCombo(int val){
   if(val>=0 && val<=3)return val;
   if(val==4)return registers["A"];
   if(val==5)return registers["B"];
   if(val==6)return registers["C"];
   return 0;
}
long long solve(long long registerA){
   int instruc_pointer=0;
   vector<long long>res;
   registers["A"]=registerA;
   registers["B"]=0;
   registers["C"]=0;
   while(instruc_pointer<opcode.size()){
	int op = opcode[instruc_pointer].first, comb = getCombo(opcode[instruc_pointer].second), literal = opcode[instruc_pointer].second;
	if(op==0) registers["A"] = registers["A"] >> comb; //adv
	else if(op==1) registers["B"] ^= literal; //bxl
	else if(op==2) registers["B"] = comb & 7; //bst
	else if(op==3){ //jnz
	   if(registers["A"]!=0 && instruc_pointer != literal){
		   instruc_pointer = literal;
		   continue;
	   }
	}else if(op==4) registers["B"] ^= registers["C"]; //bxc
	else if(op==5) res.push_back(comb&7); //out
	else if(op==6) registers["B"] = registers["A"]>>comb; //bdv
	else if(op==7) registers["C"] = registers["A"]>>comb; //cdv

	instruc_pointer++;
   }
   return res[0];
}
long long dfs(int index, long long val){
	if(index<0)return val;
	val<<=3;
	cout <<index<<" " <<val<<endl;
	long long target = input[index];
	for(int i = 0; i <8; i++){
	    long long tmp = val+i;
	    if( solve(tmp) == target){ // get in the feasible space!!
	       auto res = dfs(index-1, tmp);
	       if(res>=0)return res;
	    }
	}
	return -1;
}
int main(){
   scanf("Register A: %lld\n", &registers["A"]);
   scanf("Register B: %lld\n", &registers["B"]);
   scanf("Register C: %lld\n", &registers["C"]);
   int op, combo;
   scanf("Program: ");
   while(scanf("%d,%d,", &op, &combo)!=EOF){
	   opcode.push_back({op, combo});
	   input.push_back(op);
	   input.push_back(combo);
   }
   printf("%lld\n", dfs(input.size()-1,0));
   return 0;
}
