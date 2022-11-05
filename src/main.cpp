#include <string>
#include <iostream>
#include <vector>
#include <complex>
#include "polynom.hpp"
#include "quat.hpp"


int main(){
    std::vector<double> vc1 {1., 2., 3., 4.};
    std::vector<double> vc2 {2., 5., 6.};
    std::vector<std::complex<double>> vc3 {{1., 2.}, {3., 4.}, {5., 6.}}; 
    std::vector<std::complex<double>> vc4 {{2., 4.}, {6., 8.}, {10., 12.}, {-10., 14.}};

    Polynom Polynom_1(vc1);
    Polynom Polynom_2(vc2);
    Polynom Polynom_3(vc3);
    Polynom Polynom_4(vc4);

    std::cout << "Simple polynoms:" << std::endl;
    (Polynom_1 + Polynom_2).beautiful_print();
    (Polynom_1 - Polynom_2).beautiful_print();
    (Polynom_1 * Polynom_2).beautiful_print();

    std::cout << std::endl << "Complex polynoms:" << std::endl;
    (Polynom_3 + Polynom_4).beautiful_print();
    (Polynom_3 - Polynom_4).beautiful_print();
    (Polynom_3 * Polynom_4).beautiful_print();

    std::vector <Quat <double>> vq1 {{1., 2., 3., 4.}, {5., 6., 7., 8.}};
    std::vector <Quat <double>> vq2 {{2., 4., 6., 8.}, {10., 12., 14., 16.}};

    Polynom Quat_1(vq1);
    Polynom Quat_2(vq2);

    std::cout << std::endl << "Quaternion polynoms:" << std::endl;
    Quat_1 + Quat_2;
    // (Quat_1 - Quat_2).beautiful_print();
    // (Quat_1 * Quat_2).beautiful_print();
    return 0;
}