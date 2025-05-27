
#ifndef USD_HPP
#define USD_HPP

#include "currency.hpp"

class USD : public Currency {
public:
    USD(double v);
    double to_usd() const override;

    USD operator+(const Currency& other) const;
    USD operator-(const Currency& other) const;
    bool operator<(const Currency& other) const;
    bool operator>(const Currency& other) const;

private:
    double value;
};

#endif // USD_HPP


