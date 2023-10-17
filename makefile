bank_sim: driver.o
	g++ driver.o -o bank_sim

driver.o: driver.cpp queue.h arrayQueue.h
	g++ -c driver.cpp
clean:
	rm *.o driver