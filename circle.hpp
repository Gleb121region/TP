#include "shape.hpp"

class Circle: public Shape {
public:
  Circle(double radius, point_t pos);
  ~Circle() = default;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move( point_t point) override;
  void move( double dx, double dy) override;
  std::string getName() const override;
  void scale(const double coefficient) override;
private:
  double radius_;
  point_t pos_;
};


