/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:57:53 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/10 18:54:29 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char	*Form::Exception::what() const throw() { return ("Form Exception"); }
const char	*Form::GradeTooHighException::what() const throw() { return ("Grade too high"); }
const char	*Form::GradeTooLowException::what() const throw() { return ("Grade too low"); }
const char	*Form::AlreadySignedException::what() const throw() { return ("Already Signed"); }

Form::Form(std::string name, int grade_to_sign, int grade_to_execute):
	name(name), grade_to_sign(assertGrade(grade_to_sign)),
	grade_to_execute(assertGrade(grade_to_execute)) {}

Form::Form(void): name("FPADPDDSEOSLLM"), grade_to_sign(1), grade_to_execute(1) {}
Form::Form(const Form &rhs): name(rhs.name), grade_to_sign(rhs.grade_to_sign), grade_to_execute(rhs.grade_to_execute) {}
Form::~Form(void) {}

Form	&Form::operator=(const Form &rhs) {
	is_signed = rhs.is_signed;
	return (*this);
}

void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > grade_to_sign)
		throw (GradeTooLowException());
	else if (is_signed)
		throw (AlreadySignedException());
	is_signed = true;
}

std::string	Form::getName(void) const { return (name); }
bool	Form::getIsSigned(void) const { return (is_signed); }
int	Form::getGradeToSign(void) const { return (grade_to_sign); }
int	Form::getGradeToExecute(void) const { return (grade_to_execute); }

std::ostream	&operator<<(std::ostream &os, const Form &obj) {
	os << "Form \"" << obj.getName() << "\" is "
	<< (obj.getIsSigned() ? "" : "not ") << "signed"
	<< " requires " << obj.getGradeToSign() << " to sign and "
	<< obj.getGradeToExecute() << " to execute!";
	return (os);
}

int	Form::assertGrade(int grade) const {
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	return (grade);
}
