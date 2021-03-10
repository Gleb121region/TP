#include "CompositeShape.hpp"
#include "Errors.hpp"

CompositeShape &CompositeShape::operator=(const CompositeShape &copied_obj)
  {
  size_ = copied_obj.getNumShapes();
  for (size_t i = 0; i < size_; ++i)
  {
    shape_array_[i] = copied_obj.shape_array_[i];
  }
  return *this;
}

std::shared_ptr<Shape> CompositeShape::operator[](const size_t num) const
{
  if (num < size_)
  {
    return shape_array_[num];
  } else{
    throw Array_overflow();
  }
}

void CompositeShape::addShape(std::shared_ptr<Shape> &new_shape)
{
  if (!(new_shape == nullptr))

  {
    if (new_shape.get() != this)

    {
      shape_array_type new_array(new std::shared_ptr<Shape>[size_ + 1]);
      for (size_t i = 0; i < getNumShapes(); ++i)
      {
        new_array[i] = shape_array_[i];
      }
      new_array[size_++] = new_shape;
      shape_array_.swap(new_array);
    } else
      {
        throw  Element_equal_itself();
    }
  } else{
    throw NullPointerException();
  }
}

void CompositeShape::replaceShape(const size_t num)
{
  if (size_ != 0)
  {
    if (num < size_)
    {
      shape_array_[num] = nullptr;
      for (size_t i = num; i < size_ - 1; ++i)
      {
        shape_array_[i] = shape_array_[i + 1];
      }
      shape_array_[--size_] = nullptr;
    } else{
      throw  VariableOutOfRange();
    }
  } else{
    throw NullPointerException();
  }
}

size_t CompositeShape::getNumShapes() const noexcept
{
  return size_;
}

double CompositeShape::getArea() const noexcept
{
  double area = 0;
  for (size_t i = 0; i < size_; ++i)
  {
    area += shape_array_[i]->getArea();
  }
  return area;
}

rectangle_t CompositeShape::getFrameRect() const noexcept
{
  if (size_ != 0)
  {
    rectangle_t shapeFrRect = shape_array_[0]->getFrameRect();
    point_t a =
      {shapeFrRect.pos.x - shapeFrRect.width / 2, shapeFrRect.pos.y + shapeFrRect.height / 2};
    point_t b =
      {shapeFrRect.pos.x + shapeFrRect.width / 2, shapeFrRect.pos.y - shapeFrRect.height / 2};
    for (size_t i = 1; i < size_; ++i)
    {
      shapeFrRect = shape_array_[i]->getFrameRect();
      if (shapeFrRect.pos.x - shapeFrRect.width / 2 < a.x)
      {
        a.x = shapeFrRect.pos.x - shapeFrRect.width / 2;
      }
      if (shapeFrRect.pos.y + shapeFrRect.height / 2 > a.y)
      {
        a.y = shapeFrRect.pos.y + shapeFrRect.height / 2;
      }
      if (shapeFrRect.pos.x + shapeFrRect.width / 2 > b.x)
      {
        b.x = shapeFrRect.pos.x + shapeFrRect.width / 2;
      }
      if (shapeFrRect.pos.y - shapeFrRect.height / 2 < b.y)
      {
        b.y = shapeFrRect.pos.y - shapeFrRect.height / 2;
      }
    }
    return
    {b.x - a.x, a.y - b.y,
     {(a.x + b.x) / 2, (a.x + b.x) / 2}};
  } else{
    return
    {0, 0,
     {0, 0}};
  }
}

void CompositeShape::move(point_t point)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shape_array_[i]->move(point);
  }
}

void CompositeShape::move(const double dx, const double dy) noexcept
{
  for (size_t i = 0; i < size_; ++i)
  {
    shape_array_[i]->move(dx, dy);
  }
}



void CompositeShape::scale(const double coefficient)
{
  if (coefficient <= 0)
  {
    throw VariableBelowZero();
  }
  for (size_t i = 0; i < size_; ++i)
  {
    double x_in_this_foo = shape_array_[i]->getFrameRect().pos.x;
    double y_in_this_foo = shape_array_[i]->getFrameRect().pos.y;
    shape_array_[i]->move(x_in_this_foo,y_in_this_foo);
    shape_array_[i]->scale(coefficient);
  }
}

CompositeShape::CompositeShape(const std::shared_ptr<Shape> &init_shape):
   size_(0),
   shape_array_(new std::shared_ptr<Shape> [1])
{
  if (init_shape.get() != nullptr)
  {
    shape_array_[size_++] = init_shape;
  } else{
    throw NullPointerException();
  }
}

CompositeShape::CompositeShape(const CompositeShape &copied_obj):
   size_(copied_obj.getNumShapes()),
   shape_array_(new std::shared_ptr<Shape> [copied_obj.getNumShapes()])
{
  for (size_t i = 0; i < copied_obj.getNumShapes(); ++i)

  {
    shape_array_[i] = copied_obj.shape_array_[i];
  }
}

void CompositeShape::printParams() const noexcept {
  rectangle_t outFrRect = getFrameRect();
  std::cout << "The amount of shapes is " << size_ << "\n"
            << "Area of Composite shape is " << getArea() << ".\n"
            << "Frame rectangle centre position is point (" << outFrRect.pos.x << ";" << outFrRect.pos.y << ").\n"
            << "Its width is " << outFrRect.width << " and height is " << outFrRect.height << ".\n\n";
  for (size_t i = 0; i < size_; ++i)
  {
    shape_array_[i]->getName();
  }
}

std::string CompositeShape::getName() const
{
  std::string string="";
  for (size_t i = 0; i < size_; ++i)
  {
   string += shape_array_[i]->getName();
  }
  return  string;
}



