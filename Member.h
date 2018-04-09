#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <map>
#include <iterator>
using namespace std;

/**
 * This is the header of the program, which includes the class `Member`.
 * The class contains the variables and the signatures of the `Member` functions.
 **/

class Member{
	
	int id;
	static int id_member;
	map <int,Member*> followers;
	map <int,Member*> following;
	static int counter;
	
	public:
	
	Member();

	~Member();

	void follow(Member& member2);

	void unfollow(Member& member2);

	int numFollowing();

	int numFollowers();
	
	static int count();

};

#endif


