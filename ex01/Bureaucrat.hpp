/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:36:03 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/10 18:17:43 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CPP
# define BUREAUCRAT_CPP

# include "Form.hpp"
# include <string>
# include <exception>
# include <iostream>

class Form;

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;
	public:
		class Exception: public std::exception { public: virtual const char *what() const throw(); };
		class GradeTooHighException: public Exception { public: virtual const char *what() const throw(); };
		class GradeTooLowException: public Exception { public: virtual const char *what() const throw(); };

					Bureaucrat(void);
					Bureaucrat(std::string name, int grade);
					~Bureaucrat(void);
		Bureaucrat	&operator=(const Bureaucrat &rhs);
					Bureaucrat(const Bureaucrat &rhs);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		setGrade(int grade);
		int			assertGrade(int grade) const;
		void		incrementGrade(void);
		void		decrementGrade(void);
		void		signForm(Form &form);
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
