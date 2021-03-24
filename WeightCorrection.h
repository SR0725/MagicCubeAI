#include<iostream>
#include<vector>
#include "PocketCube.h"
#include "NeuralNetwork.h"

using namespace std;
#ifndef WEIGHTCORRECTION_H
#define WEIGHTCORRECTION_H

class WeightCorrection{
private:
  PocketCube pc;
  NeuralNetwork NN;
  int times = 0;
  int MaxTimes = 10;
  void Correction(int t){
  	
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
	
  void Main(){
    for(;times < MaxTimes;times ++){
      for(int t =0;t < 6;t++){
        TrainData(t);
        Correction(t);
      }
    }
  }
};
#endif