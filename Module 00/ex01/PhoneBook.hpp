/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:53:54 by maskour           #+#    #+#             */
/*   Updated: 2025/10/07 18:15:27 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
class PhoneBook// tis class the rol of it is to print the table that have all the information 
{
private:
    int index;
    char * add;
    char *search;
    char contacts[8];
    int *index[8];
public:
    char *add;
    char *search;
    char *add_contact(char *add);
    char *search_contact(char *search);
    int set_index(int index);
    char *set_first_name(char *first_name);
    char *set_last_name(char *last_name);
    char *set_nickname(char *nickname);
    int *set_phone_number(int *phone_number);
    char *set_darkest_secret(char *darkest_secret);
};


#endif