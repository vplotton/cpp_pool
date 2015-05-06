#ifndef SPTROWNERSHIP_HPP
# define SPTROWNERSHIP_HPP

template <class P>
class SPtrOwnership
{
	protected:
		SPtrOwnership():
			m_count(new unsigned int(1))
		{}

		P	clone(P const & val)
		{
			++*m_count;
			return val;
		}

		bool	release(P const &)
		{
			if (!--*m_count)
			{
				delete m_count;
				return true;
			}
			return false;
		}

		enum
		{
			destructiveCopy = false
		};

	private:
		unsigned int *m_count;
};

#endif /* !SPTROWNERSHIP_HPP */
