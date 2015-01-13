#include "Scalar.hpp"
#include <math.h>
#include <limits.h>

Scalar::Scalar(): _value(0){

}

Scalar::Scalar(double src): _value(src){

}

Scalar::Scalar(char src) {
    this->_value = static_cast<double>(src);
}

Scalar::Scalar(Scalar const &src) {
    this->_value = src.get_value();
}

Scalar::~Scalar() {

}

Scalar &Scalar::operator=(Scalar const &rhs) {
    this->_value = rhs.get_value();
    return *this;
}

double Scalar::get_value() const {
    return this->_value;
}


std::ostream & operator<<(std::ostream & o, Scalar const & i) {
    static const std::string ascii[32] = {
            "\\0","\\1","\\2","\\3","\\4","\\5","\\6","\\a","\\b",
            "\\n","\\v","\\f","\\r","\\14","\\15","\\16","\\17",
            "\\18","\\19","\\20","\\21","\\22","\\23","\\24",
            "\\25","\\26","\\27","\\28","\\29","\\30","\\31", "\\32"};
    double value = i.get_value();
    if (isnan(value) || isinf(value))
    {
        o << "char: impossible" << std::endl;
        o << "int: impossible" << std::endl;
    }
    else
    {
        if (value > INT_MAX || value < INT_MIN)
            o << "int: impossible" << std::endl;
        else
            o << "int: " << static_cast<int>(value) << std::endl;
        if (value > CHAR_MAX || value < CHAR_MIN)
            o << "char: impossible" << std::endl;
        else
        {
            if (value >= 0 && value <= 31)
                o << "char: '" << ascii[static_cast<int>(value)] << "'" << std::endl;
            else
                o << "char: '" << static_cast<char>(value) << "'" << std::endl;
        }
    }
    o << "float: " << static_cast<float>(value) << "f" << std::endl;
    o << "double: " << value;

    return o;
}
