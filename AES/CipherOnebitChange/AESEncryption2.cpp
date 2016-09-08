/*
2016/09/07
made by eldsg
KAU 2011122025 kimkyoungmin
*/

#include<cstdio>
#include<cstdlib>
#include<map>
#include<string>
#include<iostream>
#include<sstream>

using namespace std;

const string encryptionKey = "2011122025KIMKYO"; // 128bit encryptionKey
const string sBoxInput[] = { 
	"00","01","02","03","04","05","06","07","08","09","0A","0B","0C","0D","0E","0F",
	"10","11","12","13","14","15","16","17","18","19","1A","1B","1C","1D","1E","1F",
	"20","21","22","23","24","25","26","27","28","29","2A","2B","2C","2D","2E","2F",
	"30","31","32","33","34","35","36","37","38","39","3A","3B","3C","3D","3E","3F",
	"40","41","42","43","44","45","46","47","48","49","4A","4B","4C","4D","4E","4F",
	"50","51","52","53","54","55","56","57","58","59","5A","5B","5C","5D","5E","5F",
	"60","61","62","63","64","65","66","67","68","69","6A","6B","6C","6D","6E","6F",
	"70","71","72","73","74","75","76","77","78","79","7A","7B","7C","7D","7E","7F",
	"80","81","82","83","84","85","86","87","88","89","8A","8B","8C","8D","8E","8F",
	"90","91","92","93","94","95","96","97","98","99","9A","9B","9C","9D","9E","9F",
	"A0","A1","A2","A3","A4","A5","A6","A7","A8","A9","AA","AB","AC","AD","AE","AF",
	"B0","B1","B2","B3","B4","B5","B6","B7","B8","B9","BA","BB","BC","BD","BE","BF",
	"C0","C1","C2","C3","C4","C5","C6","C7","C8","C9","CA","CB","CC","CD","CE","CF",
	"D0","D1","D2","D3","D4","D5","D6","D7","D8","D9","DA","DB","DC","DD","DE","DF",
	"E0","E1","E2","E3","E4","E5","E6","E7","E8","E9","EA","EB","EC","ED","EE","EF",
	"F0","F1","F2","F3","F4","F5","F6","F7","F8","F9","FA","FB","FC","FD","FE","FF",
};
const string sBoxOutput[] = {
	"63","7C","77","7B","F2","6B","6F","C5","30","01","67","2B","FE","D7","AB","76",
	"CA","82","C9","7D","FA","59","47","F0","AD","D4","A2","AF","9C","A4","72","C0",
	"B7","FD","93","26","36","3F","F7","CC","34","A5","E5","F1","71","D8","31","15",
	"04","C7","23","C3","18","96","05","9A","07","12","80","E2","EB","27","B2","75",
	"09","83","2C","1A","1B","6E","5A","A0","52","3B","D6","B3","29","E3","2F","84",
	"53","D1","00","ED","20","FC","B1","5B","6A","CB","BE","39","4A","4C","58","CF",
	"D0","EF","AA","FB","43","4D","33","85","45","F9","02","7F","50","3C","9F","A8",
	"51","A3","40","8F","92","9D","38","F5","BC","B6","DA","21","10","FF","F3","D2",
	"CD","0C","13","EC","5F","97","44","17","C4","A7","7E","3D","64","5D","19","73",
	"60","81","4F","DC","22","2A","90","88","46","EE","B8","14","DE","5E","0B","DB",
	"E0","32","3A","0A","49","06","24","5C","C2","D3","AC","62","91","95","E4","79",
	"E7","C8","37","6D","8D","D5","4E","A9","6C","56","F4","EA","65","7A","AE","08",
	"BA","78","25","2E","1C","A6","B4","C6","E8","DD","74","1F","4B","BD","8B","8A",
	"70","3E","B5","66","48","03","F6","0E","61","35","57","B9","86","C1","1D","9E",
	"E1","F8","98","11","69","D9","8E","94","9B","1E","87","E9","CE","55","28","DF",
	"8C","A1","89","0D","BF","E6","42","68","41","99","2D","0F","B0","54","BB","16",
};
map<char, string> hexToAscii;
map<string, string> sBox;
map<string, string> sInverseBox;
void keySchedule(int a);
void roundKey(int a);
void subBytes();
void shiftRows();
void encMixColumns();
void hexToAsciiInit(){
	hexToAscii['0'] = "0000";
	hexToAscii['1'] = "0001";
	hexToAscii['2'] = "0010";
	hexToAscii['3'] = "0011";
	hexToAscii['4'] = "0100";
	hexToAscii['5'] = "0101";
	hexToAscii['6'] = "0110";
	hexToAscii['7'] = "0111";
	hexToAscii['8'] = "1000";
	hexToAscii['9'] = "1001";
	hexToAscii['A'] = "1010";
	hexToAscii['B'] = "1011";
	hexToAscii['C'] = "1100";
	hexToAscii['D'] = "1101";
	hexToAscii['E'] = "1110";
	hexToAscii['F'] = "1111";
}
void boxInit(){
	for(int i = 0; i<256; i++){
		sBox[sBoxInput[i]] = sBoxOutput[i];
		sInverseBox[sBoxOutput[i]] = sBoxInput[i];
	}
}
char plainText[5][5];
char cipherKey[5][5];
string plainTextHex[5][5];
string cipherKeyHex[5][5];

