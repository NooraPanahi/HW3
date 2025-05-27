#ifndef IRR_HPP
#define IRR_HPP


#include "currency.hpp"
#include "USD.hpp"
class IRR : public Currency {
    public:
        IRR(double v);
        double to_usd() const override;

         USD operator/(double rate) const;
         USD operator+(const Currency& other) const;
         USD operator-(const Currency& other) const;
         bool operator<(const Currency& other) const;
         bool operator>(const Currency& other) const;

         double get_value() const;

private:
         double value;
};

#endif