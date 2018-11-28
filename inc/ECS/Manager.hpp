// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Manager.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 22:45:33 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 22:45:34 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MANAGER_HPP
# define MANAGER_HPP

# include "Entity.hpp"

class Manager
{
private:
	std::vector<std::unique_ptr<Entity>>			entities;
	std::array<std::vector<Entity*>, max_groups>	grouped_entities;
public:
	Manager(void);
	~Manager(void);
	void					update(void);
	void					draw(void);
	void					refresh(void);
	void					addToGroup(Entity* entity, std::size_t group);
	std::vector<Entity*>	&getGroup(std::size_t group);
	Entity					&addEntity(void);
};

#endif