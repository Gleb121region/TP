#include <cassert>
#include <stdexcept>
#include "diamond.hpp"

Diamond::Diamond(double side, double side2, point_t point):
  side_(side),
  side2_(side2),
  point_(point)
{
  assert(side_ > 0);
  assert(side2_ > 0);
}

double Diamond::getArea() const
{
  return (side_ * side2_) / 2;
}

rectangle_t Diamond::getFrameRect() const
{
  return rectangle_t{side_, side2_, point_};
}

void Diamond::move(double dx, double dy)
{
  point_.x += dx;
  point_.y += dy;
}

void Diamond::move( point_t point)
{
  point_ = point;
}

std::string Diamond::getName() const
{
  return "Diamond\n";
}

void Diamond::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument ("Invalid scaling coefficient");
  }
  side_ *= coefficient;
  side2_ *= coefficient;
}
