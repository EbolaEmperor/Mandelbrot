#include "GMP_Wrapper.h"

void GMPWrapperInitialize(){
    mpf_set_default_prec(PRCS);
}

template<>
int Complex<GMPFloat>::cmpNorm(double rhs) const{
    return abs2().cmp(rhs * rhs);
}

template<>
int Complex<__float128>::cmpNorm(double rhs) const{
    return abs2() > rhs * rhs;
}

template class Complex<GMPFloat>;
template class Complex<__float128>;