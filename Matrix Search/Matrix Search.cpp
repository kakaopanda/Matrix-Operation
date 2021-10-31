#include<iostream>
using namespace std;

class Intarr{ 
	int *a; // �����Ҵ��� �����ϴ� ������ �迭�� ������
	int n; // ������ �迭�� ũ��
	int pos; // Ž�� �ڷ��� ��ġ
public:
	Intarr(); //  �⺻ ������
	Intarr(int k); // �Ű������� �Է¹޴� ������
	~Intarr(); // �⺻ �Ҹ���(�����Ҵ� ����)
	int size(); // ������ �迭�� ũ�� ��ȯ �Լ�
	int search(int n); // Ư�� �����Ϳ� ��ġ�ϴ� ������ �ε����� Ž���ϴ� �Լ�
	void printarray(); // ������ �迭�� ���ҿ� ���� ��ü ��� �Լ�
	void insert(int input); // ������ �迭�� �޸� ���Ҵ� �� ���ο� ���Ҹ� �����ϴ� �Լ�
};

Intarr::Intarr(){} //  �⺻ ������

Intarr::Intarr(int k){ // �Ű������� �Է¹޴� ������
	n = k;
	a = (int*)malloc(sizeof(int)*n);
	int input;
	for(int i=0; i<n; i++){
		cout << "array[" << i << "] : ";
		cin >> input;
		a[i] = input;
	}
}

Intarr::~Intarr(){ // �⺻ �Ҹ���(�����Ҵ� ����)
	free(a);
}

int Intarr::size(){ // ������ �迭�� ũ�� ��ȯ �Լ�
	return n;
}

int Intarr::search(int data){ // Ư�� �����Ϳ� ��ġ�ϴ� ������ �ε����� Ž���ϴ� �Լ�
	cout << "\n�迭�� �˻��մϴ�.\n";
	pos = -1;

	for(int i=0; i<n; i++){
		if(a[i]==data)
		{
			cout << "�Է°��� ��ġ�ϴ� �����͸� �߰��߽��ϴ�." << endl;
			pos = i;
			cout << "�Է°�(" << data << ")��(��) ��ġ�ϴ� �ε����� array[" << pos << "] �Դϴ�." << endl << endl;
		}
	}
	if(pos < 0)
		cout << "�Է°�(" << data << ")��(��) ��ġ�ϴ� �����͸� �߰����� ���߽��ϴ�." << endl;
	return pos;
}

void Intarr::printarray(){ // ������ �迭�� ���ҿ� ���� ��ü ��� �Լ�
	cout << "\n�迭�� ����մϴ�.\n";

	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << endl;

	return;
}

void Intarr::insert(int input){ // ������ �迭�� �޸� ���Ҵ� �� ���ο� ���Ҹ� �����ϴ� �Լ�
	cout << "\n�迭�� ���ο� ���Ҹ� �߰��մϴ�." << endl;
	a = (int*)realloc(a,sizeof(int)*(size()+1));
	a[size()] = input;
	n = size()+1;

	return;
}

int main(void){
	int search_data;

	cout << "ũ�Ⱑ 10�� ������ �迭�� �����մϴ�." << endl;
	cout << "�� ���ҿ� ������ ���� �Է����ּ���. " << endl << endl;

	Intarr x(10); // ũ�Ⱑ 10�� ������ �迭 ����.

	x.printarray(); // ������ �迭�� ���� ��ü ���. 
	cout << "������ ������ �迭�� ũ��� " << x.size() << "�Դϴ�." << endl; // ������ �迭�� ũ�� ���.

	cout << "Ž���� �������� ���� �Է����ּ��� : ";
	cin >> search_data;
	x.search(search_data); // �Է°��� ��ġ�ϴ� �迭�� ���� Ž��. (Ž�� ����)

	cout << "Ž���� �������� ���� �Է����ּ��� : ";
	cin >> search_data;
	x.search(search_data); // �Է°��� ��ġ�ϴ� �迭�� ���� Ž��. (Ž�� ����)

	x.insert(100); // ������ �迭�� ���� �޸� ���Ҵ� �� ���ο� ���� ����.
	x.printarray(); // ������ �迭�� ���� ��ü ���.

	cout << "������ ������ �迭�� ũ��� " << x.size() << "�Դϴ�." << endl << endl; // ������ �迭�� ũ�� ���.
}
