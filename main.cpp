#include <iostream>
#include <memory>
#include "rectangle.hpp"
#include "circle.hpp"
#include "diamond.hpp"
#include "CompositeShape.hpp"

void print_type_and_area(Shape *shape)
{
  std::cout<<"Info about\t"+shape->getName()<<'\t';
  std::cout<<"S:"<< shape->getArea()<<'\n';
}

double getFramePosX(const Shape*  shape)
{
  return shape->getFrameRect().pos.x;
}

double getFramePosY(const Shape*  shape)
{
  return shape->getFrameRect().pos.y;
}

void  give_information(Shape * shape)
{
  std::cout <<  "Height:\t" << shape->getFrameRect().height << '\n' <<
            "Width:\t" << shape->getFrameRect().width << '\n' <<
            "Position:\t{" << getFramePosX(shape) << "," << getFramePosY(shape) << '}'<<'\n';

  std::cout << "Center of shape's frame rectangle is {" << getFramePosX(shape) <<
            "," << getFramePosY(shape) <<'}'<< '\n';
}

void moving(Shape* shape,  point_t point)
{
  shape->move(point);
  rectangle_t frameRectValue1 = shape->getFrameRect();
  std::cout << "New position(to point) x,y" << ": " <<
            frameRectValue1.pos.x << ", " << frameRectValue1.pos.y << '\n';

  shape->move(point.x, point.y);
  rectangle_t frameRectValue2 = shape->getFrameRect();
  std::cout << "New position x,y(to axes)" << ": " <<
            frameRectValue2.pos.x << ", " << frameRectValue2.pos.y << '\n';
}


void testShape(Shape* shape)
{
  point_t position = {10.2, 7.3};
  print_type_and_area(shape);
  give_information(shape);
  moving(shape,position);
}

int A1()
{
  Shape* shape1 = new Circle(5.01, {1,3});
  Shape* shape2 = new Rectangle(7.0, 4.238, {-5.0, 2.0});
  Shape* shape3 = new Diamond(11,21,{29,-88});

  Shape* arr[] = {shape1, shape2, shape3};

  const int count = 3;

  for (size_t i = 0; i < count; i++)
  {
    testShape(arr[i]);
    delete arr[i];
  }
  return 0;
}

int mian(){
  A1();

  std::shared_ptr<Shape> shape_1 = std::make_shared<Rectangle>(Rectangle(8.4, 8.7, {2.75, -8.5}));
  std::shared_ptr<Shape> shape_2 = std::make_shared<Circle>(Circle(1.8, {1.8, 9}));

  CompositeShape compS (shape_1);
  compS.addShape(shape_2);
  compS.printParams();

  compS.replaceShape(1);
  compS.printParams();

  compS.move({5,-5});
  compS.printParams();

  CompositeShape compS2 = compS;
  compS2.printParams();

  compS2.scale(3);
  compS2.printParams();

  compS2[0]->move(9,-2);
  compS2.printParams();

  return 0;
}
