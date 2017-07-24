#/usr/bin/lua

local arn = require 'libarn'

print("version:", arn.version())
print("region:", arn.region(0), arn.region(-1))
print("channel:", arn.channel(10), arn.channel(43))
print("frequency:", arn.frequency(0, 24), arn.frequency(1, 45))
