/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:27:42 by gulee             #+#    #+#             */
/*   Updated: 2022/12/01 15:49:01 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string GetNewName(std::string str)
{
    return str.append(".replace");
}

void Replace(std::string Line, char **argv)
{
    int end;
    std::string cut;
    std::string s2;
    std::string s1;
    std::string NewFileName;

    s2 = argv[3];
    s1 = argv[2];
    if (Line.find(s1) == std::string::npos)
    {
        std::cout << "No Search for in " << argv[1] << std::endl;
        exit(1);
    }
    while ((end = Line.find(s1)) != -1)
    {
        cut =  cut + Line.substr(0,end);
        cut = cut + s2;
        Line = Line.substr(end + s1.length(), Line.length());
    }
    cut = cut + Line;
    std::cout << "cut:  " << cut << std::endl;
    NewFileName = GetNewName(argv[1]);
    std::ofstream ofs(NewFileName, std::ofstream::out);
    ofs << cut;
    ofs.close();
}


int main(int argc, char **argv)
{
    std::string Line;
    std::string OldText;

    if (argc != 4)
    {
        std::cout << "Error in parameters <filename> <s1> <s2> plz...." << std::endl;
    }
    else
    {
        std::ifstream ifs(argv[1]);
        if (ifs.is_open())
        {
            while(std::getline(ifs,Line))
                OldText = OldText + Line + "\n";
            if (OldText.length() == 0)
            {
                std::cout << "File Empty : " << argv[1] << std::endl;
                ifs.close();
                exit(1);
            }
            OldText.resize(OldText.size() - 1);
            ifs.close();
        }
        else
        {
            std::cout << "Error for in File Name : " << argv[1] << std::endl;
            exit(0);
        }
        Replace(OldText,argv);
    }
    return 0;
}
