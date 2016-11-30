# Points to the root of Google Test. Change it to reflect where your
# clone of the googletest repo is
GTEST_DIR = /usr/local/include/googletest
#GTEST_DIR = /usr/local/include/gtest

# Flags passed to the preprocessor and compiler
CPPFLAGS += -std=c++11 --coverage -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread

# All tests produced by this Makefile.
TESTS = ScoreboardTest

# All Google Test headers. Adjust only if you moved the subdirectory
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o *.gcov *.gcda *.gcno

# Builds gtest.a and gtest_main.a.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds the class and associated test
Scoreboard.o : Scoreboard.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Scoreboard.cpp

ScoreboardTest.o : ScoreboardTest.cpp \
                     Scoreboard.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c ScoreboardTest.cpp

ScoreboardTest : Scoreboard.o ScoreboardTest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
