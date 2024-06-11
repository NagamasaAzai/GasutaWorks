//Создание абстрактного класса
abstract class TwoDShape {
	private double width;
	private double height;
	private String name;

	//Конструктор по умолчанию
	TwoDShape() {
		width = height = 0.0;
		name = "none";
	}

	//Параметризированный конструктор
	TwoDShape(double w, double h, String n) {
		width = w;
		height = h;
		name = n;

	}

	//Создание обьекта с одинаковыми значениями
	TwoDShape(double x, String n) {
		width = height = x;
		name = n;
	}

	//Создание одного обьекта на основе другого
	TwoDShape(TwoDShape ob) {
		width = ob.width;
		height = ob.height;
		name = ob.name;
	}

	//Методы доступа к переменным width и height
	double getWidth() { return width; };
	double getHeight() { return height; };
	void setWidth(double w) { width = w; };
	void setHeight(double h) {height = h; };

	String getName() { return name; };

	void showDim() {
		System.out.println("Ширина и высота - " + width + " и " + height);
	}

	//Теперь метод area() абстрактный
	abstract double area();
}

//Подкласс для представления треугольников, произвольный от класса TwoDShape
class Triangle extends TwoDShape {
	private String style;

	//Конструктор по умолчанию
	Triangle() {
		super();
		style = "none";
	}

	//Констуктор класса Triangle
	Triangle(String s, double w, double h) {
		super(w, h, "Треугольник");
		style = s;
	}

	//Констуктор с одним аргументом для посторения треугольника
	Triangle(double x) {
		super(x, "Треугольник"); //вызвать конструктор суперкласса
		style = "закрашенный";
	}

	//Создание одного обьекта на основе другого
	Triangle(Triangle ob) {
		super(ob); //передача обьекта конструктору класса TwoDShape
		style = ob.style;
	}

	double area() {
		return getWidth() * getHeight() / 2;
	}

	void showStyle() {
		System.out.println("Треугольник" + style);
	}
}



	//Подкласс для представления прямоугольников, производный от класса TwoDShape
class Rectangle extends TwoDShape {
	//Конструктор по умолчанию
	Rectangle() {
		super();
	}

	//Конструктор класса Rectangle
	Rectangle(double w, double h) {
		super(w, h, "прямоугольник"); //вызвать конструктор класса TwoDShape
	}

	//Создание квадрата
	Rectangle(double x) { 
		super(x, "прямоугольник"); //вызвать конструктор суперкласса
	}

	//Создание одного обьекта на основе другого
	Rectangle(Rectangle ob) {
		super(ob); // Передача обьекта конструктору класса TwoDShape
	}

	boolean isSquare() {
		if(getWidth() == getHeight()) return true;
		return false;
	}

	double area() {
		return getWidth() * getHeight();
	}	
}

class AbsShape {
	public static void main(String args[]) {
		TwoDShape shapes[] = new TwoDShape[4];

		shapes[0] = new Triangle("контурный", 8.0, 12.0);
		shapes[1] = new Rectangle(10);
		shapes[2] = new Rectangle(10, 4);
		shapes[3] = new Triangle(7.0);

		for(int i=0; i < shapes.length; i++) {
			System.out.println("Обьект - " + shapes[i].getName());
			System.out.println("Площадь - " + shapes[i].area());
			System.out.println();
		}
	}
}
