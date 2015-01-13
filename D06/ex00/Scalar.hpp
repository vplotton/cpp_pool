/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 17:43:24 by sbres             #+#    #+#             */
/*   Updated: 2015/01/13 17:43:32 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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