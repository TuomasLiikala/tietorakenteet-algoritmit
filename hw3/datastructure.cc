// Tuomas Liikala 240493

#include "datastructure.hh"


Datastructure::Datastructure()
{

}

bool Datastructure::add(Gender gender, std::string& name, int ID, int born, 
	     int died)
{
    for (Mymap::iterator it = c1.begin(); it != c1.end(); ++it)
      if (it->first==ID)
        return false;

  Person temp_person = {
    ID,
    gender,
    name,
    born,
    died,
    std::vector<Person*>(), //motherfather_temp,
    std::vector<Person*>(), //partners_temp,
    std::vector<Person*>(), //children_temp,
  };

  c1.insert(Mymap::value_type(ID, temp_person));

  return true;
}

void Datastructure::remove()
{

}

//Adds ID1 and ID2 as partners
bool Datastructure::addPartner(int ID1, int ID2)
{
  //Mymap::iterator partner1 = c1.find(ID1);
  for (Mymap::iterator it = c1.begin(); it != c1.end(); ++it)
    if (it->first==ID1)
      PartnerFirst = &it->second;
    else if (it->first==ID2)
      PartnerSecond = &it->second;

  if (!((*PartnerFirst).ID >= 0 && (*PartnerSecond).ID >= 0))
  {
    return false;
  }

 for (Mymap::iterator it = c1.begin(); it != c1.end(); ++it)
  {
    if (it->first==ID1)
    {
      (it->second).partners.push_back(PartnerSecond);
    }
    else if (it->first==ID2)
    {
      (it->second).partners.push_back(PartnerFirst);
    }
  }

  return true;
}

//Adds a child to the given people
bool Datastructure::addChild(int IDChild, int IDwoman, int IDman)
{

  for (Mymap::iterator it = c1.begin(); it != c1.end(); ++it)
  {
    if (it->first==IDman)
      Father = &it->second;
    else if (it->first==IDwoman)
      Mother = &it->second;
    else if (it->first==IDChild)
      Child = &it->second;
  }

  if (!((*Father).ID >= 0 && (*Mother).ID >= 0 && (*Child).ID >= 0 ))
  {
    return false;
  }
  
  for (Mymap::iterator it = c1.begin(); it != c1.end(); ++it)
  {
    if (it->first==IDman)
    {
      (it->second).children.push_back(Child);
    }
    else if (it->first==IDwoman)
    {
      (it->second).children.push_back(Child);
    }
    else if (it->first==IDChild)
    {
      (it->second).parents.push_back(Father);
      (it->second).parents.push_back(Mother);
    }
  }

  return true;
}

bool parent(Person *person, Person *person2)
{

  if (! (*person2).parents.size() > 0 )
  {
    return false;
  }
  else 
  {
    bool left = parent( person, (*person2).parents.at(0) );
    bool right = parent( person, (*person2).parents.at(1) );

    if (left == true || right == true ||
	(*person2).parents.at(0)->ID == (*person).ID ||
        (*person2).parents.at(1)->ID == (*person).ID)
    {
      return true;
    }
    else return false;
  }
}

std::vector<int> rootParent (Person *person, std::vector<int> roots)
{

  if ((*person).parents.size() != 2 )
  {
    roots.push_back((*person).ID);
    
    //return roots;
  }
  else if (((person))==person->parents.at(0) ||
   (((person))==person->parents.at(1)))
    {
      return roots;
    }
  else
  {
    if(((person))!=person->parents.at(0))
    {
      std::vector<int> roots1 = 
        rootParent( (*person).parents.at(0), roots );
      roots.reserve(roots.size() + roots1.size());
      roots.insert(roots.end(), roots1.begin(), roots1.end());
    }

    if(((person))!=person->parents.at(1))
    {
      std::vector<int> roots2 =
        rootParent( (*person).parents.at(1), roots );
      roots.reserve(roots.size() + roots2.size());
      roots.insert(roots.end(), roots2.begin(), roots2.end());
    }
  }
   
  return roots;
}

//Checks if the two people are related
Relation Datastructure::relation(int ID1, int ID2)
{
  for (Mymap::iterator it = c1.begin(); it != c1.end(); ++it)
    if (it->first==ID1)
      *PartnerFirst = it->second;
    else if (it->first==ID2)
      *PartnerSecond = it->second;

  if ((!((*PartnerFirst).ID >= 0)) || (!((*PartnerSecond).ID >= 0)))
  {
    return INVALID_ID;
  }

  std::vector<int> roots1;
  std::vector<int> roots2;

  roots1 = rootParent(PartnerFirst,roots1);
  roots2 = rootParent(PartnerSecond,roots2);

  for(std::vector<Person>::size_type i = 0; i != roots1.size(); i++) {
     for(std::vector<Person>::size_type j = 0; j != roots2.size(); j++) {
       if ( roots1[i] == roots2[j] ) return RELATED;
     }
  }

  return NOT_RELATED;
}

void Datastructure::print(Person *TreePerson, int tabs)
{
  //std::cout << "a" << std::endl;
  for (int i=0; i<tabs;i++)
  {
    std::cout << "    ";
  }

  //std::cout << "b" << std::endl;
  std::cout << (*TreePerson).name << " " << (*TreePerson).born << " - ";
  if ((*TreePerson).dead>(*TreePerson).born)
  {
    std::cout << (*TreePerson).dead;
  }

  std::cout << std::endl;


  //std::cout << "c" << std::endl;
  for(std::vector<Person>::size_type i = 0;
    i != (*TreePerson).partners.size(); i++)
  {
    //std::cout << i << std::endl;
    for (int j=0; j<tabs;j++)
    {
      std::cout << "    ";
    }
    std::cout << "& " << (*TreePerson).partners.at(i)->name << " "
      << (*TreePerson).partners.at(i)->born << " - ";
    if ((*TreePerson).partners.at(i)->dead>(*TreePerson).partners.at(i)->born)
    {
      std::cout << (*TreePerson).partners.at(i)->dead;
    }

    std::cout << std::endl;

 
    for(std::vector<Person>::size_type j = 0;
      j != (*TreePerson).children.size(); j++)
    {
      //std::cout << j << std::endl;
       //std::cout << (*TreePerson).children.at(j)->ID << std::endl;
      for (Mymap::iterator it = c1.begin(); it != c1.end(); ++it)
      {
        //std::cout << (*TreePerson).children.size() << " " << j << std::endl;
        if (it->first==(*TreePerson).children.at(j)->ID &&
	    (it->second.parents.at(0)->ID==(*TreePerson).partners.at(i)->ID ||
             it->second.parents.at(1)->ID==(*TreePerson).partners.at(i)->ID))
        {
	  //	  std::cout << tabs << std::endl;
          print(&(it->second),tabs+1);
	  //print((*TreePerson).children.at(j),tabs+1);
	}
      }
    }
  }
}

//Prints the family tree
void Datastructure::print(int ID)
{

  //Person *TreePerson = new Person;

  for (Mymap::iterator it = c1.begin(); it != c1.end(); ++it)
  {
    if (it->first==ID)
    {
      std::cout << std::endl;
      print(&(it->second), 0);
    }
  }
}

Datastructure::~Datastructure()
{
  PartnerFirst=NULL;
  delete PartnerFirst;
  PartnerSecond=NULL;
  delete PartnerSecond;
  Father = NULL;
  delete Father;
  Mother = NULL;
  delete Mother;
  Child = NULL;
  delete Child;
  //empty();
}
