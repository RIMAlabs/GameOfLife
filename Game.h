//
// Created by Rafael Magana on 09/07/24.
//

#ifndef GAME_H
#define GAME_H

#include "Matrix.h"

/**
 * @class Game
 * @brief Manages the Game of Life logic.
 */
class Game {
private:
    static bool** cells; ///< Static pointer to the cells of the matrix.
    static Matrix* matrix; ///< Static pointer to the matrix.
    bool** buffer; ///< Buffer to store the next state of the game grid.
    int width; ///< Width of the game grid.
    int height; ///< Height of the game grid.

    /**
     * @brief Counts the number of alive neighbors for a cell.
     * @param x X-coordinate of the cell.
     * @param y Y-coordinate of the cell.
     * @return Number of alive neighbors.
     */
    int countAliveNeighbors(int x, int y);

public:
    /**
     * @brief Constructs a Game object with a given matrix.
     * @param matrix Pointer to the Matrix object.
     */
    Game(Matrix* matrix);

    /**
     * @brief Updates the game state to the next generation.
     */
    void updateGame();
};

#endif // GAME_H