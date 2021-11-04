/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:43:16 by vfurmane          #+#    #+#             */
/*   Updated: 2021/11/04 14:00:41 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

void	Contact::updateInfo(std::string first_name, std::string last_name,
		std::string nickname, std::string phone_number,
		std::string darkest_secret)
{
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nickname = nickname;
	this->_phone_number = phone_number;
	this->_darkest_secret = darkest_secret;
}

std::string	Contact::getFirstName()
{
	return (this->_first_name);
}

std::string	Contact::getLastName()
{
	return (this->_last_name);
}

std::string	Contact::getNickname()
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber()
{
	return (this->_phone_number);
}

std::string	Contact::getDarkestSecret()
{
	return (this->_darkest_secret);
}