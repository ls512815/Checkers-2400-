#include <iostream>
#ifndef SPACE_H
#define SPACE_H

namespace main_savitch_14 {

class space 
{
	public:
		space()
		{	
			empty = true; 
			king = false; 
			red = false;
		}
		void output() const;
		space& operator=(const space& x);
		void setking(bool y) 
		{
			king = y;
		}
		bool isempty() const 
		{
			return empty;
		}
		void setempty(bool y) 
		{
			empty = y;
		}
		void setred(bool y)
		{
			red = y;
		}
	
		bool isred() const 
		{
			return red;
		}
		bool isking() const 
		{
			return king;
		}
	private:
		bool empty;
		bool red;
		bool king;
};

}
#endif
