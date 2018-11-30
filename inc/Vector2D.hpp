// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Vector2D.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/27 22:52:27 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/27 22:52:28 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VECTOR_2D_HPP
# define VECTOR_2D_HPP

# include <iostream>

class Vector2D
{
public:
	int x;
	int y;

	Vector2D(void);
	Vector2D(int xpos, int ypos);
	~Vector2D(void);

	Vector2D &add(Vector2D const &vec);
	Vector2D &sub(Vector2D const &vec);
	Vector2D &mul(Vector2D const &vec);
	Vector2D &div(Vector2D const &vec);
	Vector2D &zero(void);

	Vector2D &operator+=(const Vector2D &v1);
	Vector2D &operator-=(const Vector2D &v1);
	Vector2D &operator/=(const Vector2D &v1);
	Vector2D &operator*=(const Vector2D &v1);
	static int vectorLength(Vector2D vec);
	static double getAngle(Vector2D vec1, Vector2D vec2);
};

Vector2D &operator+(Vector2D &v1, Vector2D &v2);
Vector2D &operator-(Vector2D &v1, Vector2D &v2);
Vector2D &operator/(Vector2D &v1, Vector2D &v2);
Vector2D &operator*(Vector2D &v1, Vector2D &v2);
std::ostream &operator<<(std::ostream &o, const Vector2D &v);

#endif