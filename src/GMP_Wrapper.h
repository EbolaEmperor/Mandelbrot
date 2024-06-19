#ifndef _FLOAT_H_
#define _FLOAT_H_

#include <iostream>
#include <string>
#include <gmp.h>
#define PRCS 128

class GMPFloat{
private:
    mpf_t data;
public:
    GMPFloat(){
        mpf_init2(data, PRCS);
    }
    GMPFloat(const GMPFloat& rhs): GMPFloat(){
        mpf_set(data, rhs.data);
    }
    GMPFloat(const long int rhs): GMPFloat(){
        mpf_set_si(data, rhs);
    }
    GMPFloat(const double rhs): GMPFloat(){
        mpf_set_d(data, rhs);
    }
    GMPFloat(std::string str): GMPFloat(){
        mpf_set_str(data, str.c_str(), 10);
    }
    ~GMPFloat(){
        mpf_clear(data);
    }
    GMPFloat& operator = (const GMPFloat& rhs){
        mpf_set(data, rhs.data);
        return *this;
    }

#define GMPFloatBinaryOp(Op,mpfFun)                  \
    GMPFloat operator Op (const GMPFloat &rhs) const{ \
        GMPFloat res;                                \
        mpfFun(res.data, data, rhs.data);           \
        return res;                                 \
    }
    GMPFloatBinaryOp(+, mpf_add)
    GMPFloatBinaryOp(-, mpf_sub)
    GMPFloatBinaryOp(*, mpf_mul)
    GMPFloatBinaryOp(/, mpf_div)
#undef GMPFloatBinaryOp

    GMPFloat operator * (long int rhs) const{
        GMPFloat res;
        mpf_mul_ui(res.data, data, rhs);
        return res;
    }

#define GMPFloatBinaryOpAss(Op,mpfFun)              \
    GMPFloat& operator Op (const GMPFloat &rhs) {    \
        mpfFun(data, data, rhs.data);              \
        return *this;                              \
    }
    GMPFloatBinaryOpAss(+=, mpf_add)
    GMPFloatBinaryOpAss(-=, mpf_sub)
    GMPFloatBinaryOpAss(*=, mpf_mul)
    GMPFloatBinaryOpAss(/=, mpf_div)
#undef GMPFloatBinaryOpAss

    friend std::ostream& operator << (std::ostream& out, const GMPFloat &rhs){
        static char tmps[PRCS + 10];
        gmp_sprintf(tmps, "%.Ff", rhs.data);
        out << tmps;
        return out;
    }

    friend GMPFloat sqrt(const GMPFloat &rhs){
        GMPFloat res;
        mpf_sqrt(res.data, rhs.data);
        return res;
    }

    friend long int to_int(const GMPFloat &rhs){
        return mpf_get_si(rhs.data);
    }

    int cmp(double rhs) const{
        return mpf_cmp_d(data, rhs);
    }
};

static void GMPWrapperInitialize(void)__attribute__((constructor));

template<typename Float>
class Complex{
private:
    Float _real, _image;
public:
    const Float& real() const{return _real;}
    const Float& image() const{return _image;}
    Complex() {}
    Complex(const Float& r): _real(r) {}
    Complex(const Float& r, const Float& i): _real(r), _image(i) {}
    Complex(const Complex<Float>& rhs): _real(rhs.real()), _image(rhs.image()) {}
    Complex<Float>& operator = (const Complex<Float> &rhs){
        _real = rhs.real();
        _image = rhs.image();
        return *this;
    }

#define ComplexBinaryOp(Op)                              \
    Complex<Float> operator Op (const Complex<Float> &rhs) const{      \
        Complex res;                                     \
        res._real = _real Op rhs._real;                  \
        res._image = _image Op rhs._image;               \
        return res;                                      \
    }                                                   
    ComplexBinaryOp(+)
    ComplexBinaryOp(-)
#undef ComplexBinaryOp

#define ComplexBinaryAssOp(Op)                           \
    Complex<Float>& operator Op (const Complex<Float> &rhs){    \
        _real Op rhs._real;                              \
        _image Op rhs._image;                            \
        return *this;                                    \
    }                                                    
    ComplexBinaryAssOp(+=)
    ComplexBinaryAssOp(-=)
#undef ComplexBinaryAssOp

    Complex<Float> operator * (const Complex<Float> &rhs) const{
        return Complex(_real * rhs._real - _image * rhs._image,
                       _real * rhs._image + _image * rhs._real);
    }

    Complex<Float> operator / (const Float &rhs) const{
        return Complex(_real / rhs, _image / rhs);
    }

    Complex<Float> operator / (const Complex<Float> &rhs) const{
        return Complex(_real * rhs._real + _image * rhs._image,
                       _image * rhs._real - _real * rhs._image) / rhs.abs2();
    }

    Float abs2() const{
        Float res;
        res = _real * _real + _image * _image;
        return res;
    }
    int cmpNorm(double rhs) const;
};

inline long int to_int(const __float128 &rhs){
    return (long int)rhs;
}

typedef __float128 MPFloat;
typedef Complex<MPFloat> MPComplex;

#endif