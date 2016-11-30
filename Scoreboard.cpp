/** 
 * @file myscoreboard.cpp
 * @brief Scoreboard class for my super important basketball game I have to keep track of.
 * @author VRPS
 * @version 1.1
 * @date 2016-11-09
 */

#include"Scoreboard.h"
#include<iomanip>
using std::cout;
using std::setw;

/**
 * @brief Constructor for Scoreboard. Allocates memory on da heap for our 
 *   vector< vector<int> > used to hold all the scores.
 *
 *   The better way to do this would probably be to use a 2d array, but that's ok, we'll just be bad and use vectors.
 *
 * @param numComp:int Number of competitors. Used to determine # rows in our 2D vector
 * @param numPeriods:int Number of numPeriods. Used to determine # columns in our 2D vector
 */
Scoreboard::Scoreboard(int numComp, int numPeriods)
{
   m_numComp    = numComp;
   m_numPeriods = numPeriods;

   vector<int> rowVec(numPeriods, 0);//create vec for ea team/competitor
   scorbianKing =new vector< vector<int> >(numComp, rowVec);//heaps of fun ;)
}

/**
 * @brief Destructor for Scoreboard. Deallocates memory on da heap used in
 *   the vector< vector<int> > used to hold all the scores.
 */
Scoreboard::~Scoreboard()
{  delete scorbianKing;  }

/**
 * @brief setScore function used to set value for one competitors score in a specific period.
 *
 * @param competitor Competitor # for the score (row #)
 * @param period:int Period for the score (column #)
 * @param score:int Score value that's being updated.
 */
void Scoreboard::setScore(int competitor, int period, int score)
{
   competitor--;//Indices start at 1 instead of 0...!?
   period--;

   if(periodInRange(period) && competitorInRange(competitor))
   {  (*scorbianKing)[competitor][period] = score;  }
	
	notifyObservers();
}

/**
 * @brief getScore fxn used to get one particular score value for a competitor in a specific period.
 *
 * @param competitor:int Competitor whose score we want (row #)
 * @param period:int The period of the score we want (column #)
 *
 * @return If params are valid, we return the appropriate score value, o/w we return INT_MIN.
 */
int Scoreboard::getScore(int competitor, int period)
{
   competitor--;
   period--;

   if(periodInRange(period) && competitorInRange(competitor))
   {  return (*scorbianKing)[competitor][period];  }
   else
   {  return INT_MIN;  }
}

/**
 * @brief getTotalScore fxn used to get the total score earned by a competitor for all periods.
 *   (The sum of the scores from ea period.)
 *
 * @param competitor:int Competitor # we are interested in (row #)
 *
 * @return If we are passed a valid competitor return sum of all the scores from ea period. O/w return INT_MIN.
 */
int Scoreboard::getTotalScore(int competitor)
{
   competitor--;

   if(competitorInRange(competitor))
   {
      int mySum =0;
      for(int i=0; i<m_numPeriods; i++)
      {  mySum +=getScore(competitor, i);  }

      return mySum;
   }
   else
   {  return INT_MIN;  }
}

/**
 * @brief Determines if a specified period is in range for our data structure.
 *
 * @param period:int Period # we are interested in (column #)
 *
 * @return True if passed a valid period. O/w return false.
 */
bool Scoreboard::periodInRange(int period)
{
   if(period > -1 && period < m_numPeriods)
   {  return true;  }
   else
   {  return false;  }
}

/**
 * @brief Determines if a specified competitor is in range for our data structure.
 *
 * @param competitor:int Competitor # we are interested in (row #)
 *
 * @return True if passed a valid competitor. O/w return false.
 */
bool Scoreboard::competitorInRange(int competitor)
{
   if(competitor > -1 && competitor < m_numComp)
   {  return true;  }
   else
   {  return false;  }
}

/**
 * @brief print fxn to see everything printed to std out.
 */
void Scoreboard::printScores()
{
   cout<< "Scoreboard:\n";
   for(int i=0; i<m_numComp; i++)
   {
      for(int j=0; j<m_numPeriods; j++)
      {  cout<< setw(5) <<(*scorbianKing)[i][j];  }
      cout<< '\n';
   }
}

/**
 * @brief Used to zero out the scoreboard.
 */
void Scoreboard::clearScoreboard()
{
   for(size_t i=0; i<(*scorbianKing).size(); i++)
   {
      for(size_t j=0; j<(*scorbianKing)[i].size(); j++)
      {  setScore(i, j, 0);  }
   }
	
	notifyObservers();
}

