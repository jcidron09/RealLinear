//
// Created by Joshua Cidron on 2/2/24.
//

#ifndef LINEARALGEBRA_LINEARALGEBRAERRORS_H
#define LINEARALGEBRA_LINEARALGEBRAERRORS_H

#include <exception>
#include <string>

class LinearAlgebraException : public std::exception{
    private:
        std::string error_type{};
        std::string error_text{};
    public:
        LinearAlgebraException(const std::string& error_type);
        [[nodiscard]] const char* what() const noexcept override {return error_text.c_str();};
};


#endif //LINEARALGEBRA_LINEARALGEBRAERRORS_H
