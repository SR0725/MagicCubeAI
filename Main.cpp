#include<iostream>
#include "PocketCube.h"
#include "NeuralNetwork.h"
#include "WeightCorrection.h"
#ifdef _WIN64
system("chcp 65001");
#endif

class MainFunction{
private:
  PocketCube pc;
  NeuralNetwork NN;
  char CommandInput[2];
  void cubeEnter(){
    bool b_cubeEnter = true;
    while(b_cubeEnter){
      cout<<endl;
      string c;
      while(true){
        pc.print();
        cout<<"command:";
        cin.clear();
        getline(cin,c);
        if(c == "exit"){
          b_cubeEnter = false;
          break;
        }
        else
        pc.suffle(c);
     }
    }
  }
  void NNBlockValueTrans(){
  	for(int i = 0;i < 6;i++)
  		for(int j = 0;j < 2;j++)
  			for(int k = 0;k < 2;k++)
  				NN.pc.block[i][j][k] = pc.block[i][j][k];
  }

public:
  void description(){
      cout << endl;
      cout << "\x1b[32m----------------------------------------------------------------" << endl;
      cout << "\x1b[37m         Pocket Cube solution find by machine learning" << endl;
      cout << "\x1b[32m----------------------------------------------------------------" << endl;
      cout << "\x1b[37mCommand Description:" << endl;
      cout << "\x1b[37mM\x1b[1;30m     Perform a machine learning program" << endl;
      cout << "\x1b[37mO\x1b[1;30m     Output the current AI accuracy rate" << endl;
      cout << "\x1b[37mR\x1b[1;30m     Make Pocket Cube turns into value " << endl;
      cout << "\x1b[37mE\x1b[1;30m     Manually enter the pocket Cube value" << endl;
      cout << "\x1b[37mS\x1b[1;30m     AI solve" << endl;
      cout << "\x1b[37mr\x1b[1;30m     Random weight" << endl;
  }
  void inputCommand(){
    cout << "Command:";
    cin.getline(CommandInput,2);
    switch (CommandInput[0]) {
      case 'M':cout << "M";break;
      case 'O':cout << "O";break;
      case 'R':cout << "R";break;
      case 'E':cubeEnter();break;
      case 'S':NNBlockValueTrans();NN.Solve();break;
      case 'r':NN.wRandom();cout<<"\x1b[37mRandom weight Finish!";break;
    }
  }
};

int main(){
  MainFunction MainF;
  while(true){
  MainF.description();
  MainF.inputCommand();
  }
}
