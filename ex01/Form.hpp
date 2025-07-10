/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:57:56 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/10 18:48:56 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_to_sign;
		const int			grade_to_execute;
	public:
		class Exception: public std::exception { public: virtual const char *what() const throw(); };
		class GradeTooHighException: public Exception { public: virtual const char *what() const throw(); };
		class GradeTooLowException: public Exception { public: virtual const char *what() const throw(); };
		class AlreadySignedException: public Exception { public: virtual const char *what() const throw(); };

							Form(void);
							Form(std::string name, int grade_to_sign, int grade_to_execute);
							Form(const Form &rhs);
		Form				&operator=(const Form &rhs);
							~Form(void);
		int					assertGrade(int grade) const;
		std::string			getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);
};

std::ostream	&operator<<(std::ostream &os, const Form &obj);

#endif
