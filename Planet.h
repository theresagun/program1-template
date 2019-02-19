#ifndef PLANET_CJM
#define PLANET_CJM
#include "Star.h"
class Planet{
	private:
		int id;
		int pos;
		int distance;
		char type;
	public:
		Planet(){this->id=-1;};
		Planet(int);
        	int orbit();

	//Inline Getter Methods	
	
		long getID() {
        		return this->id;
		}

		int getDistance() {
			return this->distance;
		}

        	int getPos() {
			return this->pos;
		}

		char getType() {
			return this->type;
		}

		//you may add any additional methods you may need.
};
#endif
