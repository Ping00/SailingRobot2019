#include <iostream>
#include "../Modules/Calculation_Unit/calculation_unit.hpp"
int main(int argc, char* argv[])
{

    Calculation_Unit CU;

    double test = 90;
    std::cout << "Test Default (D): " << test << std::endl;


    test = CU.degrees_to_radians(test);
    std::cout << "Test (R):" << test << std::endl;

    test = CU.radians_to_degrees(test);
    std::cout << "Test (D): " << test << std::endl;
    //------

    VEC2 vector;

    std::cout << "VECTOR X : " << vector.x << std::endl;
    std::cout << "VECTOR Y : " << vector.y << std::endl;

    double result = CU.convert_coordinates(-1,1,2000,4000,1);

    //BEARING OFFSET
    int offset = 90;

    int bearing = 0 + offset;

    


    return 0;
}