void printPlainText(){
	printf("Plain Text is : \n");
	for(int i = 0; i<4; i++){
		for(int j = 0; j<4; j++){
			cout << plainTextHex[i][j] << " (" << hexToAscii[plainTextHex[i][j][0]] + hexToAscii[plainTextHex[i][j][1]] << ")  ";
		}
		cout << endl;
	}
}
void printCipherKey(){
	printf("Cipher Key is : \n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j<4; j++){
			cout << cipherKeyHex[i][j] << " (" << hexToAscii[cipherKeyHex[i][j][0]] + hexToAscii[cipherKeyHex[i][j][1]] << ")  ";
		}
		cout << endl;
	}
}

void inputPlainText(){
	char str[3];
	printf("Input PlianText : \n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			scanf("%c", &plainText[j][i]);
			memset(str, 0, sizeof(str));
			sprintf(str, "%02X", plainText[j][i]);
			plainTextHex[j][i] += str;
		}
	}
}


void inputCipherKey(){
	char str[3];
	printf("Input CipherKey : \n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			scanf("\n%c", &cipherKey[j][i]);
			memset(str, 0, sizeof(str));
			sprintf(str, "%02X", cipherKey[j][i]);
			cipherKeyHex[j][i] += str;
		}
	}
}

void process(int count){
	for(int i = 0; i <= count; i++){
		if(i == 0){
//			printf("Start of Round : \n");
			roundKey(i);
		}
		else if(i!=count){
//			printf("%d After subBytes : \n", i);
			subBytes();
//			printf("%d After shiftRows : \n", i);
			shiftRows();	
//			printf("%d After encMixColums : \n", i);
			encMixColumns();
//			printf("%d Start of Round : \n", i+1);
			roundKey(i);
		}
		else{
//			printf("%d After subBytes : \n", i);
			subBytes();
//			printf("%d After shiftRows : \n", i);
			shiftRows();
//			printf("OutPut : \n");
			roundKey(i);
		}
	}
}
void shiftRows(){
	for(int i = 1; i<4; i++){
		for(int j = 0; j<i; j++){
			for(int k = 0; k< 3; k++){
				swap(plainTextHex[i][k], plainTextHex[i][k+1]);
			}
		}
	}
/*
	for(int i = 0; i<4; i++){
		for(int j = 0; j<4; j++){
			cout << plainTextHex[i][j] << " (" << hexToAscii[plainTextHex[i][j][0]] + hexToAscii[plainTextHex[i][j][1]] << ")  ";
		}
		cout << endl;
	}
*/
}
void subBytes(){
	for(int i = 0; i< 4; i++){
		for(int j = 0; j<4; j++){
			plainTextHex[i][j] = sBox[plainTextHex[i][j]];
//			cout << plainTextHex[i][j] << " (" << hexToAscii[plainTextHex[i][j][0]] + hexToAscii[plainTextHex[i][j][1]] << ")  ";
		}
//		cout << endl;
	}	
}

unsigned char gfMultiply(unsigned char h1, unsigned char h2){
	unsigned char p = 0;
	unsigned char counter = 0;
	unsigned char hi_bit_set;
	for(counter = 0; counter < 8; counter++){
		if((h2 & 1)==1) p^=h1;
		hi_bit_set = (h1 & 0x80);
		h1 <<= 1;
		if(hi_bit_set == 0x80) h1^=0x1b;
		h2 >>= 1;
	}
	return p;
}

