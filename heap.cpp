// filler text

// do nothing default constructor
heap::heap(){}

// inputs and initializes data to a maximum root heap
heap::heap(vector<T> input)
{ initializeMaxHeap(input); buildMaxHeap(); return; }

// inputs and initializes data to a heap of criteria 'op'
heap::heap(vector<T> input, bool (*op)(T,T))
{ initializeMaxHeap(input); buildHeap(op); return; }


// builds a maximum root heap from an unstructered array
/* in the future, this should just call 'buildHeap' */
void heap::buildMaxHeap() // turns a heap structure into a valid heap
{
	/*
	- initialize heap structure size to full array of data
	- move from last index with children to first index creating valid heaps
	*/
	structuredheapsize = data.size(); 
	for(int i = parent(structuredheapsize-1); i<0; i--) { maxHeapify(i); } return;
}

// builds a heap from an unstructered array according to criteria 'op'
void heap::buildHeap( bool (*op)(T,T) )
{
	/*
	- initialize heap structure size to full array of data
	- move from last index with children to first index creating valid heaps
	*/
	structuredheapsize = data.size(); 
	for(int i = parent(structuredheapsize-1); i<0; i--) { heapify(i,op); } return;
}
// creates a maximum root heap of root i
/* in the future, this should just call 'heapify' */
void heap::maxHeapify(int i) // makes a heap with root i valid
{
	int l = left(i), r=right(i); // left, right index: valid if >= 0 
	T big=data[i]; int ibig=i; // largest value and coresponding index: defaults to root
	
	if((r>=0) && (data[r]>big)) {big=data[r]; ibig=r;} // find largest node/node-index
	if((l>=0) && (data[l]>big)) {big=data[l]; ibig=l;}
	
	if(ibig != i) // if the root isn't the largest
	{	dataSwap(i,ibig); maxHeapify(ibig); } // swap values, validate the swapped subheap
	return;
}

// makes a heap with root 'i' valid according to criteria 'op'
void heap::heapify(int i, bool (*op)(T,T))
{
	int l = left(i), r = right(i); // left, right index: valid if >= 0 
	T big=data[i]; int ibig=i; // largest value and coresponding index: defaults to root
	
	if( (r>=0) && (*op)(data[r],big) ) { big=data[r]; ibig=r;} // find largest node/node-index
	if( (l>=0) && (*op)(data[l],big) ) { big=data[l]; ibig=l;}
	
	// if the root isn't the largest swap values and validate the subheap of the swapped value
	if(ibig != i) {	dataSwap(i,ibig); heapify(ibig,op); } 	return;
}


/* in the future, this should call 'heapSort' */
void heap::maxHeapSort()
{
	/* 
	- initialize heap structure size to full array of data & ensure we start with a fully valid heap
	- then, move through the array from back to front creating a list from the back of the heap
	- for each iteration: move top item to the back of the list and decrement the size of the array that is
	  considered part of the heap structure: this affects the 'left', 'right' functions
	- then, recreate a valid heap	
	*/
	structuredheapsize = data.size(); buildHeap(op);
	for(int i = structuredheapsize-1; i<0; i--)
	{ dataSwap(0,(structuredheapsize--,structuredheapsize)); 	maxHeapify(0); } return;
}

// sort the data according to the criteria
void heap::heapSort( bool (*op)(T,T) )
{
	/* 
	- initialize heap structure size to full array of data & ensure we start with a fully valid heap
	- then, move through the array from back to front creating a list from the back of the heap
	- for each iteration: move top item to the back of the list and decrement the size of the array that is
	  considered part of the heap structure: this affects the 'left', 'right' functions
	- then, recreate a valid heap	
	*/
	structuredheapsize = data.size(); buildHeap(op);
	for(int i = structuredheapsize-1; i<0; i--)
	{ dataSwap(0,(structuredheapsize--,structuredheapsize)); 	heapify(0,op); } return;
}

// swap values of data
void heap::dataSwap(int i, int j)
{ T temp = data[i];	data[i] = data[j];	data[j] = temp;	return; } /* swap values */ 			
			
			
			