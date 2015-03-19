#include "XmlParser.hh"
#include "Pokemon.hh"
#include "PokemonArray.hh"

XmlParser::XmlParser(std::string file)
{
	_file.open(file.c_str());
}

XmlParser::~XmlParser()
{
	;
}

void		XmlParser::getOtherStats(PokeStats &pokeStats,unsigned int found, unsigned int end){
	const char			*tab[8]={"male", "female", "egg-group", "<egg-group",
								   "species", "height", "weight", "description"};
	for (int i=0; i < 8; ++i)
	{
		found = _buff.find(tab[i], found);
		found += std::string(tab[i]).size() + 1;
		end = _buff.find("<", found);
		if (i == 3){
			pokeStats.insert(std::pair<std::string, std::string>("egg-Type", _buff.substr(found, end - found)));
		}
		else
			pokeStats.insert(std::pair<std::string, std::string>(tab[i], _buff.substr(found, end - found)));
	}
}

PokeEvolutions		XmlParser::getEvolution(unsigned int found, unsigned int end)
{
	unsigned int		finish = _buff.find("</evolutions>", found);
	unsigned int		continueVal;
	PokeEvolutions		evol;

	found = _buff.rfind("<evolutions>", finish);
	std::string			evolutionsStr = _buff.substr(found + 13, finish - found);
	found = 0;
	end = 0;
	std::string			evolution;
	while (found < evolutionsStr.size())
	{
		found = evolutionsStr.find("<evolution id=", found);
		continueVal = found;
		if (found > evolutionsStr.size())
			break;
		PokeStats		evolstats;
		found += 15;
		end = evolutionsStr.find("'", found);
		evolstats.insert(std::pair<std::string, std::string>("id", evolutionsStr.substr(found, end - found)));
		found = evolutionsStr.find("<name>", found);
		found += 6;
		end = evolutionsStr.find("<", found);
		evolstats.insert(std::pair<std::string, std::string>("name", evolutionsStr.substr(found, end - found)));
		found = evolutionsStr.find("<lvl>", found);
		if (found > evolutionsStr.size() || found > evolutionsStr.find("</evolution>", continueVal)){
			evolstats.insert(std::pair<std::string, std::string>("level", "0"));
			evol.push_back(evolstats);
			found = continueVal + 1;
			continue;
		}
		found += 5;
		end = evolutionsStr.find("<", found);
		evolstats.insert(std::pair<std::string, std::string>("level", evolutionsStr.substr(found, end - found)));
		evol.push_back(evolstats);
	}
	return evol;
}

PokeStats	XmlParser::getStats(unsigned int &found, unsigned int &end)
{
	const char			tab[][10]={"name", "type", "ability", "exp",
								   "HP", "ATK", "DEF", "SPD", "SAT", "SDF"};
	PokeStats	mapStat;
	for (int i=0; i < 10;++i)
	{
		found = _buff.find(tab[i], found);
		found += std::string(tab[i]).size();
		end = _buff.find ("<", found);
		mapStat.insert(std::pair<std::string, std::string>(tab[i], _buff.substr(found + 1, end - found - 1)));
	}
	return mapStat;
}

PokeMoves XmlParser::getMoves(unsigned int found, unsigned int end,   unsigned int finish)
{
	PokeMoves	moves;
	finish = _buff.rfind("</move>", finish);
	while (found < finish)
	{
		std::map<std::string, std::string>	moveData;
		moveData.insert(std::pair<std::string, std::string>("type", getToken(found, end, "<move type='", "'")));
		moveData.insert(std::pair<std::string, std::string>("name", getToken(found, end, "<name>", "<")));
		moveData.insert(std::pair<std::string, std::string>("level", getToken(found, end, "<lvl>", "<")));
		moves.push_back(moveData);
		found = _buff.find("</move>", found);
	}
	return moves;
}

std::string	XmlParser::getToken(unsigned int &found, unsigned int &end,
					 const std::string &tokenBack, const std::string &tokenEnd)
{
	found = _buff.find(tokenBack, found);
	found += tokenBack.size();
	end = _buff.find(tokenEnd, found);
	return _buff.substr(found, (end - found));
}

void	XmlParser::startParser()
{
	unsigned int		found = 0;
	unsigned int		end = 0;
	std::stringstream			Ss;
	PokeStats					pokeStats;
	PokeMoves					pokeMoves;
	PokeEvolutions					pokeEvolutions;
	Ss << _file.rdbuf();
	_buff = Ss.str();
	int					id;
	unsigned int		finishIndex = _buff.rfind("</pokemon>");

	while (_buff.find("</pokemon>", end) != finishIndex)
	{
		id = std::atoi(getToken(found, end, "<pokemon id='", "'").c_str());
		pokeStats = this->getStats(found, end);
		getOtherStats(pokeStats, found, end);
		pokeEvolutions = this->getEvolution(found, end);
		pokeMoves = this->getMoves(found, end, _buff.find("</pokemon>", end));
		PokemonArray::getInstance().push_back(new Pokemon(id, pokeStats, pokeEvolutions, pokeMoves));
	}
	_file.close();
}
