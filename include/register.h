#ifndef REGISTER_H_
#define REGISTER_H_

class Register
{
	int id_;
	// TODO : Define all attributes...

public:
	Register();
	Register(
		char id[20]
		// TODO : Add attributes
	);
	Register(const Register& record); // Copy constructor
	
	inline const int getID() const
	{
		return this->id_;
	}
};

#endif
