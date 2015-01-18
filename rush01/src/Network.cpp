#include "modules/Network.hpp"

#include <sys/types.h>
#include <sys/sysctl.h>

#include <stdlib.h>

#include <sys/socketvar.h>
#include <netinet/ip.h>
#include <netinet/ip_var.h>
#include <netinet/tcp.h>
#include <netinet/tcp_var.h>
/*
#include <sys/sysctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/route.h>
*/
Network::Network() :
	AbstractModule("Network"), m_previousTotalInput(0), m_previousTotalOutput(0)
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
	m_infos.at(2).setInfo(calculateNetworkInput(inBytes) * 1024);
	m_infos.at(3).setInfo(calculateNetworkOutput(outBytes) * 1024);
}

void	Network::initData()
{
	m_infos.push_back(Info("Packets In", EInfo::OCTET));
	m_infos.push_back(Info("Packets Out", EInfo::OCTET));
	m_infos.push_back(Info("UpStream", EInfo::BYTES));
	m_infos.push_back(Info("DownStream", EInfo::BYTES));

	updateData();
}

void	Network::getInOutput(unsigned long long &in, unsigned long long &out)
{
	void *oldp = reinterpret_cast<void*>(new int[256]);
	size_t oldlen = sizeof(struct ipstat);
	size_t	newlen = 0;
	void * newp = NULL;

	int retval = sysctlbyname("net.inet.ip.stats", oldp, &oldlen, newp, newlen);

	(void)retval;

	struct ipstat * g = (struct ipstat *) oldp;

	in = g->ips_total * 8;
	out = g->ips_localout * 8;
}

unsigned long long	Network::calculateNetworkInput(unsigned long long recvTotal)
{
	unsigned long long recvSinceLastTime = recvTotal - m_previousTotalInput;

	m_previousTotalInput = recvTotal;
	return recvSinceLastTime;
}

unsigned long long  Network::calculateNetworkOutput(unsigned long long sendTotal)
{
	unsigned long long	sendSinceLastTime = sendTotal - m_previousTotalOutput;

	m_previousTotalOutput = sendTotal;
	return sendSinceLastTime;
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
