This repository contains an example implementation of a simple type list
and a simple type switch class, using only C++11. I have provided a
longer explanation [in a blog
post](http://bastian.rieck.ru/blog/posts/2015/type_lists_and_switches).

# Building it

    $ mkdir build
    $ cd build
    $ cmake ../
    $ make

# Examples

    $ ./type_list_demo
    The type list has a length of 4
    The first type is c
    The second type is s
    The third type is i
    The fourth type is l

    $ ./type_switch_demo
    Called with the following type: c
    Called with the following type: b
    Oops, this type does not exist: Index is out of range

Nothing too spectacular.
