#include "Matrix.h"
#include <cstdlib>
#include <ctime>

/**
 * @brief Constructs a square Matrix of given size.
 * @param size Size of the square matrix.
 */
Matrix::Matrix(int size) : Matrix(size, size) {}

/**
 * @brief Constructs a Matrix of given width and height.
 * @param width Width of the matrix.
 * @param height Height of the matrix.
 */
Matrix::Matrix(int width, int height) : width(width), height(height) {
    cells = new bool*[width];
    for(int i = 0; i < width; ++i) {
        cells[i] = new bool[height];
        for(int j = 0; j < height; ++j) {
            cells[i][j] = false;
        }
    }
}

/**
 * @brief Destructor to clean up allocated memory.
 */
Matrix::~Matrix() {
    for(int i = 0; i < width; ++i) {
        delete[] cells[i];
    }
    delete[] cells;
}

/**
 * @brief Fills the matrix with random boolean values.
 */
void Matrix::fillRandomly() {
    srand(time(0));
    for(int i = 0; i < width; ++i) {
        for(int j = 0; j < height; ++j) {
            cells[i][j] = rand() % 2 == 1;
        }
    }
}

/**
 * @brief Gets the value of a cell at given coordinates.
 * @param x X-coordinate of the cell.
 * @param y Y-coordinate of the cell.
 * @return Boolean value of the cell.
 */
bool Matrix::getCell(int x, int y) const {
    return cells[x][y];
}

/**
 * @brief Sets the value of a cell at given coordinates.
 * @param alive Boolean value to set.
 * @param x X-coordinate of the cell.
 * @param y Y-coordinate of the cell.
 */
void Matrix::setCell(bool alive, int x, int y) {
    cells[x][y] = alive;
}

/**
 * @brief Gets the 2D array of cells.
 * @return 2D array of boolean values.
 */
bool** Matrix::getCells() const {
    return cells;
}

/**
 * @brief Sets the 2D array of cells.
 * @param newCells New 2D array of boolean values.
 */
void Matrix::setCells(bool** newCells) {
    for(int i = 0; i < width; ++i) {
        for(int j = 0; j < height; ++j) {
            cells[i][j] = newCells[i][j];
        }
    }
}

/**
 * @brief Gets the width of the matrix.
 * @return Width of the matrix.
 */
int Matrix::getWidth() const {
    return width;
}

/**
 * @brief Gets the height of the matrix.
 * @return Height of the matrix.
 */
int Matrix::getHeight() const {
    return height;
}