#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Fly
{
	int flightNumber;
	char* departurePoint;
	char* destination;
	char* label;
	int totalSeatsNumber;
	int occupiedSeats;

public:
	Fly();
	Fly(int flightNumber, char* departurePoint, char* destination,
		char* label, int totalSeatsNumber, int occupiedSeats);
	~Fly();


	int getFlightNumber();
	char* getDeparturePoint();
	char* getDestinationPoint();
	void buyTicket();
	void returnTicket();
	void showInfo();
	Fly(const Fly& other);
	Fly& operator=(const Fly& other);
};