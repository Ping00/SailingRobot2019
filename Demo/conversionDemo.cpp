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
    int bearing = 0;

    int offset_bearing = offset + bearing;
    VEC2 pos_vec = CU.degrees_to_vector(offset_bearing);

    int destination_bearing = 155;
    VEC2 destination_vec = CU.degrees_to_vector(destination_bearing);

    std::cout << "X: " << pos_vec.x << std::endl;
    std::cout << "Y: " << pos_vec.y << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "X: " << destination_vec.x << std::endl;
    std::cout << "Y: " << destination_vec.y << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "DIFFERENCE" << std::endl;
    


    return 0;
}
