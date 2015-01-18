class	A
{
	public:
		A();
		~A();
		void	func() const;
	
	private:
		int	m_a;
};

A::A() : m_a(0)
{
}

A::~A()
{
}

void	A::func() const
{
	m_a++;
}

int		main()
{
	A	a;

	a.func();

	return (0);
}