void encMixColumns(){
	unsigned int ret[4];
	unsigned char b[4];
	char str[4][3];
	for(int i = 0; i<4; i++){
			stringstream a[4];
			for(int j = 0; j<4; j++){
				a[j] << std::hex << plainTextHex[j][i];
				a[j] >> ret[j];
			}
			
//			printf("%d %d %d %d %02X %02X %02X %02X\n", a0, a1, a2, a3, a0, a1, a2, a3);
			b[0] = gfMultiply(0x02, ret[0]) ^ gfMultiply(0x03, ret[1]) ^ gfMultiply(0x01, ret[2]) ^ gfMultiply(0x01, ret[3]);
			b[1] = gfMultiply(0x01, ret[0]) ^ gfMultiply(0x02, ret[1]) ^ gfMultiply(0x03, ret[2]) ^ gfMultiply(0x01, ret[3]);
			b[2] = gfMultiply(0x01, ret[0]) ^ gfMultiply(0x01, ret[1]) ^ gfMultiply(0x02, ret[2]) ^ gfMultiply(0x03, ret[3]);
			b[3] = gfMultiply(0x03, ret[0]) ^ gfMultiply(0x01, ret[1]) ^ gfMultiply(0x01, ret[2]) ^ gfMultiply(0x02, ret[3]);
//			printf("%d %d %d %d %02X %02X %02X %02X\n", b0, b1, b2, b3, b0, b1, b2, b3);
			for(int j = 0; j<4; j++){
				sprintf(str[j], "%02X", b[j]);
				plainTextHex[j][i] = str[j];
			}
	}
/*
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cout << plainTextHex[i][j] << " (" << hexToAscii[plainTextHex[i][j][0]] + hexToAscii[plainTextHex[i][j][1]] << ")  ";
		}
		cout << endl;
	}
*/
}
void roundKey(int con){
	char str[3];
	unsigned int c, d;
	unsigned char ret;
	for(int i = 0; i<4; i++){
		for(int j = 0; j<4; j++){
			stringstream a,b;
			memset(str, 0, sizeof(str));
			a << std::hex << plainTextHex[i][j];
			a >> c;
			b << std::hex << cipherKeyHex[i][j];
			b >> d;
			ret = c^d;
			sprintf(str, "%02X", ret);
			plainTextHex[i][j] = str;
		}
	}
/*
	for(int i = 0; i<4; i++){
		for(int j = 0; j<4; j++){
			cout << plainTextHex[i][j] << " (" << hexToAscii[plainTextHex[i][j][0]] + hexToAscii[plainTextHex[i][j][1]] << ")  ";
		}
		cout << endl;
	}
*/
	keySchedule(con);
}
void keySchedule(int con){
	string testHex[4];
	for(int i = 0; i<4; i++) testHex[i] = cipherKeyHex[i][3];
	for(int i = 0; i<3; i++){
		swap(testHex[i], testHex[i+1]);
	}
	for(int i = 0; i<4; i++){
		testHex[i] = sBox[testHex[i]];
	}
	char str[3];
	for(int i = 0; i<4; i++){
		unsigned int aa= 1;
		stringstream a, b;
		unsigned int c, d;
		unsigned char ret;
		memset(str, 0, sizeof(str));
		a << std::hex << cipherKeyHex[i][0];
		a >> c;
		b << std::hex << testHex[i];
		b >> d;
		ret = c^d;
///		printf("%02X %02X %02X\n", c, d, ret);
		if(i == 0 && con <= 7) ret ^= (aa << con);
		else if(i==0 && con == 8) ret ^= 0x1b;
		else if(i==0 && con == 9) ret ^= 0x36;
//		printf("%02X\n", ret);
		sprintf(str, "%02X", ret);
		cipherKeyHex[i][0] = str;
	}
	for(int i = 1; i<4; i++){
		for(int j = 0; j<4; j++){
			stringstream a, b;
			unsigned int c, d;
			unsigned char ret;
			memset(str, 0, sizeof(str));
			a << std::hex << cipherKeyHex[j][i];
			a >> c;
			b << std::hex << cipherKeyHex[j][i-1];
			b >> d;
			ret = c^d;
//			printf("%02X %02X %02X\n", c, d, ret);
			sprintf(str, "%02X", ret);
			cipherKeyHex[j][i] = str;
		}
	}
	if(con != 10){
		cout << con+1 << " Round Key : " << endl;
		for(int i = 0; i<4; i++){
			for(int j = 0; j<4; j++){
				cout << cipherKeyHex[i][j] << " (" << hexToAscii[cipherKeyHex[i][j][0]] + hexToAscii[cipherKeyHex[i][j][1]] << ")  ";
			}
			cout << endl;
		}
	}
}
void testinit(){
	cipherKeyHex[0][0] = "2B", cipherKeyHex[0][1] = "28", cipherKeyHex[0][2] = "AB", cipherKeyHex[0][3] = "09";
	cipherKeyHex[1][0] = "7E", cipherKeyHex[1][1] = "AE", cipherKeyHex[1][2] = "F7", cipherKeyHex[1][3] = "CF";
	cipherKeyHex[2][0] = "15", cipherKeyHex[2][1] = "D2", cipherKeyHex[2][2] = "15", cipherKeyHex[2][3] = "4F";
	cipherKeyHex[3][0] = "16", cipherKeyHex[3][1] = "A6", cipherKeyHex[3][2] = "88", cipherKeyHex[3][3] = "3C";

	plainTextHex[0][0] = "32", plainTextHex[0][1] = "88", plainTextHex[0][2] = "31", plainTextHex[0][3] = "E0";
	plainTextHex[1][0] = "43", plainTextHex[1][1] = "5A", plainTextHex[1][2] = "31", plainTextHex[1][3] = "37";
	plainTextHex[2][0] = "F6", plainTextHex[2][1] = "30", plainTextHex[2][2] = "98", plainTextHex[2][3] = "07";
	plainTextHex[3][0] = "A8", plainTextHex[3][1] = "8D", plainTextHex[3][2] = "A2", plainTextHex[3][3] = "34";
}
int main(){
	boxInit();
	hexToAsciiInit();
//	testinit();
	inputPlainText();
	inputCipherKey();
	printPlainText();
	printCipherKey();
	process(10);
}

