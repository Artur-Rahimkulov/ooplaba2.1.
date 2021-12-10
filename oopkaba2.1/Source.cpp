#include <iostream>;
#include <sstream>;
#include <ctime>
#include <clocale>
#include <locale.h>

using namespace std;

class Rectangle {
protected:
	int height;
	int width;
public:
	Rectangle() {
		printf("Rectangle()\n");
		height = 0;
		width = 0;
	}
	Rectangle(int height, int width) {
		printf("Rectangle(int height, int width)\n");
		this->height = height;
		this->width = width;
	}
	Rectangle(const Rectangle& rect) {
		printf("Rectangle(const Rectangle &rect)\n");
		height = rect.height;
		width = rect.width;
	}
	~Rectangle() {
		printf("%d, %d\n", height, width);
		printf("~Rectangle()\n");
	}
	void setHeight(int height) {
		printf("void setHeight(int height)\n");
		this->height = height;
	}
	void setWidth(int width) {
		printf("void setHeight(int width)\n");
		this->width = width;
	}
	int getHeight() {
		printf("int getHeight()\n");
		return height;
	}
	int getWidth() {
		printf("int getWidth()\n");
		return width;
	}
	int getS() {
		printf("getS() = %d\n", height * width);
		return height * width;
	}
};
class Cuboid : public Rectangle {
private:
	int length;
public:
	Cuboid() : Rectangle() {
		printf("Cuboid()\n");
		length = 0;
	}
	Cuboid(int height, int width, int length) : Rectangle(height, width) {
		printf("Cuboid(int height, int width, int length)\n");
		this->length = length;
	}
	Cuboid(const Cuboid& cuboid) {
		printf("Cuboid(const Cuboid &cuboid)\n");
		height = cuboid.height;
		width = cuboid.width;
		length = cuboid.length;
	}
	void setLength(int length) {
		printf("void setLength(int length)\n");
		this->length = length;
	}
	int getLength() {
		printf("int getLength()\n");
		return length;
	}
	~Cuboid() {
		printf("%d, %d, %d\n", height, width, length);
		printf("~Cuboid()\n");
	}
	int getV();


};
int Cuboid::getV() {
	printf("getV() = %d\n", height * width * length);
	return height * width * length;
} 
class RectangleINRectangle { 
protected:
	 
	Rectangle* inner;
	Rectangle* outer;
public: 
	RectangleINRectangle(const RectangleINRectangle& rir1) {
		printf("RectangleINRectangle(const RectangleINRectangle& rir1)\n"); 
		this->inner = rir1.inner; 
		this->outer = rir1.outer;
	};
	RectangleINRectangle(int h1, int w1, int h2, int w2) { 
		printf("RectangleINRectangle(int h1, int w1, int h2, int w2)\n");
		this->inner = new Rectangle(h1, w1); 
		this->outer = new Rectangle(h2, w2);

	};
	RectangleINRectangle() { 
		printf("RectangleINRectangle()\n");
		this->inner = new Rectangle(); 
		this->outer = new Rectangle();
		 
	};
	~RectangleINRectangle() {
		//delete inner;
		//delete outer;
		 
		printf("~RectangleINRectangle\n");
	}
	Rectangle getInner() { 
		printf("Rectangle getInner()\n");
		return *inner;
	} 
	Rectangle getOuter() {
		printf("Rectangle getOuter()\n");
		return *outer;
	}
	void setInner(const Rectangle& r1) {
		printf("void setInner(const Rectangle& r1)\n"); 
		(*this->inner) = r1;
	}
	void setOuter(const Rectangle& r1) {
		printf("void setOuter(const Rectangle& r1)\n"); 
		(*this->outer) = r1;
	}

};
int main()
{
	setlocale(LC_ALL, "rus");
	while (true) {
		int menu;
		printf(
			"\nМеню:\n"
			"\n1 статически создать" 
			"\n2 динамически создать" 
			"\n3 создание наследуемых обьектов" 
			"\n4 создание обьектов в различных переменных" 
			"\n5 создание и удаление композиции обьектов\n" 
		);
		scanf_s("%d", &menu);
		switch (menu)
		{
		case 1:
		{
			printf("статическое создание\n");
			Rectangle r1;
			Rectangle r2(3, 4);
			Rectangle r3(r2);
			r1.setHeight(5);
			r1.setWidth(5);
			r1.getS();
			r2.getS();
			printf_s("width r3 = %d\n", r3.getWidth());
		}
		getchar();
		break;
		case 2:
		{
			printf("динамическое создание\n");
			Rectangle* r1 = new Rectangle();
			Rectangle* r2 = new Rectangle(3, 4);
			Rectangle* r3 = new Rectangle(*r2);
			(*r1).setHeight(5);
			(*r1).setWidth(5);
			r1->getS();
			r2->getS();
			printf_s("width r3 = %d\n", r3->getWidth());
			delete r1;
			delete r2;
			delete r3;
		}
		getchar();
		break;

		case 3:
		{
			printf("создание наследуемых объектов\n");

			Cuboid c1;
			Cuboid c2(1, 2, 3);
			Cuboid c3(c2);
			getchar();
			break;
		}
		case 4:
		{
			printf("создание обьектов в различных переменных\n");

			Rectangle* r1 = new Cuboid(3, 4, 5);
			//int i = (*r1).getHeight();
			//i = (*r1).getS();
			//i = (*r1).getWidth();
			//(*r1).setHeight(5);
			//(*r1).setWidth(5);
			delete r1;
			Cuboid *c2 = new Cuboid(1, 2, 3);
			//i = (*c2).getHeight();
			//i = (*c2).getLength();
			//i = (*c2).getS();
			//i = (*c2).getV();
			//i = (*c2).getWidth();
			//(*c2).setHeight(5);
			//(*c2).setLength(5);
			//(*c2).setWidth(5);
			delete c2;
		}
		break;

		case 5:
		{
			printf("создание и удаление композиции обьектов\n");

			RectangleINRectangle rir1;
			RectangleINRectangle rir2(1, 2, 3, 4);
			RectangleINRectangle rir3(rir2);

		}
		break;
		default:
			break;
		}
	}
}