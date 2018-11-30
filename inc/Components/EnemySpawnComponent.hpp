// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   EnemySpawnComponent.hpp                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/30 13:22:43 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/30 13:22:43 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_SPAWN_COMPONENT_HPP
# define ENEMY_SPAWN_COMPONENT_HPP

# include "Component.hpp"
# include "Components.hpp"
# include "MyFramework.hpp"
# include "Game.hpp"

class EnemySpawnComponent: public Component
{
private:
    Entity      *hero;
    std::string sprite_id;
    unsigned    count;
public:
    EnemySpawnComponent(Entity *entityToAttack, std::string id);
    void init(void) override;
    void update(void) override;
    void addSpawns(int n);
    void killSpawn(Entity &s);
};

#endif