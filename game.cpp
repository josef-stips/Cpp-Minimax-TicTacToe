#include<iostream>
#include<climits>
#include<chrono>
using namespace std;
using namespace chrono;

void draw_game(char field[3][3], int size);
void user_input_handle();
void user_choose_character();
void change_player();
void ai_call();
pair<int, int> minimax(bool maximazing_player, int depth, char field[3][3]);

char field[3][3] = { 
    {'0', '0', '0'}, 
    {'0', '0', '0'}, 
    {'0', '0', '0'}
};

char winner = ' ';
char user_char = ' ';
char ai_char = ' ';
char curr_player = ' ';

int main() {
    draw_game(field, sizeof(field) / sizeof(field[0]));
    user_choose_character();
    user_input_handle();

    return 0;
}

pair<int, int> minimax(bool maximazing_player, int depth, char field[3][3]) {

    if(maximazing_player) {
        return {1, 2};

    } else {

        return {2,2};
    };
};

void ai_call() {
    cout << "\nthe ai is thinking... \n";

    // clock start
    auto start = high_resolution_clock::now();

    pair<int, int> bestVal = minimax(true, INT_MAX, field);

    // clock end
    auto end = high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    field[bestVal.first][bestVal.second] = ai_char;
    draw_game(field, sizeof(field) / sizeof(field[0]));
    change_player();

    cout << "\nthe ai had to think for " << duration.count() << " milliseconds" << "\n";
};

void change_player() {
    curr_player = curr_player == 'x' ? 'o' : 'x';

    if(curr_player != user_char) {
        ai_call();
    };
};

void user_choose_character() {
    cout << "\nchoose a character (x, o) \n";
    cin >> user_char;
    cout << "\nyou choosed the letter " << user_char << "\n";

    curr_player = user_char;
    ai_char = curr_player == 'x' ? 'o' : 'x';
};

void user_input_handle() {
    while(winner == ' ') {
        int user_input_x;
        int user_input_y;

        cout << "\n" << "input a number between 0 and 2 for the row x: ";
        cin >> user_input_x;
        cout << "\n" << "input a number between 0 and 2 for the column y: ";    
        cin >> user_input_y;

        field[user_input_x][user_input_y] = user_char;

        draw_game(field, sizeof(field) / sizeof(field[0]));
        change_player();
    };
};

void draw_game(char field[3][3], int size) {
    cout << "\n";

    // draw field
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << field[i][j] << " ";
        };

        cout << "\n";
    };
};