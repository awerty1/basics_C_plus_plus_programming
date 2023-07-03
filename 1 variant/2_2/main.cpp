// Файл main.cpp
#include <iostream>
#include "lucky_tickets.h"

int main() {
    size_t count = calculateTotalLuckyTickets();

    std::cout << "Total number of lucky tickets: " << count << std::endl;

    return 0;
}