// Файл tests.cpp
#include <cassert>
#include "lucky_tickets.h"

void testCalculateTotalLuckyTickets() {
    // Проверка на корректность подсчета количества счастливых билетов
    size_t count = calculateTotalLuckyTickets();
    assert(count == 55252);
}

int main() {
    testCalculateTotalLuckyTickets();

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}