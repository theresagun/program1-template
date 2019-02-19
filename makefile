F1=program1
F2=Star
F3=Planet
F4=List
F5=Vector
FLAGS = -Wall -g -std=c++14

all: $(F1).o $(F2).o $(F3).o $(F4).o $(F5).o
	g++ $(FLAGS) $(F1).o $(F2).o $(F3).o $(F4).o $(F5).o -o $(F1)

$(F1).o: $(F1).cpp
	g++ -c $(FLAGS) $(F1).cpp -o $(F1).o

$(F2).o: $(F2).cpp $(F2).h
	g++ -c $(FLAGS) $(F2).cpp -o $(F2).o

$(F3).o: $(F3).cpp $(F3).h
	g++ -c $(FLAGS) $(F3).cpp -o $(F3).o

$(F4).o: $(F4).cpp $(F4).h
	g++ -c $(FLAGS) $(F4).cpp -o $(F4).o

$(F5).o: $(F5).cpp $(F5).h
	g++ -c $(FLAGS) $(F5).cpp -o $(F5).o

run: all
	./$(F1)

memcheck: all
	valgrind --leak-check=full ./$(F1)

clean: all
	rm -rf $(F1) $(F2) $(F3) $(F4) $(F5) *.o
