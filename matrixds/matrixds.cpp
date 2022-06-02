#include <matrixds/matrixds.h>
#include <stdexcept>
#include <utility>

MatrixDs::MatrixDs(const std::ptrdiff_t col, const std::ptrdiff_t row) 
{
	if (col <= 0 || row <= 0) 
	{
		throw std::bad_array_new_length();
	}
	data_.assign(row, std::vector<float>(col));
	n_row_ = row;
	n_col_ = col;
}

float& MatrixDs::at(const std::ptrdiff_t row, const std::ptrdiff_t col) 
{
	if (row < 0 || row >= n_row_ || col < 0 || col >= n_col_) 
	{
		throw std::out_of_range("");
	}
	return data_[row][col];
}

float MatrixDs::at(const std::ptrdiff_t row, const std::ptrdiff_t col) const 
{
	if (row < 0 || row >= n_row_ || col < 0 || col >= n_col_) 
	{
		throw std::out_of_range("");
	}
	return data_[row][col];
}

MatrixDs& MatrixDs::transpose() noexcept {
	MatrixDs m(n_row_, n_col_);
	for (std::ptrdiff_t i = 0; i < n_row_; ++i) 
	{
		for (std::ptrdiff_t j = 0; j < n_col_; ++j) 
		{
			m.at(j, i) = at(i, j);
		}
	}
	*this = m;
	return *this;
}

MatrixDs& MatrixDs::multiply(const MatrixDs& m) {
	if (n_col_ != m.n_row_) {
		throw std::logic_error("");
	}
	MatrixDs a(m.n_col_, n_row_);
	for (std::ptrdiff_t i = 0; i < n_row_; ++i) 
	{
		for (std::ptrdiff_t j = 0; j < m.n_col_; ++j) 
		{
			for (std::ptrdiff_t k = 0; k < n_col_; ++k) 
			{
				a.at(i, j) += at(i, k) * m.at(k, j);
			}
		}
	}
	*this = a;
	return *this;
}

void MatrixDs::swapRows(const std::ptrdiff_t rhs, const std::ptrdiff_t lhs) 
{
	if (rhs < 0 || rhs >= n_row_ || lhs < 0 || lhs >= n_row_) 
	{
		throw std::out_of_range("");
	}
	for (int i = 0; i < n_col_; ++i)
	{
		std::swap(at(rhs,i), at(lhs,i));
	}
}

void MatrixDs::swapColumns(const std::ptrdiff_t rhs, const std::ptrdiff_t lhs) 
{
	if (rhs < 0 || rhs >= n_col_ || lhs < 0 || lhs >= n_col_) 
	{
		throw std::out_of_range("");
	}
	for (int i = 0; i < n_row_; ++i) 
	{
		std::swap(at(i, rhs), at(i, lhs));
	}
}
