//
// Created by Joshua Cidron on 3/29/24.
//

#include "../RealLinear.h"

namespace RealLinear {
    Matrix::Matrix() {
        this->rows = 0;
        this->columns = 0;
        this->dimension = std::tuple<int, int>(rows, columns);
        this->entries.emplace_back();
    }
    Matrix::Matrix(int rows, int columns) {
        this->rows = rows;
        this->columns = columns;
        this->dimension = std::tuple<int, int>(rows, columns);
        for (int i = 0; i < columns; i++) {
            this->entries.emplace_back(columns);
        }
    }

    Matrix::Matrix(std::vector<Vector>& entries) {
        int previous_dimension = entries[0].dimension;
        for (const Vector& vector : entries) {
            if (previous_dimension != vector.dimension)
                throw RealLinearException("MatrixVectorConstructionError");
            else
                previous_dimension = vector.dimension;
        }
        this->rows = entries.size();
        this->columns = entries[0].dimension;
        this->dimension = std::tuple<int, int>(rows, columns);
        this->entries = entries;
    }

    //    Vector& operator [](int index);
    //    Matrix operator + (Matrix matrix);
    //    Matrix operator += (Matrix matrix);
    //    bool operator == (Matrix matrix);
    //    Matrix& operator *= (double scalar);
    //    Matrix& operator * (double scalar);

    Vector& Matrix::operator [](int index) {
        if (this->columns == 0 || this->rows == 0)
            throw RealLinearException("ZeroDimensionalMatrix");
        if (index > this->rows)
            throw RealLinearException("MatrixIndexOutOfBounds");
        return this->entries[index];
    }

    Matrix Matrix::operator +(Matrix matrix) {
        if (this->dimension != matrix.dimension) {
            throw RealLinearException("MatrixDimensionMatchError");
        }
        if (this->columns == 0 || this->rows == 0)
            throw RealLinearException("ZeroDimensionalMatrix");
        auto* sum = new Matrix(matrix.dimension);
        for (int row = 0; row < this->rows; row++) {
            for (int col = 0; col < this->columns; col++){
                sum->entries[row][col] = this->entries[row][col] + matrix.entries[row][col];
            }
        }
        return *sum;
    }

    Matrix Matrix::operator +=(Matrix matrix) {
        if (this->dimension != matrix.dimension) {
            throw RealLinearException("MatrixDimensionMatchError");
        }
        if (this->columns == 0 || this->rows == 0)
            throw RealLinearException("ZeroDimensionalMatrix");
        auto* sum = new Matrix(matrix.dimension);
        for (int row = 0; row < this->rows; row++) {
            for (int col = 0; col < this->columns; col++){
                sum->entries[row][col] = this->entries[row][col] + matrix.entries[row][col];
            }
        }
        return *sum;
    }

    bool Matrix::operator ==(RealLinear::Matrix matrix) {
        if (this->dimension != matrix.dimension)
            throw RealLinearException("MatrixDimensionMatchError");
        if (this->dimension == std::make_tuple(0,0)){
            return true;
        }
        for (int row = 0; row < this->rows; row++) {
            for (int col = 0; col < this->columns; col++){
                if (this->entries[row][col] != matrix.entries[row][col])
                    return false;
            }
        }
        return true;
    }

    Matrix& Matrix::operator*(double scalar) {
        if (this->dimension == std::make_tuple(0,0))
            throw RealLinearException("ZeroDimensionalMatrix");
        for (int row = 0; row < this->rows; row++) {
            for (int col = 0; col < this->columns; col++){
                this->entries[row][col] *= scalar;
            }
        }
        return *this;
    }

    Matrix& Matrix::operator *= (double scalar) {
        if (this->dimension == std::make_tuple(0,0))
            throw RealLinearException("ZeroDimensionalMatrix");
        for (int row = 0; row < this->rows; row++) {
            for (int col = 0; col < this->columns; col++){
                this->entries[row][col] *= scalar;
            }
        }
        return *this;
    }

}