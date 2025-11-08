template<typename T>
typename T::iterator easyfind(T &c, int v)
{
	typename T::iterator it = std::find(c.begin(), c.end(), v);

	if (it == c.end())
		throw NotFoundException();

	return it;
}
