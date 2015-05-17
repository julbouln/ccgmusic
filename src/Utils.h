#ifndef UTILS_H
#define UTILS_H
#include "Common.h"

#define ARRAY_LENGTH(V) sizeof(V)/sizeof(V[0])


using namespace std;

class Utils {
public:
	template <typename T> static void deleteVector(std::vector<T> v) {
	 for(typename std::vector<T>::iterator o = v.begin(); o != v.end(); ++o)
	    delete *o;
	  v.clear();
	};
/*
	template <typename K, typename T> static void deleteMap(std::map<K,T> v) {
	 for(typename std::map<K,T>::iterator o = v.begin(); o != v.end(); ++o)
	    delete *(o->second);
	  v.clear();
	};
*/
// static void expandIfNeccessary(int,vector<T>,T);
// static void setSize(int,vector<T>,T);

template <typename T> static int arrayLength(T* a) {return sizeof(a)/sizeof(T);};

template <typename T> static T sampleUniformObjectDistribution(std::vector<T> v) {
	double rndValue = Utils::getRandomDouble();
	double d1=v.size() - 1;
	double d2=rndValue * v.size();

	int index = (int) d1>d2 ? d2 : d1;
	
	return v.at(index);
};

/*
template <typename T> static T sampleUniformObjectDistribution(T* a) {
	double rndValue = Utils::getRandomDouble();
	double d1=Utils::arrayLength(a) - 1;
	double d2=rndValue * Utils::arrayLength(a);

	int index = (int) d1>d2 ? d2 : d1;
	
	return a[index];
};
*/

 static int getRandomInt(int,int);
 static double getRandomDouble();
 static double getRandomBetween(double,double);
 static bool contains(int[],int);
 static bool contains(vector<int>,int);

static int positiveMod(int,int);

static int clampIntToInt(int,int,int);

  static string intToString ( int );
  static string midiToNote(int);
  static string midiToNoteFr(int);

/* static T sampleUniformObjectDistribution(int,Collection<T>);
 static T sampleUniformObjectDistribution(int,vector<T>);
 static T sampleUniformObjectDistribution(int,T[]);
 */
};
#endif // UTILS_H
