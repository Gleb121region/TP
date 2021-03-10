#include <memory>
#include "shape.hpp"

typedef std::unique_ptr<std::shared_ptr<Shape>[]> shape_array_type;

class CompositeShape: public Shape
{
public:
  CompositeShape (const std::shared_ptr<Shape> &init_shape);
  CompositeShape(const CompositeShape &copied_obj);
  ~CompositeShape() =default;
  CompositeShape &operator =(const CompositeShape &copied_obj);
  std::shared_ptr<Shape> operator[](const size_t num) const;
  void addShape (std::shared_ptr<Shape> &new_shape);
  void replaceShape (const size_t num);
  size_t getNumShapes() const noexcept;
  double getArea() const noexcept override;
  rectangle_t getFrameRect() const noexcept override;
  void move(point_t point) override;
  void move (const double dx, const double dy) noexcept override;
  std::string getName() const override;
  void scale(const double coefficient) override;
  void printParams() const noexcept;
private:
  size_t size_;
  shape_array_type shape_array_;
};
