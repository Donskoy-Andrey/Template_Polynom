#pragma once
#include <string>
#include <vector>
#include <complex>
#include "polynom.hpp"


template <typename T>
class Quat{
    private:
        T _s = 0;
        T _i = 0;
        T _j = 0;
        T _k = 0;

    public:
        Quat(T s, T i, T j, T k);
        Quat() = default;

        Quat<T> operator + (const Quat<T> &quat);
        Quat<T> operator - (const Quat<T> &quat);
        Quat<T> operator * (const Quat<T> &quat);

        bool operator == (const Quat<T> &quat);
        bool operator != (const Quat<T> &quat);
        Quat<T> operator += (const Quat<T> &quat);
        Quat<T> operator * (T num);

        void print();
        void beautiful_print();
};


template <typename T>
Quat<T>::Quat(T s, T i, T j, T k){
    _s = s;
    _i = i;
    _j = j;
    _k = k;
}

template <typename T>
Quat<T> Quat<T>::operator + (const Quat<T> &quat){
    return Quat<T>(_s + quat._s, _i + quat._i, _j + quat._j, _k + quat._k);
};

template <typename T>
Quat<T> Quat<T>::operator - (const Quat<T> &quat){
    return Quat<T>(_s - quat._s, _i - quat._i, _j - quat._j, _k - quat._k);
};

template <typename T>
Quat<T> Quat<T>::operator * (const Quat<T> &quat){
    return Quat<T>(
        _s * quat._s - _i * quat._i - _j * quat._j - _k * quat._k, 
        _s * quat._i + _i * quat._s + _j * quat._k - _k * quat._j,
        _s * quat._j - _i * quat._k + _j * quat._s + _k * quat._i,
        _s * quat._k + _i * quat._j - _j * quat._i + _k * quat._s 
    );
};


template<typename T>
bool Quat<T>::operator == (const Quat<T> &quat){
    return ((_s == quat._s) and (_i == quat._i) and (_j == quat._j) and (_k == quat._k));
}

template<typename T>
bool Quat<T>::operator != (const Quat<T> &quat){
    return ((_s != quat._s) or (_i != quat._i) or (_j != quat._j) or (_k != quat._k));
}

template<typename T>
Quat<T> Quat<T>::operator += (const Quat<T> &quat){
    _s = _s + quat._s;
    _i = _i + quat._i;
    _j = _j + quat._j;
    _k = _k + quat._k;
    return *this;
}

template<typename T>
Quat<T> Quat<T>::operator * (T num){
    return Quat<T>(_s * num, _i * num, _j * num, _k * num);
}
