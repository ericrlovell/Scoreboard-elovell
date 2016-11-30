/**
 * @file myscoreboard.h
 * @brief Header file for MyScoreboard class, which inherits Kevin Buffardi's scoreboard interface.
 * @author VRPS
 * @version 1.2
 * @date 2016-11-14
 */
#ifndef MYSCOREBOARD_H
#define MYSCOREBOARD_H

#include"IScoreboard.h"
#include<vector>
#include<climits>//used in order to return int min
#include<iostream>
#include"ObserverPattern.hpp"
using std::vector;

class Scoreboard: public IScoreboard, public Observable
{
   public:
      Scoreboard(int numComp, int numPeriods);             //ctor
      ~Scoreboard();                                       //dtor
      void setScore(int competitor, int period, int score);//set one value within the scorbianKing
      int getScore(int competitor, int period);            //retrieve one value from the scorbianKing
      int getTotalScore(int competitor);                   //its like the getScore one, but it adds some stuff
      void clearScoreboard();                              //the sparsity is strong with this one...

      void printScores();                                  //used this guy to visualize the basquetbol game
   private:
      bool periodInRange(int period);
      bool competitorInRange(int competitor);
      vector< vector<int> > *scorbianKing;//gasp! put asterisk on right

      int m_numComp;
      int m_numPeriods;
};

#endif
