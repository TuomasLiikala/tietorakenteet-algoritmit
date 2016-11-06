#include "datastructure.hh"



Datastructure::Datastructure()
{
	//std::cout << "constructor" << std::endl;
}

void Datastructure::add(std::string rank, unsigned int birthYear, 
	unsigned int enlistingYear, std::string shirtColor, std::string name)
{
	people.push_back ({rank, birthYear, enlistingYear, shirtColor, 			name});
	/*if (people.size()>1)
	{
		//for (unsigned int i = 0; 
		//     i < static_cast<unsigned int>(people.size()-1); i++)
		for (unsigned int i = 
		static_cast<unsigned int>(people.size()-1); 
			i > 0 ; i--)
		{

		Person p = people[i-1];
		Person p2 = people[i];
		
		if (p.enlistingYear>p2.enlistingYear)
		{
			  people[i-1] = p2;
			  people[i] = p;
		}
		else if (p.enlistingYear==p2.enlistingYear)
		{
			if (p.birthYear>p2.birthYear)
			{
			  people[i-1]=p2;
			  people[i]=p;
			}
			else
			{
				people[i-1]=p;
		  		people[i]=p2;
			}
		}
		}	
	}*/
}

void Datastructure::find(unsigned int index)
{
        unsigned int i = index-1;
	unsigned int ui = 0;
	if (index >= ui && index
		<= static_cast<unsigned int>(people.size()))
	std::cout  << people[i].name << SEPARATOR << people[i].rank
	 << SEPARATOR << people[i].birthYear << SEPARATOR
	 << people[i].enlistingYear << SEPARATOR 
	 << people[i].shirtColor << std::endl;
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
		
		for (unsigned int i = 0; 
		     i < static_cast<unsigned int>(people.size()); i++)
		{
			if (people[i].birthYear<=yr)
			{
			  yr=people[static_cast<unsigned int>(i)].birthYear;
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
		
		for (unsigned int i  = 0; 
		     i < static_cast<unsigned int>(people.size()); i++)
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
