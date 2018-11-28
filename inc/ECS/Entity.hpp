// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Entity.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 19:57:30 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 19:57:30 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENTITY_HPP
# define ENTITY_HPP 

# include <iostream>
# include <vector>
# include <array>
# include <bitset>
# include <algorithm>
# include <memory>
# include "Component.hpp"

class Manager;

constexpr std::size_t max_components = 32;
constexpr std::size_t max_groups = 32;

inline std::size_t get_new_component_type_id(void)
{
	static std::size_t	last_id = 0u;
	return (last_id++);
}

template<typename T>
inline std::size_t get_component_id(void)
{
	static std::size_t type_id = get_new_component_type_id();
	return (type_id);
}


class Entity
{
private:
	Manager									&manager;
	bool									active = true;
	std::vector<std::unique_ptr<Component>>	components;
	std::array<Component*, max_components>	components_array;
	std::bitset<max_components>				components_bitset;
	std::bitset<max_groups>					groups_bitset;
public:
	Entity(Manager &man);
	~Entity(void);
	void	update(void);
	void	draw(void);
	void	destroy(void);
	void	addGroup(std::size_t group);
	void	delGroup(std::size_t group);
	bool	isActive(void) const;
	bool	hasGroup(std::size_t group);
	
	template<typename T>
	bool	hasComponent(void) const
	{
		return (components_bitset[get_component_id<T>()]);
	}

	template<typename T>
	T		&getComponent(void) const
	{
		auto ptr(components_array[get_component_id<T>()]);
		return (*static_cast<T*>(ptr));
	}

	template<typename T, typename ... TArgs>
	T		&addComponent(TArgs ... m_args)
	{
		T	*c(new T(std::forward<TArgs>(m_args)...));
		c->entity = this;
		std::unique_ptr<Component> u_ptr{c};
		components.emplace_back(std::move(u_ptr));
		components_array[get_component_id<T>()] = c;
		components_bitset[get_component_id<T>()] = true;
		c->init();
		return (*c);
	}
};
#endif