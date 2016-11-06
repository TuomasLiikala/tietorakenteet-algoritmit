// Definition of Datastructure class for UDS/Tiraka homework 1 -

#ifndef DATASTRUCTURE_HH
#define DATASTRUCTURE_HH

#include <string>
#include <vector>
#include <iostream>

const char SEPARATOR = ' ';
const std::string MSG_EMPTY_DS = "Data structure is empty.\n";

// the one (Hero)
struct Person
{
  std::string rank;
  unsigned int birthYear;
  unsigned int enlistingYear;
  std::string shirtColor;
  std::string name;
};

class Datastructure {

public:

  Datastructure();
   
  ~Datastructure();
   
   // Adds one value to the datastructure
  void add(std::string rank, unsigned int birthYear, 
    unsigned int enlistingYear, std::string shirtColor, std::string name);
   
  // Finds and prints person with index
  void find(unsigned int index);
   
  // Finds and prints youngest person
  void youngest();
   
  // Finds and prints oldest person
  void oldest();// Definition of Datastructure class for UDS/Tiraka homework 1 -

#ifndef DATASTRUCTURE_HH
#define DATASTRUCTURE_HH

#include <string>
#include <vector>
#include <iostream>

const char SEPARATOR = ' ';
const std::string MSG_EMPTY_DS = "Data structure is empty.\n";

// the one (Hero)
struct Person
{
  std::string rank;
  unsigned int birthYear;
  unsigned int enlistingYear;
  std::string shirtColor;
  std::string name;
};

class Datastructure {

public:

  Datastructure();
   
  ~Datastructure();
   
   // Adds one value to the datastructure
  void add(std::string rank, unsigned int birthYear, 
    unsigned int enlistingYear, std::string shirtColor, std::string name);
   
  // Finds and prints person with index
  void find(unsigned int index);
   
  // Finds and prints youngest person
  void youngest();
   
  // Finds and prints oldest person
  void oldest();
   
  // Empties the datastructure
  void empty();
   
  // returns the size of the datastructure
  size_t size();

private:
  // our honored heroics
  Person person;

  // pass unneeded sorts, true : doesent find from empty
  unsigned bool optimization = true;
  
  // key vector for this datastructure, very used
  std::vector<Person> people;
  
  // Copy constructor is forbidden
  Datastructure(const Datastructure&);
  
  // Assignment operator is forbidden
  Datastructure& operator=(const Datastructure&);
   
  // sorting algoithm
  void quickSort(std::vector<Person>&, unsigned int, unsigned int);
  
  // partitates vector half
  unsigned int partition(std::vector<Person>&, unsigned int, unsigned int);
   
  // swaping two Persons together
  void swap(Person& x, Person& y);
};

#endif

   
  // Empties the datastructure
  void empty();
   
  // returns the size of the datastructure
  size_t size();

private:
  // our honored heroics
  Person person;
  
  // key vector for this datastructure, very used
  std::vector<Person> people;
  
  // Copy constructor is forbidden
  Datastructure(const Datastructure&);
  
  // Assignment operator is forbidden
  Datastructure& operator=(const Datastructure&);
   
  // sorting algoithm
  void quickSort(std::vector<Person>&, unsigned int, unsigned int);
  
  // partitates vector half
  unsigned int partition(std::vector<Person>&, unsigned int, unsigned int);
   
  // swaping two Persons together
  void swap(Person& x, Person& y);
};

#endif

