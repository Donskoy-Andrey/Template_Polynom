#pragma once
#include <vector>
#include <complex>


template <typename T>
class Polynom{
    private:
        std::vector<T> _coefficients; // T = Quat <double>

    public:
        Polynom(const std::vector <T> &data);
        Polynom(int len);
        Polynom() = default;

        Polynom<T> operator + (const Polynom<T> &poly);
        Polynom<T> operator - (const Polynom<T> &poly);
        Polynom<T> operator * (const Polynom<T> &poly);

        void print();
        void beautiful_print();
};


template <typename T>
Polynom<T>::Polynom(const std::vector <T> &data){
    for (int i = 0; i < data.size(); ++i){
        _coefficients.push_back(data[i]);
    }
};

template <typename T>
Polynom<T>::Polynom (int len){
    for (int i = 0; i < len; ++i){
        _coefficients.push_back(0);
    }
};
 
template <typename T>
Polynom<T> Polynom<T>::operator + (const Polynom<T> &poly){
    Polynom<T> result_polynom(std::max(_coefficients.size(), poly._coefficients.size()));

    if (_coefficients.size() >= poly._coefficients.size()) {
        for (int i = 0; i < _coefficients.size(); ++i) {
            result_polynom._coefficients[i] = _coefficients[i];
        }
        for (int i = 0; i < poly._coefficients.size(); ++i) {     
            result_polynom._coefficients[i] += poly._coefficients[i];
        }
    } else {
        for (int i = 0; i < poly._coefficients.size(); ++i) {
            result_polynom._coefficients[i] = poly._coefficients[i];
        }
        for (int i = 0; i < _coefficients.size(); ++i) {
            result_polynom._coefficients[i] += _coefficients[i];
        }
    }

    return result_polynom;
};

template <typename T>
Polynom<T> Polynom<T>::operator - (const Polynom<T> &poly){
    Polynom<T> result_polynom(std::max(_coefficients.size(), poly._coefficients.size()));

    for (int i = 0; i < _coefficients.size(); ++i) {
        result_polynom._coefficients[i] = _coefficients[i];
    }
    for (int i = 0; i < poly._coefficients.size(); ++i) {    
        result_polynom._coefficients[i] -= poly._coefficients[i];
    }
    
    return result_polynom;
};

template <typename T>
Polynom<T> Polynom<T>::operator * (const Polynom<T> &poly){
    int result = (_coefficients.size() - 1) + (poly._coefficients.size() - 1) + 1;
    Polynom<T> result_polynom(result);

    for (int i = 0; i < _coefficients.size(); i++)
        for (int j = 0; j < poly._coefficients.size(); j++)
            result_polynom._coefficients[i + j] += _coefficients[i] * poly._coefficients[j];

    return result_polynom;
};


template <typename T>
void Polynom<T>::print(){
    std::cout << "[" << _coefficients[0];
    for (int i = 1; i < _coefficients.size(); ++i){
        std::cout << " " << _coefficients[i];
    }
    std::cout << "]" << std::endl;
};

template <typename T>
void Polynom<T>::beautiful_print(){
    int counter = 0;
    while (_coefficients[counter] == 0){
        ++counter;
    }

    std::cout << _coefficients[counter];
    
    if (counter >= 1){
        std::cout << "*x";
        if (counter > 1){
            std::cout << "^" << counter;
        }
    }

    for (int i = counter+1; i < _coefficients.size(); ++i){
        if (_coefficients[i] > 0){
            std::cout << " + " << _coefficients[i] << "*x";
        } else if (_coefficients[i] < 0) {
            std::cout << " - " << -_coefficients[i] << "*x";
        } else {
            continue;
        }
        if (i > 1){
            std::cout << "^" << i;
        }
    }
    std::cout << std::endl;
};


template<>
void Polynom<std::complex<double>>::beautiful_print(){
    int counter = 0;

    std::cout << "(" << _coefficients[counter].real() << " + " << _coefficients[counter].imag() << "j)";
    
    for (int i = counter+1; i < _coefficients.size(); ++i){
        
        std::cout << " + (" << _coefficients[i].real() << " + " << _coefficients[i].imag() << "j)" << "*x";
        
        if (i > 1){
            std::cout << "^" << i;
        }
    }
    std::cout << std::endl;
};