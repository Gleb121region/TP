#ifndef FAKE_ERRORS_HPP
#define FAKE_ERRORS_HPP

#include <exception>
#include <iostream>

class NullPointerException: std::exception
{
public:
  NullPointerException()
  {
    std::cerr << __LINE__ << ": " << "NullPointerException" << '\n';
  }
};

class VariableBelowZero: std::exception
{
public:
  VariableBelowZero()
  {
    std::cerr << __LINE__ << ": " << "VariableBelowZero" << '\n';
  }
};

class VariableOutOfRange: std::exception
{
public:
  VariableOutOfRange()
  {
    std::cerr << __LINE__ << ": " << "VariableOutOfRange" << '\n';
  }
};

class Array_overflow: std::exception
{
public:
  Array_overflow()
  {
    std::cerr << __LINE__ << ": " << "Array overflow" << '\n';
  }
};
class Element_equal_itself: std::exception
{
public:
  Element_equal_itself()
  {
    std::cerr << __LINE__ << ": " << "the element is equal to itself" << '\n';
  }
};

#endif //FAKE_ERRORS_HPP
