#include "Board.h"
#include "Hash.h"
#include <cmath>
#include <limits>

using namespace std;

int	main( int argc, char *argv[] )
{
   if ( argc != 2 )
   {
      printf("Error: you must include the hash table size as a");
      printf(" command-line parameter.\n");
      exit(0);
   }
   int size = atoi(argv[1]);

   Hash<Board> table(size);

   // Now we attempt to read in boards until "EOF" is detected
   Board	b; // used to store the boards being read
   cin >> b;
   while ( !cin.eof() )
   {
      if (!table.query(b))
         table.insert(b);

      cin >> b;
   };

   int total = 0;
   int min = std::numeric_limits<int>::max();
   int max = std::numeric_limits<int>::min();
   for (int i=0; i < table.getNumSlots(); i++) {  
      total += table.getSlotCount(i);
      if (table.getSlotCount(i) > max)
         max = table.getSlotCount(i);
      if (table.getSlotCount(i) < min)
         min = table.getSlotCount(i);
   }

   float avg = ((float)total / (float)table.getNumSlots());

   float sd = 0;
   for (int i=0; i < table.getNumSlots(); i++)
      sd += pow((float)table.getSlotCount(i) - avg, 2);
   sd = sqrt(sd / (float)table.getNumSlots());
   

   cout << "Total: " << total << endl; 
   cout << "Average: " << avg << endl; 
   cout << "standard deviation: " << sd << endl; 
   cout << "minimum: " << min << endl; 
   cout << "maximum: " << max << endl << endl;
   
   // Best Hashing performance with 50 hash table slots
   /*
   int* slotCounts = new int[size];
   for (int i = 0; i < size; ++i) 
   {
   	slotCounts[i] = table.getSlotCount(i);
   }
   for (int i = 0; i < size; ++i)
   {
   	cout << "Slot " << i << ": " << slotCounts[i] << " items" << endl;
   }
   
   
   // testing of hash class
   // assignment operator
   Hash<Board> table2(size);
   table2 = table;
   
   // query test
   cout << table2.query(b) << endl;
   
   // remove test
   table2.remove(b);
   //table2.remove(b); double remove
   cout << table2.query(b) << endl;
   //insert test
   table2.insert(b);
   cout << table2.query(b) << endl;
   
   // get slot count
   int numSlots = table2.getNumSlots();
   for (int i=0; i < numSlots/2; i++)
   	cout << table2.getSlotCount(i) << " ";
   cout << endl;
   */
   
   
   
   return 0;
}
