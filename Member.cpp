#include <iostream>
#include <map>
#include <iterator>
#include "Member.h"
using namespace std;

/**
 * The purpose of this class is implementing the header's functions.
 **/

int Member::id_member = 0;
int Member::counter = 0;

//This is the constructor of the object `Member`.
Member::Member(){
	this->id = id_member + 1;
	id_member = id;
	counter++;
}

//This is the distructor of the object `Member`.
Member::~Member(){
	map <int, Member*> :: iterator it;
	counter--;
	for(it = this->following.begin(); it != this->following.end(); ++it){
		it->second->followers.erase(it->second->followers.find(this->id));
	}
	for(it = this->followers.begin(); it != this->followers.end(); ++it){
		it->second->following.erase(it->second->following.find(this->id));
	}
}

//This function allows one Member to follow another.
void Member::follow(Member& member2){
	if(&member2 != this){
		pair <int, Member*> ptr;
		ptr.first = member2.id;
		ptr.second = &member2;
		
		if(this->following.count(member2.id) == 0){
			following.insert(ptr);		
			ptr.first = this->id;
			ptr.second = this;
			member2.followers.insert(ptr);		
		}
	}	
}

//This function allows one Member to unfollow another.
void Member::unfollow(Member& member2){
	if(&member2 != this){
		if(this->following.count(member2.id) == 1){
			this->following.erase(member2.id);
			member2.followers.erase(this->id);
		}
	}
}

//This function return the number of Members, which this Member follows them.
int Member::numFollowing(){
	return this->following.size();
}

//This function return the number of Members, which follow this Member.
int Member::numFollowers(){
	return this->followers.size();
}

//This function return the number of Members across the entire social network.
int Member::count(){
	return counter;
}
