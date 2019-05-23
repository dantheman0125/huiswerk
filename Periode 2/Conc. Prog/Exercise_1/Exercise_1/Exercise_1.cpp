// Exercise_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <complex>
#include <iostream>

#include <fstream>
#include <complex> // if you make use of complex number facilities in C++

template <class T> struct RGB { T r, g, b; };

template <class T>
class Matrix {
public:
	Matrix(const size_t rows, const size_t cols) : _rows(rows), _cols(cols) {
		_matrix = new T * [rows];
		for (size_t i = 0; i < rows; ++i) {
			_matrix[i] = new T[cols];
		}
	}
	Matrix(const Matrix& m) : _rows(m._rows), _cols(m._cols) {
		_matrix = new T * [m._rows];
		for (size_t i = 0; i < m._rows; ++i) {
			_matrix[i] = new T[m._cols];
			for (size_t j = 0; j < m._cols; ++j) {
				_matrix[i][j] = m._matrix[i][j];
			}
		}
	}
	~Matrix() {
		for (size_t i = 0; i < _rows; ++i) {
			delete[] _matrix[i];
		}
		delete[] _matrix;
	}
	T* operator[] (const size_t nIndex)
	{
		return _matrix[nIndex];
	}
	size_t width() const { return _cols; }
	size_t height() const { return _rows; }
protected:
	size_t _rows, _cols;
	T** _matrix;
};

// Portable PixMap image
class PPMImage : public Matrix<RGB<unsigned char> >
{
public:
	PPMImage(const size_t height, const size_t width) : Matrix(height, width) { }
	void save(const std::string& filename)
	{
		std::ofstream out(filename, std::ios_base::binary);
		out << "P6" << std::endl << _cols << " " << _rows << std::endl << 255 << std::endl;
		for (size_t y = 0; y < _rows; y++)
			for (size_t x = 0; x < _cols; x++)
				out << _matrix[y][x].r << _matrix[y][x].g << _matrix[y][x].b;
	}
};

//constexpr auto max_row = 22, max_column = 78, max_iteration = 20;
int x;
int y;
int main()
{

	const unsigned width = 1600;
	const unsigned height = 1600;
	const unsigned int max_ite = 10000;
	PPMImage image(height, width);

	for (unsigned int piX = 0; piX < width; piX++) {
		for (unsigned int piY = 0; piY < height; piY++) {
			double x0 = (piX - width / 2.0) * 4.0 / width;
			double y0 = (piY - height / 2.0) * 4.0 / width;
			double x = 0, y = 0;
			int i = 0;
			while (x * x + y * y <= 4 && i < max_ite) {
				double xt = x * x - y * y + x0;
				y = 2 * x * y + y0;
				x = xt;
				i++;
			}
			if (i < max_ite) {
				image[piY][piX].r = image[piY][piX].g = image[piY][piX].b = 255; //white
			}
			else {
				image[piY][piX].r = image[piY][piX].g = image[piY][piX].b = 0; //black
			}
		}
	}

	image.save("mandelbrot.ppm");
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
