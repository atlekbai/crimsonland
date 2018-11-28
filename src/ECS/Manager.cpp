// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Manager.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 22:45:25 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 22:45:26 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Manager.hpp"

Manager::Manager(void)
{}

Manager::~Manager(void)
{}

void					Manager::update(void)
{
	for (auto &e: entities)
		e->update();
}

void					Manager::draw(void)
{
	for (auto &e: entities)
		e->draw();
}

void					Manager::refresh(void)
{
	for (auto i = 0u; i < max_groups; i++)
	{
		auto &v(grouped_entities[i]);
		v.erase(std::remove_if(v.begin(), v.end(), [i](Entity *e){
			return (!e->isActive() || !e->hasGroup(i));
		}), v.end());
	}
	entities.erase(
		std::remove_if(
			entities.begin(),
			entities.end(),
			[](const std::unique_ptr<Entity> &e){
				return (!e->isActive());
			}), entities.end());
}

void					Manager::addToGroup(Entity* entity, std::size_t group)
{
	grouped_entities[group].emplace_back(entity);
}

std::vector<Entity*>	&Manager::getGroup(std::size_t group)
{
	return (grouped_entities[group]);
}

Entity					&Manager::addEntity(void)
{
	Entity 					*e = new Entity(*this);
	std::unique_ptr<Entity>	ptr{e};
	entities.emplace_back(std::move(ptr));
	return (*e);
}

void					Entity::addGroup(std::size_t group)
{
	groups_bitset[group] = true;
	manager.addToGroup(this, group);
}
