#include<iostream>
using namespace std;

class Circle{ 
private:
	int r; // 반지름을 의미하는 속성변수
public:
	int Get(); // 속성변수 r값을 반환하는 함수
	void Put(int d); // 속성변수 r에 매개변수 d를 저장하는 함수
};

int Circle::Get(){ // 정수형 배열의 크기 반환 함수
	return r;
}

void Circle::Put(int d){ // 속성변수 r에 매개변수 d를 저장하는 함수
	r = d;
	return;
}

void swap(Circle &x, Circle &y){ // 두 요소에 저장된 속성변수 r의 값을 교환하는 함수
	int temp = x.Get();
	x.Put(y.Get());
	y.Put(temp);
	return;
}

int main(void){
	int index, data, size = 10;

	cout << "크기가 10인 Circle 클래스 배열을 생성합니다." << endl << endl;
	Circle *x = new Circle[10]; // 크기가 10인 Cirlce 클래스 객체배열 동적생성.

	for(int i=0; i<10; i++){
		cout << "Circle[" << i << "]" << "에 저장할 값을 입력해주세요. : ";
		cin >> data;
		x[i].Put(data);
	}

	cout << "\nCircle 클래스 배열의 출력을 진행합니다." << endl;
	for(int i=0; i<10; i++){
		cout << x[i].Get() << " ";
	}
	cout << endl << endl;

	cout << "Circle 클래스 요소들에 대해 오름차순 정렬을 진행합니다." << endl;

	for(int i=0; i<(size-1); i++){
		index = i;
		for(int j=i+1; j<size; j++){
			if(x[index].Get() < x[j].Get())

				index = j;
		}
		if(i != index){
			swap(x[i],x[index]);
		}
		for(int i=0; i<10; i++){ // 배열이 정렬되는 과정을 출력.
		cout << x[i].Get() << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "오름차순 정렬된 Circle 클래스 배열의 출력을 진행합니다." << endl;
	for(int i=0; i<10; i++){
		cout << x[i].Get() << " ";
	}
	cout << endl << endl;
	delete [] x; // Circle 클래스 객체배열 반환
}