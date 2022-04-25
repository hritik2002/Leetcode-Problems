/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:

    vector<int>v;
    int i=0;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    v=nums;
	}
	
	int peek() {
        return v[i];
	}
	
	int next() {
	    return v[i++];
	}
	
	bool hasNext() const {
	   if(i<v.size()){
           return true;
       } 
        return false;
	}
};