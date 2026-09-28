#pragma once
#include <vector>

/**
 * @class ExamTracker
 * @brief Registra examenes y calcula la suma de puntajes en un rango de tiempo.
 */
class ExamTracker {
public:
    ExamTracker();
    void record(int time, int score);
    long long totalScore(int startTime, int endTime);

private:
    std::vector<int> tiempos;
    std::vector<long long> suma;
};
