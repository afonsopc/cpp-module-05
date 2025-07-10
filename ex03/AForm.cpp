/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:57:53 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/11 00:05:46 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char	*AForm::Exception::what() const throw() { return ("AForm Exception"); }
const char	*AForm::GradeTooHighException::what() const throw() { return ("Grade too high"); }
const char	*AForm::GradeTooLowException::what() const throw() { return ("Grade too low"); }
const char	*AForm::AlreadySignedException::what() const throw() { return ("Already Signed"); }
const char	*AForm::NotSignedException::what() const throw() { return ("Not Signed"); }

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute):
	name(name), grade_to_sign(assertGrade(grade_to_sign)),
	grade_to_execute(assertGrade(grade_to_execute)) {}

AForm::AForm(void): name("FPADPDDSEOSLLM"), grade_to_sign(1), grade_to_execute(1) {}
AForm::AForm(const AForm &rhs): name(rhs.name), grade_to_sign(rhs.grade_to_sign), grade_to_execute(rhs.grade_to_execute) {}
AForm::~AForm(void) {}

AForm	&AForm::operator=(const AForm &rhs) {
	is_signed = rhs.is_signed;
	return (*this);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > grade_to_sign)
		throw (GradeTooLowException());
	else if (is_signed)
		throw (AlreadySignedException());
	is_signed = true;
}

std::string	AForm::getName(void) const { return (name); }
bool	AForm::getIsSigned(void) const { return (is_signed); }
int	AForm::getGradeToSign(void) const { return (grade_to_sign); }
int	AForm::getGradeToExecute(void) const { return (grade_to_execute); }

std::ostream	&operator<<(std::ostream &os, const AForm &obj) {
	os << "AForm \"" << obj.getName() << "\" is "
	<< (obj.getIsSigned() ? "" : "not ") << "signed"
	<< " and requires " << obj.getGradeToSign() << " to sign and "
	<< obj.getGradeToExecute() << " to execute!";
	return (os);
}

int	AForm::assertGrade(int grade) const {
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	return (grade);
}

void	AForm::execute(const Bureaucrat &executor) const {
	if (!is_signed)
		throw (NotSignedException());
	if (executor.getGrade() > grade_to_execute)
		throw (GradeTooLowException());
	_execute();
}
