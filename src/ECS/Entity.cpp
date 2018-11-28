// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Entity.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 20:11:57 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 20:11:57 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Entity.hpp"

Entity::Entity(Manager &man) : manager(man)
{}

Entity::~Entity(void)
{}

void	Entity::update(void)
{
	for (auto &c: components)
		c->update();
}

void	Entity::draw(void)
{
	for (auto &c: components)
		c->draw();
}

void	Entity::destroy(void)
{
	active = false;
}

void	Entity::delGroup(std::size_t group)
{
	groups_bitset[group] = false;
}

bool	Entity::isActive(void) const
{
	return (active);
}

bool	Entity::hasGroup(std::size_t group)
{
	return (groups_bitset[group]);
}
