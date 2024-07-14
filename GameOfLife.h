//
// Created by Rafael Magana on 09/07/24.
//

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "Matrix.h"
#include "Game.h"
#include <chrono>

/**
 * @class GameOfLife
 * @brief Manages the overall Game of Life simulation.
 */
class GameOfLife {
private:
    Matrix matrix; ///< Matrix representing the game grid.
    Game game; ///< Game logic handler.
    std::chrono::time_point<std::chrono::system_clock> startTime; ///< Start time of the current step.
    long totalTime; ///< Total time taken for the current step in milliseconds.

public:
    /**
     * @brief Constructs a GameOfLife object with a square grid of given size.
     * @param size Size of the square grid.
     */
    GameOfLife(int size);

    /**
     * @brief Constructs a GameOfLife object with a rectangular grid of given width and height.
     * @param width Width of the grid.
     * @param height Height of the grid.
     */
    GameOfLife(int width, int height);

    /**
     * @brief Gets the value of a cell at given coordinates.
     * @param x X-coordinate of the cell.
     * @param y Y-coordinate of the cell.
     * @return Boolean value of the cell.
     */
    bool getCell(int x, int y);

    /**
     * @brief Sets the value of a cell at given coordinates.
     * @param alive Boolean value to set.
     * @param x X-coordinate of the cell.
     * @param y Y-coordinate of the cell.
     */
    void setCell(bool alive, int x, int y);

    /**
     * @brief Initializes the game board with random values.
     */
    void initializeBoard();

    /**
     * @brief Advances the game state by one step.
     */
    void step();

    /**
     * @brief Gets the time taken for the last step.
     * @return Time taken for the last step in milliseconds.
     */
    long getStepTime();
};

#endif // GAMEOFLIFE_H