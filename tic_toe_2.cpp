#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int turn = 0;
vector<int> board(9, 0); // Changed to 0 for empty, 1 for Player X, -1 for Player O

void display() {
    cout << "\nBoard:\n";
    for (int i = 0; i < 9; i++) {
        if (board[i] == 1)
            cout << "X ";
        else if (board[i] == -1)
            cout << "O ";
        else
            cout << "B "; // Represents empty

        if ((i + 1) % 3 == 0)
            cout << endl;
    }
    cout << endl;
}

void go(int x) {
    if (turn % 2 == 0)
        board[x] = 1; // Player X (Human)
    else
        board[x] = -1; // Player O (Computer)
    turn++;
}

int make2() {
    if (board[4] == 0)
        return 4;
    for (int i = 1; i <= 7; i += 2) {
        if (board[i] == 0)
            return i;
    }
    return -1;
}

int poswin(int player_value) {
    vector<int> magicSquare = {8, 1, 6, 3, 5, 7, 4, 9, 2};
    vector<vector<int>> w = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };
    const int MAGIC_SUM = 15;

    for (int i = 0; i < w.size(); ++i) { // Changed to normal for loop
        const vector<int>& line = w[i];
        int current_line_sum = 0;
        int empty_pos_in_line = -1;

        for (int j = 0; j < line.size(); ++j) { // Changed to normal for loop
            int cell_idx = line[j];
            if (board[cell_idx] == player_value) {
                current_line_sum += magicSquare[cell_idx];
            } else if (board[cell_idx] == 0) {
                empty_pos_in_line = cell_idx;
            }
        }
        if (empty_pos_in_line != -1 && (current_line_sum + magicSquare[empty_pos_in_line] == MAGIC_SUM)) {
            return empty_pos_in_line;
        }
    }
    return -1;
}

bool iswin(int player_value) {
    vector<int> magicSquare = {8, 1, 6, 3, 5, 7, 4, 9, 2};
    vector<vector<int>> w = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };
    const int MAGIC_SUM = 15;

    for (int i = 0; i < w.size(); ++i) { // Changed to normal for loop
        const vector<int>& line = w[i];
        int current_line_sum = 0;
        for (int j = 0; j < line.size(); ++j) { // Changed to normal for loop
            int cell_idx = line[j];
            if (board[cell_idx] == player_value) {
                current_line_sum += magicSquare[cell_idx];
            }
        }
        if (current_line_sum == MAGIC_SUM) {
            return true;
        }
    }
    return false;
}

int main() {
    int x, p, m;

    cout << "Enter position for x: ";
    cin >> x;
    go(x);
    display();

    m = make2();
    go(m);
    display();

    cout << "Enter position for x: ";
    cin >> x;
    go(x);
    display();

    p = poswin(-1); // Check if computer can win
    if (p != -1)
        go(p);
    else {
        p = poswin(1); // Check if human can win (to block)
        if (p != -1)
            go(p);
        else {
            m = make2();
            go(m);
        }
    }
    display();

    cout << "Enter position for x: ";
    cin >> x;
    go(x);
    display();

    if (iswin(1)) {
        cout << "You WIN!!!";
        return 0;
    }

    p = poswin(-1);
    if (p != -1) {
        go(p);
    } else {
        p = poswin(1);
        if (p != -1) {
            go(p);
        } else {
            go(make2());
        }
    }
    display();

    if (iswin(-1)) {
        cout << "I WIN!!!";
        return 0;
    }

    cout << "Enter position for x: ";
    cin >> x;
    go(x);
    display();

    if (iswin(1)) {
        cout << "You WIN!!!";
        return 0;
    }

    p = poswin(-1);
    if (p != -1) {
        go(p);
    } else {
        p = poswin(1);
        if (p != -1) {
            go(p);
        } else {
            go(make2());
        }
    }
    display();

    if (iswin(-1)) {
        cout << "I WIN!!!";
        return 0;
    }

    cout << "Enter position for x: ";
    cin >> x;
    go(x);
    display();

    if (iswin(1)) {
        cout << "You WIN!!!";
        return 0;
    }

    cout << "DRAW!!!";
    return 0;
}