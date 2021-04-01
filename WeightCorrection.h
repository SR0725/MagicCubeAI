#include<iostream>
#include<vector>
#include "PocketCube.h"
#include "NeuralNetwork.h"

using namespace std;
#ifndef WEIGHTCORRECTION_H
#define WEIGHTCORRECTION_H

class WeightCorrection{
private:
  int times = 0;
  int MaxTimes = 10;
  float learningRate = 0.01f;

  void NNBlockValueTrans(){
  	for(int i = 0;i < 6;i++)
  		for(int j = 0;j < 2;j++)
  			for(int k = 0;k < 2;k++)
  				NN.pc.block[i][j][k] = pc.block[i][j][k];
  }

  void Correction(int t){
    NNBlockValueTrans();NN.Solve();
    int all = 0;
    for(int i = 0;i < 12;i++)
      all += NN.Layer3[i];
    for(int i = 0;i < 12;i++){
      for(int j = 0;j < 6;j++){
        if(j == t){
          NN.w3[i][j] += (1 - NN.Layer3[i])*(NN.Layer3[i]/all)*learningRate;
        }else{
          NN.w3[i][j] += (0 - NN.Layer3[i])*(NN.Layer3[i]/all)*learningRate;
        }
      }
    }


  }


  void TrainData(int t){
    switch (t) {
      case 0:pc.suffle("U");pc.print();break;
      case 1:pc.suffle("L");pc.print();break;
      case 2:pc.suffle("F");pc.print();break;
      case 3:pc.suffle("R");pc.print();break;
      case 4:pc.suffle("B");pc.print();break;
      case 5:pc.suffle("D");pc.print();break;
    }

  }
public:
  PocketCube pc;
  NeuralNetwork NN;
  void Main(){
    for(;times < MaxTimes;times ++){
      for(int t =0;t < 6;t++){
        TrainData(t);
        Correction(t);
        learningRate *= 0.8f;
      }
    }
  }
};
#endif
