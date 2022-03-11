#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class TikTakToe
{

public:
    char board[3][3];
    char you;
    char enemy;

    // ========== Constructor ==========

    TikTakToe(char a1, char b1, char c1, char a2, char b2, char c2, char a3, char b3, char c3)
    {
        board[0][0] = a1;
        board[0][1] = b1;
        board[0][2] = c1;
        board[1][0] = a2;
        board[1][1] = b2;
        board[1][2] = c2;
        board[2][0] = a3;
        board[2][1] = b3;
        board[2][2] = c3;
    }

    ~TikTakToe() {}

    // ========== Clear screen and add title ==========

    void setTitle()
    {
        system("CLS");
        cout << "========== Welcome to TikTakToe ==========\n\n";
    }

    // ========== Draw board ==========

    void draw()
    {
        cout << "    A   B   C\n";
        cout << "  +---+---+---+\n";
        cout << "1 | " << board[0][0] << " | " << board[1][0] << " | " << board[2][0] << " |\n";
        cout << "  +---+---+---+\n";
        cout << "2 | " << board[0][1] << " | " << board[1][1] << " | " << board[2][1] << " |\n";
        cout << "  +---+---+---+\n";
        cout << "3 | " << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << " |\n";
        cout << "  +---+---+---+\n\n";
    }

    // ========== Set your label and enemy's ==========

    void setYou()
    {
        char cinYou;
        do
        {
            cout << "Choose your label: (X or O) ";
            cin >> cinYou;
            if (cinYou != 'X' && cinYou != 'O' && cinYou != 'x' && cinYou != 'o')
                cout << "Try a different one!\n\n";
        } while (cinYou != 'X' && cinYou != 'O' && cinYou != 'x' && cinYou != 'o');
        you = cinYou;
        if (you == 'X' || you == 'x')
            enemy = 'O';
        else
            enemy = 'X';
    }

    // ========== Your turn ==========

    void yourTurn()
    {
        int done = 0;
        cout << "Your mark: " << you << "\n\n";
        string position;
        char column;
        int row;
        do
        {
            do
            {
                cout << "Choose a cell to mark: ";
                cin >> position;
                stringstream stringCin(position);
                stringCin >> column;
                stringCin >> row;
                if (column != 'A' && column != 'B' && column != 'C' && column != 'a' && column != 'b' && column != 'c')
                {
                    cout << "Try a different column! (A, B or C)\n";
                }
                if (row != 1 && row != 2 && row != 3)
                {
                    cout << "Try a different row! (1, 2 or 3)\n";
                }
                cout << "\n";
            } while ((column != 'A' && column != 'B' && column != 'C' &&
                      column != 'a' && column != 'b' && column != 'c') ||
                     (row != 1 && row != 2 && row != 3));
            int columnNumber;
            if (column == 'A' || column == 'a')
                columnNumber = 0;
            else if (column == 'B' || column == 'b')
                columnNumber = 1;
            else
                columnNumber = 2;
            if (board[columnNumber][row - 1] == ' ')
            {
                board[columnNumber][row - 1] = you;
                done = 1;
            }
            else
                cout << "Choose an empty cell!\n\n";
        } while (done == 0);
    }

    // ========== Enemy's turn ==========

    void enemyTurn()
    {
        srand(time(NULL));
        int done = 0;
        do {
            int enemyPosition = rand() % 9;
            int enemyRow = enemyPosition % 3;
            int enemyColumnNumber = enemyPosition / 3;
            if (board[enemyColumnNumber][enemyRow] == ' ')
            {
                board[enemyColumnNumber][enemyRow] = enemy;
                done = 1;
            }
        } while (done == 0);
    }

    // ========== Win conditions ==========

    bool winCondition(char mark)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark)
                return true;
            if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)
                return true;
        }
        if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
            return true;
        if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
            return true;
        return false;
    }

    // ========== Checks if the board is filled ==========

    bool boardFilled()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    int more = 1;
    while (more)
    {
        TikTakToe game(' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
        game.setTitle();
        game.setYou();
        game.setTitle();
        game.draw();
        while (true)
        {
            game.yourTurn();
            game.setTitle();
            game.draw();
            if (game.winCondition(game.you))
            {
                cout << "Congratulations, you won!\n\n";
                break;
            }
            if (game.boardFilled())
            {
                cout << "Draw!\n\n";
                break;
            }
            game.enemyTurn();
            game.setTitle();
            game.draw();
            if (game.winCondition(game.enemy))
            {
                cout << "Game over, you lost...\n\n";
                break;
            }
            if (game.boardFilled())
            {
                cout << "Draw!\n\n";
                break;
            }
        }
        cout << "Wanna play some more? (1: yes, 0: no) ";
        cin >> more;
    }
    return 0;
}