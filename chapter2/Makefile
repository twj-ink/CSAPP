CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = $(wildcard *.cpp)

TARGETS = $(SRCS:.cpp=)

all: $(TARGETS)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

