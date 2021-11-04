/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:35:06 by vfurmane          #+#    #+#             */
/*   Updated: 2021/11/04 12:55:28 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
public:

	PhoneBook(void);	
	void	addNewContact(std::string first_name, std::string last_name,
		std::string nickname, std::string phone_number,
		std::string darkest_secret);
	void	displayAllContacts();

private:

	Contact	_contacts[8];

	int	_current_id;
};

#endif
