/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:02:06 by gulee             #+#    #+#             */
/*   Updated: 2022/12/20 19:09:39 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form("default", 145, 137)
{
	std::cout << GREEN << "Default ShrubberyCreationForm Create." << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
	: Form(name, 145, 137)
{
	std::cout << GREEN << this->getName() << " : ShrubberyCreationForm Create." << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
	: Form(ref.getName(), ref.getSignGrade(), ref.getExecGrade())
{
	std::cout << BLUE << this->getName() << " : ShrubberyCreationForm Copy Create." << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	if (this != &ref)
	{
		*this = ref;
		std::cout << BLUE << this->getName() << ": ShrubberyCreationForm Insert Finish." << RESET << std::endl;
		return *this;
	}
	else
	{
		std::cout << BACK_RED << "Error: ShrubberyCreationForm Insert Type Error! FAIL!!!!!!!!!." << RESET << std::endl;
		return *this;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << RED << this->getName() << " : ShrubberyCreationForm Delete." << RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getExecGrade() < executor.getGrade())
		throw GradeTooLowException();
  if (this->getSigned() != true)
		throw IsNotSignException();
	std::cout << BLUE << "ShrubberyCreationForm execute create." << RESET << std::endl;

    std::ofstream file(executor.getName() + "_shrubbery");

    file << " \n";
    file << "                                                         .\n";
    file << "                                              .         ;\n";
    file << "                 .              .              ;%     ;;   \n";
    file << "                   ,           ,                :;%  %; \n";
    file << "                    :         ;                   :;%;'     .,\n";
    file << "           ,.        %;     %;            ;        %;'    ,;\n";
    file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
    file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
    file << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
    file << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
    file << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
    file << "                    `:%;.  :;bd%;          %;@%;'\n";
    file << "                      `@%:.  :;%.         ;@@%;' \n";
    file << "                        `@%.  `;@%.      ;@@%;    \n";
    file << "                          `@%%. `@%%    ;@@%;   \n";
    file << "                            ;@%. :@%%  %@@%; \n";
    file << "                              %@bd%%%bd%%:;  \n";
    file << "                                #@%%%%%:;;\n";
    file << "                                %@@%%%::;\n";
    file << "                                %@@@%(o);  . '     \n";
    file << "                                %@@@o%;:(.,'       \n";
    file << "                            `.. %@@@o%::;         \n";
    file << "                               `)@@@o%::;       \n";
    file << "                                %@@(o)::;       \n";
    file << "                               .%@@@@%::;         \n";
    file << "                               ;%@@@@%::;.        \n";
    file << "                              ;%@@@@%%:;;;. \n";
    file << "                          ...;%@@@@@%%:;;;;,..   \n";
    file << " \n";

    file.close();
}
