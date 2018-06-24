#include <sys/time.h>
#include "server.h"

double			get_time_micro()
{
    struct timeval	tv;
    double		time;

    if (gettimeofday(&(tv), NULL) == 0)
    {
        time = (double) tv.tv_sec + (0.000001f * tv.tv_usec);
        return (time);
    }
    else
        return (0);
}

