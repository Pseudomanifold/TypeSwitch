#ifndef TYPE_SWITCH_HH__
#define TYPE_SWITCH_HH__

#include "type_list.hh"

#include <stdexcept>

template <
  typename TypeList,
  unsigned int Index = 0,
  bool Stop = ( Index == TypeListLength<TypeList>::value )
> struct TypeSwitch
{
  template <class Functor> decltype( Functor().template operator()<typename TypeListGet<TypeList, Index>::type>() ) operator()( unsigned int i, Functor f )
  {
    if( i == Index )
      return f.template operator()<typename TypeListGet<TypeList, Index>::type>();
    else
    {
      TypeSwitch<TypeList, Index + 1> next;
      return next.operator()( i, f );
    }
  }
};

/**
  Handles the base case when the type cannot be found. This works because we
  specialize over the value of the "Stop" variable.
*/

template <
  typename TypeList,
  unsigned int Index
> struct TypeSwitch<
  TypeList,
  Index,
  true>
{
  template <class Functor> decltype( Functor().template operator()<EmptyType>() ) operator()( unsigned int /* i */, Functor /* f */ )
  {
    throw std::runtime_error( "Index is out of range" );
  }
};

#endif
