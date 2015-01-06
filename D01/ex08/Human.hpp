#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <string>

class Human
{
	private:
		void meleeAttack(std::string const & target);
		void rangedAttack(std::string const & target);
		void intimidatingShout(std::string const & target);
	public:
		void action(std::string const & action_name, std::string const & target);
};

typedef struct s_atkFunc
{
	std::string name;
	void        (Human::*func)(std::string const &);
}               t_atkFunc;

#endif /* !HUMAN_HPP */
