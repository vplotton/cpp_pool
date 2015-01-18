#include <iostream>

class Scalar {

public:
    Scalar();
    Scalar(double src);
    Scalar(char src);
    Scalar(Scalar const & src);
    ~Scalar();
    Scalar & operator=(Scalar const & rhs);
    double get_value() const;

private:
    double _value;
};

std::ostream & operator<<(std::ostream & o, Scalar const & i);
