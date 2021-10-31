#include<iostream>
using namespace std;

class Intarr{ 
	int *a; // 동적할당을 진행하는 정수형 배열의 포인터
	int n; // 정수형 배열의 크기
	int pos; // 탐색 자료의 위치
public:
	Intarr(); //  기본 생성자
	Intarr(int k); // 매개변수를 입력받는 생성자
	~Intarr(); // 기본 소멸자(동적할당 해제)
	int size(); // 정수형 배열의 크기 반환 함수
	int search(int n); // 특정 데이터와 일치하는 원소의 인덱스를 탐색하는 함수
	void printarray(); // 정수형 배열의 원소에 대한 전체 출력 함수
	void insert(int input); // 정수형 배열에 메모리 재할당 및 새로운 원소를 삽입하는 함수
};

Intarr::Intarr(){} //  기본 생성자

Intarr::Intarr(int k){ // 매개변수를 입력받는 생성자
	n = k;
	a = (int*)malloc(sizeof(int)*n);
	int input;
	for(int i=0; i<n; i++){
		cout << "array[" << i << "] : ";
		cin >> input;
		a[i] = input;
	}
}

Intarr::~Intarr(){ // 기본 소멸자(동적할당 해제)
	free(a);
}

int Intarr::size(){ // 정수형 배열의 크기 반환 함수
	return n;
}

int Intarr::search(int data){ // 특정 데이터와 일치하는 원소의 인덱스를 탐색하는 함수
	cout << "\n배열을 검색합니다.\n";
	pos = -1;

	for(int i=0; i<n; i++){
		if(a[i]==data)
		{
			cout << "입력값과 일치하는 데이터를 발견했습니다." << endl;
			pos = i;
			cout << "입력값(" << data << ")과(와) 일치하는 인덱스는 array[" << pos << "] 입니다." << endl << endl;
		}
	}
	if(pos < 0)
		cout << "입력값(" << data << ")과(와) 일치하는 데이터를 발견하지 못했습니다." << endl;
	return pos;
}

void Intarr::printarray(){ // 정수형 배열의 원소에 대한 전체 출력 함수
	cout << "\n배열을 출력합니다.\n";

	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << endl;

	return;
}

void Intarr::insert(int input){ // 정수형 배열에 메모리 재할당 및 새로운 원소를 삽입하는 함수
	cout << "\n배열에 새로운 원소를 추가합니다." << endl;
	a = (int*)realloc(a,sizeof(int)*(size()+1));
	a[size()] = input;
	n = size()+1;

	return;
}

int main(void){
	int search_data;

	cout << "크기가 10인 정수형 배열을 생성합니다." << endl;
	cout << "각 원소에 대입할 값을 입력해주세요. " << endl << endl;

	Intarr x(10); // 크기가 10인 정수형 배열 생성.

	x.printarray(); // 정수형 배열의 원소 전체 출력. 
	cout << "생성된 정수형 배열의 크기는 " << x.size() << "입니다." << endl; // 정수형 배열의 크기 출력.

	cout << "탐색할 데이터의 값을 입력해주세요 : ";
	cin >> search_data;
	x.search(search_data); // 입력값과 일치하는 배열의 원소 탐색. (탐색 성공)

	cout << "탐색할 데이터의 값을 입력해주세요 : ";
	cin >> search_data;
	x.search(search_data); // 입력값과 일치하는 배열의 원소 탐색. (탐색 실패)

	x.insert(100); // 정수형 배열에 대해 메모리 재할당 및 새로운 원소 삽입.
	x.printarray(); // 정수형 배열의 원소 전체 출력.

	cout << "수정된 정수형 배열의 크기는 " << x.size() << "입니다." << endl << endl; // 정수형 배열의 크기 출력.
}
