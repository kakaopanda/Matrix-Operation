#include <iostream>
using namespace std;

class Matrix
{
	int** m_ptr;
	int m_r;
	int m_c;
public:
	Matrix(int row, int col);
	Matrix(Matrix& m);
	~Matrix(){
		if(m_ptr != NULL){
			for(int i=0; i<m_r; i++)
				delete []m_ptr[i];
			delete []m_ptr;
		}
	}
	Matrix& operator=(Matrix& m){
		m_r = m.m_r;
		m_c = m.m_c;
		m_ptr = new int*[m_r];
		for(int i=0; i<m_r; i++)
		{
			m_ptr[i] = new int[m_c];
			for(int j=0; j<m_c; j++)
			{
				m_ptr[i][j] = m.m_ptr[i][j];
			}
		}
		return *this;
	}

	Matrix operator+(Matrix& m){ // (행렬,행렬) 간 덧셈 연산지원.
		Matrix temp(m_r, m_c);
		for(int i=0; i<m_r; i++){
			for(int j=0; j<m_c; j++){
				temp.m_ptr[i][j] = m_ptr[i][j]+m.m_ptr[i][j];
			}
		}
		return Matrix(temp);
	}

	Matrix operator+(int x){ // (행렬,상수) 간 덧셈 연산지원.
		Matrix temp(m_r, m_c);
		for(int i=0; i<m_r; i++){
			for(int j=0; j<m_c; j++){
				temp.m_ptr[i][j] = m_ptr[i][j]+x;
			}
		}
		return Matrix(temp);
	}

	Matrix operator*(Matrix& m){ // 행렬 A(m*n), 행렬 B(n*p)에 대한 행렬곱 C(m*p) 연산 지원.
		Matrix temp(m_r, m.m_c);
		if(temp.m_r==m.m_c){ // 행렬 A의 행과 행렬 B의 열이 일치할 때 연산 가능.
		for(int x=0; x<m_r; x++){
			for(int i=0; i<m.m_c; i++){
				for(int j=0; j<m_c; j++)
					temp.m_ptr[x][i] += m_ptr[x][j]*m.m_ptr[j][i];
					}
				}
		}
		else
			cout << "연산을 진행할 수 없습니다." << endl;

		return Matrix(temp);
	}

	Matrix operator*(int x){ // (행렬,상수) 간 곱셈 연산 지원.
		Matrix temp(m_r, m_c);
		for(int i=0; i<m_r; i++){
			for(int j=0; j<m_c; j++){
				temp.m_ptr[i][j] = m_ptr[i][j]*x;
			}
		}
		return Matrix(temp);
	}

	friend ostream& operator<<(ostream& o, Matrix& m);
	friend istream& operator>>(istream& ins, Matrix& m);
};

Matrix::Matrix(Matrix& m)
{
	m_r = m.m_r;
	m_c = m.m_c;
	m_ptr = new int*[m_r];
	for(int i=0; i<m_r; i++){
		m_ptr[i] = new int[m_c];
		for(int j=0; j<m_c; j++)
		{
			m_ptr[i][j] = m.m_ptr[i][j];
		}
	}
}

Matrix::Matrix(int row, int col) // 생성 행렬 초기화.
{
	m_r = row;
	m_c = col;
	m_ptr = new int*[row];
	for(int i=0; i<row; i++)
	{
		m_ptr[i] = new int[col];
		for(int j=0; j<col; j++)
		{
			m_ptr[i][j] = 0;
		}
	}
}

ostream& operator<<(ostream& o, Matrix& m)
{
	cout << "행렬을 출력합니다." << endl;
	for(int i=0; i<m.m_r; i++)
	{
		for(int j=0; j<m.m_c; j++)
		{
			o << m.m_ptr[i][j] << "\t";
		}
		o << endl;
	}
	return o;
}

istream& operator>>(istream& ins, Matrix& m)
{
	int row = m.m_r;
	int col = m.m_c;
	int **p = m.m_ptr;

	cout << "행렬의 원소에 대한 값을 입력해주세요.\n";
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			int x;
			cout << "Matrix[" << i << "][" << j << "] = ";
			ins >> x;
			p[i][j] = x;
		}
	}
	cout << endl;
	return ins;
}

int main()
{
	// 행렬 간 곱셈 연산을 위해 행렬 A의 행과 행렬 B의 열을 동일하게 설정했습니다.
	Matrix A(2,3);
	Matrix B(3,2);
	Matrix C(2,2);
	Matrix D(2,2);
	Matrix Result(2,2);

	cin >> A;
	cin >> B;
	cin >> C;
	cin >> D;

	cout << A << endl;
	cout << B << endl;
	cout << C << endl;
	cout << D << endl;

	Result = (A*B)*10 + (C*2+D);
	cout << "(A*B)*10 + (C*2+D) 연산에 대한 결과입니다.\n";
	cout << Result << endl;
}

