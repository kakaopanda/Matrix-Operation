#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Engine{ // engineNo, engineName을 가진 Engine 클래스.
public:
	int engineNo;
	string engineName;
	void show(string s);
};
void Engine::show(string s){
	cout << s << " engineNo : " << engineNo << endl;
	cout << s << " engineName : " << engineName << endl;
}

class Body{ // bodyNo, bodyName을 가진 Body 클래스.
public:
	int bodyNo;
	string bodyName;
	void show(string s);
};
void Body::show(string s){
	cout << s << " bodyNo : " << bodyNo << endl;
	cout << s << " bodyName : " << bodyName << endl;
}

class Car{
	int *carid;
public:
	Engine x;
	Body y;
	Car(int id);
	~Car();
	Car(const Car& Car);
	void changeID(int id);
	void show(string s) {cout << s << " ID : " << *carid << endl;}
};

Car::~Car(){
	delete carid;
}

Car::Car(int id){
	carid = new int[1];
	*carid = id;

	x.engineNo = 0;
	x.engineName = "EngineTestFirst";
	y.bodyNo = 0;
	y.bodyName = "BodyTestFirst";
}

Car::Car(const Car& car){
	carid = new int[1];
	carid = car.carid;
	this->x.engineNo = car.x.engineNo;
	this->x.engineName = car.x.engineName;
	this->y.bodyNo = car.y.bodyNo;
	this->y.bodyName = car.y.bodyName;
	cout << "복사 생성자 실행. 원본 객체의 ID <" << *carid << ">" << endl;
}

void Car::changeID(int id){
	*carid = id;
}

int main(){
	cout << "< 원본 객체 생성 >" << endl;
	Car first(1);
	first.show("<원본>");
	first.x.show("<원본>");
	first.y.show("<원본>");
	cout << endl;

	cout << "< 사본 객체(깊은 복사) 생성>" << endl;
	Car second(first);
	second.show("<사본>");
	second.x.show("<사본>");
	second.y.show("<사본>");

	cout << endl;
	second.changeID(2);
	cout << "---- 사본 객체의 번호를 <2>로 변경 후, ID 출력 ----" << endl;
	first.show("<원본>");
	second.show("<사본>");
	cout << endl;

	return 0;
}