#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
		m[i][i] = 1;
	TMatrix<int> m1(m);
	EXPECT_EQ(m, m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5), m1(m);
	EXPECT_EQ(true, &m!=&m1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[2][3] = 4;
	EXPECT_EQ(4, m[2][3]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[-1][-2] = 3);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[6][6] = 3);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
		m[i][i] = 1;
	EXPECT_EQ(m, m=m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(5), b(5);
	for (int i = 0; i < 5; i++)
		m[i][i] = 1;
	EXPECT_EQ(m, b = m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(5), b(8);
	m = b;
	EXPECT_EQ(8, m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(5), b(3), exp(5);
	for (int i = 0; i < 5; i++)
		m[i][i] = 1;
	for (int i = 0; i < 5; i++)
		exp[i][i] = 1;
	EXPECT_EQ(exp, b = m);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(5), b(5);
	for (int i = 0; i < 5; i++)
		m[i][i] = 1;
	for (int i = 0; i < 5; i++)
		b[i][i] = 1;
	EXPECT_EQ(true, b==m);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(5);
	for (int i = 0; i < 5; i++)
		m[i][i] = 1;
	EXPECT_EQ(true, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(5), b(6);
	EXPECT_EQ(false, b == m);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(5), b(5), exp(5);
	for (int i = 0; i < 5; i++)
		m[i][i] = 1;
	for (int i = 0; i < 5; i++)
		b[i][i] = 2;
	for (int i = 0; i < 5; i++)
		exp[i][i] = 3;
	EXPECT_EQ(exp, b + m);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(5), b(10);
	for (int i = 0; i < 5; i++)
		m[i][i] = 1;
	for (int i = 0; i < 10; i++)
		b[i][i] = 2;
	ASSERT_ANY_THROW(m + b);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(5), b(5), exp(5);
	for (int i = 0; i < 5; i++)
		m[i][i] = 5;
	for (int i = 0; i < 5; i++)
		b[i][i] = 1;
	for (int i = 0; i < 5; i++)
		exp[i][i] = 4;
	m = m - b;
	int i;
	if (m == exp)
		i = 1;
	else
		i = 0;
	EXPECT_EQ(1, i);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(5), b(10);
	for (int i = 0; i < 5; i++)
		m[i][i] = 1;
	for (int i = 0; i < 10; i++)
		b[i][i] = 2;
	ASSERT_ANY_THROW(m - b);
}

