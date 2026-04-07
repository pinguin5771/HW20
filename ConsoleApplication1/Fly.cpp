#include "Fly.h"

Fly::Fly()
{
	flightNumber = 0;
	departurePoint = new char[7] {"Noname"};
	destination = new char[7] {"Noname"};
	label = new char[7] {"Noname"};
	totalSeatsNumber = 0;
	occupiedSeats = 0;
}

Fly::Fly(int flightNumber, char* departurePoint, char* destination, 
	char* label, int totalSeatsNumber, int occupiedSeats)
{
	this->flightNumber = flightNumber;
	this->departurePoint = new char[strlen(departurePoint) + 1];
	strcpy_s(this->departurePoint, strlen(departurePoint) + 1, departurePoint);
	this->destination = new char[strlen(destination) + 1];
	strcpy_s(this->destination, strlen(destination) + 1, destination);
	this->label = new char[strlen(label) + 1];
	strcpy_s(this->label, strlen(label) + 1, label);
	this->totalSeatsNumber = totalSeatsNumber;
	this->occupiedSeats = occupiedSeats;
}

Fly::~Fly()
{
	delete[] departurePoint;
	delete[] destination;
	delete[] label;
}

int Fly::getFlightNumber()
{
	return flightNumber;
}

char* Fly::getDeparturePoint()
{
	return departurePoint;
}

char* Fly::getDestinationPoint()
{
	return destination;
}

void Fly::buyTicket()
{
	if (occupiedSeats < totalSeatsNumber)
	{
		occupiedSeats++;
		cout << "Ticket bought!\n";
	}
	else
		cout << "No free seats!\n";
}

void Fly::returnTicket()
{
	if (occupiedSeats > 0)
	{
		occupiedSeats--;
		cout << "Ticket returned!\n";
	}
}

void Fly::showInfo()
{
	cout << "+++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "| Flight number: " << flightNumber << endl;
	cout << "| Departure: " << departurePoint << endl;
	cout << "| Destination: " << destination << endl;
	cout << "| Label: " << label << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "| Total seats: " << totalSeatsNumber << endl;
	cout << "| Occupied seats: " << occupiedSeats << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++\n";
}

Fly::Fly(const Fly& other)
{
	flightNumber = other.flightNumber;

	departurePoint = new char[strlen(other.departurePoint) + 1];
	strcpy_s(departurePoint, strlen(other.departurePoint) + 1, other.departurePoint);

	destination = new char[strlen(other.destination) + 1];
	strcpy_s(destination, strlen(other.destination) + 1, other.destination);

	label = new char[strlen(other.label) + 1];
	strcpy_s(label, strlen(other.label) + 1, other.label);

	totalSeatsNumber = other.totalSeatsNumber;
	occupiedSeats = other.occupiedSeats;
}
Fly& Fly::operator=(const Fly& other)
{
	if (this == &other)
		return *this;

	delete[] departurePoint;
	delete[] destination;
	delete[] label;

	flightNumber = other.flightNumber;

	departurePoint = new char[strlen(other.departurePoint) + 1];
	strcpy_s(departurePoint, strlen(other.departurePoint) + 1, other.departurePoint);

	destination = new char[strlen(other.destination) + 1];
	strcpy_s(destination, strlen(other.destination) + 1, other.destination);

	label = new char[strlen(other.label) + 1];
	strcpy_s(label, strlen(other.label) + 1, other.label);

	totalSeatsNumber = other.totalSeatsNumber;
	occupiedSeats = other.occupiedSeats;

	return *this;
}
