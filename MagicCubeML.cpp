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
	cout << "Ý”Èë
