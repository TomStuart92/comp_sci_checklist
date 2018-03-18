/*
Rule 23. Prefer Class Hierachies to tagged classes

Advantages: 
    - Decrease memory footprint and class size.
    - Fields can be final. 
    - Correct compile time errors.
*/


public class ClassHierachies {
  // don't use a tagged class:
  static class TaggedFigure {
    enum Shape { RECTANGLE, CIRCLE };
    final Shape shape;
    double length;
    double width;
    double radius;

    TaggedFigure(double radius) {
      this.shape = Shape.CIRCLE;
      this.radius = radius;
    }

    TaggedFigure(double length, double width) {
      this.shape = Shape.RECTANGLE;
      this.length = length;
      this.width = width;
    }

    double area() {
      switch(this.shape) {
        case RECTANGLE: 
          return length * width;
        case CIRCLE:
          return Math.PI * (radius * radius);
        default:
        throw new AssertionError(shape);
      }
    }
  }

  // instead define abstract classes for common behaviour:
  abstract class Figure() {
    abstract double area();
  }

  // then create specific implementations.
  class Circle extends Figure {
    final double radius;
    Circle(double radius) {
      this.radius = radius;
    }
    @Override
    double area() {
      return Math.PI * (this.radius * this.radius);
    }
  }

  class Rectangle extends Figure {
    final double length;
    final double width;

    Rectangle(double length, double width) {
      this.length = length;
      this.width = width;
    }
    @Override
    double area() {
      return this.length * this.width;
    }
  }

}