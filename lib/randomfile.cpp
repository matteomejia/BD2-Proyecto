#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdio.h>

#include "register.h"
#include "randomfile.h"

RandomFile::RandomFile(std::string filename)
{
	this->filename_ = filename;
	// TODO : Initialize random file
}

void RandomFile::insert(Register record)
{
	// TODO : Insert record into table
}

Register RandomFile::search(int record_id)
{
	// TODO : Find and return register with id = record_id
	
	return Register();
}
