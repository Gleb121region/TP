#include <cassert>
#include <stdexcept>
#include "circle.hpp"

#define PI 3.1415926535

Circle::Circle(double radius, point_t pos):
  radius_(radius),
  pos_(pos)
{
  assert(radius_ > 0);
}


double Circle::getArea() const
{
  return PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t {radius_ * 2,radius_ * 2,pos_};
}

void Circle::move( point_t point)
{
  pos_ = point;
}

void Circle::move( double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

std::string Circle::getName() const
{
  return "Circle\n";
}

void Circle::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument ("Invalid scaling coefficient");
  }
  radius_ *= coefficient;
}
