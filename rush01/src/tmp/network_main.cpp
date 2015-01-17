#include <sys/sysctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/route.h>

int main (int argc, const char * argv[])
{
	NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

	int mib[] = {
		CTL_NET,
		PF_ROUTE,
		0,
		0,
		NET_RT_IFLIST2,
		0
	};
	size_t len;
	if (sysctl(mib, 6, NULL, &len, NULL, 0) < 0) {
		fprintf(stderr, "sysctl: %s\n", strerror(errno));
		exit(1);
	}
	char *buf = (char *)malloc(len);
	if (sysctl(mib, 6, buf, &len, NULL, 0) < 0) {
		fprintf(stderr, "sysctl: %s\n", strerror(errno));
		exit(1);
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
	printf("total ibytes %qu\tobytes %qu\n", totalibytes, totalobytes);
	[pool drain];
	return 0;
}
