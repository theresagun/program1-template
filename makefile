F1=lab3
F2=Star
F3=Planet
FLAGS = -Wall -g -std=c++14

all: $(F1).o $(F2).o $(F3).o
	g++ $(FLAGS) $(F1).o $(F2).o $(F3).o -o $(F1)

$(F1).o: $(F1).cpp
	g++ -c $(FLAGS) $(F1).cpp -o $(F1).o

$(F2).o: $(F2).cpp
	g++ -c $(FLAGS) $(F2).cpp -o $(F2).o

$(F3).o: $(F3).cpp
	g++ -c $(FLAGS) $(F3).cpp -o $(F3).o

run: all
	./$(F1)

memcheck: all
	valgrind --leak-check=full ./$(F1)

clean: all
	rm -rf $(F1) *.o
