build:
	g++ -std=c++20 -o spending.out main.cpp functions/*.cpp util/*.cpp
clean:
	rm *.out
	rm *.exe
run:
	./spending.out help