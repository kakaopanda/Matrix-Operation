#include<iostream>
using namespace std;

class Circle{ 
private:
	int r; // �������� �ǹ��ϴ� �Ӽ�����
public:
	int Get(); // �Ӽ����� r���� ��ȯ�ϴ� �Լ�
	void Put(int d); // �Ӽ����� r�� �Ű����� d�� �����ϴ� �Լ�
};

int Circle::Get(){ // ������ �迭�� ũ�� ��ȯ �Լ�
	return r;
}

void Circle::Put(int d){ // �Ӽ����� r�� �Ű����� d�� �����ϴ� �Լ�
	r = d;
	return;
}

void swap(Circle &x, Circle &y){ // �� ��ҿ� ����� �Ӽ����� r�� ���� ��ȯ�ϴ� �Լ�
	int temp = x.Get();
	x.Put(y.Get());
	y.Put(temp);
	return;
}

int main(void){
	int index, data, size = 10;

	cout << "ũ�Ⱑ 10�� Circle Ŭ���� �迭�� �����մϴ�." << endl << endl;
	Circle *x = new Circle[10]; // ũ�Ⱑ 10�� Cirlce Ŭ���� ��ü�迭 ��������.

	for(int i=0; i<10; i++){
		cout << "Circle[" << i << "]" << "�� ������ ���� �Է����ּ���. : ";
		cin >> data;
		x[i].Put(data);
	}

	cout << "\nCircle Ŭ���� �迭�� ����� �����մϴ�." << endl;
	for(int i=0; i<10; i++){
		cout << x[i].Get() << " ";
	}
	cout << endl << endl;

	cout << "Circle Ŭ���� ��ҵ鿡 ���� �������� ������ �����մϴ�." << endl;

	for(int i=0; i<(size-1); i++){
		index = i;
		for(int j=i+1; j<size; j++){
			if(x[index].Get() < x[j].Get())

				index = j;
		}
		if(i != index){
			swap(x[i],x[index]);
		}
		for(int i=0; i<10; i++){ // �迭�� ���ĵǴ� ������ ���.
		cout << x[i].Get() << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "�������� ���ĵ� Circle Ŭ���� �迭�� ����� �����մϴ�." << endl;
	for(int i=0; i<10; i++){
		cout << x[i].Get() << " ";
	}
	cout << endl << endl;
	delete [] x; // Circle Ŭ���� ��ü�迭 ��ȯ
}