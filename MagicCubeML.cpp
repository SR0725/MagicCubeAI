#include <iostream>
using namespace std;
struct Weitht{
	int W1[16][12];
	int W2[12][12];
	int W3[12][12];
};

void MagicCubeReset(int MagicCubeBlock[6][2][2]);
void MagicCube(int MagicCubeBlock[6][2][2]);

int main(){
	int MagicCubeBlock[6][2][2];
	MagicCubeReset(MagicCubeBlock);
	while(1)
	MagicCube(MagicCubeBlock);

}

void MagicCubeReset(int MagicCubeBlock[6][2][2]){
	for(int i = 0;i < 6;i++)
		for(int j = 0;j < 2;j++)
			for(int k = 0;k < 2;k++)
				MagicCubeBlock[i][j][k] = i;
}

void MagicCube(int MagicCubeBlock[6][2][2]){
	int ts[2];
	int action;
	cout << "輸入數值已進行魔方轉動\n1 上層右轉\n2 上層左轉\n3 下層右轉\n4 下層左轉\n5 右層上轉\n6 右層下轉\n7 左層上轉\n8 左層下轉\n9 前層順時針轉\n10 前層逆時針轉\n11 後層順時針轉\n12 後層逆時針轉\n";
	cin >> action;
	switch(action){
		case 1:
			ts[0] = MagicCubeBlock[3][0][1];
			ts[1] = MagicCubeBlock[3][1][1];
			for(int i = 3;i > 0;i++){
			MagicCubeBlock[i][0][1] = MagicCubeBlock[i-1][0][1];
			MagicCubeBlock[i][1][1] = MagicCubeBlock[i-1][1][1];
			}
			MagicCubeBlock[0][0][1] = ts[0];
			MagicCubeBlock[0][1][1] = ts[1];

			ts[0] = MagicCubeBlock[5][0][1];
			MagicCubeBlock[5][0][1] = MagicCubeBlock[5][1][1];
			MagicCubeBlock[5][1][1] = MagicCubeBlock[5][1][0];
			MagicCubeBlock[5][1][0] = MagicCubeBlock[5][0][0];
			MagicCubeBlock[5][0][0] = ts[0];
			break;
		case 2:
			ts[0] = MagicCubeBlock[0][0][1];
			ts[1] = MagicCubeBlock[0][1][1];
			for(int i = 0;i < 4;i++){
			MagicCubeBlock[i][0][1] = MagicCubeBlock[i+1][0][1];
			MagicCubeBlock[i][1][1] = MagicCubeBlock[i+1][1][1];
			}
			MagicCubeBlock[3][0][1] = ts[0];
			MagicCubeBlock[3][1][1] = ts[1];

			ts[0] = MagicCubeBlock[5][0][0];
			MagicCubeBlock[5][0][0] = MagicCubeBlock[5][1][0];
			MagicCubeBlock[5][1][0] = MagicCubeBlock[5][1][1];
			MagicCubeBlock[5][1][1] = MagicCubeBlock[5][0][1];
			MagicCubeBlock[5][0][1] = ts[0];
			break;
		case 3:
			ts[0] = MagicCubeBlock[3][0][0];
			ts[1] = MagicCubeBlock[3][1][0];
			for(int i = 3;i > 0;i++){
			MagicCubeBlock[i][0][0] = MagicCubeBlock[i-1][0][0];
			MagicCubeBlock[i][1][0] = MagicCubeBlock[i-1][1][0];
			}
			MagicCubeBlock[0][0][0] = ts[0];
			MagicCubeBlock[0][1][0] = ts[1];

			ts[0] = MagicCubeBlock[5][0][1];
			MagicCubeBlock[4][0][1] = MagicCubeBlock[4][1][1];
			MagicCubeBlock[4][1][1] = MagicCubeBlock[4][1][0];
			MagicCubeBlock[4][1][0] = MagicCubeBlock[4][0][0];
			MagicCubeBlock[4][0][0] = ts[0];
		case 4:
			ts[0] = MagicCubeBlock[0][0][0];
			ts[1] = MagicCubeBlock[0][1][0];
			for(int i = 0;i < 4;i++){
			MagicCubeBlock[i][0][0] = MagicCubeBlock[i+1][0][0];
			MagicCubeBlock[i][1][0] = MagicCubeBlock[i+1][1][0];
			}
			MagicCubeBlock[3][0][0] = ts[0];
			MagicCubeBlock[3][1][0] = ts[1];

			ts[0] = MagicCubeBlock[5][0][0];
			MagicCubeBlock[4][0][0] = MagicCubeBlock[4][1][0];
			MagicCubeBlock[4][1][0] = MagicCubeBlock[4][1][1];
			MagicCubeBlock[4][1][1] = MagicCubeBlock[4][0][1];
			MagicCubeBlock[4][0][1] = ts[0];
		case 5:
			ts[0] = MagicCubeBlock[2][0][0];
			ts[1] = MagicCubeBlock[2][0][1];
			MagicCubeBlock[2][0][0] = MagicCubeBlock[5][1][1];
			MagicCubeBlock[2][0][1] = MagicCubeBlock[5][1][0];
			MagicCubeBlock[5][1][0] = MagicCubeBlock[0][1][0];
			MagicCubeBlock[5][1][1] = MagicCubeBlock[0][1][1];
			MagicCubeBlock[0][1][0] = MagicCubeBlock[4][1][1];
			MagicCubeBlock[0][1][1] = MagicCubeBlock[4][1][0];
			MagicCubeBlock[4][1][0] = ts[0];
			MagicCubeBlock[4][1][1] = ts[1];
			ts[0] = MagicCubeBlock[1][1][0];
			MagicCubeBlock[1][1][0] = MagicCubeBlock[1][1][1];
			MagicCubeBlock[1][1][1] = MagicCubeBlock[1][0][1];
			MagicCubeBlock[1][0][1] = MagicCubeBlock[1][0][0];
			MagicCubeBlock[1][0][0] = ts[0];
			break;
		case 6:
			ts[0] = MagicCubeBlock[2][0][0];
			ts[1] = MagicCubeBlock[2][0][1];
			MagicCubeBlock[4][1][0] = MagicCubeBlock[0][1][1];
			MagicCubeBlock[4][1][1] = MagicCubeBlock[0][1][0];
			MagicCubeBlock[2][0][0] = MagicCubeBlock[4][1][0];
			MagicCubeBlock[2][0][1] = MagicCubeBlock[4][1][1];
			MagicCubeBlock[2][0][0] = MagicCubeBlock[5][1][1];
			MagicCubeBlock[2][0][1] = MagicCubeBlock[5][1][0];
			MagicCubeBlock[4][0][0] = ts[0];
			MagicCubeBlock[4][0][1] = ts[1];
			ts[0] = MagicCubeBlock[1][1][0];
			MagicCubeBlock[1][1][0] = MagicCubeBlock[1][1][1];
			MagicCubeBlock[1][1][1] = MagicCubeBlock[1][0][1];
			MagicCubeBlock[1][0][1] = MagicCubeBlock[1][0][0];
			MagicCubeBlock[1][0][0] = ts[0];
			break;
		case 7:
			ts[0] = MagicCubeBlock[2][1][1];
			ts[1] = MagicCubeBlock[2][1][0];
			MagicCubeBlock[2][1][1] = MagicCubeBlock[5][0][0];
			MagicCubeBlock[2][1][0] = MagicCubeBlock[5][0][1];
			MagicCubeBlock[5][0][1] = MagicCubeBlock[0][0][1];
			MagicCubeBlock[5][0][0] = MagicCubeBlock[0][0][0];
			MagicCubeBlock[0][0][1] = MagicCubeBlock[4][0][0];
			MagicCubeBlock[0][0][0] = MagicCubeBlock[4][0][1];
			MagicCubeBlock[4][0][1] = ts[0];
			MagicCubeBlock[4][0][0] = ts[1];
			ts[0] = MagicCubeBlock[3][1][0];
			MagicCubeBlock[3][1][0] = MagicCubeBlock[3][1][1];
			MagicCubeBlock[3][1][1] = MagicCubeBlock[3][0][1];
			MagicCubeBlock[3][0][1] = MagicCubeBlock[3][0][0];
			MagicCubeBlock[3][0][0] = ts[0];
			break;
		case 8:
			ts[0] = MagicCubeBlock[2][1][1];
			ts[1] = MagicCubeBlock[2][1][0];
			MagicCubeBlock[4][0][1] = MagicCubeBlock[0][0][0];
			MagicCubeBlock[4][0][0] = MagicCubeBlock[0][0][1];
			MagicCubeBlock[2][1][1] = MagicCubeBlock[4][0][1];
			MagicCubeBlock[2][1][0] = MagicCubeBlock[4][0][0];
			MagicCubeBlock[2][1][1] = MagicCubeBlock[5][0][0];
			MagicCubeBlock[2][1][0] = MagicCubeBlock[5][0][1];
			MagicCubeBlock[4][1][1] = ts[0];
			MagicCubeBlock[4][1][0] = ts[1];
			ts[0] = MagicCubeBlock[1][1][0];
			MagicCubeBlock[3][1][0] = MagicCubeBlock[3][1][1];
			MagicCubeBlock[3][1][1] = MagicCubeBlock[3][0][1];
			MagicCubeBlock[3][0][1] = MagicCubeBlock[3][0][0];
			MagicCubeBlock[3][0][0] = ts[0];
			break;
		case 9:
			ts[0] = MagicCubeBlock[0][1][0];
			MagicCubeBlock[0][1][0] = MagicCubeBlock[0][1][1];
			MagicCubeBlock[0][1][1] = MagicCubeBlock[0][0][1];
			MagicCubeBlock[0][0][1] = MagicCubeBlock[0][0][0];
			MagicCubeBlock[0][0][0] = ts[0];
			ts[0] = MagicCubeBlock[1][0][0];
			ts[1] = MagicCubeBlock[1][0][1];
			MagicCubeBlock[1][0][0] = MagicCubeBlock[5][1][0];
			MagicCubeBlock[1][0][1] = MagicCubeBlock[5][0][0];
			MagicCubeBlock[5][0][0] = MagicCubeBlock[3][1][0];
			MagicCubeBlock[5][1][0] = MagicCubeBlock[3][1][1];
			MagicCubeBlock[3][1][0] = MagicCubeBlock[4][1][0];
			MagicCubeBlock[3][1][1] = MagicCubeBlock[4][0][0];
			MagicCubeBlock[4][0][0] = ts[0];
			MagicCubeBlock[4][1][0] = ts[1];
			break;
		case 10:
			ts[0] = MagicCubeBlock[0][1][0];
			MagicCubeBlock[0][1][0] = MagicCubeBlock[0][1][1];
			MagicCubeBlock[0][1][1] = MagicCubeBlock[0][0][1];
			MagicCubeBlock[0][0][1] = MagicCubeBlock[0][0][0];
			MagicCubeBlock[0][0][0] = ts[0];
			ts[0] = MagicCubeBlock[4][0][0];
			ts[1] = MagicCubeBlock[4][1][0];
			MagicCubeBlock[4][1][0] = MagicCubeBlock[3][1][0];
			MagicCubeBlock[4][0][0] = MagicCubeBlock[3][1][1];
			MagicCubeBlock[3][1][0] = MagicCubeBlock[5][0][0];
			MagicCubeBlock[3][1][1] = MagicCubeBlock[5][1][0];
			MagicCubeBlock[5][1][0] = MagicCubeBlock[1][0][0];
			MagicCubeBlock[5][0][0] = MagicCubeBlock[1][0][1];
			MagicCubeBlock[1][0][0] = ts[0];
			MagicCubeBlock[1][0][1] = ts[1];
			break;
		case 11:
			ts[0] = MagicCubeBlock[2][1][0];
			MagicCubeBlock[2][1][0] = MagicCubeBlock[2][1][1];
			MagicCubeBlock[2][1][1] = MagicCubeBlock[2][0][1];
			MagicCubeBlock[2][0][1] = MagicCubeBlock[2][0][0];
			MagicCubeBlock[2][0][0] = ts[0];
			ts[0] = MagicCubeBlock[1][1][1];
			ts[1] = MagicCubeBlock[1][1][0];
			MagicCubeBlock[1][1][1] = MagicCubeBlock[5][0][1];
			MagicCubeBlock[1][1][0] = MagicCubeBlock[5][1][1];
			MagicCubeBlock[5][1][1] = MagicCubeBlock[3][0][1];
			MagicCubeBlock[5][0][1] = MagicCubeBlock[3][0][0];
			MagicCubeBlock[3][0][1] = MagicCubeBlock[4][0][1];
			MagicCubeBlock[3][0][0] = MagicCubeBlock[4][1][1];
			MagicCubeBlock[4][1][1] = ts[0];
			MagicCubeBlock[4][0][1] = ts[1];
			break;
		case 12:
			ts[0] = MagicCubeBlock[2][1][0];
			MagicCubeBlock[2][1][0] = MagicCubeBlock[2][1][1];
			MagicCubeBlock[2][1][1] = MagicCubeBlock[2][0][1];
			MagicCubeBlock[2][0][1] = MagicCubeBlock[2][0][0];
			MagicCubeBlock[2][0][0] = ts[0];
			ts[0] = MagicCubeBlock[4][1][1];
			ts[1] = MagicCubeBlock[4][0][1];
			MagicCubeBlock[4][0][1] = MagicCubeBlock[3][0][1];
			MagicCubeBlock[4][1][1] = MagicCubeBlock[3][0][0];
			MagicCubeBlock[3][0][1] = MagicCubeBlock[5][1][1];
			MagicCubeBlock[3][0][0] = MagicCubeBlock[5][0][1];
			MagicCubeBlock[5][0][1] = MagicCubeBlock[1][1][1];
			MagicCubeBlock[5][1][1] = MagicCubeBlock[1][1][0];
			MagicCubeBlock[1][1][1] = ts[0];
			MagicCubeBlock[1][1][0] = ts[1];
			break;
		default:
			cout << "\n請輸入正確數值！" << endl;
			break;
	}
}
