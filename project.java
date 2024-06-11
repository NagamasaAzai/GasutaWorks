//Создание абстрактного класса
abstract class TwoDShape {
	private double width;
	private double height;
	private double depth;
	private String name;

	//Конструктор по умолчанию
	TwoDShape() {
		width = height = depth = 0.0;
		name = "none";
	}

	//Параметризированный конструктор
	TwoDShape(double w, double h, double d, String n) {
		width = w;
		depth = d;
		height = h;
		name = n;

	}

	//Создание обьекта с одинаковыми значениями
	TwoDShape(double x, String n) {
		width = height = depth = x;
		name = n;
	}

	//Создание одного обьекта на основе другого
	TwoDShape(TwoDShape ob) {
		width = ob.width;
		depth = ob.depth;
		height = ob.height;
		name = ob.name;
	}

	//Методы доступа к переменным width и height
	double getWidth() { return width; };
	double getHeight() { return height; };
	double getDepth() { return depth; };
	void setWidth(double w) { width = w; };
	void setDepth(double d) { depth = d; };
	void setHeight(double h) {height = h; };

	String getName() { return name; };

	void showDim() {
		System.out.println("Ширина и высота и глубина - " + width + " и " + height + "и" + depth);
	}

	//Теперь метод area() абстрактный
	abstract double area();
}

//Подкласс для представления треугольников, произвольный от класса TwoDShape
/*class Triangle extends TwoDShape {
	private String style;

	//Конструктор по умолчанию
	Triangle() {
		super();
		style = "none";
	}

	//Констуктор класса Triangle
	Triangle(double w, double h, String s) {
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
*/


	//Подкласс для представления прямоугольников, производный от класса TwoDShape
class Rectangle extends TwoDShape {
	//Конструктор по умолчанию00
	Rectangle() {
		super();
	}

	//Конструктор класса Rectangle
	Rectangle(double w, double h, double d) {
		super(w, h, d, "Куб"); //вызвать конструктор класса TwoDShape
	}

	//Создание куба
	Rectangle(double z) { 
		super(z, "Куб"); //вызвать конструктор суперкласса
	}

	//Создание одного обьекта на основе другого
	Rectangle(Rectangle ob) {
		super(ob); // Передача обьекта конструктору класса TwoDShape
	}

	boolean isCube() {
		if((getWidth() == getHeight()) & (getDepth()==getHeight())) return true;
		return false;
	}

	double area() {
		return getWidth() * getHeight() * getDepth();
	}	
}

class AbsShape {
	public static void main(String args[]) {
		TwoDShape shapes[] = new TwoDShape[2];

	//	shapes[0] = new Triangle("контурный", 8.0, 12.0);
		shapes[0] = new Rectangle(10.0);
		shapes[1] = new Rectangle(10.0, 4.0, 5.0);
	//	shapes[3] = new Triangle(7.0);

		for(int i=0; i < shapes.length; i++) {
			System.out.println("Обьект - " + shapes[i].getName());
			System.out.println("Площадь - " + shapes[i].area());
			System.out.println();
		}
	}
}
