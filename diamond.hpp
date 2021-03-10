#include "shape.hpp"

class Diamond: public Shape
{
public:
  Diamond(double side, double side2, point_t point);
  ~Diamond() override = default;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move( point_t point) override;
  std::string getName() const override;
  void scale(const double coefficient) override;

private:
  double side_, side2_;
  point_t point_;
};

