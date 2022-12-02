#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int outcome(const char& t_elfMove, const char& t_myMove) {
    switch (t_elfMove) {
    case 'A': // Rock
        switch (t_myMove) {
        case 'X': // Rock -> Draw
            return 3;
        case 'Y': // Paper -> Win
            return 6;
        case 'Z': // Scissors -> Lose
            return 0;
        default:
            break;
        }
        break;
    case 'B': // Paper
        switch (t_myMove) {
        case 'X': // Rock -> Lose
            return 0;
        case 'Y': // Paper -> Draw
            return 3;
        case 'Z': // Scissors -> Win
            return 6;
        default:
            break;
        }
        break;
    case 'C': // Scissors
        switch (t_myMove) {
        case 'X': // Rock -> Win
            return 6;
        case 'Y': // Paper -> Lose
            return 0;
        case 'Z': // Scissors -> Draw
            return 3;
        default:
            break;
        }
        break;
    default:
        return 0;
    }
}

char move(const char& t_elfMove, const char& t_outcome) {
    switch (t_elfMove) {
    case 'A': // Rock
        switch (t_outcome) {
        case 'X': // Lose -> Scissors
            return 'C';
        case 'Y': // Draw -> Rock
            return 'A';
        case 'Z': // Win -> Paper
            return 'B';
        default:
            break;
        }
        break;
    case 'B': // Paper
        switch (t_outcome) {
        case 'X': // Lose -> Rock
            return 'A';
        case 'Y': // Draw -> Paper
            return 'B';
        case 'Z': // Lose -> Scissors
            return 'C';
        default:
            break;
        }
        break;
    case 'C': // Scissors
        switch (t_outcome) {
        case 'X': // Loose -> Paper
            return 'B';
        case 'Y': // Draw -> Scissors
            return 'C';
        case 'Z': // Win -> Rock
            return 'A';
        default:
            break;
        }
        break;
    default:
        return 0;
    }
}

int main()
{
    map<char, int> moveScore = {
        {'X', 1}, {'Y', 2}, {'Z', 3}, {'A', 1}, {'B', 2}, {'C', 3}
    };
    map<char, int> endsScore = {
        {'X', 0}, {'Y', 3}, {'Z', 6}
    };
    ifstream file("input.txt");
    int scorePart1(0), scorePart2(0);
    int maxScore(0);
    int offset(0);
    char* input;
    string line;
    char elfMove, myMove;
    while (getline(file, line)) {
        elfMove = line[0];
        myMove = line[2];
        scorePart1 += outcome(elfMove, myMove) + moveScore[myMove];
        scorePart2 += endsScore[myMove] + moveScore[move(elfMove, myMove)];
    }
    cout << "Scored " << scorePart1 << " for part One." << endl;
    cout << "Scored " << scorePart2 << " for part Two." << endl;
}

