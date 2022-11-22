#include<iostream>
#include<cstring>
#include <iomanip>
#define M 10007
using namespace std;
const int MAX_N = 102;
class Matrix {
    public:
        Matrix() {
            row = col = 0;
            memset(mat, 0, sizeof(mat));
        }
        // TODO
        Matrix(int r, int c);
        const int &getrow() {
            return row;
        }
        const int &getcol() {
            return col;
        }
        // TODO
        int *operator[] (const int &x);
        const int *operator[] (const int &x) const {
            return mat[x];
        }
        // TODO
        Matrix operator+ (const Matrix &x) const;
        // TODO: note that this function is declared with the keyword "friend"
        friend Matrix operator* (const Matrix &x, const Matrix &y);
        void print() {
            for(int i=0;i<row;i++) {
                if(i==0) std::cout << "/";
                else if(i==row-1) std::cout << "\\";
                else std::cout << "|";
                for(int j=0;j<col;j++) {
                    std::cout << std::right << std::setw(8) << mat[i][j];
                }
                if(i==0) std::cout << " \\\n";
                else if(i==row-1) std::cout << " /\n";
                else std::cout << " |\n";
            }
        }
    private:
        int mat[MAX_N][MAX_N];
        int row, col;
};

// TODO
Matrix::Matrix(int r, int c)
{
    row = r;
    col = c;
    memset(mat,0,sizeof(mat));
}

// TODO
int *Matrix::operator[] (const int &x)
{
    return mat[x];
}

// TODO
Matrix Matrix::operator+ (const Matrix &x) const
{
    Matrix tmp(x.row,x.col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if((mat[i][j]%M+x[i][j]%M)%M >= 0)tmp[i][j] = (mat[i][j]%M+x[i][j]%M)%M;
            else tmp[i][j]=M+((mat[i][j]%M+x[i][j]%M)%M);
            //cout<<"mat:"<<mat[i][j]<<endl;
        }
    }
    return tmp;
}
// TODO: note that this function is declared with the keyword "friend"
Matrix  operator* (const Matrix &x, const Matrix &y)
{
    Matrix tmp(x.row,y.col);
    for(int i=0;i<x.row;i++)
    {
        for(int j=0;j<y.col;j++)
        {
            int sum = 0;
            for(int k=0;k<x.col;k++)
            {
                if((x.mat[i][k] * y.mat[k][j])%M < 0)
                {
                    //std::cout<<"negative"<<std::endl;
                    sum += M + (x.mat[i][k] * y.mat[k][j])%M;    
                }
                else sum += (((x.mat[i][k])%M)*(y.mat[k][j]%M))%M;
            }
            //std::cout<<tmp[i][j]<<std::endl;
            tmp[i][j] = sum%M;
        }
    }

    return tmp;
}
