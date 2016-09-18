#define OFF 0
#define GREEN 1
#define RED 2

int update_state(int state){
  switch(state){
  	case OFF:
  		return GREEN;

    case GREEN:
    	return RED;

    case RED:
    	return OFF;
  }
  return state;
}