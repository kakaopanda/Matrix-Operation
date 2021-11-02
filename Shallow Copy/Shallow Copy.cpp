#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Engine{ // engineNo, engineName�� ���� Engine Ŭ����.
public:
	int engineNo;
	string engineName;
	void show(string s);
};
void Engine::show(string s){
	cout << s << " engineNo : " << engineNo << endl;
	cout << s << " engineName : " << engineName << endl;
}

class Body{ // bodyNo, bodyName�� ���� Body Ŭ����.
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
	cout << "���� ������ ����. ���� ��ü�� ID <" << *carid << ">" << endl;
}

void Car::changeID(int id){
	*carid = id;
}

int main(){
	cout << "< ���� ��ü ���� >" << endl;
	Car first(1);
	first.show("<����>");
	first.x.show("<����>");
	first.y.show("<����>");
	cout << endl;

	cout << "< �纻 ��ü(���� ����) ����>" << endl;
	Car second(first);
	second.show("<�纻>");
	second.x.show("<�纻>");
	second.y.show("<�纻>");

	cout << endl;
	second.changeID(2);
	cout << "---- �纻 ��ü�� ��ȣ�� <2>�� ���� ��, ID ��� ----" << endl;
	first.show("<����>");
	second.show("<�纻>");
	cout << endl;

	return 0;
}