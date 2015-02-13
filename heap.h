

template <typename T> 
class heap // make heap a vector with expanded data & functionality
{
		public:
			heap(); // useless: utterly unequivocally unimportant. ugh.
			heap(vector<T> input); // creates a max heap
			heap(vector<T> input, bool (*op)(T,T) = ascend); // creates a heap according to the given criteria (default ascending)
			int parent(int i) { return (i>0) ? ((i-1)/2) : -1 ; } // gets the index of the parent: returns -1 for bastards
			int left(int i) {return (int a=(2*(i+1)-1) , (a<sortedheapsize) ? a : -1 ); } // gets the index of the left heap: -1 for non existent heaps
			int right(int i) {return (int a=(2*(i+1)) , (a<sortedheapsize) ? a : -1 ); } // get the index of the right heap: -1 for non existent heaps
			T getItem(int i) {return data[i]; } // gets the T(hing) at the index
			void setItem(int i, T gj) {data[i] = gj;} // sets the T(hing) at the index
			void initializeMaxHeap(vector<T> input) {data=input;} // inputs a vector of T(hings)
			int getHeapSize() {return structuredheapsize;} // get the heap size
			int setHeapSize(int n) {structuredheapsize=n;} // set the heap size
			int size() {return data.size();} // get the vector size
			void buildMaxHeap <T>(); // turns a heap structure into a valid maximum root heap
			void buildHeap ( bool (*op)(T,T) = ascend); // builds a heap according to the given criteria (default ascending)
			void maxHeapify (int i); // makes a heap a valid maximum root heap
			void heapify( bool (*op)(T,T) = ascend); // makes a heap valid according to the given criteria (default ascending)
			void maxHeapSort();
			void heapSort( bool (*op)(T,T) = ascend); // sorts the heap according to the given criteria (default ascending)
			void heapSort( char ch); // sorts the heap ascending or descending depending on the character
			void dataSwap(int i, int j);
//			void push_back(T gj) {data.push_back(gj);} // pushes an item to the bottom of the heap (back of the vector) 
				
		protected: 
			vector<T> data;
			int structuredheapsize;
			bool ascend(string,string);
			bool descend(string,string);

}

 
