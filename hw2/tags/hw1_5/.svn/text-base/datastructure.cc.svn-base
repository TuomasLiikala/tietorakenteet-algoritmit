#include "datastructure.hh"



Datastructure::Datastructure()
{
	sorted=0;
	//std::cout << "constructor" << std::endl;
}

void Datastructure::add(std::string rank, unsigned int birthYear, 
	unsigned int enlistingYear, std::string shirtColor, std::string name)
{
	sorted++;
	people.push_back ({rank, birthYear, enlistingYear, shirtColor, name});
}

void Datastructure::find(unsigned int index)
{

	if (sorted>0)
        {
		for (unsigned int j =
                sorted;
                        j > 0 ; j--)
                {
                	for (unsigned int i =
                	static_cast<unsigned int>(people.size()-1);
                        	i > 0 ; i--)
                	{

                		if (people[i-1].enlistingYear> people[i].enlistingYear)
                		{
					p = people[i-1];
                          		people[i-1] = people[i];
                          		people[i] = p;
                		}
                	else if (people[i-1].enlistingYear==people[i].enlistingYear)
                	{
                        	if (people[i-1].birthYear>people[i].birthYear)
                        	{
					p = people[i-1];
                          		people[i-1]=people[i];
                          		people[i]=p;
                        	}
                        	else
                        	{
                                	//people[i-1]=people[i-1];
                                	//people[i]=people[i];
                        		}
                		}
                	}
		}
        }

	sorted=0;

        unsigned int id = index-1;
	unsigned int ui = 0;
	if (index >= ui && index
		<= static_cast<unsigned int>(people.size()))
	std::cout  << people[id].name << SEPARATOR << people[id].rank
	 << SEPARATOR << people[id].birthYear << SEPARATOR
	 << people[id].enlistingYear << SEPARATOR 
	 << people[id].shirtColor << std::endl;
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
