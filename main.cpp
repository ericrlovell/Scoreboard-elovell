/**
 * @file main.cpp
 * @brief Sample int main to use myscoreboard class.
 * @author VRPS
 * @version 1.1
 * @date 2016-11-10
 */
//Luke Short
#include"myscoreboard.h"
using std::cout;

int main()
{
   int numberOfTeams =2;
   int numberOfPeriods=4;
   MyScoreboard scorby(numberOfTeams, numberOfPeriods);

   cout<< "Super important ball game.\n";
   scorby.printScores();
   scorby.setScore(0, 2, 13);
   cout<<"-----------------------\n";
   scorby.setScore(1, 2, 13);
   scorby.printScores();
   cout<<"-----------------------\n";
   scorby.setScore(0, 3, 327);
   scorby.printScores();
   cout<<"-----------------------\n";
   int mySuperSpecialScore =scorby.getScore(0, 2);
   cout<<"mySuperSpecialScore  = " <<mySuperSpecialScore <<'\n';
   int mySuperSpecialScoreSum =scorby.getTotalScore(0);
   cout<<"mySuperSpecialScoreSum  = " <<mySuperSpecialScoreSum <<'\n';
   cout<<"Clearing scoreboard for next game...\n";
   scorby.clearScoreboard();
   scorby.printScores();

   return 0;
}

