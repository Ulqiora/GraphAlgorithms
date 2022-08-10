CC=g++
BD=../build
CXX_FLAGS=-c -g -Wall -Werror -Wextra -Wfloat-equal -Warray-bounds -std=c++17
LCOVFLAGS=-fprofile-arcs -ftest-coverage
GTESTFLAGS=-lgtest

ifeq ($(shell uname -s), Linux)
	GTESTFLAGS+= -lpthread -lrt
endif
#              Файлы для основного проекта
PROJECT_FILES_SOURCES=Matrix.cpp main_debug.cpp graph.cpp GraphAlgorithms.cpp
PROJECT_FILES_OBJECTS=$(addprefix $(BD)/,$(PROJECT_FILES_SOURCES:.cpp=.o))
#              Файлы для тестов
TESTS_FILES_SOURCES=Matrix.cpp main_test.cpp graph.cpp GraphAlgorithms.cpp
TESTS_FILES_OBJECTS=$(addprefix $(BD)/,$(TESTS_FILES_SOURCES:.cpp=.o))

all: clean Debug

./$(BD)/%.o:%.cpp
	$(CC) $(CXX_FLAGS) $< -o $@

./$(BD)/%.o:*/%.cpp
	$(CC) $(CXX_FLAGS) $< -o $@

./$(BD)/%.o: */*/%.cpp
	$(CC) $(CXX_FLAGS) $< -o $@

./$(BD)/%.o: */*/*/%.cpp
	$(CC) $(CXX_FLAGS) $< -o $@

debug:$(PROJECT_FILES_OBJECTS)
	$(CC) -g  $^ -o $(BD)/$@ 
	./$(BD)/$@
test:$(TESTS_FILES_OBJECTS)
	$(CC) -g  $^ -o $(BD)/test   $(GTESTFLAGS)
	./$(BD)/$@

clean:
	rm -rf $(BD)/*.*
	rm -rf $(BD)/*