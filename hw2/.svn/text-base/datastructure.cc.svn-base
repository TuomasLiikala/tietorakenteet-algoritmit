//This is the file where you will implement the datastructure. main.cc
//and interface for datastructure.hh will be found from julkinen/hw<X>,
//and they should be copied in this directory.

#include "datastructure.hh"

Datastructure::Datastructure()
{
  root = NULL;
}

bool Datastructure::treeInsert(TreeNode *&root2, std::string& newItem) 
{
  if ( root2 == NULL )
  {
    root2 = new TreeNode( newItem );
    return true;
  }
  else if ( newItem == root2->word && root2->count == 0 )
  {
    root2->count=1;
    return true;
  }
  else if ( newItem == root2->word && root2->count > 0 )
    {
      //root2->count=1;
      return false;
    }
  else if ( newItem < root2->word )
  {
    if ( treeInsert( root2->left, newItem ) == false )
    {
      return false;
    }
  }
  else
  {
    if ( treeInsert( root2->right, newItem ) == false )
    {
      return false;
    }
  }
  return true;
}

bool Datastructure::add(std::string &word)
{
  return treeInsert(root,word);
}

bool treeContains( TreeNode *root2, std::string word )
{   
  if ( root2 == NULL ) 
  {	
     return false;
  } 
  else if ( word == root2->word ) 
  {	
     return true;
  }
  else if ( word < root2->word ) 
  {	
     return treeContains( root2->left, word );
  }
  else 
  {	
     return treeContains( root2->right, word );
  } 
}

bool treeRemove(TreeNode *root2, std::string newItem) 
{
  if ( root2 == NULL )
  {	
    return false;
  }
  else if ( newItem == root2->word )
  {
    if (root2->count>0)
    {    
      root2->count=0;

      return true;
    }
    else return false;
  }
  else if ( newItem < root2->word )
  {
    return treeRemove( root2->left, newItem );
  }
  else if (newItem >= root2->word )
  {
    return treeRemove( root2->right, newItem );
  }
  return false;
}

bool Datastructure::remove(std::string& word)
{
  if ( root == NULL )
  {	
    return false;
  } 
  else if ( word == root->word )
  {
    if (root->count>0)
    {   
      root->count=0;	     
      return true;
    }
    else
    {
      return false;
    }
     
  } 
  else if ( word < root->word )
  {	
    return treeRemove( root->left, word );
  } 
  else
  {	
    return treeRemove( root->right, word );
  }   
}

bool Datastructure::search(std::string& word)
{
  if ( root == NULL )
  {
    return false;
  }
  else if ( word == root->word )
  {
    return true;
  }
  else if ( word < root->word )
  {
    return treeContains( root->left, word );
  }
  else
  {
    return treeContains( root->right, word );
  }
}

bool treeList(TreeNode *node2)
{   
  bool printed = false; 
  if ( node2 != NULL ) 
  {
     treeList(node2->left);
     if ( node2->count>0 )
     {
       std::cout << node2->word << " ";
       if ( printed == false )
       {
         printed = true;
       }
     }
     treeList( node2->right );
  } 
  return printed;
}

void Datastructure::print()
{
  if( treeList(root) )
  {
    std::cout << std::endl;
  }
}

unsigned int countNodes(TreeNode *node2) 
{
  if ( node2 == NULL )
  {
    return 0;
  }
  else
  {
    unsigned int leftCount = countNodes( node2->left );
    unsigned int rightCount = countNodes( node2->right );
    return  node2->count + leftCount + rightCount;  
  }
}

unsigned int Datastructure::amountOfWords()
{     
  if ( root == NULL )
  {
    return 0;
  }
  else 
  {
    unsigned int leftCount = countNodes( root->left );
    unsigned int rightCount = countNodes( root->right );
    return root->count + leftCount + rightCount;  
  }
}

void freeNodes(TreeNode *node2)
{   
  if ( node2 == NULL ) 
  {
    return;	
  }
  else 
  {	
    freeNodes( node2->left );
    freeNodes( node2->right );
	
    delete node2;
    node2=nullptr;
  }   
}

void Datastructure::empty()
{
  freeNodes(root);
  
  root = NULL;
}

Datastructure::~Datastructure()
{
  empty();
}
