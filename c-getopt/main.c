// by Qige <qigezhao@gmail.com> since 2018.03.05
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

//#include <getopt.h>

int main(int argc, char **argv)
{
    // verified by Qige @ 2017.01.31
    int c = 0;
    while((c = getopt(argc, argv, "vhdDi:b:")) != -1) {
        switch(c) {
        case 'h':
            env.flag.help = 1;
            break;
        case 'v':
            env.flag.version = 1;
            break;
        case 'd':
            env.flag.debug = 1;
            break;
        case 'D':
            env.flag.daemon = 1;
            break;
        case 'i':
            env.conf.idle = atoi(optarg);
            break;
        default:
            {
                // TODO: handle your own parameters here
            }
            break;
        }
    }
}
