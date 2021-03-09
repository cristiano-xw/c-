#ifndef _MATRIX_H
#define _MATRIX_H
class Matrix
{
	public:
		Matrix(int size=2);//构造 
		~Matrix();//析构 
		void setMatrix(const double*values);
		void printMatrix() const;    
		int getsize() const{return size;}//得到矩阵大小 
		double &element(int i,int j){return elements[i*size+j];}
		double element(int i,int j) const {return elements[i*size+j];}
		
	private:
		int size;
		double *elements;
};
#endif
