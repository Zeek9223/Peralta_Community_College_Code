#include <iostream>
#include "Distance.h"
using namespace std;

/* Constructs a default Distance of 0 (0 feet and 0.0 inches)
 */
Distance::Distance(){
    feet = 0;
    inches = 0;
}


/* Constructs a distance of ft feet and in inches,
 unless in >= 12, in which case the values of feet and inches
 are adjusted accordingly. A Distance will always be positive.
 */
Distance::Distance(unsigned ft, double in){
    feet = ft;
    while(in >= 12){
        feet = feet + 1;
        in = in -12;
    }
    inches = in;
}


/* Constructs a distance of 0 ft and in inches,
 unless in >= 12, in which case the values of feet and inches
 are adjusted accordingly. A Distance will always be positive.
 */
Distance::Distance(double in){
    feet = 0;
    
    while(in >= 12){
        feet = feet + 1;
        in = in -12;
    }
    
    inches = in;
}


/* Returns just the feet portion of the Distance
 */
unsigned Distance::getFeet() const{
    return feet;
}


/* Returns just the inches portion of the Distance
 */
double Distance::getInches() const{
    return inches;
}


/* Returns the entire distance as the equivalent amount of inches.
 (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
 */
double Distance::distanceInInches() const{
    return (feet*12 + inches);
}


/* Returns the entire distance as the equivalent amount of feet.
 (e.g., 3 feet 6 inches would be returned as 3.5 feet)
 */
double Distance::distanceInFeet() const{
    return (feet + inches/12.0);
}


/* Returns the entire distance as the equivalent amount of meters.
 1 inch equals 0.0254 meters.
 (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
 */
double Distance::distanceInMeters() const{
    return distanceInInches()*0.0254;
}


/* Returns the sum of 2 Distances.
 */
Distance Distance::operator+(const Distance &rhs) const{
    Distance d(distanceInInches()+rhs.distanceInInches());
    return d;
}


/* Returns the difference between 2 Distances.
 */
Distance Distance::operator-(const Distance &rhs) const{
    double inc = distanceInInches() - rhs.distanceInInches();
    if(inc < 0)
        inc = -inc;
    
    Distance d(inc);
    return d;
}


/* Outputs to the stream out the Distance in the format:
 feet' inches'' (i.e. 3' 3.41'')
 */
ostream & operator<<(ostream &out, const Distance &rhs){
    out<<rhs.getFeet()<<"\' "<<rhs.getInches()<<"\"";
    return out;
}
