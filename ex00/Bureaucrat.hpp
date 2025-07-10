/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:36:03 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/10 14:51:02 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CPP
# define BUREAUCRAT_CPP

# include <string>
# include <exception>

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;
	public:
					Bureaucrat(void);
					Bureaucrat(std::string name, int grade);
					~Bureaucrat(void);
		Bureaucrat	&operator=(const Bureaucrat &rhs);
					Bureaucrat(const Bureaucrat &rhs);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		setGrade(int grade);
		void		incrementGrade(void);
		void		decrementGrade(void);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char	*what() const throw();
		};
};

#endif
