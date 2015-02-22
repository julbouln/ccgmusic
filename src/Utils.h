#ifndef UTILS_H
#define UTILS_H
#include "Common.h"

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

 static int getRandomInt(int,int);
 static double getRandomBetween(double,double);
 static bool contains(int[],int);

static int positiveMod(int,int);

static int clampIntToInt(int,int,int);

  static string intToString ( int );
/* static T sampleUniformObjectDistribution(int,Collection<T>);
 static T sampleUniformObjectDistribution(int,vector<T>);
 static T sampleUniformObjectDistribution(int,T[]);
 */
};
#endif // UTILS_H
