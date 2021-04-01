#include<iostream>
#include<vector>
#include "PocketCube.h"
#include "WCNeuralNetwork.h"

using namespace std;
#ifndef WEIGHTCORRECTION_H
#define WEIGHTCORRECTION_H

class WeightCorrection{
private:
  int times = 0;
  int MaxTimes = 10;
  float learningRate = 0.01f;


  void Correction(int t){
    NN.Input();
    int all = 0;
    for(int i = 0;i < 12;i++)
      all += NN.Layer3[i];
    for(int i = 0;i < 12;i++){
      for(int j = 0;j < 6;j++){
        if(j == t){
          NN.w3[i][j] += (1 - NN.Layer4[i])*(NN.Layer3[i]/all)*learningRate;
        }else{
          NN.w3[i][j] += (0 - NN.Layer4[i])*(NN.Layer3[i]/all)*learningRate;
        }
      }
    }
  }

  void PocketCubeReset(){
      for(int i=0;i<6;i++){
          for(int j=0;j<2;j++){
              for(int k=0;k<2;k++){
                  NN.pc.block[i][j][k] = NN.pc.color[i];
              }
          }
      }
  }

  void TrainData(int t){
    switch (t) {
      case 0:NN.pc.suffle("U");break;
      case 1:NN.pc.suffle("L");break;
      case 2:NN.pc.suffle("F");break;
      case 3:NN.pc.suffle("R");break;
      case 4:NN.pc.suffle("B");break;
      case 5:NN.pc.suffle("D");break;
    }
  }
public:
  PocketCube pc;
  WCNeuralNetwork NN;
  void Main(){
    times = 0;
    for(;times < MaxTimes;times ++){
      for(int t =0;t < 6;t++){
        PocketCubeReset();
        TrainData(t);
        Correction(t);
        learningRate *= 0.8f;
      }
    }
  }
};
#endif
