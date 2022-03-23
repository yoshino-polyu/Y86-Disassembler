// 枚举所有的zf, sf, of的所有组合, 然后看看各个组合的结果是什么. 
#include<bits/stdc++.h>
using namespace std;

int main() {
	string a;
	cin >> a;
	cout << "zf: zero or not " << endl;
	cout << "sf: negative or not " << endl;
	cout << "of: signed overflow " << endl;
	if (a == "jmp") {
		cout << "direct jump" << endl;
	}
	if (a == "je") {
		printf("zf 0 res 0\n");
		printf("zf 1 res 1\n");
	}
	if (a == "jne") {
		printf("zf 0 res 1\n");
		printf("zf 1 res 0\n");
	}
	if (a == "js") {
		printf("sf 0 res 0\n");
		printf("sf 1 res 1\n");
	}
	if (a == "jns") {
		printf("sf 0 res 1\n");
		printf("sf 1 res 0\n");
	}
	if (a == "jg") {
		for (int i = 0; i <= 7; i++) {
			bitset<3> p(i);
			bitset<1> sf((i >> 2) & 1);
			bitset<1> of((i >> 1) & 1);
			bitset<1> zf(i & 1);
			cout << "sf " << sf << " of " << of << " zf " << zf << " res " << (~(sf^of)&~zf) << endl;
		}
	}
	if (a == "jge") {
		for (int i = 0; i <= 3; i++) {
			bitset<2> p(i);
			bitset<1> sf((i >> 1) & 1);
			bitset<1> of(i & 1);
			cout << " sf " << sf << " of " << of << " res " << (~(sf ^ of)) << endl;
		}
	}
	if (a == "jl") {
		for (int i = 0; i <= 3; i++) {
			bitset<2> p(i);
			bitset<1> sf((i >> 1) & 1);
			bitset<1> of(i & 1);
			cout << " sf " << sf << " of " << of << " res " << (sf ^ of) << endl;
		}
	}
	if (a == "jle") {
		for (int i = 0; i <= 7; i++) {
			bitset<3> p(i);
			bitset<1> sf((i >> 2) & 1);
			bitset<1> of((i >> 1) & 1);
			bitset<1> zf(i & 1);
			cout << "sf " << sf << " of " << of << " zf " << zf << " res " << ((sf^of)|zf) << endl;
		}
	}
}