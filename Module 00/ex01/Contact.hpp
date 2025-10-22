/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:52:57 by maskour           #+#    #+#             */
/*   Updated: 2025/10/07 18:10:57 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
class Contact//this class to stor all the infermation about the not bock
{
private:
    char *last_name;
    char *first_name;
    char *nickname;
    int *phone_number;
    char *darkest_secret;
    /* data */
public:
    char *get_firs_name(char *first_name);
    char *get_last_name(char *last_name);
    char *get_nickname(char *nickname);
    int *get_phone_number(int *phone_number);
    char *get_darkest_secret(char *darkest_secret);
};
#endif