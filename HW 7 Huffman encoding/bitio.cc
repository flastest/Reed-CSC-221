#include "huffman.hh"
#include "hforest.cc"
#include "bitio.hh"
#include <cassert>


BitIO::BitIO(std::ostream* os, std::istream* is) 
	: os_(os),is_(is) {
	assert(!((os && is) || (!os && !is)));
	

	index = 0;
	buddy = '\0';
}



BitIO::~BitIO(){
	//buddy<<(8-index);
	int i = index;
	if(is_) {
		while(i<7){
			input_bit();
			i++;
		}
	}
	if(os_){
		while(i<7){
			output_bit(0);
			i++;
		}
	}
}

//writes bool to index-th place in char, then puts char in output when index is 8
void BitIO::output_bit(bool bit) {
	std::cout<<"buddy is "<<(int) buddy<<"\n";
	std::cout<<"output bit's input is "<<bit<<"\n";
	if(bit){
		buddy|=0x1;
	}
	//move to next bit
	buddy=buddy<<1;
	std::cout<<"buddy is "<<(int) buddy<<"\n";
	index++;
	if(index ==7) {
		*os_<<buddy;
		index = 0;
		buddy = '\0';
		
	}
}

//returns index-th bit from byte
bool BitIO::input_bit() {
	std::cout<<"buddy is "<<(int) buddy<<"\n";
	//get next byte if we're at the beginning of a 8bit sequence
	if(index == 0){
		*is_>>buddy;
	}
	//get ready to save current bit
	bool ans;
	//copy buddy to temp thing, which is the current byte shifted so that 
	// the last bit is the index-th bit of buddy
	char curByteShifted = buddy;
	curByteShifted>>(8-index);
	ans = curByteShifted & 0x1;
	index++;
	//reset if we're at the end of the byte
	if (index==7){
		index=0;
	}
	return ans;
}




