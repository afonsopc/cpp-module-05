/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:41:57 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/11 00:11:16 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const char	*ShrubberyCreationForm::Exception::what() const throw() { return ("ShrubberyCreationForm Exception"); }
const char	*ShrubberyCreationForm::FileOpenException::what() const throw() { return ("File open exception"); }

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), target("default_target") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
	: AForm(rhs), target(rhs.target) {}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	AForm::operator=(rhs);
	target = rhs.target;
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

static void	write_tree(std::ofstream &ofs) {
	ofs << "       _-_" << std::endl;
	ofs << "    /~~   ~~\\" << std::endl;
	ofs << " /~~         ~~\\" << std::endl;
	ofs << "{               }" << std::endl;
	ofs << " \\  _-     -_  /" << std::endl;
	ofs << "   ~  \\ //    ~" << std::endl;
	ofs << "       | |" << std::endl;
	ofs << "       | |" << std::endl;
	ofs << "       / \\" << std::endl;
}

void	ShrubberyCreationForm::_execute(void) const {
	std::ofstream	file(target + "_shrubbery");
	if (!file.is_open())
		throw (FileOpenException());
	for (int i = 0; i < 5; ++i) {
		write_tree(file);
		file << std::endl;
	}
	file.close();
}
