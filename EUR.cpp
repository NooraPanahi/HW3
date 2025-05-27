#include "currency.hpp"
#include "EUR.hpp"
#include "USD.hpp"


EUR::EUR(double v) : value(v) {}

double EUR::to_usd() const {
    return value * 2;  // فرضی: هر یورو = 2 دلار
}

USD EUR::operator*(double rate) const {
    return USD(this->to_usd() * rate);
}

USD EUR::operator+(const Currency& other) const {
    return USD(this->to_usd() + other.to_usd());
}

USD EUR::operator-(const Currency& other) const {
    return USD(this->to_usd() - other.to_usd());
}

bool EUR::operator<(const Currency& other) const {
    return this->to_usd() < other.to_usd();
}

bool EUR::operator>(const Currency& other) const {
    return this->to_usd() > other.to_usd();
}

double EUR::get_value() const {
    return value;}