#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class IntCell {
    public:
        IntCell(int initialValue=0) {
            storedValue = new int;
            *storedValue = initialValue;
        }
        IntCell(const IntCell &rhs)
        {
         storedValue=new int;
         *storedValue=*(rhs.storedValue);
        }
        IntCell &operator=(const IntCell &rhs)
        {
         *storedValue=*(rhs.storedValue);
         return *this;
        }
  		/* You may need to define copy/move constructors and assignment operators*/
        int read() {return *storedValue;}
        void write(int x) {*storedValue = x;}
    private:
        int * storedValue;
};

class Collection {
  private:
  	IntCell * arr;
    IntCell * tem;
  	int size;
    int y=0;
  	/* You may need to define more members */
  
  public:
  	// Constructor which initializes arr with size inpSize

  	Collection(int inpSize=10) : size(inpSize)
    {
        arr = new IntCell[size];
    }
    Collection(const Collection &rhs)
    {
        size=rhs.size;
        arr=new IntCell[size];
        y=rhs.y;
        for(int i=0;i<size;i++)
        {
         arr[i]=rhs.arr[i];   
        } 
    }
    Collection &operator=(const Collection &rhs)
    {
        size=rhs.size;
        arr=new IntCell[size];
        y=rhs.y;
        for(int i=0;i<size;i++)
        {
         arr[i]=rhs.arr[i];   
        }
        return *this;
    }
  	~Collection()
    {
      	delete arr;
    }
    bool isEmpty()
    {
     if(y==0) return true;
     return false;
    }
    void makeEmpty()
    {
     y=0;
    }
    void insert(const IntCell &x)
    {
     if(y<size)
     {
      arr[y]=x;  
      y++;
     }
     else
     {
      size++;
      tem=new IntCell[size];  
      for(int i=0;i<y;i++)
      {
       tem[i]=arr[i];    
      }
      tem[y]=x;
      y++;
      arr=tem;
     }
    }
    bool contains( IntCell &x)
    {
     for(int i=0;i<y;i++)
     {
      if(arr[i].read()==x.read())
      {
       return true;   
      }
     }
     return false;
    }
    void remove(IntCell &x)
    {
     for(int i=0;i<y;i++)
     {
      if(arr[i].read()==x.read())
      {
       for(int j=i;j<y-1;j++)
       {
        arr[j]=arr[j+1];   
       }
       y--;
       i--;
      }
     }
    }
    //You may need to define copy,move constructors, and copy/move assignment operators
      
    //Define public functions isEmpty, makeEmpty, insert, remove, contains
    //Use call-by-constant-reference wherever applicable.
};


/*DO NOT MAKE ANY CHANGES TO THE CODE BELOW*/

int main() {
  int N;
  cin >> N;
  Collection c;
  int command;
  for (int i = 0; i < N; i++)
  {
    cin >> command;
    switch (command)
    {
      case 1 /*"initialize"*/:
        {
            int inpSize;
            cin >> inpSize;
            Collection c2(inpSize);
            c = c2;
        }
        break;

       case 2 /*"initializeWith"*/:
       {
            int size2;
            cin >> size2;
            Collection c2(size2);
            for (int j = 0; j < size2; j++)
            {
              int elem;
              cin >> elem;
              IntCell elemCell(elem);
              c2.insert(elemCell);
            }
            Collection c3 = c2;
            c = c3;
            break;
       }
      case 3 /*"insert"*/:
        {
            int elem;
            cin >> elem;
            IntCell elemCell(elem);
            c.insert(elemCell);
            break;
        }
      case 4 /*"remove"*/:
       {
            int elem;
            cin >> elem;
            IntCell elemCell(elem);
            c.remove(elemCell);
            break;
       } 
      case 5 /*"copy"*/:
       {
            int size2;
            cin >> size2;
            Collection c2(size2);
            for (int j = 0; j < size2; j++)
            {
              int elem;
              cin >> elem;
              IntCell elemCell(elem);
              c2.insert(elemCell);
            }
            c = c2;
            break;
       }
      case 6 /*"isEmpty"*/:
      {
            if (c.isEmpty())
            cout << "Collection is empty" << endl;
            else
            cout << "Collection is not empty" << endl;
            break;
      }
      case 7 /*"makeEmpty"*/:
            c.makeEmpty();
            break;
      case 8 /*"contains"*/:
      {
            int elem;
            cin >> elem;
            IntCell elemCell(elem);
            if (c.contains(elemCell))
            cout << "Collection contains " << elem << endl;
            else
            cout << "Collection does not contain " << elem << endl;
            break;
      }
      default:
            cout << "Invalid command!" << endl;
    }
  }
  return 0;
}