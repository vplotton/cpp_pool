#include "modules/Network.hpp"

#include <sys/sysctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/route.h>

Network::Network() :
	AbstractModule("Network")
{
}

Network::~Network()
{
}

void	Network::updateData()
{
	unsigned long long  inBytes;
	unsigned long long  outBytes;

	getInOutput(inBytes, outBytes);
	m_infos.at(0).setInfo(inBytes);
	m_infos.at(1).setInfo(outBytes);
}

void	Network::initData()
{
	m_infos.push_back(Info("In", EInfo::BYTES));
	m_infos.push_back(Info("Out", EInfo::BYTES));

	updateData();
}

void	Network::getInOutput(unsigned long long &in, unsigned long long &out)
{
	int mib[] = {
		CTL_NET,
		PF_ROUTE,
		0,
		0,
		NET_RT_IFLIST2,
		0
	};
	size_t len;
	if (sysctl(mib, 6, NULL, &len, NULL, 0) < 0)
	{
		/* handle error */
	}
	char *buf = (char *)malloc(len);
	if (sysctl(mib, 6, buf, &len, NULL, 0) < 0)
	{
		/* handle error */
	}

	char *lim = buf + len;
	char *next = NULL;
	u_int64_t totalibytes = 0;
	u_int64_t totalobytes = 0;
	for (next = buf; next < lim; ) {
		struct if_msghdr *ifm = (struct if_msghdr *)next;
		next += ifm->ifm_msglen;
		if (ifm->ifm_type == RTM_IFINFO2) {
			struct if_msghdr2 *if2m = (struct if_msghdr2 *)ifm;
			totalibytes += if2m->ifm_data.ifi_ibytes;
			totalobytes += if2m->ifm_data.ifi_obytes;
		}
	}
	in = totalibytes;
	out = totalobytes;
}

Network::Network(Network const & src) :
	AbstractModule("Network")
{
	*this = src;
}

Network & Network::operator=(Network const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}
