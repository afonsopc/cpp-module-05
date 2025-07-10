/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:45:27 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/11 00:30:35 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
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

void	testInternMakeForm() {
    std::cout << "\n=== Testing Intern makeForm ===" << std::endl;
    try {
        Intern intern;
        Bureaucrat vip("VIP", 1);
        AForm* form1 = intern.makeForm("shrubbery creation", "garden");
        if (form1) {
            std::cout << "Created form: " << *form1 << std::endl;
            vip.signForm(*form1);
            vip.executeForm(*form1);
            delete form1;
        }
        AForm* form2 = intern.makeForm("robotomy request", "Bender");
        if (form2) {
            std::cout << "Created form: " << *form2 << std::endl;
            vip.signForm(*form2);
            vip.executeForm(*form2);
            delete form2;
        }
        AForm* form3 = intern.makeForm("presidential pardon", "Arthur Dent");
        if (form3) {
            std::cout << "Created form: " << *form3 << std::endl;
            vip.signForm(*form3);
            vip.executeForm(*form3);
            delete form3;
        }
        AForm* invalidForm = intern.makeForm("invalid form", "target");
        if (!invalidForm) {
            std::cout << "Correctly returned NULL for invalid form" << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void	testInternConstructors() {
    std::cout << "\n=== Testing Intern Constructors ===" << std::endl;
    try {
        Intern intern1;
        Intern intern2(intern1);
        Intern intern3;
        intern3 = intern1;
        AForm* form1 = intern1.makeForm("shrubbery creation", "test1");
        AForm* form2 = intern2.makeForm("robotomy request", "test2");
        AForm* form3 = intern3.makeForm("presidential pardon", "test3");
        if (form1) {
            std::cout << "Intern1 created: " << form1->getName() << std::endl;
            delete form1;
        }
        if (form2) {
            std::cout << "Intern2 created: " << form2->getName() << std::endl;
            delete form2;
        }
        if (form3) {
            std::cout << "Intern3 created: " << form3->getName() << std::endl;
            delete form3;
        }
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void	testInternEdgeCases() {
    std::cout << "\n=== Testing Intern Edge Cases ===" << std::endl;
    try {
        Intern intern;
        AForm* form1 = intern.makeForm("SHRUBBERY CREATION", "test");
        if (!form1) {
            std::cout << "Case sensitivity test passed - uppercase rejected" << std::endl;
        }
        AForm* form2 = intern.makeForm("shrubbery", "test");
        if (!form2) {
            std::cout << "Partial match test passed - incomplete name rejected" << std::endl;
        }
        AForm* form3 = intern.makeForm("", "test");
        if (!form3) {
            std::cout << "Empty form name test passed" << std::endl;
        }
        AForm* form4 = intern.makeForm("shrubbery creation", "");
        if (form4) {
            std::cout << "Empty target test - form created: " << form4->getName() << std::endl;
            delete form4;
        }
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
    std::cout << "\n=== INTERN TESTING ===" << std::endl;
    testInternMakeForm();
    testInternConstructors();
    testInternEdgeCases();
    std::cout << "\n=== END OF TESTS ===" << std::endl;
}
