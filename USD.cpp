#include "currency.hpp"
#include "USD.hpp"

USD::USD(double v) : value(v) {}


// same as get functions
double USD::to_usd() const  { 
    return value;
 }


USD USD::operator+(const Currency& other) const {
    return USD(this->to_usd() + other.to_usd());
}

USD USD::operator-(const Currency& other) const {
    return USD(this->to_usd() - other.to_usd());
}

bool USD::operator<(const Currency& other) const {
    return this->to_usd() < other.to_usd();
}

bool USD::operator>(const Currency& other) const {
    return this->to_usd() > other.to_usd();
}


