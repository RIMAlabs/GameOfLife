#include "GameOfLife.h"

/**
 * @brief Constructs a GameOfLife object with a square grid of given size.
 * @param size Size of the square grid.
 */
GameOfLife::GameOfLife(int size) : matrix(size), game(&matrix) {}

/**
 * @brief Constructs a GameOfLife object with a rectangular grid of given width and height.
 * @param width Width of the grid.
 * @param height Height of the grid.
 */
GameOfLife::GameOfLife(int width, int height) : matrix(width, height), game(&matrix) {}

/**
 * @brief Gets the value of a cell at given coordinates.
 * @param x X-coordinate of the cell.
 * @param y Y-coordinate of the cell.
 * @return Boolean value of the cell.
 */
bool GameOfLife::getCell(int x, int y) {
    return matrix.getCell(x, y);
}

/**
 * @brief Sets the value of a cell at given coordinates.
 * @param alive Boolean value to set.
 * @param x X-coordinate of the cell.
 * @param y Y-coordinate of the cell.
 */
void GameOfLife::setCell(bool alive, int x, int y) {
    matrix.setCell(alive, x, y);
}

/**
 * @brief Initializes the game board with random values.
 */
void GameOfLife::initializeBoard() {
    matrix.fillRandomly();
}

/**
 * @brief Advances the game state by one step.
 */
void GameOfLife::step() {
    auto start = std::chrono::system_clock::now();
    game.updateGame();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    totalTime = static_cast<long>(elapsed_seconds.count() * 1000);
}

/**
 * @brief Gets the time taken for the last step.
 * @return Time taken for the last step in milliseconds.
 */
long GameOfLife::getStepTime() {
    return totalTime;
}