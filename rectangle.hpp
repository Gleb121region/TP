#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(double width,double height, point_t point);
  ~Rectangle() = default;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move( point_t  point) override;
  void move( double dx, double dy) override;
  std::string getName() const override;
  void scale(const double coefficient) override;
private:
  double width_,height_;
  point_t point_;
};
