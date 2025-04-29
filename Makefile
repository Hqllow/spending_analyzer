build:
	g++ -std=c++20 -o spending.out *.cpp
clean:
	rm *.out
	rm *.exe
run:
	./spending.out help