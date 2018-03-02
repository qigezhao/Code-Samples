#!/usr/bin/python
# charset: utf-8
# by Qige <qigezhao@gmail.com> since 2018.03.02

import re


# string.split(',')
def splitCityRawLine(idxNamePop):
    if idxNamePop:
        l1 = idxNamePop.strip()
        l2 = re.sub('\u3000','',l1)
        idx, pop = re.findall('[0-9\.]+', l2)
        name = re.search('[^0-9\.]+', l2).group()
        return idx, name, pop

    return None, None, None


# split into index,city,populations
def main(fin = 'city_raw.txt', fout = 'city.csv'):
    fd = open(fin,'r', encoding = 'utf-8')
    fd2 = open(fout, 'w', encoding = 'utf-8')
    if fd and fd2:
        for line in fd.readlines():
            idx, name, pop = splitCityRawLine(line)
            if idx:
                fd2.write("%s,%s,%s\n" %(idx, name, pop))

        fd.close()
        fd2.close()


# cli call
if __name__=="__main__":
    main()
