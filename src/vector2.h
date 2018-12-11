#pragma once

#include <cmath>

namespace MyEngine {

template<typename T>
struct Vector2;

using Vector2i  = Vector2<int>;
using Vector2u = Vector2<unsigned>;
using Vector2b  = Vector2<bool>;
using Vector2f  = Vector2<float>;
using Vector2d  = Vector2<double>;

template<typename T>
struct Vector2 {
	T m_x;
	T m_y;

	Vector2();
	Vector2(T x = 0, T y = 0): m_x(x), m_y(y) {}
	Vector2(Vector2<T>& in)	 : m_x(in.m_x), m_y(in.m_y) {}
	Vector2(T in)			 : m_x(in), m_y(in) {}

	Vector2<T> XX() const { return Vector2<T>(m_x, m_x); }
	Vector2<T> XY() const { return Vector2<T>(m_x, m_y); }
	Vector2<T> YX() const { return Vector2<T>(m_y, m_x); }
	Vector2<T> YY() const { return Vector2<T>(m_y, m_y); }


	
	Vector2 operator+() const { 
		return *this; 
	}
	
	Vector2 operator+(const T& scalar) const {
		return Vector2(m_x + scalar, m_y + scalar);
	}

	friend Vector2 operator+(const T& scalar, const Vector2& addend) { 
		return addend + scalar;
	}  
	
	Vector2 operator+(const Vector2& addend) const { 
		return Vector2(m_x + addend.m_x, m_y + addend.m_y);
	}



	Vector2 operator-() const { 
		return Vector2(-m_x, -m_y); 
	}
	
	Vector2 operator-(const T& scalar) const {
		return Vector2(m_x - scalar, m_y - scalar);
	}

	friend Vector2 operator-(const T& scalar, const Vector2& subtrahend) { 
		return Vector2(scalar - subtrahend.m_x, scalar - subtrahend.m_y);
	} 
	
	Vector2 operator-(const Vector2& subtrahend) const { 
		return Vector2(m_x - subtrahend.m_x, m_y - subtrahend.m_y);
	} 



	Vector2 operator*(const T& scalar) const { 
		return Vector2(m_x * scalar, m_y * scalar);
	} 

	friend Vector2 operator*(const T& scalar, const Vector2& multiplied) { 
		return multiplied * scalar;
	}



	Vector2 operator/(const T& scalar) const {
		T factor = 1 / scalar; 
		return Vector2(m_x * factor, m_y * factor);
	} 

	friend Vector2 operator/(const T& scalar, const Vector2& divider) { 
		return divider / scalar;
	}  
	


	Vector2& operator+=(const T& scalar) {
		return *this = *this + scalar;
	}

	Vector2& operator+=(const Vector2& addend) const { 
		return *this = *this + addend;
	}



	Vector2& operator-=(const T& scalar) {
		return *this = *this - scalar;
	}

	Vector2& operator-=(const Vector2& subtrahend) const { 
		return *this = *this - subtrahend;
	}



	Vector2& operator*=(const T& scalar) {
		return *this = *this * scalar;
	}

	Vector2& operator/=(const T& scalar) {
		return *this = *this / scalar;
	}


	bool operator==(const Vector2& other) {
		return m_x == other.m_x && m_y == other.m_y;
	}

	bool operator!=(const Vector2& other) {
		return !(*this == other);
	}


	T length() {
		return sqrt(m_x * m_x + m_y * m_y);
	}

	T length(const Vector2& other) {
		T x = m_x - other.m_x;
		T y = m_y - other.m_y;
		return sqrt(x * x + y * y);
	}

	T Dot(const Vector2& other) {
		return m_x * other.m_x + m_y * other.m_y;
	}
};




}


