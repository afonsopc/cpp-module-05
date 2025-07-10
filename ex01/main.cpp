/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:45:27 by afpachec          #+#    #+#             */
/*   Updated: 2025/07/10 18:53:19 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
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

void	testFormConstructors() {
    std::cout << "\n=== Testing Form Constructors ===" << std::endl;
    try {
        Form f1;
        std::cout << "Default form: " << f1 << std::endl;
        Form f2("Contract", 25, 5);
        std::cout << "Valid form: " << f2 << std::endl;
        Form f3(f2);
        std::cout << "Copy form: " << f3 << std::endl;
        Form f4("Assignment", 50, 10);
        std::cout << "Before assignment: " << f4 << std::endl;
        f4 = f2;
        std::cout << "After assignment: " << f4 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void	testFormInvalidGrades() {
    std::cout << "\n=== Testing Form Invalid Grades ===" << std::endl;
    try {
        Form f1("InvalidHigh", 0, 50);
        std::cout << "This shouldn't print: " << f1 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Grade to sign 0 - Exception caught: " << e.what() << std::endl;
    }
    try {
        Form f2("InvalidLow", 151, 50);
        std::cout << "This shouldn't print: " << f2 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Grade to sign 151 - Exception caught: " << e.what() << std::endl;
    }
    try {
        Form f3("InvalidExecute", 50, 0);
        std::cout << "This shouldn't print: " << f3 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Grade to execute 0 - Exception caught: " << e.what() << std::endl;
    }
    try {
        Form f4("InvalidExecute2", 50, 151);
        std::cout << "This shouldn't print: " << f4 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Grade to execute 151 - Exception caught: " << e.what() << std::endl;
    }
}

void	testFormSigning() {
    std::cout << "\n=== Testing Form Signing ===" << std::endl;
    try {
        Form form("TestForm", 50, 25);
        Bureaucrat highRank("HighRank", 30);
        Bureaucrat lowRank("LowRank", 60);
        std::cout << "Initial form: " << form << std::endl;
        std::cout << "High rank bureaucrat: " << highRank << std::endl;
        std::cout << "Low rank bureaucrat: " << lowRank << std::endl;
        form.beSigned(highRank);
        std::cout << "After signing by high rank: " << form << std::endl;
        Form form2("TestForm2", 50, 25);
        form2.beSigned(lowRank);
        std::cout << "This shouldn't print" << std::endl;
    } catch (std::exception &e) {
        std::cout << "Low rank signing - Exception caught: " << e.what() << std::endl;
    }
}

void	testFormAlreadySigned() {
    std::cout << "\n=== Testing Form Already Signed ===" << std::endl;
    try {
        Form form("AlreadySignedTest", 50, 25);
        Bureaucrat bureaucrat("TestBureaucrat", 30);
        std::cout << "Initial form: " << form << std::endl;
        form.beSigned(bureaucrat);
        std::cout << "After first signing: " << form << std::endl;
        form.beSigned(bureaucrat);
        std::cout << "This shouldn't print" << std::endl;
    } catch (std::exception &e) {
        std::cout << "Already signed - Exception caught: " << e.what() << std::endl;
    }
}

void	testBureaucratSignForm() {
    std::cout << "\n=== Testing Bureaucrat signForm Method ===" << std::endl;
    try {
        Form form1("Contract1", 50, 25);
        Form form2("Contract2", 20, 10);
        Bureaucrat bureaucrat("TestBureaucrat", 30);
        std::cout << "Bureaucrat: " << bureaucrat << std::endl;
        std::cout << "Form1: " << form1 << std::endl;
        std::cout << "Form2: " << form2 << std::endl;
        bureaucrat.signForm(form1);
        std::cout << "After signing form1: " << form1 << std::endl;
        bureaucrat.signForm(form2);
        std::cout << "Form2 after failed signing: " << form2 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void	testFormGetters() {
    std::cout << "\n=== Testing Form Getters ===" << std::endl;
    try {
        Form form("TestForm", 75, 25);
        Bureaucrat bureaucrat("TestBureaucrat", 50);
        std::cout << "Form name: " << form.getName() << std::endl;
        std::cout << "Grade to sign: " << form.getGradeToSign() << std::endl;
        std::cout << "Grade to execute: " << form.getGradeToExecute() << std::endl;
        std::cout << "Is signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
        form.beSigned(bureaucrat);
        std::cout << "After signing - Is signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void	testFormEdgeCases() {
    std::cout << "\n=== Testing Form Edge Cases ===" << std::endl;
    try {
        Form form1("BoundaryForm", 1, 150);
        std::cout << "Boundary form: " << form1 << std::endl;
        Bureaucrat topBureaucrat("TopBureaucrat", 1);
        Bureaucrat bottomBureaucrat("BottomBureaucrat", 150);
        form1.beSigned(topBureaucrat);
        std::cout << "After signing with top bureaucrat: " << form1 << std::endl;
        Form form2("ExactMatch", 100, 50);
        Bureaucrat exactBureaucrat("ExactBureaucrat", 100);
        form2.beSigned(exactBureaucrat);
        std::cout << "Exact grade match form: " << form2 << std::endl;
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
    std::cout << "\n=== FORM TESTING ===" << std::endl;
    testFormConstructors();
    testFormInvalidGrades();
    testFormSigning();
    testFormAlreadySigned();
    testBureaucratSignForm();
    testFormGetters();
    testFormEdgeCases();
    std::cout << "\n=== END OF TESTS ===" << std::endl;
}
