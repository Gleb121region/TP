#include <cassert>
#include <stdexcept>
#include "rectangle.hpp"

Rectangle::Rectangle(double width, double height, point_t point):
  width_(width),
  height_(height),
  point_(point)
{
  assert(width_ > 0 && height_ > 0);
}


double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t{width_,height_,point_};
}

void Rectangle::move(point_t  point)
{
  point_ = point;
}

void Rectangle::move(double dx, double dy)
{
  point_.x += dx;
  point_.y += dy;
}

std::string Rectangle::getName() const
{
  return "Rectangle\n";
}

void Rectangle::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument ("Invalid scaling coefficient");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}

