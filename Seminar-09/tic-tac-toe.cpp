#include <iostream>

constexpr size_t BOARD_SIZE      = 4;
constexpr size_t PLAYERS_COUNT   = 2;
const size_t WINNING_LINE_LENGTH = 4;
const int EMPTY_CELL = -1;

void initPlayerSymbols(char playerSymbols[PLAYERS_COUNT])
{
    for (size_t i = 0; i < PLAYERS_COUNT; i++)
    {
        std::cout << "Enter symbol for player " << i << ": ";
        std::cin >> playerSymbols[i];
    }
}

void clearBoard(int board[BOARD_SIZE][BOARD_SIZE], int defaultValue)
{
    for (size_t i = 0; i < BOARD_SIZE; i++)
    {
        for (size_t j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = defaultValue;
        }
    }
}

bool validIndex(unsigned x, unsigned y)
{
    return x < BOARD_SIZE && y < BOARD_SIZE;
}

bool isValidMove(const int board[BOARD_SIZE][BOARD_SIZE], unsigned x, unsigned y)
{
    return validIndex(x, y) && (board[x][y] == EMPTY_CELL);
}

void getCell(const int board[BOARD_SIZE][BOARD_SIZE], unsigned& x, unsigned& y, unsigned player)
{
    bool failed = false;
    do
    {
        if(failed)
        {
            std::cout << "Invalid coordinates!" << std::endl;
        }

        std::cout << "Enter " << player << " move: ";
        std::cin >> x >> y;

        failed = true;
    } while (!isValidMove(board, x, y));
}

void makeMove(int board[BOARD_SIZE][BOARD_SIZE], char symbol, unsigned player, unsigned& xCoord, unsigned& yCoord)
{
    getCell(board, xCoord, yCoord, player);
    board[xCoord][yCoord] = player;
}

void printBoard(const int board[BOARD_SIZE][BOARD_SIZE], const char playerSymbols[PLAYERS_COUNT])
{
    system("clear");
    std::cout << " ";

    for (size_t i = 0; i < BOARD_SIZE; i++)
    {
        std::cout << "  " << i;
    }
    
    std::cout << std::endl;

    for (size_t i = 0; i < BOARD_SIZE; i++)
    {
        std::cout << i << " ";
        for (size_t j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] == EMPTY_CELL)
            {
                std::cout << "[#]";
            }
            else
            {
                std::cout << "[" << playerSymbols[board[i][j]] << "]";
            }
        }
        std::cout << std::endl;
    }
}

unsigned getConsecutiveCount(const int board[BOARD_SIZE][BOARD_SIZE], unsigned x, unsigned y, unsigned stepX, unsigned stepY)
{
    unsigned result = 0;
    int currentSymbol = board[x][y];

    unsigned tempX = x;
    unsigned tempY = y;
    
    // Those while loops can (and should) be inside another function.
    // Keeping them inside this one, hoping to make the idea of the function easier to understand.
    while (validIndex(tempX, tempY) && board[tempX][tempY] == currentSymbol)
    {
        ++result;
        tempX += stepX;
        tempY += stepY;
    }
    
    tempX = x - stepX;
    tempY = y - stepY;

    while (validIndex(tempX, tempY) && board[tempX][tempY] == currentSymbol)
    {
        ++result;
        tempX -= stepX;
        tempY -= stepY;
    }

    return result;
}

bool isWinningMove(const int board[BOARD_SIZE][BOARD_SIZE], unsigned x, unsigned y)
{
    return  (getConsecutiveCount(board, x, y, 1, 0) >= WINNING_LINE_LENGTH) ||
            (getConsecutiveCount(board, x, y, 0, 1) >= WINNING_LINE_LENGTH) ||
            (getConsecutiveCount(board, x, y, -1, 1) >= WINNING_LINE_LENGTH) ||
            (getConsecutiveCount(board, x, y, 1, 1) >= WINNING_LINE_LENGTH); 
}

void play(int board[BOARD_SIZE][BOARD_SIZE], const char playerSymbols[PLAYERS_COUNT])
{
    unsigned playerPlaying = 0;
    unsigned x = 0;
    unsigned y = 0;
    unsigned movesCount = 0;
    
    int winningPlayer = -1;

    while(true)
    {
        printBoard(board, playerSymbols);
        makeMove(board, playerSymbols[playerPlaying], playerPlaying, x, y);
        ++movesCount;

        bool cellsLeft = !(movesCount == (BOARD_SIZE * BOARD_SIZE));

        if(isWinningMove(board, x, y) || cellsLeft)
        {
            winningPlayer = cellsLeft ? playerPlaying : -1;
            break;
        }

        ++playerPlaying;

        playerPlaying %= PLAYERS_COUNT;
    }
    printBoard(board, playerSymbols);

    if(winningPlayer == -1)
    {
        std::cout << "Draw" << std::endl;
    }
    else
    {
        std::cout << "Winner is player " << winningPlayer << "!!!" << std::endl; 
    }
}

int main()
{
    char playerSymbols[PLAYERS_COUNT];
    int board[BOARD_SIZE][BOARD_SIZE];

    initPlayerSymbols(playerSymbols);
    clearBoard(board, EMPTY_CELL);
    play(board, playerSymbols);
}