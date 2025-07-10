/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 00:14:32 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/11 00:32:35 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}
Intern::Intern(const Intern &obj) { (void)obj; }
Intern	&Intern::operator=(const Intern &rhs) { return((void)rhs, *this); }
Intern::~Intern(void) {}

static AForm	*makeShrubberyCreationForm(std::string target) {
	return (new ShrubberyCreationForm(target));
}

static AForm	*makeRobotomyRequestForm(std::string target) {
	return (new RobotomyRequestForm(target));
}

static AForm	*makePresidentialPardonForm(std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string name, std::string target) {
	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *(*creators[3])(std::string) = {
		makeShrubberyCreationForm,
		makeRobotomyRequestForm,
		makePresidentialPardonForm
	};
	for (int i = 0; i < 3; i++) {
		if (name != names[i])
			continue ;
		std::cout << "Intern creates " << names[i] << " form." << std::endl;
		return (creators[i](target));
	}
	std::cout << "Intern cannot create form: " << name << "." << std::endl;
	return (NULL);
}
