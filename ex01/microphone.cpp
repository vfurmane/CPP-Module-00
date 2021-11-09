/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microphone.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:09:00 by vfurmane          #+#    #+#             */
/*   Updated: 2021/11/09 09:11:38 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

void	askContactInfo(PhoneBook *phone_book)
{
	std::string	info[5] = { "first name", "last name", "nickname",
		"phone number", "darkest secret" };

	std::cout << "You are adding a new contact." << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Please enter " << info[i] << ": ";
		std::getline(std::cin, info[i]);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << "Operation aborted..." << std::endl;
			return ;
		}
	}
	phone_book->addNewContact(info[0], info[1], info[2], info[3], info[4]);
}

int	askContactIndex(void)
{
	std::string				index;
	std::string::iterator	chr;
	int						ret;

	std::cout << "contact index: ";
	std::getline(std::cin, index);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return (-1);
	}
	chr = index.begin();
	while (chr != index.end())
		if (!isdigit(*chr++))
			return (-1);
	ret = atoi(index.c_str());
	return (ret);
}

int	main(void)
{
	int			index;
	PhoneBook	phone_book;
	std::string	command;

	do {
		std::cout << "$ ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		else if (command.compare("ADD") == 0)
			askContactInfo(&phone_book);
		else if (command.compare("SEARCH") == 0)
		{
			phone_book.displayAllContacts();
			index = askContactIndex();
			if (index < 0)
				std::cout << "Index must be a positive integer." << std::endl;
			else
				phone_book.displayContactStatus(index);
		}
	} while (command.compare("EXIT"));
	std::cout << "Good bye!" << std::endl;
	return (0);
}
