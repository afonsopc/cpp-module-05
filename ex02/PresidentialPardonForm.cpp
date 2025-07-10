/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:41:57 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/10 23:53:21 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs)
	: AForm(rhs), target(rhs.target) {}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	AForm::operator=(rhs);
	target = rhs.target;
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm(void) {}

void	PresidentialPardonForm::_execute(void) const {
	std::cout << target << " has been pardoned by "
		<< CURRENT_PRESIDENT << "." << std::endl;
}
