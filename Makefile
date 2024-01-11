CXX=g++
BD=../build
CXX_FLAGS=-c #-g -Wall -Werror -Wextra -Wfloat-equal -Warray-bounds -std=c++17
LCOVFLAGS=-fprofile-arcs -ftest-coverage
GTESTFLAGS=-lgtest

ifeq ($(shell uname -s), Linux)
	GTESTFLAGS+= -lpthread -lrt
endif
#              Файлы для основного проекта
PROJECT_FILES_SOURCES= main.cpp Matrix.cpp graph.cpp MatrixBnB.cpp GraphAlgorithms.cpp Ant.cpp AntAlgorithm.cpp \
						BnBAlgorithm.cpp ConsoleView.cpp
PROJECT_FILES_OBJECTS=$(addprefix $(BD)/,$(PROJECT_FILES_SOURCES:.cpp=.o))
#              Файлы для тестов
TESTS_FILES_SOURCES=main_test.cpp Matrix.cpp graph.cpp GraphAlgorithms.cpp MatrixBnB.cpp Ant.cpp AntAlgorithm.cpp BnBAlgorithm.cpp
TESTS_FILES_OBJECTS=$(addprefix $(BD)/,$(TESTS_FILES_SOURCES:.cpp=.o))

all: clean debug

./$(BD)/%.o:%.cpp
	$(CXX) $(CXX_FLAGS) $< -o $@

./$(BD)/%.o:*/%.cpp
	$(CXX) $(CXX_FLAGS) $< -o $@
 
./$(BD)/%.o: */*/%.cpp
	$(CXX) $(CXX_FLAGS) $< -o $@

./$(BD)/%.o: */*/*/%.cpp
	$(CXX) $(CXX_FLAGS) $< -o $@

debug:$(PROJECT_FILES_OBJECTS)
	$(CXX) -g  $^ -o $(BD)/$@ 
	./$(BD)/$@
tests: clean test_exe
	./$(BD)/test

test_exe:$(TESTS_FILES_OBJECTS)
	$(CXX) -g  $^ -o $(BD)/test   $(GTESTFLAGS)

cpplint:
	cp -f ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=cpp ../src/*/*.h ../src/*/*.cpp
	rm -rf CPPLINT.cfg

clean:
	rm -rf $(BD)/*.*
	rm -rf $(BD)/*
	