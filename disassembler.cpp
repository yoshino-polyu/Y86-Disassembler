#include<bits/stdc++.h>
using namespace std;

char s[1000005];

unordered_map<string, string> mp;
unordered_map<char, string> r;

void O2S(){
	string key, val;
	key = "00", val = "halt";
	mp[key] = val;
	key = "10", val = "nop";
	mp[key] = val;
	key = "20", val = "rrmovq";
	mp[key] = val;
	key = "21", val = "cmovle";
	mp[key] = val;
	key = "22", val = "cmovl";
	mp[key] = val;
	key = "23", val = "cmove";
	mp[key] = val;
	key = "24", val = "cmovne";
	mp[key] = val;
	key = "25", val = "cmovqe";
	mp[key] = val;
	key = "26", val = "cmovq";
	mp[key] = val;
	key = "30", val = "irmovq";
	mp[key] = val;
	key = "40", val = "rmmovq";
	mp[key] = val;
	key = "50", val = "mrmovq";
	mp[key] = val;
	key = "60", val = "addq";
	mp[key] = val;
	key = "61", val = "subq";
	mp[key] = val;
	key = "62", val = "andq";
	mp[key] = val;
	key = "63", val = "xorq";
	mp[key] = val;
	key = "70", val = "jmp";
	mp[key] = val;
	key = "71", val = "jle";
	mp[key] = val;
	key = "72", val = "jl";
	mp[key] = val;
	key = "73", val = "je";
	mp[key] = val;
	key = "74", val = "jne";
	mp[key] = val;
	key = "75", val = "jge";
	mp[key] = val;
	key = "76", val = "jg";
	mp[key] = val;
	key = "80", val = "call";
	mp[key] = val;
	key = "90", val = "ret";
	mp[key] = val;
	key = "A0", val = "pushq";
	mp[key] = val;
	key = "B0", val = "popq";
	mp[key] = val;
	
	key = "0", val = "%rax";
	r[key[0]] = val;
	key = "1", val = "%rcx";
	r[key[0]] = val;
	key = "2", val = "%rdx";
	r[key[0]] = val;
	key = "3", val = "%rbx";
	r[key[0]] = val;
	key = "4", val = "%rsp";
	r[key[0]] = val;
	key = "5", val = "%rbp";
	r[key[0]] = val;
	key = "6", val = "%rsi";
	r[key[0]] = val;
	key = "7", val = "%rdi";
	r[key[0]] = val;
	key = "8", val = "%r8";
	r[key[0]] = val;
	key = "9", val = "%r9";
	r[key[0]] = val;
	key = "A", val = "%r10";
	r[key[0]] = val;
	key = "B", val = "%r11";
	r[key[0]] = val;
	key = "C", val = "%r12";
	r[key[0]] = val;
	key = "D", val = "%r13";
	r[key[0]] = val;
	key = "E", val = "%r14";
	r[key[0]] = val;
	key = "F", val = " ";
	r[key[0]] = val;
	
	
	string s;
	getline(cin, s);
	int n = s.size();
	for(int i = 0; i < n; i += 2)
		if(s[i] <= 'z' && s[i] >= 'a') s[i] = s[i] - 'a' + 'A';
	int p = 0;
	for(int i = 0; i < n; i += 2){
		string a;
		a = s.substr(i, 2);
		//cout<<a<<"?"<<endl;
		cout<<mp[a]<<" ";
		if(a[0] == '0' || a[0] == '1' || a[0] == '9') {
			cout<<endl;
		}
		if(a[0] == '2' || a[0] == '6' || a[0] == 'A' || a[0] == 'B'){
			cout<<r[s[i+2]]<<" "<<r[s[i+3]]<<endl;
			i+=2;
		}
		if(a[0] == '3' || a[0] == '4' || a[0] == '5'){
			string b;
			b = s.substr(i+4, 16);
			reverse(b.begin(), b.end());
			for(int j = 0; j <= 16; j+=2){
				char c = b[j];
				b[j] = b[j+1];
				b[j+1] = c;
			}
			if(a[0] == '3') cout<<"$0x"<<b<<" , "<<r[s[i+3]]<<endl;
			if(a[0] == '4') cout<<r[s[i+2]]<<" , $0x"<<b<<"("<<r[s[i+3]]<<")"<<endl;
			if(a[0] == '5') cout<<"$0x"<<b<<"("<<r[s[i+3]]<<")"<<" , "<<r[s[i+2]]<<endl;
			i += 18;
		}
		if(a[0] == '7' || a[0] == '8'){
			string b;
			b = s.substr(i+2, 16);
			reverse(b.begin(), b.end());
			for(int j = 0; j <= 16; j+=2){
				char c = b[j];
				b[j] = b[j+1];
				b[j+1] = c;
			}
			cout<<"$0x"<<b<<endl;
			i += 16;
		}
	}
}

int main() {
	O2S();
	return 0;
}