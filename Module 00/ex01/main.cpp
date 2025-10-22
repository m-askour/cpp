/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:31:25 by maskour           #+#    #+#             */
/*   Updated: 2025/10/16 14:37:27 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <Contact.hpp>
#include <iostream>



int parsing(char *input)
{
    int i;
    i = 0;
    while (input[i])
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9'))
            return (0);
        return (1);
    }
    return (0);
}
int  main ()
{
    PhoneBook   *table;
    Contact     cont;
    char *input;
    while (1)
    {
        if (parsing(input))
            std :: cout << "this is not good char";
        if (input == "ADD")
        {
            std :: cin >> table.add >> '\n';
            table.add_contact;
        }
        else if (input == "SEARCH")
        {
            std :: cin >> table.search >> '\n';
            table.search_contact;   
        }
        else if (input == "EXIT")
            break;
        else
            std :: cout << "put just ADD or SEARCH or EXIT" << '\n';
    }
    return (0);
}