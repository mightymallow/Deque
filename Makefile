Deque:
	g++ -c Deque.cpp
	g++ -c Deque_test.cpp
	g++ -o Deque Deque.o Deque_test.o

clean:
	rm *.o Deque
