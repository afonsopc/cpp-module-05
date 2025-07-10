/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:57:56 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/11 00:01:51 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <iostream>

class Bureaucrat;

class AForm {
	protected:
		virtual void		_execute(void) const = 0;
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
		class NotSignedException: public Exception { public: virtual const char *what() const throw(); };

							AForm(void);
							AForm(std::string name, int grade_to_sign, int grade_to_execute);
							AForm(const AForm &rhs);
		AForm				&operator=(const AForm &rhs);
		virtual				~AForm(void);
		int					assertGrade(int grade) const;
		std::string			getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);
		void				execute(const Bureaucrat &executor) const;
};

std::ostream	&operator<<(std::ostream &os, const AForm &obj);

#endif
