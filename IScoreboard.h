/*
 * IScoreboard.h
 *
 * Author: Kevin Buffardi
 * Updated: Nov 8, 2016
 * Description: Interface for an abstract scoreboard for keeping score for any 
 *              kind of competition with TWO or more competitors and AT LEAST 
 *              ONE period.
 *
 *              For a simple scoreboard, there may only be one period.
 *              However, some scoreboards will have multiple periods, such as
 *              some sports that have four periods (quarters) and the total
 *              score represents the sum total of all periods.
 *
 *              Competitors and periods are numbered in increasing order from 1
 *              so a scoreboard for a 9-inning baseball game will have
 *              competitors 1 and 2 with innings {1...9}, inclusive. 
 *
 *              Periods should initially have 0 score for all competitors.
 *
 *              See comments for each method for description on how they should
 *              behave and how to use the parameters
 */
#ifndef ISCOREBOARD_H_
#define ISCOREBOARD_H_

class IScoreboard
{
  public:
  	/*
  	 * void setScore(int,int,int)
  	 *  Sets the score for one competitor for a given period. Out of range
  	 *  values should result in no changes in the scoreboard.
  	 */
	virtual void setScore(int competitor, int period, int score)=0;
	
	/*
  	 * void getScore(int,int)
  	 *  Returns the score for one competitor for a given period. Out of range
  	 *  values should return INT_MIN
  	 */
	virtual int getScore(int competitor, int period)=0;

	/*
  	 * int getTotalScore(int)
  	 *  Gets the sum of all periods for the given competitor. Out of range
  	 *  values should return 0
  	 */
	virtual int getTotalScore(int competitor)=0;

	/*
  	 * void clearScoreboard()
  	 *  Resets a scoreboard to have scores of 0 for every competitor in
  	 *  every period
  	 */
	virtual void clearScoreboard()=0;
};
#endif /* ISCOREBOARD_H_ */
