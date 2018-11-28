// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Component.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 19:53:55 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 19:54:00 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef COMPONENT_HPP
# define COMPONENT_HPP

class Entity;

class Component
{
public:
	Entity *entity;
	virtual void init(void)
	{}
	virtual void update(void)
	{}
	virtual void draw(void)
	{}
	virtual ~Component(void)
	{}
};

#endif