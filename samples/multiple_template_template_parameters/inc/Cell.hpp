#ifndef CELL_HPP
# define CELL_HPP

class Cell
{
	public:
		Cell(): m_liberties(4) {}
		~Cell() {}

		int const	&liberties() const
		{ return m_liberties; }
		void	liberties(int const &liberties)
		{ m_liberties = liberties; }

	private:
		int		m_liberties;
};

#endif /* !CELL_HPP */
