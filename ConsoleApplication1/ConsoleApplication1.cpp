#include "Fly.h"

int main()
{
    const int MAX = 100;
    Fly airplanes[MAX];

    int count = 0;
    int menu;

    do {
        cout << "\nMENU:\n";
        cout << "1 - Add airplane\n";
        cout << "2 - Show all\n";
        cout << "3 - Buy ticket\n";
        cout << "4 - Return ticket\n";
        cout << "0 - Exit\n";
        cin >> menu;

        switch (menu)
        {
        case 1:
        {
            int fn, total, occupied;
            char dep[50], dest[50], lab[50];

            cout << "Flight number: ";
            cin >> fn;

            cout << "Departure: ";
            cin.ignore();
            cin.getline(dep,50);

            cout << "Destination: ";
            cin.getline(dest, 50);

            cout << "Plane label: ";
            cin.getline(lab, 50);

            cout << "Total seats: ";
            cin >> total;

            cout << "Occupied seats: ";
            cin >> occupied;

            airplanes[count++] = Fly(fn, dep, dest, lab, total, occupied);
            break;
        }

        case 2:
        {
            for (int i = 0; i < count; i++)
                airplanes[i].showInfo();
            break;
        }

        case 3:
        {
            int fn;
            cout << "Enter flight number: ";
            cin >> fn;

            for (int i = 0; i < count; i++)
            {
                if (airplanes[i].getFlightNumber() == fn)
                    airplanes[i].buyTicket();
            }
            break;
        }

        case 4:
        {
            int fn;
            cout << "Enter flight number: ";
            cin >> fn;

            for (int i = 0; i < count; i++)
            {
                if (airplanes[i].getFlightNumber() == fn)
                    airplanes[i].returnTicket();
            }
            break;
        }

        }

    } while (menu != 0);

    return 0;
}