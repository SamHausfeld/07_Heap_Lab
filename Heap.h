#include "Queue.h"
#include <utility>

//This should be the initial arrSize
#define START_SIZE 10

/*
 * This is a priority queue, which means that as items are removed in order
 * of decreasing priority.
 *
 * 
 */
template<class Pri, class T>
class Heap : public Queue<std::pair<Pri, T> > {
public:
  Heap();
  ~Heap();

  //Add a new item
  virtual void add(std::pair<Pri,T> toAdd);

  //Remove the item with lowest priority, and return it
  //If the queue is empty, throw a string exception
  virtual std::pair<Pri,T> remove();

  //Return the number of items currently in the queue
  virtual unsigned long getNumItems();

private:
  int arrSize;
  int numItems;
  std::pair<Pri, T>* backingArray;

  //Grow the backingArray by making a new array of twice the size,
  // and copying over the data
  void grow();

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it up the "tree" of the heap until you find the right
  // place
  void bubbleUp(unsigned long index);

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it down the "tree" of the heap until you find the right
  // place
  void trickleDown(unsigned long index);  
};

// #include "Heap.ipp"
#include <string>

template<class Pri, class T>
Heap<Pri, T>::Heap(){
	arrSize = START_SIZE;
	numItems = 0;
	backingArray = new std::pair<Pri, T>[arrSize];
}

template<class Pri, class T>
Heap<Pri, T>::~Heap(){
	delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri, T>::grow(){

	// does this even?

	std::pair<Pri, T>* biggerBackingArray;
	for (int k = 0; k < numItems; k++) {
		biggerBackingArray[k] = backingArray[k%arrSize];
	}
	backingArray = biggerBackingArray;
}

template<class Pri, class T>
void Heap<Pri, T>::add(std::pair<Pri, T> toAdd){
	if (numItems + 1 > arrSize) grow();
	backingArray[numItems] = toAdd;
	bubbleUp(numItems);
	numItems++;
}

template<class Pri, class T>
void Heap<Pri, T>::bubbleUp(unsigned long index){
	if (index <= 0) return;
	int pdex = parent(index);
	if (backingArray[index].first <= backingArray[pdex].first) {
		// We include .first because we are dealing with heaps after all
		return;
		std::cout << "Bubbled up!" << std::endl;
	}
	backingArray[pdex].swap(backingArray[index]);
	bubbleUp(pdex); // Classy.

	

}

template<class Pri, class T>
void Heap<Pri, T>::trickleDown(unsigned long index){
	do{
		// Decide j.
		int j = -1;
		int rdex = right(index);
		int ldex = left(index);
		if (rdex < numItems && backingArray[index].first < backingArray[rdex].first) { // R is smaller than index.
			if (backingArray[ldex].first < backingArray[rdex].first) // L is smaller than R.
				j = ldex;
			else j = rdex;
		}else {
			if (ldex < numItems && backingArray[index].first < backingArray[ldex].first) // R is bigger than index, but L is smaller.
				j = ldex;
		}
		// Swap'em
		if (j >= 0)
			backingArray[index].swap(backingArray[j]);

	} while (index <= 0);
			
		// Is there a way to do this recursively?? I experimented a bit but kept running into roadblocks.
}


template<class Pri, class T>
std::pair<Pri, T> Heap<Pri, T>::remove(){
	std::pair<Pri, T> tmp = backingArray[0]; // store the root
	numItems--;
	backingArray[0] = backingArray[numItems]; // replace the root
	trickleDown(0); // bubble down that replacement back to where it came from
	return tmp; // return the old root
}

template<class Pri, class T>
unsigned long Heap<Pri, T>::getNumItems(){
	return numItems;
	// that's it????
}


// My extra methods...
int left(unsigned long i) {
	return (2 * i) + 1;
}

int right(unsigned long i) {
	return (2 * i) + 2;
}

int parent(unsigned long i) {
	return (i - 1) / 2;
}