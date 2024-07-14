//
// Created by Rafael Magana on 09/07/24.
//

#ifndef MATRIX_H
#define MATRIX_H

/**
 * @class Matrix
 * @brief Represents a 2D grid of boolean values.
 */
class Matrix {
private:
    bool** cells; ///< 2D array of boolean values representing the grid cells.
    int width; ///< Width of the grid.
    int height; ///< Height of the grid.

public:
    /**
     * @brief Constructs a square Matrix of given size.
     * @param size Size of the square matrix.
     */
    Matrix(int size);

    /**
     * @brief Constructs a Matrix of given width and height.
     * @param width Width of the matrix.
     * @param height Height of the matrix.
     */
    Matrix(int width, int height);

    /**
     * @brief Destructor to clean up allocated memory.
     */
    ~Matrix();

    /**
     * @brief Fills the matrix with random boolean values.
     */
    void fillRandomly();

    /**
     * @brief Gets the value of a cell at given coordinates.
     * @param x X-coordinate of the cell.
     * @param y Y-coordinate of the cell.
     * @return Boolean value of the cell.
     */
    bool getCell(int x, int y) const;

    /**
     * @brief Sets the value of a cell at given coordinates.
     * @param alive Boolean value to set.
     * @param x X-coordinate of the cell.
     * @param y Y-coordinate of the cell.
     */
    void setCell(bool alive, int x, int y);

    /**
     * @brief Gets the 2D array of cells.
     * @return 2D array of boolean values.
     */
    bool** getCells() const;

    /**
     * @brief Sets the 2D array of cells.
     * @param newCells New 2D array of boolean values.
     */
    void setCells(bool** newCells);

    /**
     * @brief Gets the width of the matrix.
     * @return Width of the matrix.
     */
    int getWidth() const;

    /**
     * @brief Gets the height of the matrix.
     * @return Height of the matrix.
     */
    int getHeight() const;
};

#endif // MATRIX_H
