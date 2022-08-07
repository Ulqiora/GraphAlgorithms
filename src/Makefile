CC=g++
BD=../build/
PROJECT_FILES_SOURCES=Matrix.cpp graph.cpp queue.cpp stack.cpp main_debug.cpp GraphAlgorithms.cpp
PROJECT_FILES_OBJECTS=$(addprefix $(BD),$(PROJECT_FILES_SOURCES:.cpp=.o))
CXX_FLAGS=-c -g -Wall -Werror -Wextra -Wfloat-equal -Warray-bounds -std=c++17
LCOVFLAGS=-fprofile-arcs -ftest-coverage
GTESTFLAGS=-lgtest -I./ -L./

ifeq ($(shell uname -s), Linux)
	GTESTFLAGS+= -lpthread -lsubunit -lrt -lm
endif

all: clean Debug

./$(BD)%.o:	%.cpp
	$(CC) $(CXX_FLAGS) $< -o $@

./$(BD)%.o:	*/%.cpp
	$(CC) $(CXX_FLAGS) $< -o $@

./$(BD)%.o: */*/%.cpp
	$(CC) $(CXX_FLAGS) $< -o $@

./$(BD)%.o: */*/*/%.cpp
	$(CC) $(CXX_FLAGS) $< -o $@

Debug:$(PROJECT_FILES_OBJECTS)
	$(CC) -g  $^ -o $@ 

clean:
	rm -rf $(BD)*.*