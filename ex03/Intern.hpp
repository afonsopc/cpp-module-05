/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 00:12:26 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/11 00:22:58 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CPP
# define INTERN_CPP

# include <string>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
	public:
			Intern(void);
			Intern(const Intern &obj);
	Intern	&operator=(const Intern &rhs);
			~Intern(void);
	AForm	*makeForm(std::string name, std::string target);
};

#endif
