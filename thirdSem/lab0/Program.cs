using System;

namespace lab0
{
    abstract class Shape
    {
        private double perimeter;
        private double area;

        public double p
        {
            set { perimeter = value; }
            get { return perimeter; }
        }
        public double s
        {
            set { area = value; }
            get { return area; }
        }

        public void printSpecifications(string shapeName)
        {
            Console.WriteLine($"{shapeName}\nПериметр = {this.p}\nПлощадь = {this.s}\n------------------\n");
        }
    }

    class Rectangle : Shape
    {
        private double length;
        private double width;

        public double a
        {
            set { length = value; }
            get { return length; }
        }
        public double b
        {
            set { width = value; }
            get { return width; }
        }

        public void calculatePerimeter()
        {
            this.p = 2 * (length + width);
        }

        public void calculateArea()
        {
            this.s = length * width;
        }
    }

    class Triangle : Shape
    {
        private double first;
        private double second;
        private double third;

        public double a
        {
            set { first = value; }
            get { return first; }
        }
        public double b
        {
            set { second = value; }
            get { return second; }
        }
        public double c
        {
            set { third = value; }
            get { return third; }
        }

        public void calculatePerimeter()
        {
            this.p = first + second + third;
        }

        public void calculateArea()
        {
            double pp = (a + b + c) / 2;
            this.s = Math.Sqrt(pp * (pp - first) * (pp - second) * (pp - third));
        }
    }

    class Circle : Shape
    {
        private double radius;

        public double r
        {
            set { radius = value; }
            get { return radius; }
        }

        public void calculatePerimeter()
        {
            p = 2 * Math.PI * radius;
        }

        public void calculateArea()
        {
            s = Math.PI * Math.Pow(radius, 2);
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            var rectangle = new Rectangle();
            rectangle.a = 13;
            rectangle.b = 29;

            rectangle.calculatePerimeter();
            rectangle.calculateArea();

            rectangle.printSpecifications("Прямоугольник 1");

            var triangle = new Triangle();
            triangle.a = 3;
            triangle.b = 4;
            triangle.c = 5;

            rectangle.calculatePerimeter();
            triangle.calculateArea();
            triangle.printSpecifications("Треугольник 1");

            var circle = new Circle();
            circle.r = 1 / Math.Sqrt(Math.PI);

            circle.calculatePerimeter();
            circle.calculateArea();
            circle.printSpecifications("Круг 1");
        }
    }
}