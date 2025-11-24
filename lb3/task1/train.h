#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include <iostream>

using namespace std;

class Train {
private:
    string destination;
    int trainNumber;       
    int departureTime;      
    int totalSeats;         
    int cupeSeats;   
    int platskartSeats;      

public:
    Train();
    Train(const string& dest, int number, int time, int total, int cupe, int plats);

    void readData();
    void displayHeader() const;
    void displayData() const;

    //Гетери (для доступу до приватних полів)
    string getDestination() const { return destination; }
    int getDepartureTime() const { return departureTime; }
    int getTotalSeats() const { return totalSeats; }
    bool hasGeneralSeats() const { return (totalSeats - cupeSeats - platskartSeats) > 0; }
};

#endif