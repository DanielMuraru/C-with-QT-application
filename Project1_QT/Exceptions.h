#pragma once
#include <string>
class RepoExceptions
{

private:
	std::string mesaj;
public:
	RepoExceptions(const std::string& msg) :mesaj(msg) {}
//	~RepoExceptions() {};
	std::string getmsg() const {
		return mesaj;
	}

};
class ValidatorExceptions
{
private:
	std::string mesaj;
public:
	ValidatorExceptions(const std::string& msg):mesaj(msg){}
//	~ValidatorExceptions(){}
	std::string getmsg()const
	{
		return mesaj;
	}

};