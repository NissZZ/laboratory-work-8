#include <iostream>
using namespace std;

struct Matrix {
    int** data_ = nullptr;
    size_t n_ = 0u;
    size_t m_ = 0u;
};

void Construct(Matrix& out, size_t n, size_t m)
{
    out.data_ = new int*[n];
    out.n_ = n;
    out.m_ = m;
    for (int i = 0; i < n; i++)
    {
        out.data_[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            out.data_[i][j] = 0;
        }
    }
}

void Destruct(Matrix& in)
{
    for (int i = 0; i < in.n_; i++)
    {
        delete[] in.data_[i];
    }
    delete[] in.data_;
}

Matrix Copy(const Matrix& matrix)
{
    Matrix copy;
    copy.data_ = new int*[matrix.n_];
    copy.n_ = matrix.n_;
    copy.m_ = matrix.m_;
    for (int i = 0; i < matrix.n_; i++)
    {
        copy.data_[i] = new int[matrix.m_];
        for (int j = 0; j < matrix.m_; j++)
        {
            copy.data_[i][j] = matrix.data_[i][j];
        }
    }
    return copy;
}

Matrix Add(const Matrix& a, const Matrix& b)
{
    Matrix copy;
    if (a.n_ != b.n_ || a.m_ != b.m_)
    {
        return copy;
    }
    copy.data_ = new int*[a.n_];
    copy.n_ = a.n_;
    copy.m_ = a.m_;
    for (int i = 0; i < a.n_; i++)
    {
        copy.data_[i] = new int[a.m_];
        for (int j = 0; j < a.m_; j++)
        {
            copy.data_[i][j] = a.data_[i][j] + b.data_[i][j];
        }
    }
    return copy;
}

Matrix Sub(const Matrix& a, const Matrix& b)
{
    Matrix copy;
    if (a.n_ != b.n_ || a.m_ != b.m_)
    {
        return copy;
    }
    copy.data_ = new int*[a.n_];
    copy.n_ = a.n_;
    copy.m_ = a.m_;
    for (int i = 0; i < a.n_; i++)
    {
        copy.data_[i] = new int[a.m_];
        for (int j = 0; j < a.m_; j++)
        {
            copy.data_[i][j] = a.data_[i][j] - b.data_[i][j];
        }
    }
    return copy;
}

Matrix Mult(const Matrix& a, const Matrix& b)
{
    Matrix copy;
    if (a.m_ != b.n_ || a.n_ != b.m_)
    {
        return copy;
    }
    copy.data_ = new int*[a.n_];
    copy.n_ = a.n_;
    copy.m_ = a.m_;
    for (int i = 0; i < a.n_; i++)
    {
        copy.data_[i] = new int[a.m_];
        for (int j = 0; j < a.m_; j++)
        {
            copy.data_[i][j] = a.data_[i][j] * b.data_[i][j];
        }
    }
    return copy;
}

void Transposition(Matrix& matrix)
{
    Matrix copy = Copy(matrix);
    delete[] matrix.data_;
    matrix.n_ = copy.m_;
    matrix.m_ = copy.n_;
    matrix.data_ = new int*[matrix.n_];
    for (int i = 0; i < matrix.n_; i++)
    {
        matrix.data_[i] = new int[matrix.m_];
        for (int j = 0; j < matrix.m_; j++)
        {
            matrix.data_[i][j] = copy.data_[j][i];
        }
    }
    Destruct(copy);
}

bool operator==(const Matrix& a, const Matrix& b)
{
    if (a.n_ == b.n_ && a.m_ == b.m_)
    {
        for (int i = 0; i < a.n_; i++)
        {
            for (int j = 0; j < a.m_; j++)
            {
                if (a.data_[i][j] != b.data_[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}


