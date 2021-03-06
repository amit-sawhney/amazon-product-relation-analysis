EXENAME = main
OBJS = main.o graph.o node.o dfs.o pagerank.o betweenness.o
TEST_OBJS = graph.o node.o tests.o dfs.o pagerank.o betweenness.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement logic:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
ifneq ($(strip $(SKIP_EWS_CHECK)),True)
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif
endif

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o: src/main.cpp src/graph.cpp src/graph.h src/dfs.cpp src/dfs.h src/pagerank.cpp src/pagerank.h
	$(CXX) $(CXXFLAGS) src/main.cpp

graph.o: src/graph.cpp src/graph.h src/node.cpp src/node.h src/betweenness.cpp src/betweenness.h src/dfs.cpp src/dfs.h
	$(CXX) $(CXXFLAGS) src/graph.cpp

betweenness.o: src/betweenness.cpp src/betweenness.h src/node.cpp src/node.h
	$(CXX) $(CXXFLAGS) src/betweenness.cpp

node.o: src/node.cpp src/node.h 
	$(CXX) $(CXXFLAGS) src/node.cpp

dfs.o: src/dfs.cpp src/dfs.h src/node.cpp src/node.h src/graph.cpp src/graph.h 
	$(CXX) $(CXXFLAGS) src/dfs.cpp

pagerank.o: src/pagerank.cpp src/pagerank.h src/node.cpp src/node.h src/graph.cpp src/graph.h 
	$(CXX) $(CXXFLAGS) src/pagerank.cpp

test: output_msg $(TEST_OBJS)
	$(LD) $(TEST_OBJS) $(LDFLAGS) -o test

tests.o: tests/tests.cpp catch/catch.hpp
	$(CXX) $(CXXFLAGS) tests/tests.cpp

clean:
	-rm -f *.o $(EXENAME) test
