/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:53:54 by maskour           #+#    #+#             */
/*   Updated: 2025/11/01 22:17:25 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include<iostream>
class Zombie
{
private:
std::string name;
int num;
public:
Zombie(std::string name);
~Zombie();
void announce(void);
};

Zombie* zombieHorde( int N, std::string name );
#endif