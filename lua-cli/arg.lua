#!/usr/bin/lua
-- verified on OpenWrt by Qige <qigezhao@gmail.com>
-- 2017.07.31

local daemon = require "qdaemon/nms4"
daemon.run(argv[1], argv[2])

--[[
-- list all arguments
for i, v in pairs(arg) do
  print(i, v)
done
]]--
