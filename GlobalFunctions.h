#pragma once
#include <string>

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

//Sign Up Page Functions 
	void signup (String^user , String^pass);
// Login Page Functions 
	bool login (string username , string password);
//Add Hall Function 
	bool addHall(string hallName, string hallAddress);