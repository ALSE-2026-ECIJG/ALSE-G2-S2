#include "ExamTracker.h"
#include <algorithm>

ExamTracker::ExamTracker() {
    suma.push_back(0);
}

void ExamTracker::record(int time, int score) {
    tiempos.push_back(time);
    suma.push_back(suma.back() + score);
}

long long ExamTracker::totalScore(int startTime, int endTime) {
    int desde = lower_bound(tiempos.begin(), tiempos.end(), startTime) - tiempos.begin();
    int hasta = upper_bound(tiempos.begin(), tiempos.end(), endTime) - tiempos.begin();
    return suma[hasta] - suma[desde];
}
