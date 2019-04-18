
template <class CallObj>
bool execObj(CallObj& obj) {
	try
	{
		obj();
	}
	catch (const char* msg) {
		std::cout << "\tCaught Exception: " << msg << "\n";
		return false;
	}
	catch (...) {
		std::cout << "\tCaught Exception \n ";
		return false;
	}
	return true;
}
