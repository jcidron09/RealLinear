//
// Created by Joshua Cidron on 2/2/24.
//

#ifndef RealLinear_REALLINEARERRORS_H
#define RealLinear_REALLINEARERRORS_H

#include <exception>
#include <string>

class RealLinearException : public std::exception{
    private:
        std::string error_type{};
        std::string error_text{};
    public:
        RealLinearException(const std::string& error_type);
        [[nodiscard]] const char* what() const noexcept override {return error_text.c_str();};
        std::string type();
};


#endif //RealLinear_REALLINEARERRORS_H
