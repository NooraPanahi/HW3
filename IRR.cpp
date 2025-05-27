#include "currency.hpp"
#include "IRR.hpp"


#include "USD.hpp"

IRR::IRR(double v) : value(v) {}

double IRR::to_usd() const {
    return value / 10.0;  
}
USD IRR::operator+(const Currency& other) const {
    return USD(this->to_usd() + other.to_usd());
}

USD IRR::operator-(const Currency& other) const {
    return USD(this->to_usd() - other.to_usd());
}

bool IRR::operator<(const Currency& other) const {
    return this->to_usd() < other.to_usd();
}

bool IRR::operator>(const Currency& other) const {
    return this->to_usd() > other.to_usd();
}

USD IRR::operator/(double rate) const {
    return USD(this->to_usd() / rate);
}

double IRR::get_value() const {
    return value;
}
