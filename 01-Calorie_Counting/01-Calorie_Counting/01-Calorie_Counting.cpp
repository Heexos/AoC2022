// 01-Calorie_Counting.cpp

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countMostCarryingCalories(const string& t_filename, const int& t_top) {
    int* maxScores = new int[t_top]();
    int* tmp = new int[t_top]();
    string line;
    ifstream file(t_filename);
    int currScore(0);
    int maxScore(0);
    int offset(0);
    while (getline(file, line)) {
        if (line == "") {
            for (int i(0); i < t_top; i++) {
                if (currScore > maxScores[i]) {
                    tmp[i] = currScore;
                    for (int j(i + 1); j < t_top; j++) {
                        tmp[j] = maxScores[j - 1];
                    }
                    break;
                }
                else {
                    tmp[i] = maxScores[i];
                }
            }

            for (int i(0); i < t_top; i++) {
                maxScores[i] = tmp[i];
            }
            currScore = 0;
        }
        else {
            currScore += stoi(line);
        }
    }
    for (int i(0); i < t_top; i++) {
        maxScore += maxScores[i];
    }
    delete[] maxScores;
    delete[] tmp;
    return maxScore;

}
int main()
{   
    string filePath = "input.txt";
    int maxScore(0);

    cout << "----- Part One -----" << endl;
    maxScore = countMostCarryingCalories(filePath, 1);
    cout << "The elf who carries the most calories carries " << maxScore << endl << endl;
    cout << "----- Part Two -----" << endl;
    maxScore = countMostCarryingCalories(filePath, 3);
    cout << "The 3 elves who carry the most calories carry " << maxScore << endl;
}