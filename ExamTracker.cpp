#include <iostream>
#include <vector>

using namespace std;

class ExamTracker {
private:
    vector<long long> tiempos;
    vector<long long> puntajes;

public:

    ExamTracker() {
    }

    void record(int time, int score) {
        tiempos.push_back(time);
        puntajes.push_back(score);
    }

    long long totalScore(int startTime, int endTime) {

        long long total = 0;

        for (int i = 0; i < (int)tiempos.size(); i++) {

            if (tiempos[i] >= startTime &&
                tiempos[i] <= endTime) {

                total += puntajes[i];
            }
        }

        return total;
    }
};

int main() {

    ExamTracker examenes;

    examenes.record(1, 98);

    cout << examenes.totalScore(1, 1) << endl;

    examenes.record(5, 99);

    cout << examenes.totalScore(1, 3) << endl;

    cout << examenes.totalScore(1, 5) << endl;

    cout << examenes.totalScore(3, 4) << endl;

    cout << examenes.totalScore(2, 5) << endl;

    return 0;
}