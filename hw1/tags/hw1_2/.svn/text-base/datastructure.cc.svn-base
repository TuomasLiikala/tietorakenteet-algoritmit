#include "datastructure.hh"

//using namespace std;
std::vector<Person> people;

Datastructure::Datastructure()
{
	//std::cout << "constructor" << std::endl;
}

void Datastructure::add(std::string rank, unsigned int birthYear, 
	unsigned int enlistingYear, std::string shirtColor, std::string name)
{
    people.push_back ({rank, birthYear, enlistingYear, shirtColor, name});
}

void Datastructure::find(unsigned int index)
{
	unsigned int ui = 0;
	if (index >= ui && index
		< static_cast<unsigned int>(people.size()))
	std::cout  << people[index].name << SEPARATOR << people[index].rank
	 << SEPARATOR << people[index].birthYear << SEPARATOR
	 << people[index].enlistingYear << SEPARATOR 
	<< people[index].shirtColor << std::endl;
}

size_t Datastructure::size()
{
	//std::cout << "size" << std::endl;
	size_t ss = people.size();
	return ss;
}

void Datastructure::empty()
{
people.clear();	
//std::cout << "empty" << std::endl;
}

void Datastructure::oldest()
{
	if (people.size()>0){
	
		
		unsigned int index=0;
		unsigned int yr=999990;
		
		for (int i = 0; i < static_cast<int>(people.size()); i++)
		{
			if (people[i].birthYear<=yr)
			{
				yr=people[i].birthYear;
				index=i;
			}
		}
	 	std::cout  << people[index].name << SEPARATOR
		<< people[index].rank << SEPARATOR 
		<< people[index].birthYear << SEPARATOR
	 	<< people[index].enlistingYear << SEPARATOR
		<< people[index].shirtColor << std::endl;
	}
}

void Datastructure::youngest()
{
	if (people.size()>0){
	
		
		unsigned int index=0;
		unsigned int yr=0;
		
		for (int i = 0; i < static_cast<int>(people.size()); i++)
		{
			if (people[i].birthYear>=yr)
			{
				yr=people[i].birthYear;
				index=i;
			}
		}
	 	std::cout  << people[index].name << SEPARATOR
		<< people[index].rank << SEPARATOR
		<< people[index].birthYear << SEPARATOR
	 	<< people[index].enlistingYear << SEPARATOR 
		<< people[index].shirtColor << std::endl;
	}
}

Datastructure::~Datastructure()
{
	people.clear();
	//std::cout << "destructor" << std::endl;
}

/*bool Datastructure::cmp( const Person * a, const Person * b ) {
    return a->getage() < b->getage() ;
}*/
