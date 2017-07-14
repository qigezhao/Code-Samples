/*
 * libc-lua.c
 *
 *  Created on: Jul 14, 2017
 *      Author: Qige <qigezhao@gmail.com>
 */

#include <lua5.1/lua.h>
#include <lua5.1/lualib.h>
#include <lua5.1/lauxlib.h> // not "luaxlib.h"

static int version(lua_State *L)
{
	lua_pushstring(L, "QZ170714");
	return 1;
}
static int channel(lua_State *L)
{
	int channel = luaL_checknumber(L, 1);
	if (channel < 14) channel = 14;
	if (channel > 60) channel = 60;
	lua_pushnumber(L, channel);
	return 1; // must return "1"!
}
static int region(lua_State *L)
{
	int region = luaL_checknumber(L, 1);
	if (region < 0) region = 0;
	if (region > 1) region = 1;
	lua_pushnumber(L, region);
	return 1;
}

static int frequency(lua_State *L)
{
	int region = luaL_checknumber(L, 1);
	int channel = luaL_checknumber(L, 2);
	int freq = 0;
	if (region > 0) {
		freq = 474 + (channel - 21) * 8;
	} else {
		freq = 473 + (channel - 14) * 6;
	}

	lua_pushnumber(L, freq);
	return 1;
}
static const struct luaL_Reg arn3_lua[] = {
	{"version", version},
	{"region", region},
	{"channel", channel},
	{"frequency", frequency},
	{NULL, NULL}
};

int luaopen_lua(lua_State *L)
{
	luaL_openlib(L, "arn3_lua", arn3_lua, 0);
	return 1;
}

