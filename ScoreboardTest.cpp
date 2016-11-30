/**
 * Unit Tests for Scoreboard
**/

#include <gtest/gtest.h>
#include "Scoreboard.h"
 
class ScoreboardTest : public ::testing::Test
{
	protected:
		ScoreboardTest(){} //constructor runs before each test
		virtual ~ScoreboardTest(){} //destructor cleans up after tests
		void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(ScoreboardTest, setScoreLowerBoundCompetitors)
{
	Scoreboard board(3,1);
	board.setScore(1,1,1);
	ASSERT_EQ(1, board.getScore(1,1) );
}
TEST(ScoreboardTest, setScoreUpperBoundCompetitors)
{
	Scoreboard board(3,1);
	board.setScore(3,1,9);
	ASSERT_EQ(9, board.getScore(3,1) );
}
TEST(ScoreboardTest, setScoreMiddle)
{
	Scoreboard board(10,1);
	board.setScore(5,1,100);
	ASSERT_EQ(100, board.getScore(5,1) );
}
TEST(ScoreboardTest, setScoreOverBoundCompetitors)
{
	Scoreboard board(10,1);
	board.setScore(11,1,99);
	ASSERT_EQ(0, board.getScore(10,1) );
	ASSERT_EQ(INT_MIN, board.getScore(11,1) );
}
TEST(ScoreboardTest, setScoreUnderBoundCompetitors)
{
	Scoreboard board(10,1);
	board.setScore(0,1,99);
	ASSERT_EQ(0, board.getScore(1,1) );
	ASSERT_EQ(INT_MIN, board.getScore(0,1) );
}
TEST(ScoreboardTest, setScoreUpperBoundPeriods)
{
	Scoreboard board(3,10);
	board.setScore(1,10,100000);
	ASSERT_EQ(100000, board.getScore(1,10) );
}
