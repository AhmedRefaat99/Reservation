#include "GlobalFunctions.h"
#include <string>
#include <fstream>
#include <iostream>
#include <istream>
#include <vector>

using namespace std;
using namespace System::IO;

// Sign Up Page Functions  --------------------------------------------------------------------------------------------------------------

	void signup (String^user ,String^pass)
		{
			String^Read = File::ReadAllText ("Users.txt");
			StreamWriter^write = gcnew StreamWriter ("Users.txt");
			write -> Write (Read + user + "`" + pass + Environment::NewLine );
			write->Close();
		}

//----------------------------------------------------------------------------------------------------------------------------------------
	bool login (string username , string password)
	{
		struct user
		{
			string savedUserName , savedPassword;
		};
		string u,p;
		vector <user> users;
		ifstream input;
		input.open("Users.txt");
		user temp;
		while ( getline(input , u,'`')&& getline (input,p) )
		{
			temp.savedUserName = u ;
			temp.savedPassword = p;
			users.push_back(temp);
		}
		for (unsigned int i= 0 ; i < users.size() ; i++)
		{
			if (users[i].savedUserName == username && users[i].savedPassword == password )
			{
				return true;
			}
		}
		return false;
	}
// Add Hall Function 
	bool addHall(string hallName, string hallAddress)
	{
		struct hall
		{
			string savedHallName , savedHallAddress;
		};
		ifstream input;
		input.open("HallsList.txt");
		vector <hall> halls;
		string u,p;
		hall temp;
		while ( getline(input , u,'`')&& getline (input,p) )
		{
			if ( u == hallName )
				return false ;
			temp.savedHallName = u;
			temp.savedHallAddress = p;
			halls.push_back(temp);
		}
		temp.savedHallName = hallName;
		temp.savedHallAddress = hallAddress;
		halls.push_back(temp);
		input.close();
		ofstream output;
		output.open("HallsList.txt");
		for (unsigned int i = 0 ; i < halls.size() ; i++)
		{
			output<<halls[i].savedHallName <<'`'<<halls[i].savedHallAddress<<endl;
		}
		output.close();
		ofstream newfile;
		newfile.open("HallsData/"+hallName+".txt");
		newfile.close();
		return true;
	}