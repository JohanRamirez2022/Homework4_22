/* -----------------------------------------------------------------------------
FILE NAME:         driver.cpp
DESCRIPTION:       Bank Queue Sim
USAGE:             ./bank_sim
COMPILER:          Compiled with custom makefile
NOTES:             Exit codes: 0 = Success, Otherwise = Error

MODIFICATION HISTORY:

Author              Date          Modification(s)
----------------    ----------    ---------------
Eduardo Garcia,
Johan Ramirez    2023-10-10    Version 1.0

----------------------------------------------------------------------------- */

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

#include "priorityQueue.h"
#include "arrayQueue.h"

using namespace std;

const string PROGRAMMER_NAME = "Eduardo Garcia, Johan Ramirez";	//Programmer's Name

/*
 *
 *
 */
//prints out statistics
void statistics(int& customerTally, int& waitingTime)
{
    double avg = waitingTime / customerTally;
    cout << "Final Statistics \n";
    cout << "Total number of people processed: " << customerTally << endl;
    cout << "Average amount of time spent waiting: " << avg << endl; 
}



//once the file is fully read, this function executes to finish processing data
void finish(PriorityQueue<int>& events, ArrayQueue<int>& transactionTimes, int& waitingTime, int& customerTally)
{
    while (!events.isEmpty())
    {
        if (events.peekFront() > transactionTimes.peekFront())//continues emptying out queue's until both are empty
        {
            cout << "Processing a departure event at time: " << transactionTimes.peekFront() << endl;
            transactionTimes.dequeue();
            if (transactionTimes.isEmpty())
            {
                break;
            }
            break;
        }
        else
        {
            cout << "Processing an arrival event at time: " << events.peekFront() << endl;
            events.dequeue();
        }
    }
    while (!transactionTimes.isEmpty())
    {
        cout << "Processing a departure event at time: " << transactionTimes.peekFront() << endl;
        transactionTimes.dequeue();
    }

    statistics(customerTally, waitingTime);
}


void eventHandling(PriorityQueue<int>& events, ArrayQueue<int>& transactionTimes, int& waitingTime, int& customerTally)
{
    if(events.peekFront() < transactionTimes.peekFront())//takes the smaller values from the front of both queues and prints out
    {
        cout << "Processing an arrival event at time: " << events.peekFront() << endl;
        events.dequeue();
    }
    else
    {
        cout << "Processing a departure event at time: " << transactionTimes.peekFront() << endl;
        transactionTimes.dequeue();
    }
}




void fileHandling(PriorityQueue<int>& events, ArrayQueue<int>& transactionTimes, int& waitingTime, int& customerTally)
{
    int customerIn; //time when most recent customer enters
    int estimate; //time estimate for most recent customer

    ifstream inFile ("list.txt");

    while (!inFile.eof())
    {

        inFile >> customerIn >> estimate;//reads in file assigning values to respective number
        events.push(customerIn);//pushes in customer entry time to events queue

        waitingTime += estimate;
        customerTally += 1;

        if (transactionTimes.isEmpty())
        {
            int departureTime = estimate + events.peekFront(); //departure time becomes sum of the latest time estimate and first event in events queue
            transactionTimes.enqueue(departureTime);
        }
        else
        {
            transactionTimes.enqueue(waitingTime);
        }

        eventHandling(events, transactionTimes, waitingTime, customerTally);
    }
    finish(events, transactionTimes, waitingTime, customerTally);//finish runs once there are no more lines to be processed in the infile
}


int main()
{
    cout << "\n\nProgrammed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << "  " __TIME__ << endl << endl;

    
    PriorityQueue<int> events; //queue for tracking customer arrival times
    ArrayQueue<int> transactionTimes; //queue for tracking estimated transaction times

    int waitingTime = 0; 
    int customerTally = 0;
   
    cout << "Simulation Begins \n";
    fileHandling(events, transactionTimes, waitingTime, customerTally);
    
return 0;
}
