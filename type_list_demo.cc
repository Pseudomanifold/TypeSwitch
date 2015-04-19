#include "type_list.hh"

#include <iostream>
#include <typeinfo>

int main( int, char** )
{
  typedef TypeList<char, short, int, long> IntegerTypeList;

  std::cout << "The type list has a length of " << TypeListLength<IntegerTypeList>::value << std::endl
            << "The first type is " << typeid( TypeListGet<IntegerTypeList, 0>::type ).name() << std::endl
            << "The second type is " << typeid( TypeListGet<IntegerTypeList, 1>::type ).name() << std::endl
            << "The third type is " << typeid( TypeListGet<IntegerTypeList, 2>::type ).name() << std::endl
            << "The fourth type is " << typeid( TypeListGet<IntegerTypeList, 3>::type ).name() << std::endl;

  return 0;
}
