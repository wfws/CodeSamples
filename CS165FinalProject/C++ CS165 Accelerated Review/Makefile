CXX = g++
CXXFLAGS = -std=c++0x 
#CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -L/user/local/boost/ -l/boost/random/random_number_generator.hpp
#LDFLAGS = -L/user/local/boost/ -l/boost/random/uniform_int_distribution.hpp

OBJS = AccelReviewImp.o CS165AccelReview.o

SRCS = AccelReviewImp.cpp CS165AccelReview.cpp

HEADERS = AccelReview.h 

#target: dependencies
#	rule to build
#

CS165Accelerated_Review: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o CS165AccelReview.exe

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)