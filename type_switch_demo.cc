#include "type_list.hh"
#include "type_switch.hh"

#include <iostream>
#include <typeinfo>

struct Functor
{
  template <class T> void operator()()
  {
    std::cout << "Called with the following type: " << typeid(T).name() << std::endl;
  }
};

int main( int, char** )
{
  typedef TypeList<char, bool> MyTypes;

  Functor f;
  TypeSwitch<MyTypes> ts;

  for( unsigned int i = 0; i < TypeListLength<MyTypes>::value; i++ )
    ts( i, f );

  try
  {
    ts( 42, f );
  }
  catch( std::runtime_error& e )
  {
    std::cerr << "Oops, this type does not exist: " << e.what() << std::endl;
  }

  return 0;
}
