#include <iostream>
#include "ExamTracker.h"

int main() {
    ExamTracker et;
    et.record(1, 98);
    std::cout << "totalScore(1,1) = " << et.totalScore(1, 1) << " (esperado: 98)\n";
    et.record(5, 99);
    std::cout << "totalScore(1,3) = " << et.totalScore(1, 3) << " (esperado: 98)\n";
    std::cout << "totalScore(1,5) = " << et.totalScore(1, 5) << " (esperado: 197)\n";
    std::cout << "totalScore(3,4) = " << et.totalScore(3, 4) << " (esperado: 0)\n";
    std::cout << "totalScore(2,5) = " << et.totalScore(2, 5) << " (esperado: 99)\n";
    return 0;
}
