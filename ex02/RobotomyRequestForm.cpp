/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:41:57 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/10 23:53:26 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs)
	: AForm(rhs), target(rhs.target) {}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	AForm::operator=(rhs);
	target = rhs.target;
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm(void) {}

void	RobotomyRequestForm::_execute(void) const {
	static bool	last_robotomy_successfuly;

	std::cout << "ZZZZZZZRRRRRRR - " << target << " has "
		<< (last_robotomy_successfuly ? "not " : "") << "been robotomized." << std::endl;
	last_robotomy_successfuly = !last_robotomy_successfuly;
}
