#include <iostream>
#include <map>
#include <iterator>
#include "Member.h"
using namespace std;

/**
 * The purpose of this class is to check the execution of the program's functions. 
 **/

Member avi, beni, chana;

//This method ckecks the function `follow`. 
void testFollow() {
	cout << "Follow Test:" << endl;

	Member orel, naama;

	orel.follow(orel);
	cout << orel.numFollowers() << orel.numFollowing() << endl; // 0 0

	orel.follow(naama);
	cout << orel.numFollowers() << orel.numFollowing() << endl; // 0 1
	cout << naama.numFollowers() << naama.numFollowing() << endl; // 1 0
	
	naama.follow(orel);
	cout << orel.numFollowers() << orel.numFollowing() << endl; // 1 1
	cout << naama.numFollowers() << naama.numFollowing() << endl; // 1 1

	avi.follow(naama);
	cout << avi.numFollowers() << avi.numFollowing() << endl; // 0 1
	cout << naama.numFollowers() << naama.numFollowing() << endl; // 2 1
	
	orel.follow(naama);
	cout << orel.numFollowers() << orel.numFollowing() << endl; // 1 1
	cout << naama.numFollowers() << naama.numFollowing() << endl; // 2 1
	cout << "\n" << endl;
}

//This method ckecks the function `unfollow`.
void testUnfollow() {
	cout << "Unfollow Test:" << endl;

	Member orel, naama;
	orel.unfollow(orel);
	cout << orel.numFollowers() << orel.numFollowing() << endl; // 0 0

	orel.follow(naama);
	cout << orel.numFollowers() << orel.numFollowing() << endl; // 0 1
	cout << naama.numFollowers() << naama.numFollowing() << endl; // 1 0
	
	naama.follow(orel);
	cout << orel.numFollowers() << orel.numFollowing() << endl; // 1 1
	cout << naama.numFollowers() << naama.numFollowing() << endl; // 1 1

	avi.follow(naama);
	cout << avi.numFollowers() << avi.numFollowing() << endl; // 0 1
	cout << naama.numFollowers() << naama.numFollowing() << endl; // 2 1

	avi.unfollow(naama);
	cout << avi.numFollowers() << avi.numFollowing() << endl; // 0 0
	cout << naama.numFollowers() << naama.numFollowing() << endl; // 1 1

	orel.unfollow(naama);
	cout << orel.numFollowers() << orel.numFollowing() << endl; // 1 0
	cout << naama.numFollowers() << naama.numFollowing() << endl; // 0 1

	orel.unfollow(naama);
	cout << orel.numFollowers() << orel.numFollowing() << endl; // 1 0
	cout << naama.numFollowers() << naama.numFollowing() << endl; // 0 1
	cout << "\n" << endl;
}

//This method ckecks the function `numFollowers`.
void testNumFollowers() {
	cout << "NumFollowers Test:" << endl;

	Member orel, naama;
	orel.follow(naama);
	avi.follow(beni);
	orel.follow(beni);
	naama.follow(orel);

	cout << orel.numFollowers() << endl; // 1
	cout << naama.numFollowers() << endl; // 1 
	cout << beni.numFollowers() << endl; // 2
	cout << avi.numFollowers() << endl; // 0
	cout << "\n" << endl;
}

//This method ckecks the function `numFollowing`.
void testNumFollowing() {
	cout << "NumFollowing Test:" << endl;

	Member orel, naama;
	orel.follow(naama);
	avi.follow(beni);
	orel.follow(beni);
	naama.follow(orel);

	cout << orel.numFollowing() << endl; // 2
	cout << naama.numFollowing() << endl; // 1 
	cout << beni.numFollowing() << endl; // 0
	cout << avi.numFollowing() << endl; // 1
	cout << "\n" << endl;
}

//This function define another Member, which added to the social network. It's for the test of the function count().
void anotherOne() {
	Member dana;
	cout << Member::count() << endl;
}

//This method ckecks the function `count`.
void testCount(){
	cout << "Count Test:" << endl;

	Member orel, naama, hadar;
	cout << Member::count() << endl; // 6
	anotherOne(); // 7
	cout << Member::count() << endl; // 6
	cout << "\n" << endl;
}

int main() {

	//follow test
	testFollow();

	//unfollow test
	testUnfollow();

	//numFollowers test
	testNumFollowers();

	//numFollowers test
	testNumFollowing();

	//count test 
	testCount();

}
