#include "datastructure.hh"

Datastructure::Datastructure()
{
}

void Datastructure::add(std::string rank, unsigned int birthYear, 
  unsigned int enlistingYear, std::string shirtColor, std::string name)
{
  people.push_back ({rank, birthYear, enlistingYear, shirtColor, name});
}

void Datastructure::find(unsigned int index)
{
  unsigned int p=0;
  unsigned int q=static_cast<unsigned int>(people.size()-1);

  if (people.size()>0)
  {
    quickSort(people,p,q);

    unsigned int id = index-1;
    unsigned int ui = 0;

    if (index >= ui && index <= static_cast<unsigned int>( people.size() ))
    {
      std::cout  << people[id].name << SEPARATOR << people[id].rank
      << SEPARATOR << people[id].birthYear << SEPARATOR
      << people[id].enlistingYear << SEPARATOR 
      << people[id].shirtColor << std::endl;
    }
  }
}

size_t Datastructure::size()
{
  size_t ss = people.size();
  
  return ss;
}

void Datastructure::empty()
{
  people.clear();	
}

void Datastructure::oldest()
{
  if (people.size()>0)
  {
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
  if (people.size()>0)
  {		
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

void Datastructure::quickSort(std::vector<Person>& A, unsigned int p,
  unsigned int q)
{
  unsigned int r;
  
  if(p<q)
  {
    r=partition(A, p,q);
    quickSort(A,p,r);  
    quickSort(A,r+1,q);
  }
}


unsigned int Datastructure::partition(std::vector<Person>& A, unsigned int p,
  unsigned int q)
{
  unsigned int i=p;
  unsigned int j;

  for(j=p+1; j<q; j++)
  {
    if(A[j].enlistingYear<A[p].enlistingYear || 
      (A[j].birthYear <= A[p].birthYear && A[j].enlistingYear == 
       A[p].enlistingYear))
    {
      i=i+1;

      swap(A[i],A[j]);
    }
  }

  swap(A[i],A[p]);
  return i;
}

void Datastructure::swap(Person& x, Person& y)
{
  Person temp;
  temp = x;
  x = y;
  y = temp;
}

Datastructure::~Datastructure()
{
	people.clear();
}
