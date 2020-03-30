#include <sys/time.h>
#include <sys/resource.h>

long int get_full_time (void)
{
  struct timeval buf;

  gettimeofday (&buf, 0);
           /* преобразуем время в секундах
              в сотые доли секунды */
  return   buf.tv_sec * 100
           /* преобразуем время в микросекундах 
              в сотые доли секунды */
         + buf.tv_usec / 10000;
}
