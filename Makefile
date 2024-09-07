main:
	g++ -std=c++20 -g -o game main.cpp cards.cpp utility.cpp

tests:
	g++ -std=c++20 -g -o tests tests.cpp cards.cpp utility.cpp 

clean:
	rm *out *.o tests game




 


# rm *out *.o test game
# testbst : intbst.cpp intbst.h testbst.cpp 
# 	g++ --std=c++20 -g -Wall -O0 intbst.cpp intbst.h testbst.cpp -o testbst


# clean:
# 	rm testbst

# CXX=g++
# targets = game tests

# all: $(targets)

# game: main.o cards.o utility.o
# 	g++ main.o cards.o utility.o -o game

# main.o: main.cpp
# 	g++ main.cpp -c

# main: main.o 
# 	$(CXX) $^ -o $@

# tests: cards.o tests.o
# 	$(CXX) $^ -o $@

# # cards: cards.o
# # 	$(CXX) $^ -o $@

# cards.o: cards.cpp cards.h utility.cpp utility.h
# 	$(CXX) $^ -c

# utility.o: utility.cpp utility.h
# 	$(CXX) $^ -c

# tests.o: tests.cpp	
# 	$(CXX) $^ -c

# .PHONY: clean all
# clean: 
# 	rm -f *.o $(targets)
