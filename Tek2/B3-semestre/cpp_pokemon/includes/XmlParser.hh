#ifndef XMLPARSER_HH_
# define XMLPARSER_HH_

#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Pokemon.hh"

class	XmlParser
{
public:
	XmlParser(std::string file = "");
	~XmlParser();
	void		startParser();
private:
	std::ifstream	_file;
    PokeStats	getStats( unsigned int&, unsigned int&);
    PokeMoves	getMoves( unsigned int found, unsigned int end,  unsigned int finish);
	PokeEvolutions		getEvolution(unsigned int , unsigned int );
	void		getOtherStats(PokeStats &,unsigned int , unsigned int);
	std::string	getToken(unsigned int &, unsigned int &, const std::string &, const std::string &);
	std::string	_buff;
};

#endif
