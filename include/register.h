#ifndef REGISTER_H_
#define REGISTER_H_

//Unused file because it was implemented internally in the organizations

class Register
{
	int id_;
	// TODO : Define all attributes...

public:
	Register();
	Register(
		int id
		// TODO : Add attributes
	);
	Register(const Register& record); // Copy constructor
	
	inline const int getID() const
	{
		return this->id_;
	}
};

#endif
