#ifndef TYPE_LIST_HH__
#define TYPE_LIST_HH__

#include <type_traits>

struct EmptyType
{
};

template <
    typename T0 = EmptyType,
    typename T1 = EmptyType,
    typename T2 = EmptyType,
    typename T3 = EmptyType,
    typename T4 = EmptyType,
    typename T5 = EmptyType,
    typename T6 = EmptyType,
    typename T7 = EmptyType,
    typename T8 = EmptyType,
    typename T9 = EmptyType
> struct TypeList;

/**
  Recursive case: A full type list has a head and a tail, consisting of the
  remaining types. The length of the type list is recursively defined via an
  enum.
*/

template <
    typename T0,
    typename T1,
    typename T2,
    typename T3,
    typename T4,
    typename T5,
    typename T6,
    typename T7,
    typename T8,
    typename T9
> struct TypeList
{
  typedef T0 head;
  typedef TypeList<T1,T2,T3,T4,T5,T6,T7,T8,T9> tail;

  enum
  {
    length = tail::length + 1
  };
};

/**
  Base case: An empty type list. This is the fully-specialized template, so we
  can finally initialize the enum correctly. Head and tail are not required
  here because we do not want to recursive ad infinitum.
*/

template <> struct TypeList<
    EmptyType,
    EmptyType,
    EmptyType,
    EmptyType,
    EmptyType,
    EmptyType,
    EmptyType,
    EmptyType,
    EmptyType,
    EmptyType>
{
  enum
  {
    length = 0
  };
};

template <typename TypeList> struct TypeListLength
{
  enum
  {
    value = TypeList::length
  };
};

template <
  typename TypeList,
  unsigned int Index,
  unsigned int Step = 0,
  bool Stop = ( Index == Step ),
  bool OutOfRange = ( TypeListLength<TypeList>::value == 0 )
> struct TypeListGet
{
  /**
    Recurse into the type list by "evaluating" the tail argument. Step is
    increased but the remaining two attributes are set automatically.
  */

  typedef typename TypeListGet<typename TypeList::tail, Index, Step + 1>::type type;
};

/**
  Handles the base case for out-of-range errors. Whenever we have reached an _empty_ type list, we cannot recursive any more. We also must not defined a "type" here because we want to cause a compiler error.
*/

template <
  typename TypeList,
  unsigned int Index,
  unsigned int Step,
  bool Stop
> struct TypeListGet<
  TypeList,
  Index,
  Step,
  Stop,
  true>
{
};

/**
  Specialization for handling found elements. Here, we want the "Stop"
  attribute to be true, indicating that "Index" and "Step" coincide.
*/

template <
  typename TypeList,
  unsigned int Index,
  unsigned int Step,
  bool OutOfRange
> struct TypeListGet<
  TypeList,
  Index,
  Step,
  true,
  OutOfRange>
{
  // The desired type is the head of the list. This checks out because we
  // always remove a type from the list when we recurse.
  typedef typename TypeList::head type;
};

#endif
