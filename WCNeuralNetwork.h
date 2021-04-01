#include<iostream>
#include <cstdlib>
#include <ctime>
#include "PocketCube.h"

using namespace std;
#ifndef WCNEURALNETWORK_H
#define WCNEURALNETWORK_H

class WCNeuralNetwork{
private:
  float max;

  void NNLayer2(){
    for(int i = 0; i < 16; i++) //歸零
    {
      Layer2[i] = 0;
    }
    for(int i = 0; i < 24; i++) //權重函數加成
    {
      for(int j = 0; j < 16; j++)
      {
        Layer2[j] += (Layer1[i] * w1[i][j]);
      }
    }
    for(int i = 0; i < 16; i++) //激活函數加成
    {
      if(Layer2[i] < 0)
      {
        Layer2[i] = 0;
      }
    }
    NNLayer3();
  }

  void NNLayer3(){
    for(int i = 0; i < 12; i++) //歸零
    {
      Layer3[i] = 0;
    }
    for(int i = 0; i < 16; i++) //權重函數加成
    {
      for(int j = 0; j < 12; j++)
      {
        Layer3[j] += (Layer2[i] * w2[i][j]);
      }
    }
    for(int i = 0; i < 12; i++) //激活函數加成
    {
      if(Layer3[i] < 0)
      {
        Layer3[i] = 0;
      }
    }
    NNLayer4();
  }

  void NNLayer4(){
    for(int i = 0; i < 6; i++) //歸零
    {
      Layer4[i] = 0;
    }
    for(int i = 0; i < 12; i++) //權重函數加成
    {
      for(int j = 0; j < 6; j++)
      {
        Layer4[j] += (Layer3[i] * w3[i][j]);
      }
    }
    for(int i = 0; i < 6; i++) //激活函數加成
    {
      if(Layer4[i] < 0)
      {
        Layer4[i] = 0;
      }
    }
    for(int i = 0; i < 6; i++)
      if(Layer4[i] > max){
        max = Layer4[i];
      }

  }

public:
  float w1[24][16]; //384
  float w2[16][12]; //192
  float w3[12][6]; //72
  float Layer1[24];
  float Layer2[16];
  float Layer3[12];
  float Layer4[6];
  PocketCube pc;

  void wRandom()
  {
    srand(time(NULL));
    for(int i = 0; i < 24; i++)
    {
      for(int j = 0; j < 16; j++)
      {
        w1[i][j] =2 * rand() / (RAND_MAX + 1.0) -1;
      }
    }
    for(int i = 0; i < 16; i++)
    {
      for(int j = 0; j < 12; j++)
      {
        w2[i][j] =2 * rand() / (RAND_MAX + 1.0) -1;
      }
    }
    for(int i = 0; i < 12; i++)
    {
      for(int j = 0; j < 6; j++)
      {
        w3[i][j] =2 * rand() / (RAND_MAX + 1.0) -1;
      }
    }
  }

  void Input()
  {
    for(int i = 0; i < 6; i++)
    {
      for(int j = 0; j < 2; j++)
      {
        for(int k = 0; k < 2; k++)
        {
          Layer1[(4*i)+(2*j)+k] = pc.block[i][j][k];
        }
      }
    }
    NNLayer2();
  }
};
#endif
