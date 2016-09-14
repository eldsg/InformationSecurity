#include<cstdio>
#include<cmath>
#include<cstdlib>

const int pkey = 3;
const int qkey = 11;
const int plain[3] = { 12, 20, 25};
int cipher[3], makeplain[3];
int n, on, e, d;
int gcd(int a, int b);
void make(){
	n = pkey*qkey;
	on = (pkey-1)*(qkey-1);
	for(int i = 2; i<on; i++){
		int ret = gcd(on, i);
		if(ret == 1) {
			e = i;
			break;
		}
	}
	for(int i = 1;; i++){
		if((e * i)%on == 1){
			d = i;
			break;
		}
	}
}
int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}
int encrypt(int plain){
	int c;
	c = pow(plain, e);
	c %= n;
	return c;
}
int descrypt(int cipher){
	int p;
	p = pow(cipher, d);
	p %= n;
	return p;
}
int main(){
	make();
	for(int i = 0; i<3; i++){
		cipher[i] = encrypt(plain[i]);
		printf("encrypt : %d\n", cipher[i]);
	}
	for(int i = 0; i<3; i++){
		makeplain[i] = descrypt(cipher[i]);
		printf("descrypt: %d\n", makeplain[i]);
	}
}
