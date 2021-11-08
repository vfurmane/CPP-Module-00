/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microphone.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:09:00 by vfurmane          #+#    #+#             */
/*   Updated: 2021/11/08 14:54:58 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

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

int	main(void)
{
	PhoneBook phone_book;
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
			phone_book.displayAllContacts();
	} while (command.compare("EXIT"));
	std::cout << "Good bye!" << std::endl;
	return (0);
}
