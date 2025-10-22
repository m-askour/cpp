/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:06:43 by maskour           #+#    #+#             */
/*   Updated: 2025/10/04 18:28:04 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void aper_to_lawer(char *av)
{
    int i = 0;
    while (av[i])
    {
        if (av[i] >= 'a' && av[i] <= 'z')
            av[i] = av[i] - 32;
        i++;
    }
}

int main (int ac, char **av)
{
    if (ac < 2)
        std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    int i;
    i = 1;
    while (av[i])
    {
        
        aper_to_lawer(av[i]);
        std :: cout << av[i] << " ";
        i++;
    }
    std :: cout << "\n";
    return (0);
}