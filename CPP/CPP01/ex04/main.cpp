/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:35:48 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/17 21:35:05 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <unistd.h>

int openFiles(std::ifstream &rFile, std::ofstream &wFile, char **argv)
{
	std::string wName;

	rFile.open(argv[1]);
	if (!rFile.good())
		return (0);
	wName.append(argv[1]);
	wName.append(".replace");
	wFile.open(wName.c_str());
	if (!wFile.good())
		return (0);
	return (1);
}

void replaceInLine(std::string line, std::ofstream &wFile, std::string sed1, std::string sed2)
{
	int i = 0;
	int j;

	while (line[i] && (int)line.find(sed1, i) != -1)
	{
		j = i;
		i = (int)line.find(sed1, i);
		if (i != -1)
		{
			while (i && j != i && j < 70)
				wFile << line[j++];
		}
		wFile << sed2;
		i = j + sed1.size();
	}
	if (i < (int)line.size())
	{
		j = i;
		while (j < (int)line.size())
			wFile << line[j++];
	}
}

int strReplace(std::ifstream &rFile, std::ofstream &wFile, std::string sed1, std::string sed2)
{
	std::string line;
	
	while (!rFile.eof())
	{
		std::getline(rFile, line);
		if ((int)line.find(sed1) != -1)
			replaceInLine(line, wFile, sed1, sed2);
		else
			wFile << line;
		wFile << "\n";
	}
	wFile.close();
	rFile.close();
	return (1);
}

int main(int argc, char **argv)
{
	std::ifstream rFile;
	std::ofstream wFile;
	if (argc != 4)
	{
		std::cout << "Not enough arg" << std::endl;
		return (0);
	}
	if (!openFiles(rFile, wFile, argv))
	{
		std::cout << "Not able to locate " << argv[1] << std::endl;
		return (0);
	}
	strReplace(rFile, wFile, argv[2], argv[3]);
	return 0;
}
