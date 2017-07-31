#!/bin/sh
# verified on OpenWrt by Qige <qigezhao@gmail.com>
# 2017.07.31
while getopts "C:c" OPT; do
  case $OPT in
    c)
      echo "- read channel";;
    C)
      echo "- set channel to $OPTARG";;
    ?)
      echo "- read rfinfo (default)";;
    esac
done
shift $((OPTIND - 1))
