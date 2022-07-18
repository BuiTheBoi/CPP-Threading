// C++ Early Objects: Page 149, Problem 10

#include <iostream>
#include <string>
#include <iomanip>

const double ADULT_TICKET_PRICE = 10.0;
const double CHILD_TICKET_PRICE = 6.0;
const int WIDTH = 30;

int main()
{
    // Input
    std::cout << "Enter movie name: ";
    std::string movie;
    std::getline(std::cin, movie);

    std::cout << "Enter adult tickets sold: ";
    int adult_tickets;
    std::cin >> adult_tickets;

    std::cout << "Enter child tickets sold: ";
    int child_tickets;
    std::cin >> child_tickets;

    double gross_box_office_rev = (adult_tickets * ADULT_TICKET_PRICE) + (child_tickets * CHILD_TICKET_PRICE);
    // Output
    system("clear");

    std::cout << std::left << std::setw(WIDTH) << "Movie Name:" << "\"" << movie << "\"" << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "Adult Tickets Sold:" << adult_tickets << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "Child Tickets Sold:" << child_tickets << std::endl;

    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    std::cout << std::left << std::setw(WIDTH) << "Gross Box Office Revenue:" << "$" << gross_box_office_rev << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "Amount Paid to Distributor:" << "-$" << gross_box_office_rev * 0.2 << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "Net Box Office Revenue:" << "$" << gross_box_office_rev * 0.8 << std::endl;

    return 0;
}