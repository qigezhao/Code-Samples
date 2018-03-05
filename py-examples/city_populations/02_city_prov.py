#!/usr/bin/python
# charset: utf-8
# by Qige <qigezhao@gmail.com> since 2018.03.02

import re

import requests
#from bs4 import BeautifulSoap
from bs4 import BeautifulSoup


# call baidu.com
def baiduResult(city):
    if city:
        url = 'http://www.baidu.com/s?wd=%s属于哪个省' % (city)

        # query baidu.com
        resp = requests.get(url)
        resp.encoding = 'utf-8'
        html = resp.content

        # parse
        baidu = BeautifulSoup(html, 'html.parser')
        # find title
        title = baidu.select('title')

        # 2 major result
        baike = baidu.select('#wrapper_wrapper #content_left .op_exactqa_s_answer a')
        if not baike or baike == '':
            baike = baidu.select('#wrapper_wrapper #content_left .op_exactqa_s_answer')

        # parse again
        s2 = BeautifulSoup(str(baike), 'html.parser')
        prov = str(s2.text).strip('[]').strip()

        print(url, ' -> ',prov)
        return prov

    return None


# wrapper
def findCityOfProv(city):
    if city:
        prov = baiduResult(city)
        return prov

    return None


# handle gbk by utf-8
def main(fin = "city.csv", fout = "city_prov.csv"):
    fd = open(fin, "r", encoding = 'utf-8')
    fd2 = open(fout, "w", encoding = 'utf-8')

    if fd and fd2:
        for line in fd.readlines():
            data = line.strip()
            idx, city, pop = data.split(',')
            prov = findCityOfProv(city)

            # leave empty cell when not found
            if (not prov):
                prov = ''

            print("%s %s belongs to %s\n" % (idx, city, prov))
            fd2.write("%s,%s,%s,%s\n" % (idx, prov, city, pop))

# cli call
if __name__=="__main__":
    main()
