/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:36:03 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/10 14:51:37 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade too high"); }
const char* Bureaucrat::GradeTooLowException::what() const throw() { return ("Grade too low"); }

Bureaucrat::Bureaucrat(std::string name, int grade): name(name) { setGrade(grade); }
Bureaucrat::Bureaucrat(void): name("Chvd") { setGrade(1); }
Bureaucrat::Bureaucrat(const Bureaucrat &rhs): name(rhs.name) { setGrade(rhs.grade); }
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs) { return (setGrade(rhs.grade), *this); }
Bureaucrat::~Bureaucrat(void) {}
int	Bureaucrat::getGrade(void) const { return (this->grade); }
std::string	Bureaucrat::getName(void) const { return (this->name); }
void	Bureaucrat::incrementGrade(void) { setGrade(this->grade - 1); }
void	Bureaucrat::decrementGrade(void) { setGrade(this->grade + 1); }

void	Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}
