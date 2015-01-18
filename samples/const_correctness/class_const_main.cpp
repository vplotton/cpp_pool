class	A
{
	public:
		A();
		~A();
		void	func();
	
	private:
		int	m_a;
};

A::A() : m_a(0)
{
}

A::~A()
{
}

void	A::func()
{
}

int		main()
{
	A const	a;

	a.func();

	return (0);
}
