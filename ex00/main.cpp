/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:45:27 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/10 14:53:33 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void	testConstructors() {
	std::cout << "\n=== Testing Constructors ===" << std::endl;
	try {
		Bureaucrat b1;
		std::cout << "Default: " << b1.getName() << ", grade " << b1.getGrade() << std::endl;
		Bureaucrat b2("Alice", 75);
		std::cout << "Valid: " << b2.getName() << ", grade " << b2.getGrade() << std::endl;
		Bureaucrat b3(b2);
		std::cout << "Copy: " << b3.getName() << ", grade " << b3.getGrade() << std::endl;
		Bureaucrat b4("Bob", 100);
		std::cout << "Before assignment: " << b4.getName() << ", grade " << b4.getGrade() << std::endl;
		b4 = b2;
		std::cout << "After assignment: " << b4.getName() << ", grade " << b4.getGrade() << std::endl;
		
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void	testValidGrades() {
	std::cout << "\n=== Testing Valid Grades ===" << std::endl;
	try {
		Bureaucrat b1("HighRank", 1);
		std::cout << "Highest grade: " << b1.getName() << ", grade " << b1.getGrade() << std::endl;
		Bureaucrat b2("LowRank", 150);
		std::cout << "Lowest grade: " << b2.getName() << ", grade " << b2.getGrade() << std::endl;
		Bureaucrat b3("MiddleRank", 75);
		std::cout << "Middle grade: " << b3.getName() << ", grade " << b3.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void	testInvalidGrades() {
	std::cout << "\n=== Testing Invalid Grades ===" << std::endl;
	try {
		Bureaucrat b1("TooHigh", 0);
		std::cout << "This shouldn't print: " << b1.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Grade 0 - Exception caught: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b2("TooHigh2", -5);
		std::cout << "This shouldn't print: " << b2.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Grade -5 - Exception caught: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b3("TooLow", 151);
		std::cout << "This shouldn't print: " << b3.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Grade 151 - Exception caught: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b4("TooLow2", 200);
		std::cout << "This shouldn't print: " << b4.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Grade 200 - Exception caught: " << e.what() << std::endl;
	}
}

void	testIncrementDecrement() {
	std::cout << "\n=== Testing Increment/Decrement ===" << std::endl;
	try {
		Bureaucrat b("TestEmployee", 75);
		std::cout << "Initial: " << b.getName() << ", grade " << b.getGrade() << std::endl;
		b.incrementGrade();
		std::cout << "After increment: " << b.getName() << ", grade " << b.getGrade() << std::endl;
		b.decrementGrade();
		std::cout << "After decrement: " << b.getName() << ", grade " << b.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void	testBoundaryIncrement() {
	std::cout << "\n=== Testing Boundary Increment ===" << std::endl;
	try {
		Bureaucrat b("TopBureaucrat", 1);
		std::cout << "Before increment: " << b.getName() << ", grade " << b.getGrade() << std::endl;
		b.incrementGrade();
		std::cout << "This shouldn't print" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Increment at grade 1 - Exception caught: " << e.what() << std::endl;
	}
}

void	testBoundaryDecrement() {
	std::cout << "\n=== Testing Boundary Decrement ===" << std::endl;
	try {
		Bureaucrat b("BottomBureaucrat", 150);
		std::cout << "Before decrement: " << b.getName() << ", grade " << b.getGrade() << std::endl;
		b.decrementGrade();
		std::cout << "This shouldn't print" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Decrement at grade 150 - Exception caught: " << e.what() << std::endl;
	}
}

void	testSetGrade() {
	std::cout << "\n=== Testing SetGrade ===" << std::endl;
	try {
		Bureaucrat b("TestBureaucrat", 50);
		std::cout << "Initial: " << b.getName() << ", grade " << b.getGrade() << std::endl;
		b.setGrade(25);
		std::cout << "Set to 25: " << b.getName() << ", grade " << b.getGrade() << std::endl;
		b.setGrade(0);
		std::cout << "This shouldn't print" << std::endl;
	} catch (std::exception &e) {
		std::cout << "SetGrade(0) - Exception caught: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b2("TestBureaucrat2", 50);
		b2.setGrade(151);
		std::cout << "This shouldn't print" << std::endl;
	} catch (std::exception &e) {
		std::cout << "SetGrade(151) - Exception caught: " << e.what() << std::endl;
	}
}

int	main() {
	std::cout << "=== BUREAUCRAT TESTING ===" << std::endl;
	testConstructors();
	testValidGrades();
	testInvalidGrades();
	testIncrementDecrement();
	testBoundaryIncrement();
	testBoundaryDecrement();
	testSetGrade();
	std::cout << "\n=== END OF TESTS ===" << std::endl;
}
