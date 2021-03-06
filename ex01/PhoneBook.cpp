/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:46:13 by vfurmane          #+#    #+#             */
/*   Updated: 2021/11/10 10:04:37 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstring>
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void)
{
	this->_current_id = 0;
}

void	PhoneBook::addNewContact(std::string first_name, std::string last_name,
		std::string nickname, std::string phone_number,
		std::string darkest_secret)
{
	if (this->_current_id >= 8)
	{
		for (int i = 1; i < 8; i++)
			this->_contacts[i - 1] = this->_contacts[i];
		this->_current_id = 7;
	}
	this->_contacts[this->_current_id].updateInfo(first_name, last_name, nickname, phone_number, darkest_secret);
	if (this->_current_id < 8)
		this->_current_id++;
}

static void	writeTruncatedData(std::string data)
{
	std::cout << "|";
	if (data.size() > 10)
		std::cout << data.substr(0, 9) << (data.size() > 10 ? "." : "");
	else
	{
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << data;
	}
}

void	PhoneBook::displayAllContacts()
{
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < this->_current_id; i++)
	{
		std::cout << "|" << std::setfill(' ') << std::setw(10);
		std::cout << i;
		writeTruncatedData(this->_contacts[i].getFirstName());
		writeTruncatedData(this->_contacts[i].getLastName());
		writeTruncatedData(this->_contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}
}

void	PhoneBook::displayContactStatus(int index)
{
	if (index < 0 || index >= 8)
	{
		std::cout << "Out of bound" << std::endl;
		return ;
	}
	std::cout << this->_contacts[index].getFirstName() << std::endl;
	std::cout << this->_contacts[index].getLastName() << std::endl;
	std::cout << this->_contacts[index].getNickname() << std::endl;
	std::cout << this->_contacts[index].getPhoneNumber()<< std::endl;
	std::cout << this->_contacts[index].getDarkestSecret() << std::endl;
}
