#include "Game.h"

bool** Game::cells = nullptr;
Matrix* Game::matrix = nullptr;

/**
 * @brief Constructs a Game object with a given matrix.
 * @param mat Pointer to the Matrix object.
 */
Game::Game(Matrix* mat) {
    matrix = mat;
    cells = matrix->getCells();
    width = matrix->getWidth();
    height = matrix->getHeight();
    buffer = new bool*[width];
    for (int i = 0; i < width; ++i) {
        buffer[i] = new bool[height];
    }
}

/**
 * @brief Updates the game state to the next generation.
 */
void Game::updateGame() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int aliveNeighbors = countAliveNeighbors(i, j);
            buffer[i][j] = aliveNeighbors == 3 || (aliveNeighbors == 2 && cells[i][j]);
        }
    }
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            cells[i][j] = buffer[i][j];
        }
    }
    matrix->setCells(cells);
}

/**
 * @brief Counts the number of alive neighbors for a cell.
 * @param x X-coordinate of the cell.
 * @param y Y-coordinate of the cell.
 * @return Number of alive neighbors.
 */
int Game::countAliveNeighbors(int x, int y) {
    int alive = 0;
    int offsets[] = {-1, 0, 1};

    for (int dx : offsets) {
        for (int dy : offsets) {
            if (dx == 0 && dy == 0) continue;
            int xNeighbor = (x + dx + width) % width;
            int yNeighbor = (y + dy + height) % height;
            if (cells[xNeighbor][yNeighbor]) alive++;
        }
    }
    return alive;
}