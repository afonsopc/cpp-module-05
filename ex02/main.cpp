/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:45:27 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/11 00:01:28 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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

void	testOutputOperator() {
    std::cout << "\n=== Testing Output Operator << ===" << std::endl;
    try {
        Bureaucrat b1("Alice", 1);
        std::cout << "Highest grade: " << b1 << std::endl;
        Bureaucrat b2("Bob", 150);
        std::cout << "Lowest grade: " << b2 << std::endl;
        Bureaucrat b3("Charlie", 75);
        std::cout << "Middle grade: " << b3 << std::endl;
        Bureaucrat b4;
        std::cout << "Default: " << b4 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void	testShrubberyCreationForm() {
    std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
    try {
        ShrubberyCreationForm form("home");
        Bureaucrat lowBureaucrat("LowBureaucrat", 150);
        Bureaucrat midBureaucrat("MidBureaucrat", 140);
        Bureaucrat highBureaucrat("HighBureaucrat", 130);
        std::cout << "Form: " << form << std::endl;
        std::cout << "Low bureaucrat: " << lowBureaucrat << std::endl;
        std::cout << "Mid bureaucrat: " << midBureaucrat << std::endl;
        std::cout << "High bureaucrat: " << highBureaucrat << std::endl;
        std::cout << "\n--- Testing signing with insufficient grade ---" << std::endl;
        lowBureaucrat.signForm(form);
        std::cout << "\n--- Testing successful signing ---" << std::endl;
        midBureaucrat.signForm(form);
        std::cout << "After signing: " << form << std::endl;
        std::cout << "\n--- Testing execution with insufficient grade ---" << std::endl;
        midBureaucrat.executeForm(form);
        std::cout << "\n--- Testing successful execution ---" << std::endl;
        highBureaucrat.executeForm(form);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void	testRobotomyRequestForm() {
    std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
    try {
        RobotomyRequestForm form("Bender");
        Bureaucrat lowBureaucrat("LowBureaucrat", 80);
        Bureaucrat midBureaucrat("MidBureaucrat", 70);
        Bureaucrat highBureaucrat("HighBureaucrat", 40);
        std::cout << "Form: " << form << std::endl;
        std::cout << "Low bureaucrat: " << lowBureaucrat << std::endl;
        std::cout << "Mid bureaucrat: " << midBureaucrat << std::endl;
        std::cout << "High bureaucrat: " << highBureaucrat << std::endl;
        std::cout << "\n--- Testing signing with insufficient grade ---" << std::endl;
        lowBureaucrat.signForm(form);
        std::cout << "\n--- Testing successful signing ---" << std::endl;
        midBureaucrat.signForm(form);
        std::cout << "After signing: " << form << std::endl;
        std::cout << "\n--- Testing execution with insufficient grade ---" << std::endl;
        midBureaucrat.executeForm(form);
        std::cout << "\n--- Testing successful execution (multiple attempts) ---" << std::endl;
        for (int i = 0; i < 5; i++) {
            highBureaucrat.executeForm(form);
        }
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void	testPresidentialPardonForm() {
    std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
    try {
        PresidentialPardonForm form("Arthur Dent");
        Bureaucrat lowBureaucrat("LowBureaucrat", 30);
        Bureaucrat midBureaucrat("MidBureaucrat", 20);
        Bureaucrat highBureaucrat("HighBureaucrat", 1);
        std::cout << "Form: " << form << std::endl;
        std::cout << "Low bureaucrat: " << lowBureaucrat << std::endl;
        std::cout << "Mid bureaucrat: " << midBureaucrat << std::endl;
        std::cout << "High bureaucrat: " << highBureaucrat << std::endl;
        std::cout << "\n--- Testing signing with insufficient grade ---" << std::endl;
        lowBureaucrat.signForm(form);
        std::cout << "\n--- Testing successful signing ---" << std::endl;
        midBureaucrat.signForm(form);
        std::cout << "After signing: " << form << std::endl;
        std::cout << "\n--- Testing execution with insufficient grade ---" << std::endl;
        midBureaucrat.executeForm(form);
        std::cout << "\n--- Testing successful execution ---" << std::endl;
        highBureaucrat.executeForm(form);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void	testFormExecution() {
    std::cout << "\n=== Testing Form Execution Edge Cases ===" << std::endl;
    try {
        ShrubberyCreationForm form("test");
        Bureaucrat executor("Executor", 130);
        std::cout << "Form: " << form << std::endl;
        std::cout << "Executor: " << executor << std::endl;
        std::cout << "\n--- Testing execution of unsigned form ---" << std::endl;
        executor.executeForm(form);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        RobotomyRequestForm form2("Robot");
        Bureaucrat signer("Signer", 50);
        Bureaucrat weakExecutor("WeakExecutor", 50);
        signer.signForm(form2);
        std::cout << "\nSigned form: " << form2 << std::endl;
        std::cout << "\n--- Testing execution with insufficient grade ---" << std::endl;
        weakExecutor.executeForm(form2);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void	testFormPolymorphism() {
    std::cout << "\n=== Testing Form Polymorphism ===" << std::endl;
    try {
        Bureaucrat vip("VIP", 1);
        AForm* forms[] = {
            new ShrubberyCreationForm("garden"),
            new RobotomyRequestForm("C-3PO"),
            new PresidentialPardonForm("Ford Prefect")
        };
        for (int i = 0; i < 3; i++) {
            std::cout << "\n--- Testing form " << i + 1 << " ---" << std::endl;
            std::cout << "Form: " << *forms[i] << std::endl;
            vip.signForm(*forms[i]);
            vip.executeForm(*forms[i]);
        }
        for (int i = 0; i < 3; i++) {
            delete forms[i];
        }
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void	testFormCopyAssignment() {
    std::cout << "\n=== Testing Form Copy and Assignment ===" << std::endl;
    try {
        ShrubberyCreationForm original("original");
        Bureaucrat signer("Signer", 140);
        signer.signForm(original);
        std::cout << "Original signed form: " << original << std::endl;
        ShrubberyCreationForm copy(original);
        std::cout << "Copied form: " << copy << std::endl;
        ShrubberyCreationForm assigned("temp");
        assigned = original;
        std::cout << "Assigned form: " << assigned << std::endl;
        Bureaucrat executor("Executor", 130);
        std::cout << "\n--- Executing original ---" << std::endl;
        executor.executeForm(original);
        std::cout << "\n--- Executing copy ---" << std::endl;
        executor.executeForm(copy);
        std::cout << "\n--- Executing assigned ---" << std::endl;
        executor.executeForm(assigned);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
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
    testOutputOperator();
    std::cout << "\n=== CONCRETE FORMS TESTING ===" << std::endl;
    testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
    testFormExecution();
    testFormPolymorphism();
    testFormCopyAssignment();
    std::cout << "\n=== END OF TESTS ===" << std::endl;
}
